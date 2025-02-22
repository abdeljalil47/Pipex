/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:18:23 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/18 10:56:32 by abdsebba         ###   ########.fr       */
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

int	in_child_process1(char **av, char **env, char **path, int *fd)
{
	int	f;

	if (!check_cmd(av[2]))
		return (ft_print_error("command not found\n"), close(fd[0]),
			close(fd[1]), 0);
	f = open(av[1], O_RDONLY);
	if (f == -1)
		return (ft_print_error("zsh: no such file or directory: infile\n"),
			close(fd[0]), close(fd[1]), 0);
	if (dup2(f, 0) == -1)
		return (close(f), close(fd[0]), close(fd[1]), 0);
	close(f);
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		return (close(fd[1]), 0);
	close(fd[1]);
	if (!ft_check_path(av, env, path))
		return (0);
	return (1);
}

int	in_child_process2(char **av, char **env, char **path, int *fd)
{
	int	file;

	close(fd[1]);
	if (!check_cmd(av[3]))
		return (ft_print_error("command not found\n"), close(fd[0]), 0);
	file = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (file == -1)
		return (ft_print_error("Couldn't open the outfile\n"), close(fd[0]), 0);
	if (dup2(fd[0], 0) == -1)
		return (close(fd[0]), close(file), 0);
	close(fd[0]);
	if (dup2(file, 1) == -1)
		return (close(file), 0);
	close(file);
	if (!ft_check_path2(av, env, path))
		return (0);
	return (1);
}

int	manage_command(char **av, char **env, char **path)
{
	int	id[2];
	int	fd[2];

	if (pipe(fd) == -1)
		return (0);
	id[0] = fork();
	if (id[0] == -1)
		return (ft_print_error("The function fork() failed\n"), 0);
	if (id[0] == 0)
	{
		if (!in_child_process1(av, env, path, fd))
			return (0);
	}
	id[1] = fork();
	if (id[1] == -1)
		return (ft_print_error("The function fork() failed\n"), 0);
	if (id[1] == 0)
	{
		if (in_child_process2(av, env, path, fd) == 0)
			return (0);
	}
	ft_close(fd, id);
	if (!check_cmd_pa(av, path))
		return (0);
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
		return (ft_print_error("Invalid argument\n"), 1);
	envarment = find_path(env);
	if (envarment == NULL)
		return (write(2, "Error: path not found!\n", 22), 1);
	path = ft_split(envarment, ':');
	if (path == NULL)
		return (1);
	if (!manage_command(av, env, path))
	{
		ft_free(path);
		return (1);
	}
	ft_free(path);
	return (0);
}
