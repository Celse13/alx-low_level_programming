#include "lists.h"
/**
 * add_dnodeint_end - add the node at the end position
 * @head: pointer to the first node dlistint_t
 * @n: int to add in new node
 * Return: the address of the new element, or NULL if it failed
**/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
dlistint_t *_new_node = malloc(sizeof(dlistint_t));

if (_new_node == NULL)
return (NULL);

_new_node->n = n;
_new_node->next = NULL;

if (*head == NULL)
{
_new_node->prev = NULL;
*head = _new_node;
}
else
{
dlistint_t *current_node = *head;
while (current_node->next != NULL)
{
current_node = current_node->next;
}
current_node->next = _new_node;
_new_node->prev = current_node;
}

return (_new_node);
}

