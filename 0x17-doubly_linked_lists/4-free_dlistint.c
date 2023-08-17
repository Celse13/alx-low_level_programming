#include "lists.h"
/**
 * free_dlistint - free dlistint_t
 * @head: pointer to the first node of dlistint_t
*/
void free_dlistint(dlistint_t *head)
{
dlistint_t *_current_node = head;

while (_current_node != NULL)
{
dlistint_t *next_node = _current_node->next;
free(_current_node);
_current_node = next_node;
}
}
