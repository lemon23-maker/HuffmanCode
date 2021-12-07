#include "HuffmanTree.h"
#include <stdlib.h>
#include <stdio.h>

int* get_w(char* s,int *n,char **ch) {
	int t[26] = { 0 };
	int n1 = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		switch (s[i]) {
			case 'a':if(t[0]==0)n1++;t[0]++;  break;
			case 'b':if(t[1]==0)n1++;t[1]++;  break;
			case 'c':if(t[2]==0)n1++;t[2]++;  break;
			case 'd':if(t[3]==0)n1++;t[3]++;  break;
			case 'e':if(t[4]==0)n1++;t[4]++;  break;
			case 'f':if(t[5]==0)n1++;t[5]++;  break;
			case 'g':if(t[6]==0)n1++;t[6]++;  break;
			case 'h':if(t[7]==0)n1++;t[7]++;  break;
			case 'i':if(t[8]==0)n1++;t[8]++;  break;
			case 'j':if(t[9]==0)n1++;t[9]++;  break;
			case 'k':if(t[10]==0)n1++;t[10]++; break;
			case 'l':if(t[11]==0)n1++;t[11]++; break;
			case 'm':if(t[12]==0)n1++;t[12]++; break;
			case 'n':if(t[13]==0)n1++;t[13]++; break;
			case 'o':if(t[14]==0)n1++;t[14]++; break;
			case 'p':if(t[15]==0)n1++;t[15]++; break;
			case 'q':if(t[16]==0)n1++;t[16]++; break;
			case 'r':if(t[17]==0)n1++;t[17]++; break;
			case 's':if(t[18]==0)n1++;t[18]++; break;
			case 't':if(t[19]==0)n1++;t[19]++; break;
			case 'u':if(t[20]==0)n1++;t[20]++; break;
			case 'v':if(t[21]==0)n1++;t[21]++; break;
			case 'w':if(t[22]==0)n1++;t[22]++; break;
			case 'x':if(t[23]==0)n1++;t[23]++; break;
			case 'y':if(t[24]==0)n1++;t[24]++; break;
			case 'z':if(t[25]==0)n1++;t[25]++; break;
		}							 
	}								 
	*n = n1;						 
	int* w = (int*)malloc(n1 * sizeof(int));
	*ch = (char*)malloc(n1 * sizeof(char));
	for (int i = 0,j = 0; i < n1; i++)
	{								 
		while (t[j]==0)				 
		{							 
			j++;					 
		}							 
		w[i] = t[j];				 
		(*ch)[i] = j + 97;			 
		printf("%c:%d ", (*ch)[i], t[j]);
		j++;						 
	}
	printf("\n");
	return w;
}
HuffmanTree get_HuffmanTree(int* w, int n) {

	if (n <= 1) {
		HuffmanTree ht = (HuffmanTree)malloc(sizeof(HTNode));
		ht->weight = *w;
		ht->lchild = -1;
		ht->rchild = -1;
		ht->parent = -1;
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
	return ht;
}

void select(HuffmanTree ht, int n, int* s1, int* s2) {
	int min1 = 2147483647, min2 = 2147483647;
	*s1 = *s2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (ht[i].parent == -1) {

			if (ht[i].weight <= min1) {
				min2 = min1;
				*s2 = *s1;
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
