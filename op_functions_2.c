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
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(exi.file);
		free(exi.line);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
