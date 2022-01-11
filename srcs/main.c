/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:46:47 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/11 14:52:25 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include<stdio.h>

static char	*ft_addpath(char *path, char *command)
{
	char	*temp;
	char	*ret;

	temp = ft_strjoin(path, "/");
	ret = ft_joincommand(temp, command);
	free(temp);
	if (access(ret, F_OK | X_OK) == 0)
		return (ret);
	else
	{
		free(ret);
		return (NULL);
	}
}

static char	*ft_getpath(char *command, char **env)
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

static int	ft_exec(char *action, char **env)
{
	char	*command;
	char	**av;
	int		ret;

	av = ft_split(action, ' ');
	if (!av)
		return (1);
	command = ft_getpath(action, env);
	if (!command)
	{
		ft_freesplit(av);
		return (1);
	}
	ret = execve(command, av, env);
	free(command);
	ft_freesplit(av);
	return (ret);
}
/*
static int	*ft_dopipe(int	fd1, int	fd2)
{
	int	pipe[2];

	pipe = pipe(pipe);
	close(pipe[0]);
	dup2(pipe[0], fd1);
	close(pipe[1]);
	dup2(pipe[1], fd2);

	return (pipe);
}
*/

int	main(int ac, char **av, char **env)
{
	int		output;

	if (ac < 5)
		return (ft_puterror(22));
	ft_fileisvalid(av[1], 1, 0, 0);
	ft_fileisvalid(av[ac - 1], 0, 1, 0);
	output = open(av[ac - 1], O_CREAT | O_WRONLY);
	if (output == -1)
		ft_puterror(13);
	ft_exec(av[2], env);
	return (0);
}
