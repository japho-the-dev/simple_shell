#include "s_Shell.h"

/**
 * _strcmp - Compares the similarity of two input strings
 * @str1: String 1
 * @str2: String 2
 * Return: 0 (on success)
 */
int _strcmp(char *str1, char *str2)
{
	int index = 0;

	while (str1[index] != '\0' || str2[index] != '\0')
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);

		index++;
	}
	return (0);
}
