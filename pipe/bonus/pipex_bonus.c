/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:04:52 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/10 18:19:59 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	valid_arg_bonus(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	ft_parte_1(char *av, char **env)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return ;
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		excute(av, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
}

int	ft_part1(int i, int ac, char **av, char **env)
{
	int	infile;
	int	outfile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		return (write(2, "Error:\nCouldn't open file", 25), 0);
	outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (outfile == -1)
		return (write(2, "Error:\nCouldn't open file or create", 35), 0);
	dup2(infile, 0);
	dup2(outfile, 1);
	close(outfile);
	while ((ac - 2) > i)
		ft_parte_1(av[i++], env);
	close(infile);
	excute(av[i], env);
	return (1);
}

int	main(int ac, char *av[], char **env)
{
	int	i;

	if (ac < 5)
		return (write(2, "Error:\nwrong input", 19), 1);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac > 6 || ac < 6 || !valid_arg_bonus(av))
			return (write(2, "Error:\nInvalid command", 23), 1);
		if (!ft_parte_2(av, env))
			return (1);
	}
	else
	{
		i = 2;
		if (!ft_part1(i, ac, av, env))
			return (1);
	}
	return (0);
}
