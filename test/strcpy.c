#include "test.h"

static int	test_strcpy(char *src)
{
	char *dest_original = malloc(strlen(src) + 1);
	if (!dest_original)
		return (0);
	char *dest_custom = malloc(strlen(src) + 1);
	if (!dest_custom)
	{
		free(dest_original);
		return (0);
	}
	char *ret_original = strcpy(dest_original, src);
	char *ret_custom = ft_strcpy(dest_custom, src);
	int res = (
		(ret_original == dest_original)
		&& (ret_custom == dest_custom)
		&& (!strcmp(dest_custom, dest_original))
	);
	free(dest_custom);
	free(dest_original);
	return (res);
}

void	unit_strcpy(void)
{
	printf("ft_strcpy\t");
	print_result(test_strcpy(""));
	print_result(test_strcpy("hello world"));
	printf("\n");
}
