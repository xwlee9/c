#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open fail");
        exit(1);
    }
    int fd1 = open ("new_test.txt", O_RDWR | O_CREAT, 0777);
    {
        if (fd == -1)
        {
            perror("creat fail");
            exit(1);
        }
    }
    char buf[2048] = {0};
    int count = read(fd, buf, sizeof(buf));  // 0 读完 -1 失败 
    if (count == -1)
    {
        perror("read error");
        exit(1);
    }
    while(count)
    {
        int ret = write(fd1, buf, count);
        printf ("write bytes %d\n", ret);
        count = read(fd, buf, sizeof(buf));
    }

    close(fd);
    close(fd1);
    
    return 0;
}