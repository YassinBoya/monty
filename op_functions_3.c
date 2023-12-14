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

/**
 * _mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void _mul(stack_t **head, unsigned int line_number)
{
stack_t *h;
int len = 0, mul_val;

h = *head;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
fclose(exi.file);
free(exi.line);
exit(EXIT_FAILURE);
}
h = *head;
mul_val = h->next->n * h->n;
h->next->n = mul_val;
*head = h->next;
free(h);
}

/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void _mod(stack_t **head, unsigned int line_number)
{
stack_t *h;
int len = 0, mod_val;

h = *head;
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
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
mod_val = h->next->n % h->n;
h->next->n = mod_val;
*head = h->next;
free(h);
}

/**
*_pchar - prints the char at the top of the stack,
*followed by a new line
*@head: stack head
*@line_number: line_number
*Return: no return
*/
void _pchar(stack_t **head, unsigned int line_number)
{
stack_t *h;

h = *head;
if (!h)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
fclose(exi.file);
free(exi.line);
exit(EXIT_FAILURE);
}
if (h->n > 127 || h->n < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
fclose(exi.file);
free(exi.line);
exit(EXIT_FAILURE);
}
printf("%c\n", h->n);
}

#include "monty.h"
/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void _pstr(stack_t **head, unsigned int line_number)
{
stack_t *h;
(void)line_number;

h = *head;
while (h)
{
if (h->n > 127 || h->n <= 0)
{
break;
}
printf("%c", h->n);
h = h->next;
}
printf("\n");
}
