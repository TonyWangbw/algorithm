#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int weight;
	int parent, lchild, rchild;
} HTNode, *HuffmanTree;	//��̬���飬Ԫ��ΪHTNode
typedef char** HuffmanCode;	//�����ÿһ��Ԫ�ض���һ�����룬��char*��ʽ�洢���ַ���

void Init_weight(int **w, int n) {
	while(!(*w=(int*)malloc((n+1)*sizeof(int))));
}

void Create_Weight(int n, int *w) {
	int i, data;
	for(i = 1; i<=n; i++) {
		scanf("%d", &data);
		w[i] = data;
	}
}

//��ʼ����������
void Init_HuffmanTree(HuffmanTree *HT,int *w, int n) {
	int i;
	int m = 2*n-1;
	HTNode *p;
	while(!((*HT)=(HTNode*)malloc(sizeof(HTNode)*(m+1))));
	for(p = (*HT)+1, i=1; i<=n; i++, p++) {
		p->weight = w[i];
		p->parent = 0;
		p->rchild = 0;
		p->lchild = 0;
	}
	for(; i<=m; i++, p++) {
		p->lchild = 0;
		p->parent = 0;
		p->rchild = 0;
		p->weight = 0;
	}
}

//����ѡ������ѭ��һ�εõ���С������ֵ��
//��HT��ѡ��parentΪ0����Ȩ����С�������ڵ㣬�������ǵ������±�ֱ�Ϊs1��s2
void Select(HuffmanTree HT, int i, int *s1, int *s2) {
	//**************begin********************
	s1=(int *)malloc(sizeof(int));
	s2=(int *)malloc(sizeof(int));
		int min1=1000,min2=1000;
	for(int j=1; j<i; j++) {
		if(HT[j].parent==0) {
			if(HT[j].weight<min1) {
				min1=HT[j].weight;
				s1=&(HT[j].weight);
			}
			if(min1<min2) {
				int t;
				t=min1;
				min1=min2;
				min2=t;
				int *y;
				y=s2;
				s2=s1;
				s1=y;
			}
		}
	}

	//****************end******************
}

//������������
void Create_HuffmanTree(HuffmanTree HT,int n) {
	//**************begin********************
	int *s1,*s2;
	for(int i=n+1; i<=2*n+1; i++) {
		Select(HT,i-1,s1, s2);
		/*��s1��s2Ϊ�±�Ľ���˫����i��
		s1��s2���±꿿ǰ����i�������ӣ���һ��Ϊ�Һ���*/
		HT[i].weight=HT[*s1].weight+HT[*s2].weight;
		HT[*s1].parent=HT[i].weight;
		HT[*s2].parent=HT[i].weight;
		HT[i].lchild =HT[*s1].weight;
		HT[i].rchild =HT[*s2].weight;
	}

	//****************end******************
}

//��ʼ�������������
void Init_HuffmanCode(HuffmanCode *HC,int n) {
	while(!((*HC) = (HuffmanCode)malloc((n+1)*sizeof(char*))));
}

//�����������
void GetHuffmanCode(HuffmanCode HC, HuffmanTree HT, int n) {
	//**************begin********************

	for(int i=1; i<n; i++) {
		int start = n-1;
		//��ǰ����������е�λ��
		int c = i;
		//��ǰ���ĸ�����������е�λ��
		int j = HT[i].parent;
		// һֱѰ�ҵ������
		while(j != 0) {
			// ����ý���Ǹ������������Ӧ·������Ϊ0������Ϊ�Һ��ӱ���Ϊ1
			if(HT[j].lchild==HT[c].parent)
				HC[i][--start] = '0';
			else
				HC[i][--start] = '1';
			//�Ը����Ϊ���ӽ�㣬�����������ķ������
			c = j;
			j = HT[j].parent;
		}
	}
	//****************end******************
}

//��ӡ�����������
void PrintCode(HuffmanCode HC, int n) {
	for(int i=1; i<=n; i++) {
		printf("%s\n", HC[i]);
	}
}

void Destory(HuffmanTree *HT, HuffmanCode *HC) {
	free(*HC);
	free(*HT);
}
int main() {
	HuffmanTree HT;
	HuffmanCode HC;
	int *w, n;

	scanf("%d", &n);

	//��ʼ��Ȩ������
	Init_weight(&w, n);


	//����Ȩֵ����
	//n��ʾȨֵ����
	Create_Weight(n, w);


	//��ʼ����������
	Init_HuffmanTree(&HT, w, n);

	//������������
	Create_HuffmanTree(HT, n);

	//��ʼ�������������
	Init_HuffmanCode(&HC, n);

	//�����������
	GetHuffmanCode(HC, HT, n);

	//��ӡ�����������
	PrintCode(HC, n);

	//�ͷſռ�
	Destory(&HT, &HC);


	return 0;
}
/*
8
5 29 7 8 14 23 3 11
*/
