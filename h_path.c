#include "s_Shell.h"
/**
 * checkpath - checks validity of a path
 * @arguments: parameters
 * @env: environment variables
 * @st: pointer to path info
 * @cmd_line: a pointer to line of args
 * Return: nothing
 */
void checkpath(char **arguments, char **env, struct stat **st, char *cmd_line)
{
	pid_t pid;
	int status;

	if (stat(arguments[0], *st) == 0)
	{
		pid = fork();
		switch (pid)
		{
			case -1:
				free(*st);
				exit(EXIT_FAILURE);
			case 0:
				if (execve(arguments[0], arguments, env) == -1)
				{
					free(*st);
					exit(EXIT_FAILURE);
				}
				break;
			default:
				wait(&status);
				free(arguments[0]);
				if (status != 0)
				{
					errno = 2;
					free(cmd_line);
					free(*st);
					exit(errno);
				}
		}
	}
	else
	{
		custom_error(arguments[0]);
		if (!isatty(STDIN_FILENO == 0))
		{
			exit(127);
		}
	}
}

