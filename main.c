#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
    char *line;
    //char *line2;
    int fd;
   // int fd2;
    int r;
    //int r2;
    
	ac = 0;
    fd = open(av[1], O_RDONLY);
    //fd2 = open(av[1], O_RDONLY);
    while((r = get_next_line(fd, &line)) > 0)
    {
       /*if((r2 = get_next_line(fd2, &line2)) > 0)
       {
           printf("%d : %s\n", r2, line2);
           free(line2);
       } */   
        printf("%d : %s\n", r, line);
		free(line);
    }
    printf("%d : %s\n", r, line);
    free(line);
   /*r2 = get_next_line(fd2, &line2);
   printf("%d : %s\n", r2, line2);
    free(line2);*/
    close(fd);
    //close(fd2);
    return (0);
}
