/*
 ============================================================================
 Name        : BasicAlgorithmsWithC.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_VEXTEX_NUM 20
typedef struct ArcNode {
	int adjVexPostion; // 弧所指向的节点在“顶点表”中的下标（从0开始）
//	int weight;        //弧的权重
	struct ArcNode *nextArcNode;        //指向下一个ArcNode的指针
} ArcNode;

typedef struct VexNode {
	char vexValue;
	ArcNode *firstArcNode;
} VexNode, VexNodeList[MAX_VEXTEX_NUM];

typedef struct {
	VexNodeList vexNodeList;
	int vexNum;	//顶点个数
	int arcNum; //弧的个数
} ALGraph;
/**
 * 功能：
 *    返回某节点所指向的第一个节点在“顶点表”中的位置
 *
 * ALGraph alg:
 *    存储结构为邻接表的图
 *
 *    如果第一个弧是由节点A指向节点B
 * int vexPosition：
 *     A在“顶节点”表中的下标
 * 返回值：
 *     A所指的第一个节点，即B在“顶点表”中的下标
 */
int findFirst(ALGraph alg, int vexPosition) {
	return ((alg.vexNodeList[vexPosition]).firstArcNode)->adjVexPostion;
}

int main(void) {
	int i;
	ALGraph alg;

	//建立“顶点表”
	printf("建立“顶点表”\n");
	printf("输入顶点个数（<=20:\n");
	scanf("%d", &alg.vexNum);
	for (i = 0; i < alg.vexNum; i++) {
		printf("输入第%d个顶点的值：\n", i);
		getchar();
		alg.vexNodeList[i].vexValue = getchar();
		alg.vexNodeList[i].firstArcNode = NULL;
	}

	//建立弧结点构成的链表
	printf("建立弧结点构成的链表\n");
	printf("输入弧的个数\n");
	scanf("%d", &alg.arcNum);
	int k;
	for (k = 0; k < alg.arcNum; ++k) {
		char a, b;
		int i, j;
		printf("输入弧ai->bj,a,b分别为节点的值，i,j分别为节点在“节点表”中的下标:\n");
		printf("注意输入格式为  \"i,j\" (不包括双引号):\n");
		scanf("%d,%d", &i, &j);
		ArcNode *p = (ArcNode*) malloc(sizeof(ArcNode));
		p->adjVexPostion = j;
		p->nextArcNode = alg.vexNodeList[i].firstArcNode;
		alg.vexNodeList[i].firstArcNode = p;
	}
	printf("邻接表结构如下：\n");
	for (i = 0; i < alg.vexNum; i++) {
		printf("%c ->", alg.vexNodeList[i].vexValue);
		ArcNode *p = (ArcNode *) malloc(sizeof(ArcNode));
		p = alg.vexNodeList[i].firstArcNode;
		while (p != NULL) {
			printf("%d ->", p->adjVexPostion);
			p = p->nextArcNode;
		}

		printf("NULL\n");
	}
	return 0;
}
