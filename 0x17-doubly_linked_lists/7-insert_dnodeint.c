#include "lists.h"
/**
 * insert_dnodeint_at_index - interst node at any index
 * @h: pointer to the first node
 * @idx: indext at where we want to insert a node
 * @n: int to be inserted
 * Return: the memory address of new node
**/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *_current_node = *h;
dlistint_t *_next;

_next = malloc(sizeof(dlistint_t));
if (_next == NULL)
return (NULL);

_next->n = n;

if (idx == 0)
{
_next->prev = NULL;
_next->next = *h;
if (*h)
(*h)->prev = _next;
*h = _next;
return (_next);
}

unsigned int position = idx - 1;
for (unsigned int i = 0; i < position && _current_node; i++)
{
_current_node = _current_node->next;
}

if (_current_node)
{
_next->prev = _current_node;
_next->next = _current_node->next;

if (_current_node->next)
_current_node->next->prev = _next;

_current_node->next = _next;
return (_next);
}

free(_next);
return (NULL);
}
