/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parte_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:50:49 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/10 18:20:50 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	excute_here(char *cmd, char **env)
{
	char		**res;
	char		*str;
	char		**path;

	path = NULL;
	if (!env || *env == NULL)
		return (write(2, "Error: problem in env", 24), 0);
	str = get_path(env);
	path = ft_split(str, ':');
	if (!path)
		return (0);
	res = ft_split(cmd, ' ');
	if (!res)
		return (ft_free_bonus(path), 0);
	ft_valid_path(&cmd, path, res);
	if (execve(cmd, res, env) == -1)
	{
		write(2, "Error: command not found\n", 25);
		ft_free_bonus(path);
		ft_free_bonus(res);
		exit (1);
	}
	return (1);
}

void	here_doc(char **av)
{
	char	*line;
	char	*str;

	while (1)
	{
		write(1, "pipe heredoc> ", 15);
		line = get_next_line(0);
		str = ft_strtrim(line, "\n");
		if (str != NULL)
		{
			if (ft_strcmp(av[2], str) == 0)
			{
				free(line);
				free(str);
				break ;
			}
			free(str);
		}
		free(line);
	}
}

int	parent(int *fd, char **av, char **env)
{
	int	outfile;

	close(fd[1]);
	outfile = open(av[5], O_CREAT | O_RDWR | O_APPEND, 0777);
	if (outfile == -1)
		return (0);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(outfile, 1);
	close(outfile);
	excute_here(av[4], env);
	return (1);
}

int	ft_parte_2(char **av, char **env)
{
	int	fd[2];
	int	pid;

	here_doc(av);
	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		excute_here(av[3], env);
	}
	else
	{
		if (!parent(fd, av, env))
			return (0);
	}
	return (1);
}
