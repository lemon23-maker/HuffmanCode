#include "HuffmanCode.h"
#include <string.h>
#include <stdio.h>
int main()
{
	char s[1000];
	int* w;
	int n;
	char* ch;
	HuffmanTree ht;
	HuffmanCode hc;
	printf("请输入字符串");
	gets(s);
	while (strcmp(s,"0")==0)
	{
		w = get_w(w, &n,&ch);
		ht = get_HuffmanTree(w, n);
		hc = HuffmanCoding(ht, n);

		//输出哈夫曼树的节点
		for (int i = 0; i < 2*n-1; i++)
		{
			printf("%d %d %d %d %d\n",i+1,ht[i].weight, ht[i].lchild, ht[i].rchild, ht[i].parent);
		}
		//输出各个字符的编码
		for (int i = 0; i < n; i++)
		{
			printf("%c:%s", ch[i], hc[i]);
		}






		free(ch);
		free(w);
		free(ht);
		free(hc);
		gets(s);
	}
}

