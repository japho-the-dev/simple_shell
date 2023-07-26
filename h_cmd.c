#include "s_Shell.h"
/**
 * execute_command - Executes the command and its arguments
 * @env: env variables of the main function
 * @cmd_line: Pointer to string containing commandline input
 * @delimiter: Delimiting character
 * Return: Nothing
 */
void execute_command(char **env, char *cmd_line, char *delimiter)
{
	int x = 0;
	char *command;
	struct stat *st = malloc(sizeof(struct stat));
	char *arguments[100] = {"", NULL};

	command = strtok(cmd_line, delimiter);

	if (command != NULL)
	{
		arguments[0] = path(command);
		while (arguments[x] != NULL)
		{
			x++;
			arguments[x] = strtok(NULL, delimiter);
		}

		checkpath(arguments, env, &st, cmd_line);
	}
	free(st);
}
