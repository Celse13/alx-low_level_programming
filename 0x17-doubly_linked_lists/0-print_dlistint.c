#include "lists.h"
/**
 * print_dlistint - print the list of nodes
 * @h: pointing to the list of nodes
 * Return: the number of nodes
**/
size_t print_dlistint(const dlistint_t *h)
{
const dlistint_t *_current_node = h;
size_t _num_node = 0;
for (; _current_node != NULL; _current_node = _current_node->next)
{
printf("%i\n", _current_node->n);
_num_node++;
}
return (_num_node);
}
