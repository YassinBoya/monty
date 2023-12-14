#include "monty.h"

/**
*usage_error - Prints an error message for incorrect command-line usage.
*Return: EXIT_FAILURE to indicate the failure.
*/

int usage_error(void)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

/**
*open_file_error - Prints an error message for file opening failure.
*@file: The name of the file that couldn't be opened.
*Return: EXIT_FAILURE to indicate the failure.
*/

int open_file_error(char *file)
{
fprintf(stderr, "Error: Can't open file %s\n", file);
return (EXIT_FAILURE);
}

/**
*unknown_instruction_opcode - Prints an error message for unknown opcode.
*@opcode: The unknown opcode encountered.
*@line_number: The line number in the Monty bytecode file.
*Return: EXIT_FAILURE to indicate the failure.
*/

void unknown_instruction_opcode(char *opcode, unsigned int line_number)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
}

/**
* malloc_error - Prints an error message for malloc failure.
*Return: EXIT_FAILURE to indicate the failure.
*/

int malloc_error(void)
{
fprintf(stderr, "Error: malloc failed\n");
return (EXIT_FAILURE);
}

