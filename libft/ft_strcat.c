/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:17:29 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/02 11:04:34 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int b;

	i = 0;
	b = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[b] = s2[i];
		i++;
		b++;
	}
	s1[b] = '\0';
	return (s1);
}
