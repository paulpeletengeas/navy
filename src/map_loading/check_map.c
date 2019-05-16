/*
** EPITECH PROJECT, 2019
** navy
** File description:
** check if map is valid or not
*/

int check_map(char *filepath)
{
    char *line = NULL;
    int index = 0;
    int fd = 0;

    if ((fd = open(filepath, O_RDONLY)) < 0)
        return (error_str("Unable to open the map\n"));
    while ((line = get_next_line(fd))) {
        free(line);
        index++;
    }
    return (close(fd));
}
