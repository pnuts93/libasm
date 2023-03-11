#include "test.h"

#define TEST_READ_EMPTY "test/txt_files/test_read_empty.txt"
#define TEST_READ_LOREM "test/txt_files/test_read_loremipsum.txt"

static int	test_read(char *buf_original, char *buf_custom, char *file, size_t iterations, size_t len)
{
	int	fd1, fd2, n1, n2, err1, err2, tot_len1, tot_len2;
	if (buf_original)
		memset(buf_original, 0, 1024);
	if (buf_custom)
		memset(buf_custom, 0, 1024);

	fd1 = open(file, O_RDONLY);
	if (fd1 < 0)
		return (0);
	fd2 = open(file, O_RDONLY);
	if (fd2 < 0)
	{
		close(fd1);
		return (0);
	}
	err1 = 0;
	err2 = 0;
	n1 = read(fd1, buf_original, len);
	err1 = errno;
	n2 = ft_read(fd2, buf_custom, len);
	err2 = errno;
	if (n1 > 0 && n2 > 0)
	{
		tot_len1 = n1;
		tot_len2 = n2;
		buf_original[n1] = 0;
		buf_custom[n2] = 0;
		while (--iterations > 0 && n1 > 0 && n2 > 0)
		{
			n1 = read(fd1, &buf_original[strlen(buf_original)], len);
			err1 = errno;
			n2 = ft_read(fd2, &buf_custom[strlen(buf_custom)], len);
			err2 = errno;
			if (n1 < 0 || n2 < 0)
				break ;
			tot_len1 += n1;
			tot_len2 += n2;
			buf_original[tot_len1] = 0;
			buf_custom[tot_len2] = 0;
		}
	}

	close(fd1);
	close(fd2);
	return (
		(n1 == n2)
		&& (err1 == err2)
		&& ((!buf_original && !buf_custom) || (strcmp(buf_original, buf_custom) == 0))
	);
}

void unit_read(void)
{
	char buf_original[1024], buf_custom[1024];

	printf("ft_read\t\t");
	print_result(test_read(NULL, NULL, TEST_READ_EMPTY, 1, 1));
	print_result(test_read(buf_original, buf_custom, TEST_READ_EMPTY, 1, 1));
	print_result(test_read(buf_original, buf_custom, TEST_READ_EMPTY, 5, 1));
	print_result(test_read(buf_original, buf_custom, TEST_READ_LOREM, 1, 0));
	print_result(test_read(buf_original, buf_custom, TEST_READ_LOREM, 1, 42));
	print_result(test_read(buf_original, buf_custom, TEST_READ_LOREM, 5, 42));
	printf("\n");
}
