/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:24:45 by preed             #+#    #+#             */
/*   Updated: 2022/03/28 18:34:04 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// applies (*del) to the content of a structure
// frees this structure
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !*del)
		return ;
	(*del)(lst->content);
	free(lst);
}
