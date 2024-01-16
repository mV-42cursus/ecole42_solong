#include <stdlib.h>
#include <stdio.h>

void	leaks2()
{
	system("leaks --list --a.out");
}

int	main(int ac, char *av[])
{
	atexit(leaks2);
	(void)ac;
	(void)av;
	char *str = malloc(10000);
	printf("%s", str);
	free(str);
	return (0);
}
