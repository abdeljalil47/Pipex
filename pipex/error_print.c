/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:18:36 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/19 13:18:12 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_error(const char *str)
{
	int	size;

	write(2, "ERROR:\n", 7);
	if (str)
	{
		size = ft_strlen(str);
		write(2, str, size);
	}
}

void	ft_free(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

int	ft_chccc(char **cmd, char **path, int i)
{
	char	*full_path;

	if (ft_find(cmd[0], "/."))
	{
		if (access(cmd[0], F_OK) == 0)
			return (1);
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
				free(full_path);
				return (1);
			}
		}
		free(full_path);
		i++;
	}
	return (0);
}

int	check_cmd_pa(char **av, char **path)
{
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(av[3], ' ');
	if (cmd == NULL)
		return (0);
	if (!ft_chccc(cmd, path, i))
		return (ft_free(cmd), 0);
	ft_free(cmd);
	return (1);
}
