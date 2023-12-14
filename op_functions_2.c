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
