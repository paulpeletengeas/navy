/*
** EPITECH PROJECT, 2019
** navy
** File description:
** open map and load it into mem
*/

#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include "proto.h"

char **load_map(char const *filepath)
{
    char **dest = NULL;
    int fd = 0;

    if ((fd = open(filepath, O_RDONLY)) == -1) {
        error_str("Unable to open the file");
        return (NULL);
    }
    if (!(dest = create_map(dest))) return (NULL);
    return ((write_map(fd, dest) != 0) ? NULL : dest);
}
