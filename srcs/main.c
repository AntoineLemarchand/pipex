/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:46:47 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/11 18:27:25 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_simpleredir(int ac, char **av, char **env)
{
	int	i;
	int	input;
	int	output;

	i = 2;
	input = open(av[1], O_CREAT | O_WRONLY);
	output = open(av[ac - 1], O_CREAT | O_WRONLY);
	if (output == -1 || input == -1)
		ft_puterror(13);
	if (dup2(input, 0) == -1 || dup2(output, 1) == -1)
	{
		close(input);
		close(output);
		ft_puterror(77);
	}
	while (i < ac - 2)
		ft_fork(input, av[i++], env);
	ft_exec(av[i], env);
}

void	ft_appendredir(int ac, char **av, char **env)
{
	int	i;
	int	input;
	int	output;

	i = 3;
	input = open(av[1], O_CREAT | O_APPEND | O_WRONLY);
	output = open(av[ac - 1], O_CREAT | O_APPEND | O_WRONLY);
	if (output == -1 || input == -1)
		ft_puterror(13);
	if (dup2(input, 0) == -1 || dup2(output, 1) == -1)
	{
		close(input);
		close(output);
		ft_puterror(77);
	}
	while (i < ac - 2)
		ft_fork(input, av[i++], env);
	ft_exec(av[i], env);
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		return (ft_puterror(22));
	ft_fileisvalid(av[1], 1, 0, 0);
	ft_fileisvalid(av[ac - 1], 0, 1, 0);
	if (!ft_strncmp(av[1], "here_doc\0", 9))
		ft_appendredir(ac, av, env);
	else
		ft_simpleredir(ac, av, env);
	return (0);
}
