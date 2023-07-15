#include <stdio.h>
#include <unistd.h>

/**
 * main - write string to stdout
 *
 * Return: 0
 */

int main(void)
{
	write(1, "c is fun\n", 10);

	return (0);
}
