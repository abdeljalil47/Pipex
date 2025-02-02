/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parte_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:50:49 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/02 12:59:37 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	dup2(outfile, 1);
	excute(av[4], env);
	return (1);
}
char *ft_join(char **v, int i, int ac)
{
	char *str;
	char *bup;

	while (i < (ac - 1) && v[i])
	{
		bup = str;
		str = ft_strjoin1(bup, v[i], 1);
		if (str == NULL)
			return (free(bup), NULL);
		i++;
	}
	return (str);
}

int	check_cmd(char **av, int ac, char **env)
{
	char **res;
	char **path;
	char *cmd;
	char *str;
	int i;

	i = 3;
	cmd = ft_join(av, i, ac);
	res = ft_split(cmd, ' ');
	if (!res)
		return (free(cmd), 0);
	free(cmd);
	str = get_path(env);
	path = ft_split(str, ':');
	if (!path)
		return (ft_free_bonus(res), 0);
	if (!ft_valid_path(&str, path, res))
		return (ft_free_bonus(path), ft_free_bonus(res), 0);
	free(cmd);
	ft_free_bonus(res);
	ft_free_bonus(path);
	return 1;
}

int	ft_parte_2(char **av, char **env, int ac)
{
	int	fd[2];
	int	pid;

	here_doc(av);
	if (!check_cmd(av, ac, env))
		return (write(2, "Error: command not found\n", 25), 0);
	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		excute(av[3], env);
	}
	else
	{
		if (!parent(fd, av, env))
			return (0);
	}
	return (1);
}
