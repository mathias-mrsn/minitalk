#include "../../includes/get_next_line.h"


t_file	*ft_find_file(t_file **mem, int fd)
{
	t_file	*tmp;
	t_file	*new;

	tmp = (*mem);
	if(fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	while(tmp)
	{
		if(tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_file) * 1);
	if(!new)
		return (NULL);
	new->fd = fd;
	new->save = NULL;
	new->readed_len = 1;
	new->next = (*mem);
	(*mem) = new;
	return (new);
}

void	ft_free(t_file **mem, int fd)
{
	t_file *back;
	t_file *next;
	t_file *curr;

	back = 0;
	next = (*mem);
	while (next)
	{
		if (next->fd == fd)
		{
			if (back == 0)
				(*mem) = next->next;
			else
				back->next = next->next;
			curr = next;
			next = next->next;
			free(curr);
		}
		else
		{
			back = next;
			next = back->next;
		}
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static t_file	*mem;
	t_file		*file;
	char		*line;

	file = ft_find_file(&mem, fd);
	if (BUFFER_SIZE < 1 || !file)
		return (NULL);
	buffer = malloc(sizeof(char) * (int)(BUFFER_SIZE + 1));
	if(!buffer)
		return(free(buffer), NULL);
	while(!ft_is_line('\n', file->save) && file->readed_len)
	{
		file->readed_len = read(file->fd, buffer, (int)BUFFER_SIZE);
		if(file->readed_len <= 0)
			break;
		buffer[file->readed_len] = '\0';
		file->save = ft_strjoin_bis(file->save, buffer);
	}
	line = ft_strdup_bis(file->save);
	file->save = ft_get_save(file->save);
	if(file->readed_len == 0 && !file->save)
		ft_free(&mem, fd);
	free(buffer);
	return (line);
}