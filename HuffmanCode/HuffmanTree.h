#ifndef HuffmanTree_H
#define HUffmanTree_H
typedef struct HTNode {

	unsigned int weight;
	unsigned int lchild,rchild;
	unsigned int parent;

}HTNode,*HuffmanTree;

typedef char** HuffmanCode;
//计算叶子结点权重数组
int* get_w(char *s,int *n,char **ch);
//构造哈夫曼树
HuffmanTree get_HuffmanTree(int*w,int n);
//选择权重最小值和次小值
void select(HuffmanTree ht, int n, int* s1, int* s2);
#endif 
