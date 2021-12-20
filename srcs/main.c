/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:26:15 by antoine           #+#    #+#             */
/*   Updated: 2021/12/20 23:12:33 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_loadcommands(int ac, char **av)
{
	int		i;
	char	**commands;

	i = 2;
	commands = malloc((ac - 1) * sizeof(char *));
	while (i != ac - 1)
	{
		commands[i - 2] = ft_strdup(av[i]);
		i++;
	}
	commands[i - 2] = NULL;
	return (commands);
}

int	main(int ac, char **av)
{
	char **commands;

	if (ac < 5)
	{
		write(1, "pipex", 5);
		ft_puterror(22);
	}
	ft_fileisvalid(av[1], 1, 0, 0);
	ft_fileisvalid(av[ac - 1], 0, 1, 0);
	commands = ft_loadcommands(ac, av);
	return (0);
}
