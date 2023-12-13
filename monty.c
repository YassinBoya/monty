#define _POSIX_C_SOURCE 200809L
#include "monty.h"

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

while (getline(&line, &len, file) != -1)
{
line_number++;
token = strtok(line, " \t\n");
if (token == NULL || token[0] == '#')
continue;

execute_opcode(token, &stack, line_number);
token = strtok(NULL, " ");
}
free_stack(&stack);
fclose(file);
free(line);
return (EXIT_SUCCESS);
}
