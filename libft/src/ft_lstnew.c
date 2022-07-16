/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:27:59 by preed             #+#    #+#             */
/*   Updated: 2022/03/28 18:31:53 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// creates a structure in heap with content
// and null pointer in next
t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = (t_list *)malloc(sizeof(t_list));
	if (!a)
		return (NULL);
	a->content = content;
	a->next = NULL;
	return (a);
}
