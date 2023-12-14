#include "monty.h"

/**
*_rotl- rotates the stack to the top
*@head: stack head
*@line_number: line_number
*Return: no return
*/

void _rotl(stack_t **head,  __attribute__((unused)) unsigned int line_number)
{
stack_t *tmp, *n_node;

tmp = *head;
if (*head == NULL || (*head)->next == NULL)
{
return;
}
n_node = (*head)->next;
n_node->prev = NULL;
while (tmp->next != NULL)
{
tmp = tmp->next;
}
tmp->next = *head;
(*head)->next = NULL;
(*head)->prev = tmp;
(*head) = n_node;
}

/**
  *_rotr- rotates the stack to the bottom
  *@head: stack head
 * @line_number: counter of lines
  *Return: no return
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
stack_t *rot_el;

rot_el = *head;
if (*head == NULL || (*head)->next == NULL)
{
return;
}
while (rot_el->next)
{
rot_el = rot_el->next;
}
rot_el->next = *head;
rot_el->prev->next = NULL;
rot_el->prev = NULL;
(*head)->prev = rot_el;
(*head) = rot_el;
}
