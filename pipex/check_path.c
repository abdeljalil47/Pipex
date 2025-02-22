/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:18:39 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/20 15:41:28 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	valid_path(char **command, char **path, char **cmd, int i)
{
	char	*full_path;

	i = 0;
	if (ft_find(cmd[0], "/."))
	{
		if (access(cmd[0], F_OK) == 0)
			return (*command = cmd[0], 1);
	}
	while (path[i])
	{
		full_path = ft_strjoin1(path[i], cmd[0]);
		if (!full_path)
			return (0);
		if (access(full_path, F_OK) == 0)
		{
			if (access(full_path, X_OK) == 0)
			{
				*command = full_path;
				return (1);
			}
		}
		free(full_path);
		i++;
	}
	return (0);
}

int	ft_check_path(char **av, char **env, char **path)
{
	char	*command;
	int		i;
	char	**cmd;

	i = 0;
	command = NULL;
	cmd = ft_split(av[2], ' ');
	if (!cmd)
		return (0);
	valid_path(&command, path, cmd, i);
	if (execve(command, cmd, env) == -1)
	{
		write(2, "zsh: command not found\n", 24);
		ft_free(cmd);
		return (0);
	}
	return (1);
}

int	ft_check_path2(char **av, char **env, char **path)
{
	char	*command;
	int		i;
	char	**cmd;

	i = 0;
	command = NULL;
	cmd = ft_split(av[3], ' ');
	if (!cmd)
		return (0);
	valid_path(&command, path, cmd, i);
	if (execve(command, cmd, env) == -1)
	{
		write(2, "zsh: command not found\n", 24);
		ft_free(cmd);
		return (0);
	}
	return (1);
}
