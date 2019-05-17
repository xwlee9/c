#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd = open("temp", O_CREAT | O_RDWR, 0666);
    if (fd == -1)
    {
        perror("open fail");
        exit(1);
    }
    // 删除临时file
    int ret = unlink("temp");

    write(fd, "hello\n", 6);
    // 重置文件指针
    lseek(fd, 0, SEEK_SET);
    // 
    char buf[8] = {0};
    int len = read(fd, buf, sizeof(buf));

    // 将读出来的内容 写在屏幕上 0 in 1 out
    write(1, buf,len);
    close(fd);
    return 0; 
}