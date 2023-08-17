#include "lists.h"
/**
 * dlistint_len - printing the elements in list
 * @h: pointer to the dlistint_t
 * Return: the number of nodes
**/
size_t dlistint_len(const dlistint_t *h)
{
const dlistint_t *_current_node = h;
size_t _num_node = 0;

for (; _current_node != NULL; _current_node = _current_node->next)
{
_num_node++;
}

return (_num_node);
}
