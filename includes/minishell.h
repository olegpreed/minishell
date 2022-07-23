/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:37:38 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/23 16:21:10 by lgarrosh         ###   ########.fr       */
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

# define PATH_MAX 1024

int		g_exit;

// pipex
int			pipex(int argc, char **argv, t_pipex *pip);
//free
void		ft_free_env_stack(t_env **env);
void		ft_free_env_node(t_env *env);
//env
int			ft_parse_envp(t_llist *l, char *envp[]);
//ft_readline
void		handler(int sig);
char		*ft_readline(char *prom);
//init
t_llist		*llist_new(t_llist_key_comparator_ptr key_cmpr, \
				t_llist_key_destructor_ptr key_dstr, \
				t_llist_val_destructor_ptr val_dstr);
int			ft_init(t_info *info, char *envp[]);
//error
int			ft_error(int ret, const char *err);
//other
char		*ft_strcpy(const char *s);
int			ft_strslice(const char *s, const char *delim, char **a, char **b);
int			ft_strcontains(const char *s, const char c);
int			ft_is_valid_id(const char *s);
//builtin
int			ft_pwd(t_llist *args, t_info *info);
int			ft_env(t_llist *args, t_info *info);
int			ft_unset(t_llist *args, t_info *info);
int			ft_export(t_llist *args, t_info *info);
int			ft_exit(t_llist *args, t_info *info);
int			ft_cd(t_llist *args, t_info *info);
int			ft_echo(t_llist *args, t_info *info);
void		not_valid_handler(char *a, char *b);
//list
int			llist_del(t_llist *list, const void *key);
int			llist_push(t_llist *list, void *key, void *val);
int			llist_set(t_llist *list, void *key, void *new_val);
int			llist_str_kcmp(const void *k1, const void *k2);
t_ll_elem	*_new_ll_elem(void *key, void *val);
int			llist_addend(t_llist *list, void *key, void *val);

#endif