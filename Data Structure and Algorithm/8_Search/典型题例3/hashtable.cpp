#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  m   30
#define  NULLKEY  NULL

typedef  struct
{
	char *key;
}RecordType;

typedef  RecordType  HashTable[m];

int hash(char *k)
{
	int h;
	char k0;
	k0 = k[0];
	switch(k0)
	{
	case 'a':
		h=1;
		break;
	case 'b':
		h=2;
		break;
	case 'c':
		h=3;
		break;
	case 'd':
		h=4;
		break;
	case 'e':
		h=5;
		break;
	case 'f':
		h=6;
		break;
	case 'g':
		h=7;
		break;
	case 'h':
		h=8;
		break;
	case 'i':
		h=9;
		break;
	case 'j':
		h=10;
		break;
	case 'k':
		h=11;
		break;
	case 'l':
		h=12;
		break;
	case 'm':
		h=13;
		break;
	case 'n':
		h=14;
		break;
	case 'o':
		h=15;
		break;
	case 'p':
		h=16;
		break;
	case 'q':
		h=17;
		break;
	case 'r':
		h=18;
		break;
	case 's':
		h=19;
		break;
	case 't':
		h=20;
		break;
	case 'u':
		h=21;
		break;
	case 'v':
		h=22;
		break;
	case 'w':
		h=23;
		break;
	case 'x':
		h=24;
		break;
	case 'y':
		h=25;
		break;
	case 'z':
		h=26;
		break;
	default:
		break;
	}
	return h;
}

void createhash(HashTable *ht)
{
	int i,j;
	int n;
	char p[10];
	int hj;
	for(i=0; i<m; i++)
		(*ht)[i].key = NULLKEY;
	printf("�������ϣ���Ԫ�ظ���:");
	scanf("%d",&n);
	for(i=1; i<=n; i++)
	{
		printf("�������%d��Ԫ��:",i);
		fflush(stdin);
		gets(p);
		j = hash(p);
//		printf("ok%d\n",j);
		if ((*ht)[j].key == NULLKEY)
		{
			(*ht)[j].key=(char*)malloc(10*sizeof(char));
			strcpy((*ht)[j].key,p);
//			printf("ok\n");
		}
		else
		{ 
			for (i=1; i<=m-1;  i++)
			{
				hj=(j+i) % m;
				if  ((*ht)[hj].key==NULLKEY) 
				{
					(*ht)[hj].key=(char*)malloc(10*sizeof(char));
					strcpy((*ht)[hj].key,p);
					i = m;
				}
				
			}
			
		}
		
	}
}

int  HashSearch( HashTable  ht,  char *K)
{
	int h0;
	int i;
	int hi;
	int result;
	h0=hash(K);
	if  (ht[h0].key==NULLKEY) 
		return (-1);
	else 
	{
		result = strcmp(ht[h0].key,K);
		if (result == 0) 
			return (h0);
		else   /* ������̽����ɢ�н����ͻ */
		{ 
			for (i=1; i<=m-1;  i++)
			{
				hi=(h0+i) % m;
				if  (ht[hi].key==NULLKEY) 
					return (-1);
				else
				{
					result = strcmp(ht[hi].key,K);
					if (result == 0) 
						return (hi);
				}
			}
			return (-1);
		}
	}
}

void printword(HashTable ht)
/*����һ����ĸ��˳�����ht��ϣ���еı�ʶ���������ͻ�ķ���Ϊ����̽�⿪�Ŷ�ַ��*/
{
	int i,j;
	for(i=1; i<=26; i++)
	{
		j = i;
		while(ht[j].key != NULLKEY)
		{
			if(hash(ht[j].key) == i)
				printf("%s\n",ht[j].key);
			j = (j+1)%m;
		}
	}
}

float unsucclength(HashTable ht)
/*ģ���ֹ�����ȸ��ʲ�������²��Ҳ��ɹ���ƽ�����ҳ����㷨 */
{
	int i,j;
	int	count;
	int asl = 0;
	float unasl;
	for(i=1; i<=26; i++)
	{
		j = i;
		count = 1;
		while(ht[j].key != NULLKEY)
		{
			count++;
			j=(j+1)%m;
		}
		asl = asl + count;
	}
	unasl = (float)asl/26;
	return (unasl);
}

void main()
{
//	int i,j;
	char *k;
	int result;
	HashTable ht;
	float uasLength;
	createhash(&ht);
	k = (char *)malloc(10*sizeof(char));
	printf("������Ҫ���ҵ�Ԫ��:");
	fflush(stdin);
	gets(k);
	result = HashSearch(ht,k);
	if(result == -1)
		printf("δ�ҵ�!\n");
	else
		printf("Ԫ��λ��Ϊ%d\n",result);
	printword(ht);
	uasLength = unsucclength(ht);
	printf("���ɹ���ƽ�����ҳ���Ϊ%f\n",uasLength);
}
