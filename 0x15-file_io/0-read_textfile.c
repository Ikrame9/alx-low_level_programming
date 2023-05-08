#include "main.h"
#include <stdio.h>


/**
 * read_textfile - reads a text file and prints it to stdout
 * @filename: the name of the file to read
 * @letters: the number of characters to read from the file
 *
 * Return: the number of characters read and printed to stdout,
 *         or 0 if an error occurs
 */


ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *fp;
	char *buf;
	ssize_t nread, nwritten;

	fp = fopen(filename, "r");
	if (fp == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		fclose(fp);
		return (0);
	}

	nread = fread(buf, sizeof(char), letters, fp);
	nwritten = fwrite(buf, sizeof(char), nread, stdout);

	free(buf);
	fclose(fp);

	return (nwritten);
}
