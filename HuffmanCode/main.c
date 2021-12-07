#include "HuffmanCode.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char s[1000];
	int* w = NULL;
	int n;
	char* ch;
	HuffmanTree ht;
	HuffmanCode hc;
	printf("请输入字符串,输入\"0\"退出\n");
	gets(s);
	while (strcmp(s,"0")!=0)
	{
		w = get_w(s, &n,&ch);
		ht = get_HuffmanTree(w, n);
		hc = HuffmanCoding(ht, n);

		//输出哈夫曼树的节点
		for (int i = 0; i < 2*n-1; i++)
		{
			printf("%d %d %d %d %d\n",i+1,ht[i].weight, ht[i].lchild+1, ht[i].rchild+1, ht[i].parent+1);
		}
		//输出各个字符的编码
		for (int i = 0; i < n; i++)
		{
			printf("%c:%s\n", ch[i], hc[i]);
		}


		//释放内存
		free(ch);
		free(w);
		free(ht);
		for (int i = 0; i < n; i++)
		{
			free(hc[i]);
		}
		free(hc);
		//输入下一组数据
		gets(s);
	}
	printf("已退出\n");
}

