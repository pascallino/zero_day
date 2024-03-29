#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file;
	int result;

    if (filename == NULL) 
    {
        return (-1);
    }
    if (text_content == NULL) 
    {
        return (1);
    }

    file = fopen(filename, "a");
    if (file == NULL) 
    {
        return (-1);
    }

    result = fputs(text_content, file);

    fclose(file);

    if (result == EOF) 
    {
        return (-1);
    }
    return (1);
}

