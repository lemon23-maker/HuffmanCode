#include "HuffmanCode.h"
#include "string.h"

HuffmanCode HuffmanCoding(HuffmanTree ht,int n) {

	HuffmanCode hc = (HuffmanCode)malloc(n * sizeof(char*));
	char* cd = (char*)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (int i = 0; i < n; i++)
	{
		int start = n - 2;
		for (int j = i,f = ht[j].parent; f != -1; j  = f,f = ht[j].parent)
		{
			if (j == ht[f].lchild)
				cd[start--] = '0';
			else
			{
				cd[start--] = '1';
			}
		}
		strcpy(hc[i], &cd[start + 1]);
	}
	return hc;
}
