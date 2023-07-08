#include "rush02.h"

char	**free_file_name(char *ptr)
{
	if (ptr == NULL)
		return (0);
	free(ptr);
	ptr = NULL;
	return (0);
}

void	free_dictionary(t_dictionary	*head)
{
	t_dictionary	*current;
	t_dictionary	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->str_number);
		free(current);
		current = next;
	}
}
