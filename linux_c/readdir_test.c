#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getFileNum(char* root)
{
    DIR* dir = NULL;
    dir = opendir(root);
    if (dir == NULL)
    {
        perror("openfail");
        exit(1);
    }

    // 遍历目录
    struct dirent* ptr = NULL;
    char path[1024] = {0};
    int count = 0;
    while((ptr = readdir(dir)) != NULL) 
    {
        // 过滤当前目录和父目录
        if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0 ) continue;
        // 是目录
        if(ptr->d_type == DT_DIR)
        {
            sprintf(path, "%s/%s", root, ptr->d_name);
            count += getFileNum(path);  // 读取子目录下面的文件数
        }
        if(ptr->d_type == DT_REG)
        {
            count ++;
        }
    }
    // 关掉目录
    closedir(dir);
    return count;
}
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("./a.out dir\n");
        exit(1);
    }
    int total = getFileNum(argv[1]);
    printf("%s has file numbers %d\n", argv[1], total);
    
    return 0;
}