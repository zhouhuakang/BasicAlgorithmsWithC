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
#include "AdjList.h"

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
int findFirstAdjNodePostion(ALGraph alg, int vexPosition) {
	return ((alg.vexNodeList[vexPosition]).firstArcNode)->adjVexPostion;
}
/**
 * 测试上一个函数
 */
void TestfindFirstAdjNodePostion() {
	int vexPosition = 0;
	ALGraph alg = createALGraph();
	printf("测试findFirstAdjNodePostion（）,请输入一个顶点的下标，将返回其第一个邻接顶点的在顶点表中的下标:\n");
	scanf("%d", &vexPosition);
	printf("vexPosition=%d的第一个邻接顶点的下表为:%d", vexPosition,
			findFirstAdjNodePostion(alg, vexPosition));
}
/**
 * 建立邻接表
 */
ALGraph createALGraph() {
	int i;
	ALGraph alg;
	int vexPosition = 0;

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
	return alg;
}
/**
 * 测试全部功能，直接可在main中调用，
 * 上面的函数只是拆分了本函数的逻辑，为了方便其他函数的调用
 * 比如DFS和BFS算法都可以引用这里的拆分之后的函数createALGraph()
 */
int testALL(void) {
	int i;
	ALGraph alg;
	int vexPosition = 0;

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

	printf("测试findFirstAdjNodePostion（）,请输入一个顶点的下标，将返回其第一个邻接顶点的在顶点表中的下标:\n");
	scanf("%d", &vexPosition);
	printf("vexPosition=%d的第一个邻接顶点的下标为:%d", vexPosition,
			findFirstAdjNodePostion(alg, vexPosition));

	return 0;
}
