#define _POSIX_C_SOURCE 200809L
#include "monty.h"


/**
 * main - Entry point of the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *Return: EXIT_SUCCESS if the program runs successfully otherwise
 *returns EXIT_FAILURE. In case of errors error messages are printed
 *to standard error.
 */
in_exit exi = {NULL, NULL, 0};

int main(int argc, char **argv)
{

FILE *file = NULL;
char *line = NULL;
char *token = NULL;
stack_t *stack = NULL;
int line_number = 0;
size_t len = 0;

if (argc != 2)
return (usage_error());

file = fopen(argv[1], "r");

if (file == NULL)
return (open_file_error(argv[1]));
exi.file = file;

while (getline(&line, &len, file) != -1)
{
exi.line = line;
line_number++;
token = strtok(line, " \t\n");
if ((token && token[0] == '#') || token == NULL)
continue;

execute_opcode(token, &stack, line_number);
}
free_stack(&stack);
fclose(file);
free(line);
return (0);
}
