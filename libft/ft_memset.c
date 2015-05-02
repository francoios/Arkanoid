/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:41:20 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/02 11:03:48 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char *a;

	a = (unsigned char*)b;
	while (len--)
		a[len] = c;
	return (a);
}
