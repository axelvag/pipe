/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:26:38 by avaganay          #+#    #+#             */
/*   Updated: 2023/02/03 14:26:57 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "../libft/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

int		ft_strchrpipex(char *str, char c);
int		str_ncmp(char *str1, char *str2, int n);
char	*path_join(char *path, char *bin);
char	*str_ndup(char *str, unsigned int n);
int		ft_open_file1(char *file);
char	*getpath(char *cmd, char **envp);
void	ft_execve(char *cmd, char **envp);
int		ft_check(char **argv);

#endif