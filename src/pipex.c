/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:25:26 by avaganay          #+#    #+#             */
/*   Updated: 2023/02/03 14:28:06 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check(char **argv)
{
	int	error;

	error = 0;
	if (argv[2][0] == '\0')
		write(STDERR, "zsh: permission denied:\n", 24);
	if (argv[3][0] == '\0')
		write(STDERR, "zsh: permission denied:\n", 24);
	return (error);
}

int	ft_strchrpipex(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

int	str_ncmp(char *str1, char *str2, int n)
{
	while (--n > 0 && *str1 && *str2 && *str1 == *str2)
	{
		str1 = str1 + 1;
		str2 = str2 + 1;
	}
	return (*str2 - *str1);
}

char	*path_join(char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (ft_strchrpipex(path, 0)
				+ ft_strchrpipex(bin, 0) + 2));
	i = 0;
	j = 0;
	while (path[j])
		joined[i++] = path[j++];
	joined[i++] = '/';
	j = 0;
	while (bin[j])
		joined[i++] = bin[j++];
	joined[i] = 0;
	return (joined);
}

char	*str_ndup(char *str, unsigned int n)
{
	char				*duped;
	unsigned int		i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	while (i < n)
		duped[i++] = *str++;
	duped[n] = 0;
	return (duped);
}

int	ft_open_file1(char *file)
{
	if (access(file, F_OK))
	{
		write(STDERR, "pipex: ", 7);
		write(STDERR, file, ft_strchrpipex(file, 0));
		write(STDERR, ": No such file or directory\n", 28);
		return (STDIN);
	}
	return (open(file, O_RDONLY));
}

char	*getpath(char *cmd, char **envp)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (envp[i] && str_ncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (cmd);
	path = envp[i] + 5;
	while (path && ft_strchrpipex(path, ':') > -1)
	{
		dir = str_ndup(path, ft_strchrpipex(path, ':'));
		bin = path_join(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strchrpipex(path, ':') + 1;
	}
	return (cmd);
}

void	ft_freesplit(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	ft_execve(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args)
	{
		exit(0);
	}
	if (ft_strchrpipex(args[0], '/') > -1)
		path = args[0];
	else
		path = getpath(args[0], envp);
	execve(path, args, envp);
    //free(path);
	write(STDERR, "pipex: ", 7);
	write(STDERR, cmd, ft_strchrpipex(cmd, 0));
	write(STDERR, ": command not found\n", 20);
	ft_freesplit(args);
	exit(1);
}


void	child_process(int file1, char *cmd, int *fd, char **envp)
{
	dup2(file1, STDIN);
	dup2(fd[1], STDOUT);
	close(fd[0]);
	close(file1);
	ft_execve(cmd, envp);
	exit(1);
}

void	parent_process(int file2, char *cmd, int *fd, char **envp, pid_t child2)
{
	waitpid(child2, NULL, 0);
	dup2(file2, STDOUT);
	dup2(fd[0], STDIN);
	close(fd[1]);
	close(file2);
	ft_execve(cmd, envp);
	exit(1);
}

void	pipex(int file1, int file2, char **argv, char **envp)
{
	int		fd[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(fd);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	if (child1 == 0)
		child_process(file1, argv[2], fd, envp);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		parent_process(file2, argv[3], fd, envp, child2);
	close(fd[0]);
	close(fd[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	file1;
	int	file2;

	if (argc != 5)
	{
		write(STDERR, "Invalid number of arguments.\n", 29);
		return (1);
	}
	if (!envp[0])
	{
		write(STDERR, "Envp empty\n", 11);
		return (1);
	}
	else
	{
		if (ft_check(argv))
			return (-1);
		file1 = ft_open_file1(argv[1]);
		file2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (file1 < 0 || file2 < 0)
			return (-1);
		pipex(file1, file2, argv, envp);
	}
	return (0);
}
