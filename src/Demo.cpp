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
//	Demo* d = new Demo("a"); //���Ϸ����ڴ棬����Ҫ��ָ����ն���
//	d->say();
//	delete d; //���򲻻������������
//	printf("--------------------------\n");
//	Demo demo("Zhangsan"); //ջ�Ϸ������,�ö������ý���,��ָ��
//	demo.say();
//	test1();
//	printf("--------------------------\n");
//	Persion p1(1, "Beijing", "xiaoa"); //ջ�Ϸ����ڴ棬����delete
//	p1.speack("��Һð����ܸ�����ʶ��ң�");

// �ṹ����Կ�ʼ

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

// �ṹ����Խ���

// �����������㷨��ʼ
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
	printf("�������ĸ߶��ǣ�%d\n", depth);
	cout << "�������������:" << endl;
	preorder(bt);
	cout << endl;
	cout << "�������������:" << endl;
	inorder(bt);
	cout << endl;

// �����������㷨����

// ��ʼ����ת������
	double d;
	string salary;
	string s = "12.56";
	d = convert<double>(s); //d����12.56
	salary = convert<string>(9000.0); //salary���ڡ�9000��
	cout<< "d=" <<d <<endl;
	cout<<"salary=" <<salary <<endl;
	return 0;
}

// ȫ�ֺ���
void test1() {

	printf("�������test1ȫ�ֺ�����\n");
}

// ����ת����
template<class T>
void to_string(string &result, const T &t) {
	ostringstream oss; //����һ����
	oss << t; //��ֵ����������
	result = oss.str(); //��ȡת������ַ�ת������д��result
}

template<class out_type, class in_value>
out_type convert(const in_value &t) {
	stringstream stream;
	stream << t; //�����д�ֵ
	out_type result; //����洢ת�����
	stream >> result; //��result��д��ֵ
	return result;
}

//�������߶ȣ��ǵݹ��㷨�������������
int depthOfBinaryTree(BTNode *tree) {
	int depth = 0;
	int tmp = 0;
	BTNode *p = tree;
	stack<BTNode *> path;
	while (p || !path.empty()) {
		if (p) {
			path.push(p);
			depth++; //ͳ�Ƶ���֧���
			p = p->lchild;
		} else {
			p = path.top();
			path.pop();
			p = p->rchild; //һ�������Һ���Ϊ�գ����ʾ�����֧������
			if (NULL == p) { //����֧����
				if (depth > tmp) {
					tmp = depth;
					depth--;
				}
			}
		} //else
	} //while
	return tmp;
}
//��ת�ַ�����������ʹ��strlen(),ע�⴫���ʵ�β�����char *����Ӧ����char[]
void reserve(char * str) {
	if (str == NULL)
		return;
	char *strbegin;
	char *strend;
	strbegin = str;
	strend = str - 1;
	while (*++strend)
		; //��strend�ƶ���ĩβ
	strend -= 1; //ĩβ��'\0'
	while (strbegin < strend) {
		char tmp = *strbegin;
		*strbegin++ = *strend;
		*strend-- = tmp;
	}
}

//���ŵĻ��ֲ���
int partition(int r[], int i, int j) {
	int pivot = r[i];
	while (i < j) {
		while (i < j && r[j] >= pivot)
			j--; //�����ƶ�
		if (i < j) {
			r[i++] = r[j];
		}
		while (i < j && r[i] <= pivot)
			i++; //�����ƶ�
		if (i < j) {
			r[j--] = r[i];
		}
	} //while(i<j)
	r[i] = pivot; //һ��ѭ���Ļ�׼�������յ�λ��
	return i;
}
//�������ǵݹ��������
void preorder(BTNode *bt) {
	stack<BTNode*> pBTNodes;
	BTNode *p;
	if (bt != NULL) {
		pBTNodes.push(bt);
		while (!pBTNodes.empty()) {
			p = pBTNodes.top();
			pBTNodes.pop(); //ջ��Ԫ�س�ջ
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
//�������ǵݹ��������
void inorder(BTNode *bt) {
	stack<BTNode*> pBTNodes;
	BTNode *p;
	if (bt != NULL) {
		p = bt; //�������Ҫ����һ�����ĺ��ӽ�㣬����Ҫ�Ƚ����ڵ㱣������
		while (!pBTNodes.empty() || p != NULL) { //����������ܳ����м�ջ�յ����������Ҫ�ж�p!=NULL
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

//ʵ��trim����
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

// ��Ա����
void Demo::say() {
	printf("I'm from China!\n");
	printf("My name is:%s\n", this->name.c_str());
}

void Persion::speack(string phrase) {
	cout << phrase << endl;
	cout << "My name is :" << this->name << endl;
	cout << "My address is :" << this->address << endl;
}
