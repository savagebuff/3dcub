#include "libft.h"

int	ft_free_array(char **arr, int val)
{
	int	i;

	i = 0;
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	if (arr && *arr)
		free(arr);
	return (val);
}
