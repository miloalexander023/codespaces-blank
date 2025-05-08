/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:22:55 by milalexa          #+#    #+#             */
/*   Updated: 2024/12/11 20:51:45 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*read_and_join(int fd, char *str);
char	*ft_strjoin(char *passed_line, char *buffer);
int		ft_strlen(char *str);
char	*get_new_line(char *str);
char	*get_new_string(char *passed_line);
int		ft_findchr(char *s, char c);
void	free_mem(char *str);
char	*ft_strdup(const char *s);

#endif
