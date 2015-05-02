/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:17:06 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/02 11:03:15 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ap;

	if (size == 0)
		return (NULL);
	if (!(ap = (void*)(malloc(size))))
		return (NULL);
	ft_bzero(ap, size);
	return (ap);
}
