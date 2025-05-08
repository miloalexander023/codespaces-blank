/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:02:46 by milalexa          #+#    #+#             */
/*   Updated: 2024/12/11 20:34:51 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "..\..\libft\libft.h"
// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

int	ft_findchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}

// char	*ft_strjoin(char *passed_line, char *buffer)
// {
// 	char	*join;
// 	int		slen1;
// 	int		slen2;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (!buffer)
// 		return (free(passed_line), NULL);
// 	slen1 = ft_strlen(passed_line);
// 	slen2 = ft_strlen(buffer);
// 	join = (char *)malloc(sizeof(char) * (slen1 + slen2 + 1));
// 	if (join == NULL)
// 		return (NULL);
// 	while (passed_line != NULL && passed_line[i] != '\0')
// 	{
// 		join[i] = passed_line[i];
// 		i++;
// 	}
// 	while (buffer[j] != '\0')
// 		join[i++] = buffer[j++];
// 	join[i] = '\0';
// 	return (free(passed_line), join);
// }

char	*get_new_string(char *passed_line)
{
	char	*new_str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!passed_line)
		return (NULL);
	while (passed_line[i] != '\n' && passed_line[i])
		i++;
	if (passed_line[i] != '\n')
		return (free(passed_line), NULL);
	len = ft_strlen(passed_line);
	new_str = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!new_str)
		return (free(passed_line), NULL);
	i++;
	while (i < len)
		new_str[j++] = passed_line[i++];
	new_str[j] = '\0';
	free(passed_line);
	return (new_str);
}

// char	*ft_strdup(const char *s)
// {
// 	char	*dup;
// 	int		i;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	dup = (char *)malloc(sizeof(char) * (i + 1));
// 	if (dup == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		dup[i] = s[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }
