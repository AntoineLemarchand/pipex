/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:46:47 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/18 11:19:56 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_simpleredir(int ac, char **av, char **env)
{
	int	input;
	int	output;

	input = open(av[1], O_RDONLY);
	output = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (output == -1 || input == -1)
		ft_puterror(13);
	if (dup2(input, 0) == -1 || dup2(output, 1) == -1)
	{
		close(input);
		close(output);
		ft_puterror(77);
	}
	ft_fork(input, av[2], env);
	ft_exec(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		return (ft_puterror(22));
	ft_fileisvalid(av[1]);
	ft_simpleredir(ac, av, env);
	return (0);
}
