/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:27:48 by antoine           #+#    #+#             */
/*   Updated: 2021/12/24 00:27:08 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<unistd.h>
# include<string.h>
# include<stdlib.h>
# include<stdio.h>

int		ft_puterror(int errno);
void	ft_fileisvalid(char *path, int read, int write, int exec);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *s);
char	**ft_loadcommands(int ac, char **av);
void	ft_freecommands(char **commands);
#endif
