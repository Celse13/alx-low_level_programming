#include "lists.h"
/**
 * sum_dlistint -  sum of all element in dlistint_t
 * @head: pointer to the first node
 * Return: total of all element of dlistint_t, or 0
**/
int sum_dlistint(dlistint_t *head)
{
dlistint_t *_current_node = head;
int result = 0;

while (_current_node != NULL)
{
result += _current_node->n;
_current_node = _current_node->next;
}

return (result);
}
