/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:18:26 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/19 13:34:38 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libr/libr.h"
# include <unistd.h>
# include <fcntl.h>

int		ft_check_path(char **av, char **env, char **path);
char	*ft_strjoin1(char *s1, char *s2);
int		ft_check_path2(char **av, char **env, char **path);
void	ft_print_error(const char *str);
void	ft_free(char **path);
int		valid_arg(char **av);
int		valid_path(char	**command, char **path, char **cmd, int i);
int		check_cmd(char *s);
void	ft_close(int *fd, int *id);
int		check_cmd_pa(char **av, char **path);
int		ft_find(char *s, char *sep);

#endif