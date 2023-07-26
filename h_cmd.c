#include "s_Shell.h"
/**
 * execute_command - Executes the command and its arguments
 * @env: env variables of the main function
 * @command_line: Pointer to string containing commandline input
 * @delimiter: Delimiting character
 * Return: Nothing
 */
void execute_command(char **env, char *command_line, char *delimiter)
{
	int x = 0;
	pid_t pid;
	int status;
	char *command;
	struct stat *st = malloc(sizeof(struct stat));
	char *arguments[100] = {"", NULL};

	command = strtok(command_line, delimiter);
	if (command != NULL)
	{
		arguments[0] = path(command);
		while (arguments[x] != NULL)
		{
			x++;
			arguments[x] = strtok(NULL, delimiter);
		}
		if (stat(arguments[0], st) == 0)
		{
			pid = fork();
			switch (pid)
			{
				case -1:
					free(st);
					exit(EXIT_FAILURE);
				case 0:
					if (execve(arguments[0], arguments, env) == -1)
					{
						free(st);
						exit(EXIT_FAILURE);
					}
					break;
				default:
					wait(&status);
					if (status != 0)
					{
						errno = 2;
						exit(errno);
					}
			}
			else
			{
				custom_error(arguments[0]);
				if (!isatty(STDIN_FILENO))
					exit(0);
			}
		}
		free(st);
	}
}
