/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exute_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:59:16 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/19 13:35:27 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_path(char **pa)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (pa[i])
	{
		str = ft_strnstr(pa[i], "PATH=", 5);
		if (str != NULL)
			return (str + 5);
		i++;
	}
	return (NULL);
}

int	ft_valid_path(char **cmd, char **path, char **cmds)
{
	int		i;
	char	*full;

	i = 0;
	if (ft_find_bonus(cmd[0], "/."))
	{
		if (access(cmd[0], F_OK) == 0)
			return (*cmd = cmds[0], 1);
	}
	while (path[i])
	{
		full = ft_strjoin1(path[i], cmds[0], 0);
		if (access(full, F_OK) == 0)
		{
			if (access(full, X_OK) == 0)
			{
				*cmd = full;
				return (1);
			}
		}
		free(full);
		i++;
	}
	return (0);
}

int	excute(char *cmd, char **env)
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
	if (!ft_valid_path(&cmd, path, res))
		return (ft_free_bonus_2(path, res), 0);
	if (!check(res[0]))
		return (ft_free_bonus(res), ft_free_bonus(path),
			free(cmd), write(2, "Error: command not found\n", 25), 0);
	if (execve(cmd, res, env) == -1)
	{
		ft_free_bonus_2(path, res);
		exit (0);
	}
	return (1);
}

void	ft_close_he(int *fd, int *pid)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}
