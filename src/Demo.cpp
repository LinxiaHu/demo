//============================================================================
// Name        : Demo.cpp
// Author      : Chunyun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "inc/demo.h"

int main() {
	LinuxSystemDemo *l1 = new LinuxSystemDemo();
	l1->pipeTest();
	printf("---------------------------\n");
//	size_t t; // long unsigned int
//	t = 999999999;
//	printf("t=%d\n", t);


	return 0;
}

int LinuxSystemDemo::pipeTest() {

	int pipe_fd[2]; //管道的read end和write end
	pid_t child_pid; //子进程
	char pipe_buf; //管道数据
	memset(pipe_fd, 0, sizeof(int) * 2); //初始化

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
