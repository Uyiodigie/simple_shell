#include "header.h"

/**
 * strcat_cd - Concatenates the message for cd error
 * @datastruct: data relevant (directory)
 * @msg: message to print
 * @error: output message
 * @ver_str: counter lines
 * Return: error message
 */
char *strcat_cd(data_shell *datastruct, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, datastruct->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datastruct->args[0]);
	_strcat(error, msg);
	if (datastruct->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datastruct->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, datastruct->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - error message for cd command in get_cd
 * @datastruct: data relevant (directory)
 * Return: Error message
 */
char *error_get_cd(data_shell *datastruct)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(datastruct->counter);
	if (datastruct->args[1][0] == '-')
	{
		msg = ": Invalid Option ";
		len_id = 2;
	}
	else
	{
		msg = ": Unable to cd to ";
		len_id = _strlen(datastruct->args[1]);
	}

	length = _strlen(datastruct->argv[0]) + _strlen(datastruct->args[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(datastruct, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_not_found - error message showing that that command was not found
 * @datastruct: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_not_found(data_shell *datastruct)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datastruct->counter);
	length = _strlen(datastruct->argv[0]) + _strlen(ver_str);
	length += _strlen(datastruct->args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datastruct->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datastruct->args[0]);
	_strcat(error, ": Not Found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * error_exit_shell - error message for exit in get_exit
 * @datastruct: data relevant (counter, arguments)
 * Return: Error message
 */
char *error_exit_shell(data_shell *datastruct)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datastruct->counter);
	length = _strlen(datastruct->argv[0]) + _strlen(ver_str);
	length += _strlen(datastruct->args[0]) + _strlen(datastruct->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datastruct->argv[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datastruct->args[0]);
	_strcat(error, ": Invalid Number: ");
	_strcat(error, datastruct->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
