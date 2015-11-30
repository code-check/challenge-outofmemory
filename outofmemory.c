#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC_SIZE     1024 * 1024 // 1 MiB
#define PRINT_INTERVAL  50          // Print for each 50 MiB
#define NTIMES          50 * 1024   // try to malloc & msize 1 MiB for NTIMES -> total of 50 GiB
int main ()
{
	char *chunks[NTIMES];
	char *chunk;
	int i;
	for (i = 0; i < NTIMES; i++) {
		chunk = (char*) malloc(MALLOC_SIZE);
		if (chunk == NULL) {
			printf("malloc failed\n");
			return 0;
		}
		chunks[i] = chunk;
	}
	printf("mallocs complete\n");
	for (i = 0; i < NTIMES; i++) {
		if (i % PRINT_INTERVAL == 0) {
			printf("Used %4d MiB\n", i);
		}
		memset(chunks[i], 'x', MALLOC_SIZE);
	}
	printf("memsets complete\n");
	return 0;
}

