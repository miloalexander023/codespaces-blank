#include "..\..\libft\libft.h"
#include "..\so_long.h"
#include "..\get_next_line.codam\get_next_line.h"

char	**map_reader(int fd)
{
	char	**map;
	char	*get_map;
	int		i;
	int		j;
	int sign;

	i = 0;
	sign = 0;
	get_map = read_map(fd);
	check_double(get_map);
	map = ft_split(get_map, '\n');
	sign = is_rectangle(map);
	if (sign == 0)
		return (0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c\n", map[i][j]);
			j++;
		}
		i++;
	}
	return (map);
}

char	*read_map(int fd)
{
	char	*get_map;
	char	*line;
	char	*temp;

	if (fd < 0)
		return(NULL);
	get_map = ft_strdup("");
	if (!get_map)
		return (NULL);
	while (line = get_next_line(fd))
	{
		temp = ft_strjoin(get_map, line);
		free(temp);
		get_map = temp;
		free(line);
	}
	close(fd);
	return(get_map);
}

int	is_rectangle(char **map)
{
	int i;
	int j;
	int k;

	if(!map)
		return (0);
	i = 0;
	j = 0;
	while (map[i][j] != '\0')
		j++;
	while (map[i] != NULL)
	{
		k = 0;
		while(map[i][k] != '\0')
			k++;
		if (j != k)
			return (0);
		i++;
	}
	return (1);
}
