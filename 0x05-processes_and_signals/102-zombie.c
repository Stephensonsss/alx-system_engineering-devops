#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * infinite_while - runs a while loop infinitely with a sleep command
 *
 * Return: 0 on success
 */
int infinite_while(void)
{
	while (1)
		sleep(1);

	return (0);
}

/**
 * main - Entry point of program
 *
 * Return: 0 on success, 98 on failure.
 */
int main(void)
{
	pid_t zombie_process;
	int   i;

	for (i = 0; i < 5; i++)
	{
		zombie_process = fork();
		if (zombie_process < 0)
		{
			fprintf(stderr, "Could not create process: %s", strerror(errno));
			exit(98);
		}

		if (zombie_process == 0)
			return (0);

		printf("Zombie process created, PID: %d\n", zombie_process);
	}

	infinite_while();

	return (0);
}
