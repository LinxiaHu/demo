//============================================================================
// Name        : Demo.cpp
// Author      : Chunyun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "inc/demo.h"

int main() {
//	int a = 999;
//	printf("a=%d\n", a);
//	Demo* d = new Demo("a"); //堆上分配内存，且需要用指针接收对象
//	d->say();
//	delete d; //否则不会调用析构函数
//	printf("--------------------------\n");
//	Demo demo("Zhangsan"); //栈上分配对象,用对象引用接收,非指针
//	demo.say();
//	test1();
//	printf("--------------------------\n");
//	Persion p1(1, "Beijing", "xiaoa"); //栈上分配内存，无需delete
//	p1.speack("大家好啊，很高兴认识大家！");

// 结构体测试开始

//	printf("Size of s1:%ld\n", sizeof(s1));
//	printf("Size of s2:%ld\n", sizeof(s2));
//	printf("Size of int*:%ld\n", sizeof(int*));
//	printf("Size of double*:%ld\n", sizeof(double*));
//	printf("Size of double:%ld\n", sizeof(double));
//	printf("Size of float:%ld\n", sizeof(float));
//	printf("Size of s2*:%ld\n", sizeof(s2*));
//	printf("Size of s3:%ld\n", sizeof(s3));
//	printf("Size of s_void:%ld\n", sizeof(s_void));
//	printf("Size of s4:%ld\n", sizeof(s4));
//	printf("Size of s5:%ld\n", sizeof(s5));
//	printf("Size of s6:%ld\n", sizeof(s6));
//	printf("Size of s7:%ld\n", sizeof(s7));
//	printf("Size of s8:%ld\n", sizeof(s8));
//	printf("Size of s9:%ld\n", sizeof(s9));
//	printf("Size of s10:%ld\n", sizeof(s10));

// 结构体测试结束

// 二叉树遍历算法开始
	BTNode *bt = NULL;
	BTNode tmp;
	BTNode tmp1;
	BTNode tmp2;
	BTNode tmp3;
	BTNode tmp4;
	tmp.data = 1;
	tmp.lchild = &tmp1;
	tmp.rchild = &tmp2;
	bt = &tmp;
	tmp1.data = 2;
	tmp1.lchild = &tmp3;
	tmp1.rchild = &tmp4;
	tmp2.data = 4;
	tmp2.lchild = NULL;
	tmp2.rchild = NULL;
	tmp3.data = 3;
	tmp3.lchild = NULL;
	tmp3.rchild = NULL;
	tmp4.data = 5;
	tmp4.lchild = NULL;
	tmp4.rchild = NULL;

	bt == NULL;
	BTNode lv1;
	BTNode lv2;
	BTNode lv3;
	lv1.data = 0;
	lv2.data = 1;
	lv3.data = 2;
	bt = &lv1;
	lv1.lchild = &lv2;
	lv1.rchild = &lv3;
	lv2.lchild = NULL;
	lv2.rchild = NULL;
	lv3.lchild = NULL;
	lv3.rchild = NULL;

	int depth = depthOfBinaryTree(bt);
	printf("二叉树的高度是：%d\n", depth);
	cout << "先序遍历二叉树:" << endl;
	preorder(bt);
	cout << endl;
	cout << "中序遍历二叉树:" << endl;
	inorder(bt);
	cout << endl;

// 二叉树遍历算法结束

// 开始测试转换函数
	double d;
	string salary;
	string s = "12.56";
	d = convert<double>(s); //d等于12.56
	salary = convert<string>(9000.0); //salary等于”9000”
	cout<< "d=" <<d <<endl;
	cout<<"salary=" <<salary <<endl;
	return 0;
}

// 全局函数
void test1() {

	printf("输出来自test1全局函数！\n");
}

// 类型转函数
template<class T>
void to_string(string &result, const T &t) {
	ostringstream oss; //创建一个流
	oss << t; //把值传递如流中
	result = oss.str(); //获取转换后的字符转并将其写入result
}

template<class out_type, class in_value>
out_type convert(const in_value &t) {
	stringstream stream;
	stream << t; //向流中传值
	out_type result; //这里存储转换结果
	stream >> result; //向result中写入值
	return result;
}

//二叉树高度，非递归算法，基于中序遍历
int depthOfBinaryTree(BTNode *tree) {
	int depth = 0;
	int tmp = 0;
	BTNode *p = tree;
	stack<BTNode *> path;
	while (p || !path.empty()) {
		if (p) {
			path.push(p);
			depth++; //统计单分支深度
			p = p->lchild;
		} else {
			p = path.top();
			path.pop();
			p = p->rchild; //一个结点的右孩子为空，则表示这个分支结束了
			if (NULL == p) { //单分支结束
				if (depth > tmp) {
					tmp = depth;
					depth--;
				}
			}
		} //else
	} //while
	return tmp;
}
//反转字符串，但不能使用strlen(),注意传入的实参不能是char *，而应该是char[]
void reserve(char * str) {
	if (str == NULL)
		return;
	char *strbegin;
	char *strend;
	strbegin = str;
	strend = str - 1;
	while (*++strend)
		; //将strend移动到末尾
	strend -= 1; //末尾是'\0'
	while (strbegin < strend) {
		char tmp = *strbegin;
		*strbegin++ = *strend;
		*strend-- = tmp;
	}
}

//快排的划分操作
int partition(int r[], int i, int j) {
	int pivot = r[i];
	while (i < j) {
		while (i < j && r[j] >= pivot)
			j--; //向右移动
		if (i < j) {
			r[i++] = r[j];
		}
		while (i < j && r[i] <= pivot)
			i++; //向左移动
		if (i < j) {
			r[j--] = r[i];
		}
	} //while(i<j)
	r[i] = pivot; //一次循环的基准数据最终的位置
	return i;
}
//二叉树非递归先序遍历
void preorder(BTNode *bt) {
	stack<BTNode*> pBTNodes;
	BTNode *p;
	if (bt != NULL) {
		pBTNodes.push(bt);
		while (!pBTNodes.empty()) {
			p = pBTNodes.top();
			pBTNodes.pop(); //栈顶元素出栈
			cout << p->data << " ";
			if (p->rchild != NULL) {
				pBTNodes.push(p->rchild);
			}
			if (p->lchild != NULL) {
				pBTNodes.push(p->lchild);
			}
		}
	}
}
//二叉树非递归中序遍历
void inorder(BTNode *bt) {
	stack<BTNode*> pBTNodes;
	BTNode *p;
	if (bt != NULL) {
		p = bt; //中序遍历要查找一个结点的孩子结点，所以要先将根节点保存下来
		while (!pBTNodes.empty() || p != NULL) { //中序遍历可能出现中间栈空的情况，所以要判断p!=NULL
			while (p != NULL) {
				pBTNodes.push(p);
				p = p->lchild;
			}
			if (!pBTNodes.empty()) {
				p = pBTNodes.top();
				pBTNodes.pop();
				cout << p->data << " ";
				p = p->rchild;
			}
		}
	}
}

//实现trim函数
char* mytrim(char *str) {
	if (str == NULL) {
		return NULL;
	}

	while (IS_SPACE(*str)) // #define IS_SPACE(c)  ((c) == ' ' || (c) == '\t')
		str++;
	int len = strlen(str);
	if (len == 0) {
		return str;
	}

	char *end = str + len - 1;
	while (IS_SPACE(*end))
		end--;
	*(++end) = '\0';
	return str;
}

// 成员函数
void Demo::say() {
	printf("I'm from China!\n");
	printf("My name is:%s\n", this->name.c_str());
}

void Persion::speack(string phrase) {
	cout << phrase << endl;
	cout << "My name is :" << this->name << endl;
	cout << "My address is :" << this->address << endl;
}
