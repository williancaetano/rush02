#include "rush02.h"

void	swap_dictionary_nodes(t_dictionary	*node1, t_dictionary	*node2)
{
	int		temp_nb;
	char	*temp_str;

	temp_nb = node1->nb;
	temp_str = node1->str_number;
	node1->nb = node2->nb;
	node1->str_number = node2->str_number;
	node2->nb = temp_nb;
	node2->str_number = temp_str;
}

void	bubble_sort(t_dictionary *head)
{
	int				swapped;
	t_dictionary	*lptr;
	t_dictionary	*current;

	swapped = 1;
	lptr = NULL;
	if (head == NULL)
		return ;
	while (swapped)
	{
		swapped = 0;
		current = head;
		while (current->next != lptr)
		{
			if (current->nb > current->next->nb)
			{
				swap_dictionary_nodes(current, current->next);
				swapped = 1;
			}
			current = current->next;
		}
		lptr = current;
	}
}

void	ft_lstadd_front(t_dictionary **lst, t_dictionary *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_dictionary **lst, t_dictionary *new)
{
	t_dictionary	*first;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		first = *lst;
		while (first->next != NULL)
			first = first->next;
		first->next = new;
		new->next = NULL;
	}
}

void	create_numbers(char *str, int nb, t_dictionary **head)
{
	t_dictionary	*entry;

	entry = (t_dictionary *)malloc(sizeof(t_dictionary));
	entry->nb = nb;
	reverse_string(str);
	entry->str_number = ft_strdup(str);
	entry->next = NULL;
	ft_lstadd_front(head, entry);
}
