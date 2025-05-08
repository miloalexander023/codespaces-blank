// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>
// int ft_strlen(char *str)
// {
// 	int  i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }
// char *strrev(char *str)
// {
// 	int i;
// 	int len;
// 	char *temp;
// 	i = 0;
// 	len = ft_strlen(str);
// 	while (i < len)
// 	{
// 		temp[i] = str[i];
// 		i++;
// 	}
// 	write(1, temp, 11);
// 	return (0);
// }

// int main(void)
// {
// 	char *str = "hello world";

// 	strrev(str);
// 	return (0);
// }