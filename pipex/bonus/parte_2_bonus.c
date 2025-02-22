/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parte_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:50:49 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/21 11:11:44 by abdsebba         ###   ########.fr       */
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

int	child1(int *pipe_fd, char **av, char **env, int *fd)
{
	close(pipe_fd[1]);
	close(fd[0]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		return (close(pipe_fd[0]), close(fd[1]), 0);
	close(pipe_fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (close(fd[1]), 0);
	close(fd[1]);
	excute_here(av[3], env);
	exit(0);
}

int	child2(int *fd, char **av, char **env)
{
	int	outfile;

	if (!check(av[4]))
		return (write(2, "Error: command not found\n", 26),
			close(fd[0]), close(fd[1]), 0);
	close(fd[1]);
	outfile = open(av[5], O_CREAT | O_RDWR | O_APPEND, 0777);
	if (outfile == -1)
		return (close(fd[0]), 0);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		return (close(outfile), 0);
	close(fd[0]);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		return (close(outfile), 0);
	close(outfile);
	excute_here(av[4], env);
	exit(0);
}

void	ft_close_wait(int *pipe_fd, int *fd, int *pid)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
}

int	ft_parte_2(char **av, char **env)
{
	int	fd[2];
	int	pipe_fd[2];
	int	pid[2];

	if (!here_doc(av, pipe_fd) || pipe(fd) == -1)
		return (0);
	pid[0] = fork();
	if (pid[0] == -1)
		return (write(2, "Error: fork() failed!\n", 21), 0);
	if (pid[0] == 0)
	{
		child1(pipe_fd, av, env, fd);
		exit(0);
	}
	pid[1] = fork();
	if (pid[1] == -1)
		return (write(2, "Error: fork() failed!\n", 21), 0);
	if (pid[1] == 0)
	{
		child2(fd, av, env);
		exit(0);
	}
	ft_close_wait(pipe_fd, fd, pid);
	return (1);
}
