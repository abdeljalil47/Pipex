/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonnus_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:04:52 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/02 12:35:13 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <libc.h>

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
		excute(av, env);
	}
	else
	{
		dup2(fd[0], 0);
		close(fd[1]);
	}
}
void	f()
{
	system("leaks pipex");
}
int	main(int ac, char *av[], char **env)
{
	int	i;
	int	infile;
	int	outfile;
atexit(f);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac > 6 || ac < 6 || !valid_arg_bonus(av))
			return (1);
		if (!ft_parte_2(av, env, ac))
			return (1);
	}
	else
	{
		infile = open(av[1], O_RDONLY);
		outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
		dup2(infile, 0);
		dup2(outfile, 1);
		i = 2;
		while ((ac - 2) > i)
			ft_parte_1(av[i++], env);
		close(infile);
		excute(av[i], env);
	}
	return (0);
}
