/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maltu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:19:07 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/17 18:18:52 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_wait(int infile, int outfile, int prev_fd)
{
	close(infile);
	close(outfile);
	if (prev_fd != -1)
		close(prev_fd);
	while (wait(NULL) > 0)
		;
}

int	ft_pipp(t_pipex *ppp, int ac)
{
	if (ppp->i < (ac - 2))
	{
		if (dup2(ppp->fd[1], STDOUT_FILENO) == -1)
			return (close(ppp->prev_fd), close(ppp->infile),
				close(ppp->fd[0]), close(ppp->fd[1]), 0);
		close(ppp->fd[0]);
		close(ppp->fd[1]);
	}
	else
	{
		if (dup2(ppp->outfile, STDOUT_FILENO) == -1)
			return (close(ppp->prev_fd), close(ppp->infile),
				close(ppp->fd[0]), close(ppp->fd[1]), close(ppp->outfile), 0);
		close(ppp->outfile);
	}
	return (1);
}

int	ft_fix_pipe_exc(t_pipex *ppp, int ac, char **env, char **av)
{
	if (ppp->i == 2)
	{
		if (dup2(ppp->infile, STDIN_FILENO) == -1)
			return (close(ppp->infile), 0);
		close(ppp->fd[0]);
		close(ppp->infile);
	}
	else
	{
		if (dup2(ppp->prev_fd, STDIN_FILENO) == -1)
			return (close(ppp->prev_fd), close(ppp->infile), 0);
		close(ppp->prev_fd);
	}
	if (!ft_pipp(ppp, ac))
		return (0);
	if (!excute(av[ppp->i], env))
		exit (EXIT_FAILURE);
	return (1);
}

void	ft_fork_failed(t_pipex *ppp, int ac)
{
	close(ppp->infile);
	close(ppp->outfile);
	if (ppp->prev_fd != -1)
		close(ppp->prev_fd);
	if (ppp->i < (ac - 2))
		close(ppp->fd[0]);
	close(ppp->fd[1]);
	return ;
}

int	open_filee(t_pipex *p, int ac, char **av)
{
	p->infile = open(av[1], O_RDONLY);
	if (p->infile == -1)
		return (write(2, "open infile: No such file or directory\n", 40), 0);
	p->outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (p->outfile == -1)
		return (write(2, "open outfile: No such file or directory\n", 40),
			close(p->infile), 0);
	p->prev_fd = -1;
	p->i = 2;
	return (1);
}
