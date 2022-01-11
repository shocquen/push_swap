#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

static int	get_max(int i)
{
	int ret = 1;
	while (i)
	{
		ret *= i;
		i--;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	int	todo;
	int	size;

	if (argc == 1)
	{
		printf("generator <todo>");
		exit(1);
	}
	size = atoi(argv[1]);
	todo = get_max(size);
	int arr[size];
	for (int i = 0; i < size; i++)
		arr[i] = i;
	// for (int i = 0; i < size; i++)
	// 	printf("%d ", arr[i]);
	for (int i = 0; i < todo; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d ", arr[i]);
			for (int k = 0; k < j; k++)
				printf("%d ", arr[k]);
		}
		printf("\n");
	}
}