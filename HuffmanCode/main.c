#include "HuffmanCode.h"
#include <string.h>
#include <stdio.h>
int main()
{
	char s[1000];
	int* w;
	int n;
	HuffmanTree ht;
	HuffmanCode hc;
	printf("请输入字符串");
	gets(s);
	while (strcmp(s,"0")==0)
	{
		w = getw(w, &n);
		ht = get_HuffmanTree(w, n);
		hc = HuffmanCoding(ht, n);











		gets(s);
	}
}

