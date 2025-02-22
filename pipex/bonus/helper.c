/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:50:05 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/19 13:34:55 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin1(char *s1, char *s2, int flag)
{
	char	*array;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	array = (char *)malloc((len1 + len2 + 2));
	if (array == NULL)
		return (NULL);
	ft_strlcpy(array, s1, len1 + 1);
	if (flag == 0)
		array[len1] = '/';
	else if (flag == 1)
		array[len1] = ' ';
	ft_strlcpy(array + len1 + 1, s2, len2 + 1);
	return (array);
}

void	ft_free_bonus(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

void	ft_free_bonus_2(char **res, char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(path);
	free(res);
	write(2, "Error: command not found\n", 25);
}

int	ft_find_bonus(char *s, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == s[0])
			return (1);
		i++;
	}
	return (0);
}

int	check(char *s)
{
	if (ft_find_bonus(s, "/.") == 1)
	{
		if (access(s, F_OK) == 0)
			return (1);
		else
			return (0);
	}
	return (1);
}
