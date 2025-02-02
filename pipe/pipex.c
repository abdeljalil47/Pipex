/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:18:23 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/02 12:09:42 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **p)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (p[i])
	{
		str = ft_strnstr(p[i], "PATH=", 5);
		if (str != NULL)
			return (str);
		i++;
	}
	return (NULL);
}

int	in_child_process(char **av, char **env, char **path, int *fd)
{
	int	f;

	f = open(av[1], O_RDONLY);
	if (f == -1)
		return (ft_print_error("Couldn't open the infile\n"), 0);
	dup2(f, 0);
	close(fd[0]);
	dup2(fd[1], 1);
	ft_check_path(av, env, path);
	return (1);
}

int	all_valid_command(char **av, char **path)
{
	if (!check_first_command(av[2], path))
		return (ft_print_error("command not found\n"), 0);
	else if (!check_second_command(av[3], path))
		return (ft_print_error("command not found\n"), 0);
	return (1);
}

int	manage_command(char **av, char **env, char **path)
{
	int	id;
	int	fd[2];
	int	f1;

	if (!all_valid_command(av, path) || pipe(fd) == -1)
		return (0);
	id = fork();
	if (id == -1)
		return (ft_print_error("The function fork() failed\n"), 0);
	if (id == 0)
	{
		if (!in_child_process(av, env, path, fd))
			return (0);
	}
	else
	{
		close(fd[1]);
		f1 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (f1 == -1)
			return (ft_print_error("Couldn't open the outfile\n"), 0);
		dup2(fd[0], 0);
		dup2(f1, 1);
		ft_check_path2(av, env, path);
	}
	return (1);
}

int	main(int ac, char *av[], char **env)
{
	char	**path;
	char	*envarment;

	path = NULL;
	envarment = NULL;
	if (ac != 5)
		return (ft_print_error("It must be 5 argument\n"), 1);
	if (env == NULL || *env == NULL)
		return (ft_print_error("env Invalid\n"), 1);
	else if (!valid_arg(av))
		return (ft_print_error("Ivalid argument\n"), 1);
	envarment = find_path(env);
	if (envarment == NULL)
		return (1);
	path = ft_split(envarment, ':');
	if (path == NULL)
		return (1);
	if (!manage_command(av, env, path))
		return (ft_free(path), 1);
	ft_free(path);
	return (0);
}
