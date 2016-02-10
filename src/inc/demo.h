#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
#include <sstream>
using namespace std;

class Demo {
public:
	inline Demo(string name) :
			name(name) {
		printf("Demo class created!\n");
	}
	inline virtual ~Demo() {
		printf("Demo class destroyed!\n");
	}

	void say();

protected:
	string name;
};

class Persion: Demo {
public:
	Persion(int id, string addr, string name) :
			id(id), address(addr), Demo(name) { // 父类构造器必须调用
		printf("Persion class created!\n");
	}
	~Persion() {
		printf("Persion class destroyed!\n");
	}
	void speack(string phrase);

private:
	int id;
	string address;
};

// 全局函数及相关结构体
//二叉树的链式存储结构
typedef struct BTNode {
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
} BTNode;
void test1();
int depthOfBinaryTree(BTNode *);
//反转字符串，但不能使用strlen(),注意传入的实参不能是char *，而应该是char[]
void reserve(char *);
//快排的划分操作
int partition(int[], int, int);
//二叉树非递归先序遍历
void preorder(BTNode *);
//二叉树非递归中序遍历
void inorder(BTNode *bt);
//实现trim函数
#define IS_SPACE(c)  ((c) == ' ' || (c) == '\t')
char* mytrim(char *);
// 类型转换函数
template<class T>
void to_string(string, T);
template<class out_type, class in_value>
out_type convert(const in_value & t);
// redis函数举例
unsigned int dictIntHashFunction(unsigned int );

// 结构体

typedef struct {
	int a;
	char c1;
	short s1;
} s1;

typedef struct {
	double d1;
	int *n1;
	char c1;
} s2;

typedef struct {
	short s1;
	s2 ss2; //结构体的对齐规则是其中最大的成员与pack() 中的最小者,所以当pack()取8和4时，s3的大小不一样，8时结构体以min(8,8)=8取值，4时以min(4,8)=4取值
	int * n1;
} s3;

typedef struct {

} s_void;

typedef struct {
	int ai;
	char a[3];
} s4;

typedef struct {
	char c;
} s5;

typedef struct {
	char c;
	char c1;
} s6;

typedef struct {
	char c;
	char c1;
	char ac[3];
} s7;

typedef struct {
	int a[2];
	char c;
	char c1;
	char ac[3];
} s8;

typedef struct {
	int a[3];
	char c1;
} s9;

typedef struct {
	int a[2];
	char c1;
	short s;
	float f1;
	short s1;
} s10;
