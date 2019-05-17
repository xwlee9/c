#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[1])
{
    if (argc < 2)
    {
        printf("./a.out filename\n");
        exit(1); 
    }
    struct stat st;
    int ret = stat(argv[1], &st);
    if(ret == -1)
    {
        perror("stat");
        exit(1);
    }
    int size = (int)st.st_size;
    printf("size is : %d\n", size);

}