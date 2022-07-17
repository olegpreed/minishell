/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arman <arman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:02:33 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/06/15 01:27:05 by arman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*ft_creat_node(char *name, char *value);
static void		ft_add_node(t_env **env, t_env *node);

t_env	*ft_env_init(char **env)
{
	t_env	*env_list;
	t_env	*newnode;
	char	**var;
	int		i;

	i = 0;
	env_list = NULL;
	while (env[i])
	{
		var = ft_split(env[i], '=');
		newnode = ft_creat_node(var[0], var[1]);
		if (!env_list)
			env_list = newnode;
		else
			ft_add_node(&env_list, newnode);
		free(var[0]);
		free(var[1]);
		free(var);
		i++;
	}
	return (env_list);
}

static t_env	*ft_creat_node(char *name, char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new)
	{
		new->name = ft_strdup(name);
		new->value = ft_strdup(value);
		new->next = NULL;
	}
	return (new);
}

static void	ft_add_node(t_env **env, t_env *node)
{
	t_env	*list;

	if (!env || !node)
		return ;
	if (*env)
	{
		list = *env;
		while (list->next)
			list = list->next;
		list->next = node;
	}
}

void	ft_env_export(t_env **env_list, char *name, char *value)
{
	if (!name || !value || !env_list)
		return ;
	if (ft_if_name_in_env(env_list, name))
		ft_env_unset(env_list, name);
	ft_add_node(env_list, ft_creat_node(name, value));
}

t_env	*ft_if_name_in_env(t_env **stack, char *name)
{
	t_env *tmp;

	if (!stack || !name)
		return (NULL);
	tmp = *stack;
	while(tmp)
	{
		if (!(ft_strncmp(tmp->name, name, ft_strlen(name) + 1)))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
