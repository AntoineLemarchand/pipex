/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:26:15 by antoine           #+#    #+#             */
/*   Updated: 2021/12/24 00:30:56 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	char	**commands;

	if (ac < 5)
		return (ft_puterror(22));
	ft_fileisvalid(av[1], 1, 0, 0);
	ft_fileisvalid(av[ac - 1], 0, 1, 0);
	commands = ft_loadcommands(ac, av);
	if (!commands)
		return (ft_puterror(12));
	/* ______ WIP ______ */
	ft_freecommands(commands);
	/* ______ WIP ______ */
	return (0);
}
