#include "monty.h"

/**
* _push - Pushes an element onto the stack.
* @stack: A pointer to the top of the stack.
* @line_number: The current line number in the Monty bytecode file.
*/

void _push(stack_t **stack, unsigned int line_number)
{
stack_t *new_node;
char *token;
int i;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
free(new_node);
malloc_error();
push_error_flag = 1;
return;
}


token = strtok(NULL, " \t\n");
if (token == NULL)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free(new_node);
push_error_flag = 1;
return;
}

for (i = 0; token[i] != '\0'; i++)
{
if (!isdigit(token[i]) && token[i] != '-')
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free(new_node);
push_error_flag = 1;
return;
}
}


new_node->n = atoi(token);
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}


/**
* _pall - Prints all values on the stack.
* @stack: A pointer to the top of the stack.
* @line_number: The current line number in the Monty bytecode file.
*/

void _pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

(void)line_number;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
* execute_opcode - Executes the corresponding function for an opcode.
* @opcode: The opcode to execute.
* @stack: A pointer to the top of the stack.
* @line_number: The current line number in the Monty bytecode file.
*/

void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
instruction_t instructions[] = {
{"push", _push},
{"pall", _pall},
{NULL, NULL}
};

int i = 0;

while (instructions[i].opcode != NULL)
{
if (strcmp(opcode, instructions[i].opcode) == 0)
{
instructions[i].f(stack, line_number);

}
i++;
return;
}

unknown_instruction_opcode(opcode, line_number);
return;
}
