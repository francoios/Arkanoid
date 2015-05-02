/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:50:59 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/02 11:03:02 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *cursor;

	while (lst)
	{
		cursor = lst->next;
		f(lst);
		lst = cursor;
	}
}
