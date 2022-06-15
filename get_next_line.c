/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:38:29 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/06/15 19:13:35 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	Crea un nuevo conjunto elemento de lista que comprende una linea del archivo
	especificcado.
*/
t_list	*ft_rdlst(int fd)
{
	t_list	*new;
	int		i;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	i = read(fd, new->s, BUFFER_SIZE);
	if (i <= 0)
	{
		free(new);
		return (0);
	}
	new->s[i] = 0;
	new->len = i;
	new->nl = new->len - ft_strlen(ft_strchr(new->s, '\n'));
	if (!ft_strchr(new->s, '\n'))
		new->next = ft_rdlst(fd);
	else
		new->next = 0;
	return (new);
}

/*
	Crea una cadena con espacio suficiente para almacenar toda la cadena
	almacenada en la lista ("Hasta el primer salto de linea o hasta el final").
*/
char	*ft_linespace(t_list *lst)
{
	int		i;
	char	*s;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		i += lst->nl;
		lst = lst->next;
	}
	s = malloc(sizeof(char) * (i + 1));
	return (s);
}

/*
	Copia la linea almacenada en la lista dentro de la cadena especificada.
*/
void	ft_strcpylst(t_list *lst, char *s)
{
	int		i;

	if (!lst)
		return ;
	i = ft_strlcpy(lst->s, s, BUFFER_SIZE);
	ft_strcpylst(lst->next, s + i);
	free(lst);
}

char	*get_next_line_aux(int fd, char	*aux)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = get_next_line(fd);
	if (!s1)
		return (ft_substr(aux, '\0'));
	i = ft_strlen(aux) + ft_strlen(s1);
	s2 = malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (ft_substr(aux, '\0'));
	ft_strlcpy(s1, s2 + ft_strlcpy(aux, s2, BUFFER_SIZE), i);
	free(s1);
	return (s2);
}

char	*get_next_line(int fd)
{
	static char	aux[BUFFER_SIZE + 1];
	char		*s1;
	char		*s2;
	t_list		*new;

	if (fd < 0 || fd > 1000 || BUFFER_SIZE <= 0)
		return (0);
	if (*aux != 0)
	{
		s1 = ft_substr(aux, '\n');
		ft_strlcpy(aux + ft_strlen(s1), aux, BUFFER_SIZE);
		if (ft_strlen(aux) != 0)
			return (s1);
		s2 = get_next_line_aux(fd, s1);
		free(s1);
		return (s2);
	}
	new = ft_rdlst(fd);
	s1 = ft_linespace(new);
	ft_strcpylst(new, s1);
	s2 = ft_substr(s1, '\n');
	ft_strlcpy(s1 + ft_strlen(s2), aux, BUFFER_SIZE);
	free(s1);
	return (s2);
}


	int main(void)
	{
		int		fd;
		// t_list	*new;
		char	*s;

		fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
		// new = ft_rdlst(fd);
		// s = ft_linespace(new);
		s = get_next_line(fd);
		// s = ft_substr("hola\nque tal", '\n');
		// ft_strcpylst(new, s);
		printf("%s\n", s);
		free(s);
		s = get_next_line(fd);
		printf("%s\n", s);
		free(s);
		close(fd);
		// while (1);
		return 0;
	}

