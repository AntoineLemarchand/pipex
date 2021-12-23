/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:00:54 by antoine           #+#    #+#             */
/*   Updated: 2021/12/24 00:30:49 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_puterror(int errno)
{
	write(1, "pipex: ", 7);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, "\n", 1);
	exit(errno);
}

void ft_freecommands(char **commands)
{
	char	**commandsbegin;

	commandsbegin = commands;
	while (*commands)
	{
		free(*commands);
		commands++;
	}
	free(commandsbegin);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		s_len;
	int		i;

	s_len = (int)ft_strlen((char *)s);
	i = 0;
	dest = malloc((s_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(const char *s)
{
	int size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}
