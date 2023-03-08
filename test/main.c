#include <stdio.h>
#include <stdlib.h>
#include "libasm.h"

int	main(void)
{
	printf("The length of 'hello world' is %ld\n", ft_strlen("hello world"));
	char src[] = "hello world";
	char dest[12];
	ft_strcpy(dest, src);
	printf("%s\n", dest);
	printf("difference between 'cocoa' and 'coconut' is %d\n", ft_strcmp("cocoa", "coconut"));
	printf("difference between 'cocoa' and 'cocoa' is %d\n", ft_strcmp("cocoa", "cocoa"));

	char buf[12];
	int n = ft_read(0, buf, 11);
	buf[n] = 0;
	printf("%s, %d characters\n", buf, n);
	printf(", has %ld characters\n", ft_write(1, "hello world", 11));
	char *dup = ft_strdup("some string");
	printf("%s\n", dup);
	ft_write(1, dup, ft_strlen(dup));
	free(dup);

	return (0);
}