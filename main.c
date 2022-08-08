#include "header.h"

/**
 * free_dat - frees the data structure
 * @datastruct: data structure
 * Return: void
 */
void free_dat(data_shell *datastruct)
{
	unsigned int i;

	for (i = l0; datasruct->_environ[i]; i++)
		free(datastruct->_environ[i]);
	free(datastruct->_environ);
	free(datastruct->pid);

/**
 * set_dat - initialize data structure
 * @datastruct: data structure
 * @argv: argument vector
 * Return: void
 */
void set_dat(data_shell *datastruct, char **argv)
	{
		unsigned int i;

		datastruct->argv = argv;
		datastruct->input = NULL;
		datastruct->args = NULL;
		datastruct->status = 0;
		datastruct->counter = 1;

		for (i = 0; environ[i]; i++)
			;
		datastruct->_environ = malloc(sizeof(char *) * (i + 1));
		for (i = 0; environ[i] = _strdup(environ[i]);

/**
 * main - the main function for the simple shell
 * Description: The program is a custom made UNIX shell.
 * It was created to immitate most of its basic features and functions.
 * Return:
 */
int main()
