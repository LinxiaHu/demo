#include <iostream>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//驱动设备头文件
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/sched.h>
//驱动设备头文件，在/usr/src中，eclipse无法找到
//#include <linux/module.h>
//#include <linux/mm.h>
//#include <linux/init.h>
//#include <linux/cdev.h>
//#include <asm/io.h>
//#include <asm/system.h>
//#include <asm/uaccess.h>

using namespace std;

class LinuxSystemDemo {
public:
	LinuxSystemDemo(){};
	~LinuxSystemDemo(){};
	int pipeTest();// IPC管道
};
