#define		_CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>

struct kid
{
	char	name[100];
	int		height;
};

// TODO: try increasing/decreasing order
int		compare(const void *first, const void *second);

int		main(void)
{
	struct kid	my_friends[] = {
		"Jack Jack", 40, "Geenie", 300, "Aladdin", 170, "Piona", 150
	};

	const int	n = sizeof(my_friends) / sizeof(struct kid);

	//qsort(my_friends, n, sizeof(struct kid), compare);

	for (int i = 0; i < n; i++)
		printf("%s		\t%d\n", my_friends[i].name, my_friends[i].height);

	return (0);
}

int		compare(const void *first, const void *second)
{
	// TODO: try increasing/decreasing order
}