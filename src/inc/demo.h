#include <iostream>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h> //open()
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
//驱动设备头文件
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/sched.h>
//驱动设备头文件，在/usr/src中，暂时无法加入include路径
//#include <linux/module.h>
//#include <linux/mm.h>
//#include <linux/init.h>
//#include <linux/cdev.h>
//#include <asm/io.h>
//#include <asm/system.h>
//#include <asm/uaccess.h>

using namespace std;

//全局函数声明开始
void *xmalloc(size_t size); //封装内存分配函数
//全局函数声明结束


class LinuxSystemDemo {
public:
	LinuxSystemDemo(){};
	~LinuxSystemDemo(){};
	int fileSys();// file stat测试
	void forkT();// fork()测试
	int getPageSize();// 返回操作系统页面大小
	int pipeTest();// IPC管道
	void memoryMap();// mmap使用
};
