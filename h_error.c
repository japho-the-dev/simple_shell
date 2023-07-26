#include "s_Shell.h"

/**
 * custom_error - writes a custom error message to stderr
 * @cmd: erroneous command
 * Return: void
 */
void custom_error(char *cmd)
{
	static int errorCount;
	char *prefix = "./hsh: ";
	int cmdLen = 0;

	while (cmd[cmdLen])
		cmdLen++;

	errorCount++;
	write(STDERR_FILENO, prefix, 7);
	print_number(errorCount);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, cmdLen);
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * print_number - prints an int to stderr
 * @n: No to print out
 * Return: Nothing
 */
void print_number(int n)
{
	char num;

	if (n > 9)
	{
		print_number(n / 10);
	}

	num = (n % 10) + '0';
	write(STDERR_FILENO, &num, 1);
}
