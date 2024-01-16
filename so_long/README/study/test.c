#include "../../../header/mandatory/structure.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = str;
	while (n--)
	{
		*ptr++ = (unsigned char)c;
	}
	ptr = str;
	return (ptr);
}

int main()
{
	// t_player player;
	// player.row = 1;
	// player.col = 0;
	// printf("%p\n", &player);
	// printf("%d\n", player.col);
	// printf("%d\n", player.row);
	// printf("%ld\n", sizeof(player));
	// ft_memset((void *)&player, 0, sizeof(player));
	// printf("%d\n", player.row);
	// printf("%d\n", player.row);
	// t_player *player2;
	// player2 = malloc(sizeof(player));
	// ft_memset((void *)player2, 0, sizeof(player2));
	// printf("%d\n", player2->row);
	// printf("%d\n", player2->col);
	// t_mlx gpu;

	// gpu.mlx = 0;
	// gpu.img = 0;
	// gpu.win = 0;
	// printf("gpu")
	t_map *data;
	data = (struct s_map *)malloc(sizeof(struct s_map) * 1);
	data = ft_memset(data, 0, sizeof(data));
	printf("sizeof gpu : %ld\n", sizeof(data->gpu));
	ft_memset(&((data)->gpu), 0, sizeof((data)->gpu));
	ft_memset(&((data)->player), 0, sizeof((data)->player));
	printf("%p\n", data->gpu.img);
	printf("%p\n", data->gpu.mlx);
	printf("%p\n", data->gpu.win);
	puts("--------------------");
	printf("%d\n", data->player.col);
	printf("%d\n", data->player.collected);
	printf("%d\n", data->player.row);
	return (0);
}
