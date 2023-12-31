#include "monty.h"
/**
* execute_ - Executes the specified opcode
* @stack: A pointer to the head of the linked list (stack).
* @counter: The line_counter
* @file: poiner to monty file
* @content: The line content
* Return: No return value
*/
int execute_(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push}, {"pall", pall}, {"pint", print_top_elemnt},
				{"pop", custom_print_function},
				{"swap", swap},
				{"add", add_top_two_elements},
				{"nop", do_nothing},
				{"sub", sub},
				{"div", add_node_to_stack},
				{"mul", multiply_to_two},
				{"mod", mod_top_two},
				{"pchar", print_char_from_stack},
				{"pstr", print_char},
				{"rotl", rotatestack},
				{"rotr", rotr},
				{"queue", setQueueMode},
				{"stack", print_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
