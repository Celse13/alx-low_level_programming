#include "lists.h"
/**
 * get_dnodeint_at_index - return the nth node of a dlistint_t linked list
 * @head: pointer to the first node
 * @index: indext at the node
 * Return: the nth node is not node, return NULL
**/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
dlistint_t *_current_node = head;
unsigned int n = 0;

while (_current_node != NULL)
{
if (n == index)
return (_current_node);

_current_node = _current_node->next;
n++;
}

return (NULL);
}
