#include "monty.h"
/**
 * _pint - prints the top
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void _pint(stack_t **head, unsigned int line_number)
{
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
fclose(exi.file);
free(exi.line);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}


/**
 * _swap - adds the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void _swap(stack_t **head, unsigned int line_number)
{
stack_t *current;
int len = 0, temp;

current = *head;
while (current)
{
current = current->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
fclose(exi.file);
free(exi.line);
exit(EXIT_FAILURE);
}
current = *head;
temp = current->n;
current->n = current->next->n;
current->next->n = temp;
}

/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void _add(stack_t **head, unsigned int line_number)
{
stack_t *head_node;
int len = 0, sum = 0;

head_node = *head;
while (head_node)
{
head_node = head_node->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
fclose(exi.file);
free(exi.line);
exit(EXIT_FAILURE);
}
head_node = *head;
sum = head_node->n + head_node->next->n;
head_node->next->n = sum;
*head = head_node->next;
free(head_node);
}

/**
*_nop- nothing
*@stack_h: stack head
*@line_number: line_number
*Return: no return
 */
void _nop(stack_t **stack_h, unsigned int line_number)
{
(void) line_number;
(void) stack_h;
}
