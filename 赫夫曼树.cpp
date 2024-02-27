#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int weight;
	int parent, lchild, rchild;
} HTNode, *HuffmanTree;	//动态数组，元素为HTNode
typedef char** HuffmanCode;	//编码表，每一个元素都是一个编码，即char*方式存储的字符串

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

//初始化哈夫曼树
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

//利用选择排序（循环一次得到最小的两个值）
//在HT中选择parent为0，且权重最小的两个节点，返回他们的数组下标分别为s1和s2
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

//创建哈夫曼树
void Create_HuffmanTree(HuffmanTree HT,int n) {
	//**************begin********************
	int *s1,*s2;
	for(int i=n+1; i<=2*n+1; i++) {
		Select(HT,i-1,s1, s2);
		/*以s1和s2为下标的结点的双亲是i；
		s1和s2中下标靠前的是i结点的左孩子，另一个为右孩子*/
		HT[i].weight=HT[*s1].weight+HT[*s2].weight;
		HT[*s1].parent=HT[i].weight;
		HT[*s2].parent=HT[i].weight;
		HT[i].lchild =HT[*s1].weight;
		HT[i].rchild =HT[*s2].weight;
	}

	//****************end******************
}

//初始化哈夫曼编码表
void Init_HuffmanCode(HuffmanCode *HC,int n) {
	while(!((*HC) = (HuffmanCode)malloc((n+1)*sizeof(char*))));
}

//求哈夫曼编码
void GetHuffmanCode(HuffmanCode HC, HuffmanTree HT, int n) {
	//**************begin********************

	for(int i=1; i<n; i++) {
		int start = n-1;
		//当前结点在数组中的位置
		int c = i;
		//当前结点的父结点在数组中的位置
		int j = HT[i].parent;
		// 一直寻找到根结点
		while(j != 0) {
			// 如果该结点是父结点的左孩子则对应路径编码为0，否则为右孩子编码为1
			if(HT[j].lchild==HT[c].parent)
				HC[i][--start] = '0';
			else
				HC[i][--start] = '1';
			//以父结点为孩子结点，继续朝树根的方向遍历
			c = j;
			j = HT[j].parent;
		}
	}
	//****************end******************
}

//打印哈夫曼编码表
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

	//初始化权重数组
	Init_weight(&w, n);


	//创建权值数组
	//n表示权值个数
	Create_Weight(n, w);


	//初始化哈夫曼树
	Init_HuffmanTree(&HT, w, n);

	//创建哈夫曼树
	Create_HuffmanTree(HT, n);

	//初始化哈夫曼编码表
	Init_HuffmanCode(&HC, n);

	//求哈夫曼编码
	GetHuffmanCode(HC, HT, n);

	//打印哈夫曼编码表
	PrintCode(HC, n);

	//释放空间
	Destory(&HT, &HC);


	return 0;
}
/*
8
5 29 7 8 14 23 3 11
*/
