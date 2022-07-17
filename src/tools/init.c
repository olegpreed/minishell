/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:25:19 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/07/03 16:10:08 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_bash(t_bash **info, char **env)
{
	if (!info)
		return ;
	*info = (t_bash *)ft_calloc(sizeof(t_bash), 1);
	if (!*info)
		ft_error(ERR_MALLOC);
	(*info)->env_list = ft_get_env(env);
	(*info)->stop = 0;
}

void	ft_init_line(t_line **line)
{
	if (!line)
		return ;
	*line = (t_line *)ft_calloc(sizeof(t_line), 1);
	if (!*line)
		ft_error(ERR_MALLOC);
	(*line)->nbr_cmd = 0;
}
