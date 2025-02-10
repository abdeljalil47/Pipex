/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:23:24 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/10 18:08:54 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_join_bonus(char **av, int i, int ac)
{
	char	*str;
	char	*bup;

	str = NULL;
	while ((ac - 1) > i)
	{
		bup = str;
		str = ft_strjoin1(bup, av[i], 0);
		if (str == NULL)
			return (free(bup), NULL);
		free(bup);
		i++;
	}
	return (str);
}

int	check_all_cmd(int ac, int i, char **av, char **path)
{
	char	**res;
	char	*str;
	int		x;

	x = 0;
	res = NULL;
	str = ft_join_bonus(av, i, ac);
	if (str == NULL)
		return (0);
	free(str);
	while (x < (ac - 3))
	{
		res = ft_split(av[i + x], ' ');
		if (res == NULL)
			return (0);
		if (!ft_valid_path_b_exx(path, res))
			return (ft_free_bonus(res), 0);
		if (check(res) == 0)
			return (ft_free_bonus(res), 0);
		ft_free_bonus(res);
		x++;
	}
	return (1);
}

int	checkc_cmd_bonus(char **av, int i, char **env, int ac)
{
	char	*tmp;
	char	**path;

	tmp = get_path(env);
	path = ft_split(tmp, ':');
	if (!path)
		return (0);
	if (!check_all_cmd(ac, i, av, path))
		return (ft_free_bonus(path), 0);
	return (ft_free_bonus(path), 1);
}
