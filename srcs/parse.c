/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:47:38 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/26 19:20:46 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_fileisvalid(char *path, int r, int w, int x)
{
	if (access(path, F_OK) != 0)
	{
		write(2, "pipex: ", 7);
		write(2, path, ft_strlen(path));
		write(2, ": ", 2);
		write(1, strerror(2), ft_strlen(strerror(2)));
		write(1, "\n", 1);
		exit(13);
	}
	else if ((r && access(path, R_OK) != 0)
		|| (w && access(path, W_OK) != 0)
		|| (x && access(path, X_OK) != 0))
	{
		write(2, "pipex: ", 7);
		write(2, path, ft_strlen(path));
		write(2, ": ", 2);
		write(1, strerror(13), ft_strlen(strerror(13)));
		write(1, "\n", 1);
		exit(13);
	}
}

char	**ft_loadcommands(int ac, char **av)
{
	int		i;
	char	**commands;

	i = 2;
	commands = malloc((ac - 1) * sizeof(char *));
	while (i != ac - 1)
	{
		commands[i - 2] = ft_strdup(av[i]);
		if (!commands[i - 2])
		{
			ft_freecommands(commands);
			return (NULL);
		}
		i++;
	}
	commands[i - 2] = NULL;
	return (commands);
}
