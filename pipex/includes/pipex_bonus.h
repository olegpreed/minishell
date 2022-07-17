/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:15:46 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/06/25 18:01:55 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "../../libft/includes/libft.h"
# include "../gnl/get_next_line.h"
# include "../../includes/struct.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_ENVP "Environment"
# define ERR_CMD "Command not found: "
# define ERR_HEREDOC "here_doc"

typedef struct s_ppxb
{
	int		infile;
	int		outfile;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		here_doc;
	pid_t	pid;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		*pipe;
	int		idx;
}			t_ppxb;

int		pipex(int argc, char **argv, t_pipex *pip);
void	close_pipes(t_ppxb *pipex);
void	child(t_ppxb pipex, char **argv, char **envp);
void	parent_free(t_ppxb *pipex);
void	child_free(t_ppxb *pipex);
void	pipe_free(t_ppxb *pipex);
char	*find_path(char **envp);
void	get_infile(char **argv, t_pipex *pip, t_ppxb *pipex);
void	get_outfile(t_pipex *pip, t_ppxb *pipex);
void	doc(char *arg, t_ppxb *pipex);
void	here_doc(char *argv, t_ppxb *pipex);
void	msg_error(char *err);
void	msg_pipe(char *arg);
int		msg(char *err);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strdup(const char *src);
// char	**ft_split(char const *s, char c);
// int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
