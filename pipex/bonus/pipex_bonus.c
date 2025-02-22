/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:04:52 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/17 22:40:01 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	valid_arg_bonus(char **av)
{
	int	i;

	i = 3;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	parent_paret(t_pipex *pp, int ac, int i, int *fd)
{
	if (pp->prev_fd != -1)
		close(pp->prev_fd);
	if (i < (ac - 2))
	{
		pp->prev_fd = fd[0];
		close(fd[1]);
	}
}

int	manage_command_maltu(char **av, char **env, int ac)
{
	t_pipex	*pp;

	pp = malloc(sizeof(t_pipex));
	if (pp == NULL)
		return (0);
	if (!open_filee(pp, ac, av))
		return (free(pp), 0);
	if (!handle_pipe_loop(pp, ac, env, av))
		return (free(pp), 0);
	return (ft_wait(pp->infile, pp->outfile, pp->prev_fd), free(pp), 1);
}

int	handle_pipe_loop(t_pipex *pp, int ac, char **env, char **av)
{
	while (pp->i < (ac - 1))
	{
		if (pp->i < (ac - 2))
		{
			if (pipe(pp->fd) == -1)
				return (write(2, "Pipe() failed!\n", 18),
					close(pp->infile), close(pp->outfile), 0);
		}
		pp->pid = fork();
		if (pp->pid == -1)
			return (ft_fork_failed(pp, ac), 0);
		else if (pp->pid == 0)
		{
			if (!ft_fix_pipe_exc(pp, ac, env, av))
				return (0);
		}
		else
			parent_paret(pp, ac, pp->i, pp->fd);
		pp->i++;
	}
	return (1);
}

int	main(int ac, char *av[], char **env)
{
	if (ac == 1)
		return (write(2, "Error: wrong input!\n", 21), 1);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac > 6 || ac < 6 || !valid_arg_bonus(av))
			return (write(2, "Error: Invalid command", 23), 1);
		if (!ft_parte_2(av, env))
			return (1);
	}
	else
	{
		if (!manage_command_maltu(av, env, ac))
			return (1);
	}
	return (0);
}
