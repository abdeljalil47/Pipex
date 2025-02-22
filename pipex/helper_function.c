/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:18:33 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/19 13:35:57 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin1(char *s1, char *s2)
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
	array[len1] = '/';
	ft_strlcpy(array + len1 + 1, s2, len2 + 1);
	return (array);
}

int	valid_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_find(char *s, char *sep)
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

int	check_cmd(char *s)
{
	if (ft_find(s, "/.") == 1)
	{
		if (access(s, F_OK) == 0)
			return (1);
		else
			return (0);
	}
	return (1);
}

void	ft_close(int *fd, int *id)
{
	close(fd[0]);
	close(fd[1]);
	waitpid(id[0], NULL, 0);
	waitpid(id[1], NULL, 0);
}
