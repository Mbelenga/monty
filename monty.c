#include "monty.h"

char *arg;

/**
 * execute - executes an opcode
 */
void execute(char *opcode, stack_t **stack, unsigned int line)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	int i;

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n",
		line, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * main - Monty interpreter
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char buffer[1024];
	char *opcode;
	stack_t *stack = NULL;
	unsigned int line = 0;

	if (argc != 2)
	{
		fprintf(stderr,
			"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr,
			"Error: Can't open file %s\n",
			argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), file))
	{
		line++;

		opcode = strtok(buffer, " \t\n");

		if (!opcode || opcode[0] == '#')
			continue;

		arg = strtok(NULL, " \t\n");

		execute(opcode, &stack, line);
	}

	free_stack(stack);
	fclose(file);

	return (0);
}
