#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int fd;  
    // 打开已经存在的文件
    // fd = open("hello.c", O_RDWR);  // O_RDONLY O_WRONLY
    // if (fd == -1)
    // {
    //     perror("open file"); 
    //     exit(1);
    // }
    
    // 创建新文件
    // O_CREAT 文件权限 本地有一个掩码 ===> 文件的实际权限 和本地掩码取反(umask) 进行一个与操作 
    
    // fd = open("myhello", O_RDWR | O_CREAT, 0777);  
    // if (fd == -1)
    // {
    //     perror("open file"); 
    //     exit(1);
    // }
    // printf("fd = %d\n", fd);

    // 判断文件是否存在
    // fd = open("myhello", O_RDWR | O_CREAT | O_EXCL, 0777);   // 同时使用才可以
    // if (fd == -1)
    // {
    //     perror("open file"); 
    //     exit(1);
    // }
    // printf("fd = %d\n", fd);

    // 将文件清空为0
    fd = open("myhello", O_RDWR | O_TRUNC); 
    if (fd == -1)
    {
        perror("open file"); 
        exit(1);
    }
    printf("fd = %d\n", fd);

    int ret = close(fd);  // 关闭文件；
    printf("ret = %d\n", ret);

}