#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("incorrect number of arguments\n");
		return 1;
	}
	char	*s1 = argv[1];
	char	*s2 = argv[2];
	int		l1 = strlen(s1) -1;
	int		l2 = strlen(s2) -1;
	int		l2_start = l2;
	int		len = l1 + l2 + 2;
	int		*arr = malloc(len * sizeof(int));
	int		*res = malloc(len * sizeof(int));
	int		i = 0;
	int		count = 0;

	while (l1 >= 0)
	{
		i = count;
		if (l2 >= 0)
		{
			while (l2 >= 0)
			{
				arr[i] += (s1[l1] - '0') * (s2[l2] - '0');
				l2--;
				i++;
			}
		}
		l2 = l2_start;
		count++;
		l1--;
	}

	printf("i: %i\n", i);
	int	y = i -1;
	int	keep = 0;
	int	k = 0;
	while (y >= 0)
	{
		if (arr[y] > 9)
		{
			res[k] = (arr[y] + keep) % 10;
			keep = (arr[y] + keep) / 10;
		}
		else
		{
			res[k] = arr[y] + keep;
			keep = 0;
		}
		printf("res[%i]: %i, keep: %i\n", y, res[k], keep);
		y--;
		k++;
	}
	if (keep != 0)
		res[k] = keep;
	
	
	printf("____________\n\n");
	y = 0;
	while (y < i)
	{
		printf("arr[%i], %i\n", y, arr[y]);
		y++;
	}
	y = k;
	while (y >= 0)
	{
		printf("%i", res[y]);
		y--;
	}
	printf("\n");
	free(arr);
	free(res);
	return 0;
}