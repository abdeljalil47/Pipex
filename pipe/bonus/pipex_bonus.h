/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:32:05 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/10 18:24:47 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin1(char *s1, char *s2, int flag);
char	*get_path(char **pa);
int		excute(char *cmd, char **env);
char	*ft_strjoin1(char *s1, char *s2, int flag);
int		ft_parte_2(char **av, char **env);
void	ft_free_bonus(char **path);
int		ft_valid_path(char **cmd, char **path, char **cmds);
int		check(char **s);
void	ft_free_bonus_2(char **res, char **path);

#endif