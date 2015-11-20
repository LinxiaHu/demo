//============================================================================
// Name        : Demo.cpp
// Author      : Chunyun
// Version     : 0.0.1
// Copyright   : hd
// Description : Linux系统编程
//============================================================================

#include "inc/demo.h"

int main() {
	LinuxSystemDemo *l1 = new LinuxSystemDemo(); // 在堆上创建对象，返回指针
	l1->pipeTest();

	printf("---------------------------\n");
	size_t t; // long unsigned int
	t = 999999999;
	printf("t=%d\n", t);

	printf("---------------------------\n");
	int *a = (int *) xmalloc(100);
	printf("a数组的地址是：%p\n", a);
	delete a;

	printf("---------------------------\n");
	int pageSize = l1->getPageSize();
	printf("操作系统页面大小是：%d\n", pageSize);

//	printf("---------------------------\n");
//	l1->forkT();

	printf("---------------------------\n");
	l1->fileSys();

	printf("---------------------------\n");
	l1->memoryMap();

	return 0;
}

//全局函数开始

//封装的内存分配函数
void *xmalloc(size_t size) {
	void *p;
	p = malloc(size);
	if (!p) {
		perror("xmalloc");
		exit(EXIT_FAILURE);
	}
	return p;
}

//全局函数结束

//类方法开始

//返回操作系统页面大小
int LinuxSystemDemo::getPageSize() {
	return getpagesize();
}
//IPC管道
int LinuxSystemDemo::pipeTest() {

	int pipe_fd[2]; //管道的read end和write end
	pid_t child_pid; //子进程
	char pipe_buf; //管道数据
	memset(pipe_fd, 0, sizeof(int) * 2); //初始化
//	child_pid = fork();

	if (pipe(pipe_fd) == -1) { //通过pipe接口打开管道，pipe_fd[0]和pipe_fd[1]分别代表读和写端
		return -1;

	}

	if (child_pid == 0) { //子进程中的操作
		close(pipe_fd[1]); //关闭写短，因为子进程负责读取
		while (read(pipe_fd[0], &pipe_buf, 1) > 0) {
			write(STDOUT_FILENO, &pipe_buf, 1); //读取成功，输出
			printf("子进程读操作：pipe_buf=%c\n", pipe_buf);
			close(pipe_fd[0]); //关闭读取端
			return 0; //成功
		}

	} else { //父进程中的操作
		close(pipe_fd[0]);
		write(pipe_fd[1], "H", 1); //写入一个字符“H"
		printf("父进程写操作：pipe_fd[1]=%d\n", pipe_fd[1]);
		close(pipe_fd[1]); //关闭写入端
		wait(NULL); //等待子进程
		return 0; //成功
	}

	return 0;
}

//file stat 测试
int LinuxSystemDemo::fileSys() {
	struct stat sb;
	int ret;
	ret = stat("/usr/local/hive/bin/hive", &sb);
	if(ret) {
		perror("stat");
		return 1;
	}
	printf("/usr/local/hive/bin/hive's size is %ld bytes\n", sb.st_size);
	return 0;
}



//fork测试
void LinuxSystemDemo::forkT() {
	int i;
	for (i = 0; i < 2; i++) {
		fork();
		printf("ppid=%d,pid=%d,i=%d\n", getppid(), getpid(), i); //getpid()返回当前线程pid,getppid()返回父进程pid
	}
	sleep(1);
}

//mmap操作
void LinuxSystemDemo::memoryMap() {
	int fd;
	void *start;
	struct stat sb;//保存文件的状态
	fd = open("/etc/passwd", O_RDONLY);
	fstat(fd, &sb);//关联fd和state结构体
	start = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);// 映射
	if(start == MAP_FAILED) {
		return;
	}
	printf("%s\n", start);
	munmap(start, sb.st_size);// 解除映射
}
