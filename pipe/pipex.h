/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:18:26 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/02 11:07:34 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

int		ft_check_path(char **av, char **env, char **path);
char	*ft_strjoin1(char *s1, char *s2);
int		ft_check_path2(char **av, char **env, char **path);
void	ft_print_error(const char *str);
void	ft_free(char **path);
int		valid_arg(char **av);
int		valid_path(char	**command, char **path, char **cmd);
int		check_first_command(char *str, char **path);
int		check_second_command(char *str, char **path);
int		check_cmd(char **s);

#endif