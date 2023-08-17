#include "lists.h"
/**
 * delete_dnodeint_at_index - delete a node at provided index
 * @head: pointer to the first node
 * @index: position to be deleted
 * Return: 1 on successfull or -1 on failure
**/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *_current_node = *head;

if (!(*head))
return (-1);

if (index == 0)
{
*head = _current_node->next;
free(_current_node);
if (*head)
(*head)->prev = NULL;
return (1);
}

unsigned int position = index - 1;
for (unsigned int i = 0; i < position && _current_node; i++)
{
_current_node = _current_node->next;
}

if (_current_node)
{
dlistint_t *node_to_delete = _current_node->next;
if (node_to_delete)
{
if (node_to_delete->next)
node_to_delete->next->prev = _current_node;
_current_node->next = node_to_delete->next;
free(node_to_delete);
return (1);
}
}

return (-1);
}
