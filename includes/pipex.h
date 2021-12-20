/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:27:48 by antoine           #+#    #+#             */
/*   Updated: 2021/12/20 23:03:07 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<unistd.h>
# include<string.h>
# include<stdlib.h>

int		ft_puterror(int errno);
void	ft_fileisvalid(char *path, int read, int write, int exec);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *s);
#endif
