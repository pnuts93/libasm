#include "test.h"

#define TEST_WRITE_FNAME_ORIGINAL "test/txt_files/test_write_original.txt"
#define TEST_WRITE_FNAME_CUSTOM "test/txt_files/test_write_custom.txt"

static void	purge_files(void)
{
	remove(TEST_WRITE_FNAME_ORIGINAL);
	remove(TEST_WRITE_FNAME_CUSTOM);
}

static int	compare_files(void)
{
	int fd1, fd2, n1, n2;
	char content_original[1024], content_custom[1024];

	fd1 = open(TEST_WRITE_FNAME_ORIGINAL, O_RDONLY);
	if (fd1 < 0)
	{
		purge_files();
		return (0);
	}
	fd2 = open(TEST_WRITE_FNAME_CUSTOM, O_RDONLY);
	if (fd2 < 0)
	{
		close(fd1);
		purge_files();
		return (0);
	}
	n1 = read(fd1, content_original, 1023);
	n2 = read(fd2, content_custom, 1023);
	close(fd1);
	close(fd2);
	purge_files();
	if (n1 < 0 || n2 < 0)
		return (0);
	content_original[n1] = 0;
	content_custom[n2] = 0;
	return (strcmp(content_custom, content_original) == 0);
}

static int	test_write(char *buf, size_t iterations, size_t len)
{
	int fd1, fd2, n1, n2, err1, err2;

	fd1 = open(TEST_WRITE_FNAME_ORIGINAL, O_CREAT | O_WRONLY, 0664);
	if (fd1 < 0)
		return (0);
	fd2 = open(TEST_WRITE_FNAME_CUSTOM, O_CREAT | O_WRONLY, 0664);
	if (fd2 < 0)
	{
		close(fd1);
		return (0);
	}
	n1 = 0;
	n2 = 0;
	err1 = 0;
	err2 = 0;
	while (iterations-- > 0 && err1 == 0 && err2 == 0)
	{
		n1 += write(fd1, buf, len);
		err1 = errno;
		n2 += ft_write(fd2, buf, len);
		err2 = errno;
	}
	close(fd1);
	close(fd2);
	return (
		(n1 == n2)
		&& (err1 == err2)
		&& (compare_files())
	);
}

void unit_write(void)
{
	printf("ft_write\t");
	print_result(test_write(NULL, 1, 1));
	print_result(test_write("", 1, 1));
	print_result(test_write("", 5, 1));
	print_result(test_write("hello world", 1, 11));
	print_result(test_write("hello world", 5, 11));
	printf("\n");
}
