/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:59:11 by alemarch          #+#    #+#             */
/*   Updated: 2022/01/17 14:12:04 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	ft_fork(int fd, char *action, char **env)
{
	int		link[2];
	pid_t	parent;

	pipe(link);
	parent = fork();
	if (!parent)
	{
		if (fd == 1)
			return (1);
		else
		{
			close(link[0]);
			if (dup2(link[1], 1) == -1)
				return (1);
			ft_exec(action, env);
		}
	}
	else
	{
		waitpid(parent, NULL, 0);
		if (dup2(link[0], 0) == -1)
			return (1);
		close(link[1]);
	}
	return (0);
}

int	ft_exec(char *action, char **env)
{
	char	*command;
	char	**av;

	av = ft_split(action, ' ');
	if (!av)
		return (1);
	command = ft_getpath(action, env);
	if (!command)
	{
		ft_freesplit(av);
		return (1);
	}
	execve(command, av, env);
	free(command);
	ft_freesplit(av);
	return (0);
}
