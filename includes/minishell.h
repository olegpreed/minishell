/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:37:38 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/21 16:24:07 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "struct.h"

// pipex
int		pipex(int argc, char **argv, t_pipex *pip);
//free
void	ft_free_env_stack(t_env **env);
void	ft_free_env_node(t_env *env);
//env
int		ft_parse_envp(t_llist *l, char *envp[]);
//ft_readline
void	handler(int sig);
char	*ft_readline(char *prom);
//init
t_llist	*llist_new(t_llist_key_comparator_ptr key_cmpr, \
			t_llist_key_destructor_ptr key_dstr, \
			t_llist_val_destructor_ptr val_dstr);
//error
int		ft_error(int ret, const char *err);
//other
int		ft_strslice(const char *s, const char *delim, char **a, char **b);

#endif