#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
- 获取文件大小
- 移动文件指针
- 文件拓展
*/
int main()
{
    int fd = open("test.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open fail");
        exit(1);
    }
    int ret = lseek(fd, 0, SEEK_END);  // filename offset where
    printf("file length is %d\n", ret);

    // 文件拓展
    int ret1 = lseek(fd, 2000, SEEK_END);
    printf("new length is %d\n", ret1);
    write(fd, "abc", 1);  // 需要再做一步写操作
    close (fd);
    return 0;
}