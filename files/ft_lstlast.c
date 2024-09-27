
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
    t_list	*temp;

    temp = lst;
    if (!temp)
        return (0);
    while (temp->next)
        temp = temp->next;
    return (temp);
}