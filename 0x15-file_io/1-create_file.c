#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

int create_file(const char *filename, char *text_content) 
{
	ssize_t bytes_written;
	int fd;

    if (filename == NULL) {
        return -1;
    }
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        return -1;
    }
    if (text_content != NULL) {
        bytes_written = write(fd, text_content, strlen(text_content));
        if (bytes_written == -1) {
            close(fd);
            return -1;
        }
    }
    close(fd);
    return 1;
}

