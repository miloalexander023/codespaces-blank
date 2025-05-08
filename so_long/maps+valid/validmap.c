/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:25:15 by marvin            #+#    #+#             */
/*   Updated: 2025/04/21 14:25:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../get_next_line.codam/get_next_line.h"
void check_double(char *line)
{
	int i;
	int player = 0;
	int collectable = 0;
	int exit = 0;
	if(!line)
		return ;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			player += 1;
		if (line[i] == 'C')
			collectable += 1;
		if (line[i] == 'E')
			exit += 1;
		i++;
	}
	if(player != 1)
		printf("only 1 player allowed\n");
	else if(collectable < 1)
		printf("needs collectables\n");
	else if(exit != 1)
		printf("only 1 exit allowed");
	else
		printf("all good\n");
}
int h_border_check(char *line)
{
	int i;
	char c = '1';
	i = 0;		
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int v_border_check(char *line)
{
	int i;
	char c = '1';
	i = 0;		
	if (line[i] != c)
		return (0);
	while (line[i] != '\0' && line[i] != '\n')
	{
		i++;
	}
	if (line[i-1] != c)
		return (0);
	return (1);
}

int	valid_map(int fd, char *result)
{
	int	map_length;
	int new_length;
	char *first_line;

	map_length = 0;
	first_line = get_next_line(fd);
	if(h_border_check(first_line) == 0)
		printf("not valid\n");
	if (first_line == NULL)
	{
		printf("NULL");
		free(first_line);
		return (0);
	}
	map_length = ft_strlen(first_line);
	while (result != NULL)
	{
		printf("%s\n", result);
		result = get_next_line(fd);
		
		if (result == NULL)
		{
			free(result);
			return (1);
		}
		if (result == first_line)
		{
			if(h_border_check(first_line) == 0)
				return(0);
		}
		if (result != first_line)
		{
			if (v_border_check(result) == 0)
				return (0);
		}
		new_length = ft_strlen(result);
		if (new_length != map_length)
		{
			printf("not valid\n");
			free(result);
			return (0);
		}
		free(result);
	}
	close(fd);
	return (1);
}
