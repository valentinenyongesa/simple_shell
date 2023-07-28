#include "main.h"

/**
 *custom_exit-implementation of the builtin exit command
 *@tokens: exit-code
 * Return: 1 if shell should exit 0 otherwise
 *
 */
int custom_exit()
{
	exit(0);
}
