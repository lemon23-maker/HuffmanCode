#ifndef HuffmanTree_H
#define HUffmanTree_H
typedef struct HTNode {

	unsigned int weight;
	unsigned int lchild,rchild;
	unsigned int parent;

}HTNode,*HuffmanTree;

typedef char** HuffmanCode;
//����Ҷ�ӽ��Ȩ������
int* getw(char *s,int *n);
//�����������
HuffmanTree get_HuffmanTree(int*w,int n);
//ѡ��Ȩ����Сֵ�ʹ�Сֵ
void select(HuffmanTree ht, int n, int* s1, int* s2);
#endif 