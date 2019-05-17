## GDB调试

- 启动dgb
	start: 只执行一步
		n: next 只执行一步
		s: step 可以进入函数体内部   finish 函数内部跳出 若有断点 先去除断点
		c: continue 直接停在断点位置
- 查看代码
	l 10(function)
	l filename : 行号(function) 
- 设置断点
	b 10(function)
	b filename : 行号(function) 
	
	b 10 if value == 10

- 删除断点
	d / del 断点编号 info / i  b
- 跳出循环  
	u
- 查看设置变量的值 
	p / print  value
- 查看变量类型
	ptype value
- 设置变量的值
	set var 变量名 = 赋值
- 设置追踪变量
	display 
	取消 	undisplay 编号 		获取编号  info display
- 退出调试
- quit


## makefile

app:main.o sum.o sub.o
	gcc main.o sum.o sub.o -o app

main.o:main.c
	gcc -c main.c

sum.o:sum.c
	gcc -c sum.c

sub.o:sub.c
	gcc -c sub.c

===>
obj=main.o sum.o sub.o
target=app
CC = gcc
$(target):$(obj)
	$(CC) $(obj) -o $(target)

%.o:%.c
	$(CC) -c $< -o $@

#### makefile 自动变量
%:自动匹配
$<: 规则中的第一个依赖
$@: 规则中的目标
$^: 规则中的所有的依赖
只能在规则中的命令中使用

#### makefile中自己 维护的变量
CC = gcc
CPPFLAGS: 预处理器需要的选项 -I
CFLAGS: 编译的时候使用的参数 -Wall -g -c
LDFLAGS: 链接库使用的参数 -L -l

### makefile函数
src=$(wildcard ./*.c)  			# 查找
obj=$(patsubset ./%.c, ./%.o, $(src))   # 替换
target=app
CC = gcc
$(target):$(obj)
	$(CC) $(obj) -o $(target)

%.o:%.c
	$(CC) -c $< -o $@

.PHONY:clean  # 声明伪目标
clean:
	rm -f $(obj) $(target)


使用make clean 执行clean
clean:
	-rm -f $(obj) $(target)	
如果执行失败 忽略

#### lseek
- 获取文件大小
- 移动文件指针
- 文件拓展

### Linux 文件操作
* stat函数
	穿透追踪函数  — 软连接
	- st_dev	// 文件设备编号
	- st_ino	// 节点
	- st_mode	// 文件类型 存取权限
	- st_nlink		// 连接该文件的硬连接数 刚建立的文件值为1
	- st_uid	// 用户ID
	- st_gid	// 组ID
	- st_rdev		// 设备文件 设备编号
	- st_size		// 文件字节数
	- st_blksize		// 块大小
	- st_block		// 块数
	- st_atime		// 最后访问时间
	- st_mtime		// 最后修改时间
	- st_ctime		// 最后改变时间
* lstat函数
	不穿透
* access函数		(const char* pathname, int mode) 
	测试文件是否具有权限
	- mode ===> R_OK  W_OK  X_OK  F_OK(存在)
* chmod 函数		(const char* pathname, 0755)
	
* chown 函数		(const char* pathname, uid_t, gid_t)

* truncate 函数		(const char* pathname, off_t length)
	文件截取/拓展

* link 函数  	创建硬链接  int link(const char* oldpath, const char* newpath);
* symlink函数  创建软链接
* readlink 函数  读软链接对应的文件名 (const char* path, char* buf, size_t bufsize);   // buf ==> 文件名
* unlink 函数与 删除文件的目录项 成功返回0 否则返回-1


* rename  	  (const char* oldpath, const char* newpath);

* chdir 	(const char* path)
	改变当前 进程(程序中打开)的路径

* getcwd	(char* buf, size_t size)

man 3

*  opendir	DIR* opendir(const char* name)

*  readdir 	struct dirent* readdir(DIR* dirp)
{
	ino_t d_ino;	//此目录进入点的inode
	ff_t d_off;	// 目录文件开头值此点的偏置
	signed short int d_reclen;	// d_name 长度 不含NULL;
	unsigned char d_type;	// d_name 文件类型
	har d_name[256];		// 文件名
} 

* dup 			(int oldfd)
	文件描述符拷贝  返回文件描述表中最小的文件描述符
* dup2		(int old, int new)
	- 如果new 被一个打开的文件描述符 拷贝前先关掉new
	- old new 同一个文件描述符 直接返回文件描述符

* fcntl 	(int fd, int cmd, NULL/long arg/struct flock *lock)
	改变已经打开文件的属性 
cmd
	- 复制现有的描述符	F_DUPFD
	- 获得/设置文件描述标记 F_GETFD F_SETFD
	- 获得/设置文件状态标记 F_GETFL F_SETFL
		追加写 O_APPEND
		非阻塞 O_NONBLOCK
		
	- 获得/设置异步IO所有权 F_GETOWN F_SETOWN
	- 获得/设置记录锁 F_GETLK F_SETLK F_GETLKW
	
