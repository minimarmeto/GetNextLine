/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:11:47 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/06/10 19:10:20 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (s + i);
	return (0);
}

int	ft_strlcpy(char *s1, char *s2, int len)
{
	int	i;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i] && i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (i);
}

char	*ft_substr(char *s, char c)
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		if (s[i++] == c)
			break ;
	str = malloc(sizeof(char) * i);
	if (!str)
		return (0);
	ft_strlcpy(s, str, i);
	return (str);
}
