#include "../../includes/get_next_line.h"

int		ft_strlen_bis(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_bis(char *src)
{
	char	*res;
	int		i;

	i = 0;
	if(!src)
		return (NULL);
	res = (char *)malloc(sizeof(char) * ft_strlen_bis(src) + 1);
	if (!res)
		return (NULL);
	while (src[i] && src[i] != '\n')
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_bis(char *s1, char *s2)
{
	int 	i;
	int 	j;
	char	*newstr;

	if(!s1)
		s1 = ft_strdup_bis("\0");
	if(!s2)
		return (NULL);
	newstr = malloc(sizeof(char) * (ft_strlen_bis(s1) + ft_strlen_bis(s2) + 1));
	if(!newstr)
		return (NULL);
	i = -1;
	j = -1;
	while(s1[++i])
		newstr[i] = s1[i];
	while(s2[++j])
		newstr[i + j] = s2[j];
	newstr[i + j] = '\0';
	free(s1);
	return (newstr);
}

int	ft_is_line(char c, char *set)
{
	while(set && *set)
	{
		if(c == *set)
			return (1);
		set++;
	}
	return (0);
}

char *ft_get_save(char *src)
{
	char	*res;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	if(!src)
		return (NULL);
	while(src[i] && src[i] != '\n')
		i++;
	if(!src[i] || !src[i + 1])
	{
		free(src);
		return (NULL);
	}
	if(src[i])
		i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen_bis(src + i) + 1));
	if (!res)
		return (NULL);
	while (src[i])
	{
		res[j] = src[i];
		i++;
		j++;
	}
	res[j] = '\0';
	free(src);
	return (res);
}