/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arman <arman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:05:24 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/06/15 01:38:22 by arman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_put(t_env **env_list)
{
	t_env	*node;

	if (env_list)
		node = *env_list;
	else
		node = NULL;
	while (node)
	{
		printf("%s=%s\n", node->name, node->value);
		node = node->next;
	}
}

void	ft_env_unset(t_env **env_list, char *name)
{
	t_env	*tmp;
	t_env	*env;

	if (!env_list || !name)
		return ;
	env = *env_list;
	tmp = env->next;
	if (!(ft_strncmp(env->name, name, ft_strlen(name) + 1)))
	{
		ft_free_env_node(env);
		env_list = &tmp;
		return ;
	}
	while (tmp)
	{
		if (!(ft_strncmp(tmp->name, name, ft_strlen(name) + 1)))
		{
			env->next = tmp->next;
			ft_free_env_node(tmp);
			return ;
		}
		env = env->next;
		tmp = tmp->next;
	}
}

t_env	**ft_get_env(char **env)
{
	t_env	**env_stack;

	env_stack = (t_env **)ft_calloc(sizeof(t_env *), 1);
	*env_stack = ft_env_init(env);
	return (env_stack);
}

void	ft_env_put_name(t_env *env, char *name)
{
	if (!env || !name)
	{
		printf("/n");
		return ;
	}
	while (env)
	{
		if (!(ft_strncmp(env->name, name, ft_strlen(name) + 1)))
			printf("%s\n", env->value);
		env = env->next;
	}
}