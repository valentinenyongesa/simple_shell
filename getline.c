#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _getline - read and write system calls
 * Return: 0
 */

int _getline(void)
{
	static char buf[1024];
	static int n;

	n = read(0, buf, 5);
	write(1, buf, n);

	return (0);
}
