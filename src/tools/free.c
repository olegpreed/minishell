/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arman <arman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:42:44 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/06/14 19:10:28 by arman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_env_stack(t_env **env)
{
	t_env	*tmp;

	if (!env)
		return ;
	while (*env)
	{
		tmp = (*env)->next;
		ft_free_env_node(*env);
		*env = tmp;
	}
	free(env);
}

void	ft_free_env_node(t_env *env)
{
	free(env->name);
	free(env->value);
	free(env);
}
