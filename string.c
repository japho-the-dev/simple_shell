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

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: Pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0;
	int src_len = 0;
	int i = 0;

	while (dest[dest_len])
		dest_len++;

	while (src[src_len])
		src_len++;

	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0'; /* Adding null terminator at the end */
	return (dest);
}
