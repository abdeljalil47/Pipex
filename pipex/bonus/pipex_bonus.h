/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:32:05 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/21 11:13:12 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./get_next_line.h"
# include "../libr/libr.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct pipex_bonus
{
	int	infile;
	int	outfile;
	int	fd[2];
	int	prev_fd;
	int	i;
	int	pid;
}			t_pipex;

char	*ft_strjoin1(char *s1, char *s2, int flag);
char	*get_path(char **pa);
int		excute(char *cmd, char **env);
char	*ft_strjoin1(char *s1, char *s2, int flag);
int		ft_parte_2(char **av, char **env);
void	ft_free_bonus(char **path);
int		ft_valid_path(char **cmd, char **path, char **cmds);
int		check(char *s);
void	ft_free_bonus_2(char **res, char **path);

int		handle_pipe_loop(t_pipex *pp, int ac, char **env, char **av);
void	parent_paret(t_pipex *pp, int ac, int i, int *fd);
void	ft_wait(int infile, int outfile, int prev_fd);
int		ft_pipp(t_pipex *ppp, int ac);
int		ft_fix_pipe_exc(t_pipex *ppp, int ac, char **env, char **av);
void	ft_fork_failed(t_pipex *ppp, int ac);
int		open_filee(t_pipex *p, int ac, char **av);
void	ft_close_he(int *fd, int *pid);
int		ft_find_bonus(char *s, char *sep);
int		here_doc(char **av, int *pipe_fd);

#endif