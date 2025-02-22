/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:47:46 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/17 19:01:32 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBR_H
# define LIBR_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *s, char sep);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t length);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

#endif
