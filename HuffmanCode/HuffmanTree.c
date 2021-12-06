#include "HuffmanTree.h"
#include <stdlib.h>
#include <stdio.h>

int* get_w(char* s,int *n,char **ch) {
	int t[26] = { 0 };
	int n1 = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		switch (s[i]) {
			case 'a':t[0]++; if(t[0]==0)n1++; break;
			case 'b':t[1]++; if(t[1]==0)n1++; break;
			case 'c':t[2]++; if(t[2]==0)n1++; break;
			case 'd':t[3]++; if(t[3]==0)n1++; break;
			case 'e':t[4]++; if(t[4]==0)n1++; break;
			case 'f':t[5]++; if(t[5]==0)n1++; break;
			case 'g':t[6]++; if(t[6]==0)n1++; break;
			case 'h':t[7]++; if(t[7]==0)n1++; break;
			case 'i':t[8]++; if(t[8]==0)n1++; break;
			case 'j':t[9]++; if(t[9]==0)n1++; break;
			case 'k':t[10]++;if(t[10]==0)n1++; break;
			case 'l':t[11]++;if(t[11]==0)n1++; break;
			case 'm':t[12]++;if(t[12]==0)n1++; break;
			case 'n':t[13]++;if(t[13]==0)n1++; break;
			case 'o':t[14]++;if(t[14]==0)n1++; break;
			case 'p':t[15]++;if(t[15]==0)n1++; break;
			case 'q':t[16]++;if(t[16]==0)n1++; break;
			case 'r':t[17]++;if(t[17]==0)n1++; break;
			case 's':t[18]++;if(t[18]==0)n1++; break;
			case 't':t[19]++;if(t[19]==0)n1++; break;
			case 'u':t[20]++;if(t[20]==0)n1++; break;
			case 'v':t[21]++;if(t[21]==0)n1++; break;
			case 'w':t[22]++;if(t[22]==0)n1++; break;
			case 'x':t[23]++;if(t[23]==0)n1++; break;
			case 'y':t[24]++;if(t[24]==0)n1++; break;
			case 'z':t[25]++;if(t[25]==0)n1++; break;
		}
	}
	*n = n1;
	int* w = (int*)malloc(n1 * sizeof(int));
	*ch = (char*)malloc(n1 * sizeof(char));
	for (int i = 0,j = 0; i < n; i++)
	{
		while (t[j]==0)
		{
			j++;
		}
		w[i] = t[j];
		(*ch)[i] = j + 96;
		printf("%c:%d ", j + 96, t[j]);
	}
	printf("\n");
	return w;
}
HuffmanTree get_HuffmanTree(int* w, int n) {

	if (n <= 1) {
		HuffmanTree ht = (HuffmanTree)malloc(sizeof(HTNode));
		ht->weight = *w;
		return;
	}
	int m = 2 * n - 1;
	HuffmanTree ht = (HuffmanTree)malloc(m * sizeof(HTNode));

	for (int i = 0; i < n; i++)
	{
		(ht + i)->weight = *(w + i);
		(ht + i)->lchild = -1;
		(ht + i)->rchild = -1;
		(ht + i)->parent = -1;
	}
	for (int i = n; i < m; i++)
	{
		(ht + i)->lchild = -1;
		(ht + i)->rchild = -1;
		(ht + i)->parent = -1;
		int s1, s2;
		select(ht, i, &s1, &s2);

		(ht + i)->weight = ht[s1].weight + ht[s2].weight;
		(ht + i)->lchild = s1;
		(ht + i)->rchild = s2;
		ht[s1].parent = i;
		ht[s2].parent = i;
	}

}

void select(HuffmanTree ht, int n, int* s1, int* s2) {
	int min1 = 2147483647, min2 = 2147483647;
	*s1 = *s2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (ht[i].parent == -1) {

			if (ht[i].weight <= min1) {
				min2 = min1;
				*s1 = *s2;
				min1 = ht[i].weight;
				*s1 = i;

			}
			else if (ht[i].weight > min1 && ht[i].weight < min2)
			{
				min2 = ht[i].weight;
				*s2 = i;
			}

		}
	}

}
