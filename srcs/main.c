/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:46:47 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/10 16:55:43 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include<stdio.h>

static char	*ft_addpath(char *path, char *command)
{
	char	*temp;
	char	*ret;

	temp = ft_strjoin(path, "/");
	ret = ft_strjoin(temp, command);
	free(temp);
	if (access(ret, F_OK | X_OK) == 0)
		return (ret);
	else
	{
		free(ret);
		return (NULL);
	}
}

char	*ft_getpath(char *command, char **env)
{
	char	**path;
	char	*curr;
	int		i;

	while (*env && ft_strncmp(*env, "PATH=", 5))
		env++;
	if (!env)
		return (NULL);
	path = ft_split(*env + 5, ':');
	curr = NULL;
	i = 0;
	while (path[i] && !curr)
	{
		curr = ft_addpath(path[i], command);
		i++;
	}
	ft_freesplit(path);
	if (!curr)
		return (NULL);
	return (curr);
}

int	main(int ac, char **av, char **env)
{
	char	**commands;
	char	*path;

	if (ac < 5)
		return (ft_puterror(22));
	ft_fileisvalid(av[1], 1, 0, 0);
	ft_fileisvalid(av[ac - 1], 0, 1, 0);
	commands = ft_loadcommands(ac, av);
	if (!commands)
		return (ft_puterror(12));
	path = ft_getpath(av[2], env);
	printf("%s\n", path);
	free(path);
	/* ______ WIP ______ */
	ft_freecommands(commands);
	/* ______ WIP ______ */
	return (0);
}
