/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsebba <abdsebba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:11:37 by abdsebba          #+#    #+#             */
/*   Updated: 2025/02/21 11:19:52 by abdsebba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	write_to_pipe(int pipe_fd, char *line)
{
	if (write(pipe_fd, line, ft_strlen(line)) == -1)
	{
		write(2, "Error: Failed to write to pipe\n", 30);
		return (0);
	}
	return (1);
}

int	read_input_and_check_delimiter(char **av, int pipe_fd)
{
	char	*line;
	char	*str;

	while (1)
	{
		write(1, "pipe heredoc> ", 15);
		line = get_next_line(0);
		if (!line)
			return (write(2, "Error: Failed to read input.\n", 29), 0);
		str = ft_strtrim(line, "\n");
		if (str != NULL)
		{
			if (ft_strcmp(av[2], str) == 0)
				return (free(line), free(str), 1);
			if (!write_to_pipe(pipe_fd, line))
				return (free(line), free(str), 0);
			free(str);
		}
		else
			return (write(2, "Error: here_doc failed\n", 24), free(line), 0);
		free(line);
	}
	return (1);
}

int	here_doc(char **av, int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
		return (write(2, "Error: pipe() failed!\n", 22), 0);
	if (!read_input_and_check_delimiter(av, pipe_fd[1]))
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (0);
	}
	close(pipe_fd[1]);
	return (1);
}
