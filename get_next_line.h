/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:28:56 by dgomez-b          #+#    #+#             */
/*   Updated: 2022/07/07 01:10:40 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_strlen(char *s);
int		ft_strlcpy(char *s1, char *s2, int len);
char	*ft_strchr(char *s, char c);
char	*ft_substr(char *s, char c);
char	*get_next_line(int fd);

typedef struct s_list
{
	char			s[BUFFER_SIZE + 1];
	int				len;
	int				nl;
	struct s_list	*next;
}				t_list;

#endif
