/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatusse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:25:39 by fcatusse          #+#    #+#             */
/*   Updated: 2019/03/15 16:52:33 by fcatusse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while (s[i] && ft_isblank(s[i]))
		i++;
	if (i == j)
		return (ft_strdup(""));
	while (j > 0 && s[j - 1] && ft_isblank(s[j - 1]))
		j--;
	cpy = ft_strsub(s, i, j - i);
	if (!cpy)
		return (NULL);
	return (cpy);
}
