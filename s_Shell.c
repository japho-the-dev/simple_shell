#include "s_Shell.h"

/**
 * main - Entry point to the project
 * @argc: no of command line arguments (void)
 * @argv: Array of strings containing command-line args
 * @env: Environmental variable
 * Return: Always 0 (On success)
 */
int main(int argc, char *argv[], char **env)
{
	size_t x = 0;
	char *s_line = NULL;

	(void)argc;
	(void)argv;

	while (1)
	{
		display_prompt();

		if (getline(&s_line, &x, stdin) == -1)
			/* free(s_line); */
			exit(EXIT_SUCCESS);

		if (_strcmp(s_line, "exit\n") == 0)
		{
			free(s_line);
			exit(0); /* Quit */
		}

		execute_command(env, s_line, " \n\t\v\b\r\f");
		free(s_line);
	}
	return (0);
}
