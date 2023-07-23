#include "s_Shell.h"
/**
 * main - Entry point for the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * struct stat filestat: file status structure
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *inputLine = NULL;      /* Input line entered by the user */
	char *commandArgs[1024];     /* Array to store command arguments */
	size_t lineLength = 0;       /* Length of the input line */
	size_t argIndex = 0;         /* Index for command arguments */
	pid_t childPID;              /* PID of the child process */
	struct stat fileStat;        /* File status structure */
	ssize_t bytesRead;

	while (1)
	{
		if (isatty(0))
			printf("#cisfun ");
		bytesRead = getline(&inputLine, &lineLength, stdin);
		if (bytesRead == -1)
			break;
		/* Tokenize the input line into command arguments */
		commandArgs[0] = strtok(inputLine, " \n");
		for (argIndex = 1; commandArgs[argIndex - 1]; argIndex++)
			commandArgs[argIndex] = strtok(NULL, " \n");
		if (commandArgs[0])
		{/* Check if the command executable exists */
			if (stat(commandArgs[0], &fileStat) == 0)
			{childPID = fork();
				if (childPID == -1)
				{
					perror("Error: ");
					return (-1);
				}
				if (childPID == 0)
					execve(commandArgs[0], commandArgs, NULL);
			}
			else
				printf("%s: No such file or directory\n", argv[0]);
		}
		/* Wait for the child process to finish */
		wait(&childPID);
	}
	free(inputLine);
	(void)argc;
	return (0);
}
