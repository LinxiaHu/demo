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
			id(id), address(addr), Demo(name) { // ���๹�����������
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

// ȫ�ֺ�������ؽṹ��
//����������ʽ�洢�ṹ
typedef struct BTNode {
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
} BTNode;
void test1();
int depthOfBinaryTree(BTNode *);
//��ת�ַ�����������ʹ��strlen(),ע�⴫���ʵ�β�����char *����Ӧ����char[]
void reserve(char *);
//���ŵĻ��ֲ���
int partition(int[], int, int);
//�������ǵݹ��������
void preorder(BTNode *);
//�������ǵݹ��������
void inorder(BTNode *bt);
//ʵ��trim����
#define IS_SPACE(c)  ((c) == ' ' || (c) == '\t')
char* mytrim(char *);
// ����ת������
template<class T>
void to_string(string, T);
template<class out_type, class in_value>
out_type convert(const in_value & t);
// redis��������
unsigned int dictIntHashFunction(unsigned int );

// �ṹ��

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
	s2 ss2; //�ṹ��Ķ���������������ĳ�Ա��pack() �е���С��,���Ե�pack()ȡ8��4ʱ��s3�Ĵ�С��һ����8ʱ�ṹ����min(8,8)=8ȡֵ��4ʱ��min(4,8)=4ȡֵ
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
