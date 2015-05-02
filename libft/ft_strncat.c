/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:14:10 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/02 11:05:40 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t b;

	i = 0;
	b = ft_strlen(s1);
	while (i < n && s2[i] != '\0')
	{
		s1[b] = s2[i];
		i++;
		b++;
	}
	s1[b] = '\0';
	return (s1);
}