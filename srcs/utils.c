/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:00:54 by antoine           #+#    #+#             */
/*   Updated: 2021/12/20 23:02:40 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_puterror(int errno)
{
	write(1, " : ", 3);
	write(1, strerror(errno), ft_strlen(strerror(errno)));
	write(1, "\n", 1);
	exit(errno);
}

void	ft_fileisvalid(char *path, int r, int w, int x)
{
	if (access(path, F_OK) != 0)
	{
		write(2, "pipex : ", 8);
		write(2, path, ft_strlen(path));
		ft_puterror(2);
	}
	else if ((r && access(path, R_OK) != 0)
		|| (w && access(path, W_OK) != 0)
		|| (x && access(path, X_OK) != 0))
	{
		write(2, "pipex : ", 8);
		write(2, path, ft_strlen(path));
		ft_puterror(13);
	}
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
