/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:37:38 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/16 15:55:26 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdio.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
// # include <sys/stat.h>
// # include <errno.h>
// # include <termios.h>
// # include <term.h>
// # include <curses.h>
// # include <termcap.h>
// # include <sys/ioctl.h>
# include "libft.h"
# include "struct.h"

// pipex
int		pipex(int argc, char **argv, t_pipex *pip);
//free
void	ft_free_env_stack(t_env **env);
void	ft_free_env_node(t_env *env);
//env
t_env	**ft_get_env(char **env);
t_env	*ft_env_init(char **env);
void	ft_env_export(t_env **env_list, char *name, char *value);
void	ft_env_put(t_env **env_list);
void	ft_env_unset(t_env **env_list, char *name);
void	ft_env_put_name(t_env *env, char *name);
t_env	*ft_if_name_in_env(t_env **stack, char *name);
void	ft_error(const char *err);

#endif