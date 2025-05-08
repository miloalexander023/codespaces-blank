/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:46:23 by milalexa          #+#    #+#             */
/*   Updated: 2024/12/11 21:22:34 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*whileloop(int fd, char *passed_line)
{
	ssize_t	bytes_read;
	char	*buffer;

	bytes_read = 1;
	while (bytes_read != 0 && ft_findchr(passed_line, '\n') == 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (free(buffer), NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(passed_line), free(buffer), NULL);
		if (bytes_read != 0)
		{
			buffer[bytes_read] = '\0';
			passed_line = ft_strjoin(passed_line, buffer);
			if (passed_line == NULL)
				return (free(buffer), NULL);
		}
		free(buffer);
	}
	return (passed_line);
}

char	*read_and_join(int fd, char *passed_line)
{
	if (passed_line == NULL)
	{
		passed_line = ft_strdup("");
		if (!passed_line)
			return (free(passed_line), NULL);
	}
	passed_line = whileloop(fd, passed_line);
	return (passed_line);
}

char	*get_new_line(char *passed_line)
{
	char	*str;
	int		i;

	if (!passed_line)
		return (NULL);
	i = 0;
	while (passed_line[i] != '\n' && passed_line[i])
		i++;
	if (passed_line[i] != '\n')
		return (ft_strdup(passed_line));
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (passed_line[i] != '\n' && passed_line[i])
	{
		str[i] = passed_line[i];
		i++;
	}
	str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*passed_line;
	char		*return_line;
	
	if (fd < 0 || BUFFER_SIZE < 1){	
		return (free(passed_line), NULL);}
	if (ft_findchr(passed_line, '\n') == 0)
	{
		passed_line = read_and_join(fd, passed_line);
		if (!passed_line || passed_line[0] == '\0')
		{
			free(passed_line);
			passed_line = NULL;
			return (NULL);
		}
	}
	return_line = get_new_line(passed_line);
	if (!return_line || return_line[0] == '\0')
	{
		free(passed_line);
		passed_line = NULL;
		return (NULL);
	}
	passed_line = get_new_string(passed_line);
	return (return_line);
}

// int	main(void)
// {
// 	int		fd = open("1char.txt", O_RDONLY);
// 	char	*result = "";
// 	while (result != NULL)
// 	{
// 		result = get_next_line(fd);
// 		if (result != NULL)
// 		{
// 			printf("%s", result);
// 			free(result);
// 		}
// 		if (result == NULL)
// 		{
// 			printf("NULL");
// 			free(result);
// 		}
// 	}
// 	close(fd);
// 	return (0);
// }
