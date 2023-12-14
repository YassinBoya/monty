#include "monty.h"

/**
 * _div - divides the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/

void _div(stack_t **head, unsigned int line_number)
{
stack_t *h;
int len = 0, div_val;

h = *head;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
fclose(exi.file);
free(exi.line);
exit(EXIT_FAILURE);
}
h = *head;
if (h->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
fclose(exi.file);
free(exi.line);
exit(EXIT_FAILURE);
}
div_val = h->next->n / h->n;
h->next->n = div_val;
*head = h->next;
free(h);
}
