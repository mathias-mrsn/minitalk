#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *newelem;

	new = 0;
	if(!f || !del || !lst)
		return (NULL);
	while(lst)
	{
		newelem = ft_lstnew((*f)(lst->content));
		if (!newelem)
		{
			ft_lstclear(&new, del);
			return (new);
		}
		ft_lstadd_back(&new, newelem);
		lst = lst->next;
	}
	return (new);
}