/*
 * AdjList.h
 *
 *  Created on: 2016年5月31日
 *      Author: zhouhuakang
 */

#ifndef GRAPH_ADJLIST_H_
#define GRAPH_ADJLIST_H_

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

int findFirstAdjNodePostion(ALGraph alg, int vexPosition);

ALGraph createALGraph();

void TestfindFirstAdjNodePostion();

#endif /* GRAPH_ADJLIST_H_ */
