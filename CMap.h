#ifndef CMAP_H
#define CMAP_H
#include <vector>
#include "Node.h"
#include "Edge.h"
using namespace std;


class CMap{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node *pNode);
	
	void resetNode();
	bool setValueToMatrixForDirectedGraph(int row,int col,int val=1);//设定有向图邻接矩阵（行，列，值）
	bool setValueToMatrixForUndirectedGragh(int row,int col,int val=1);
	void printMatrix();

	void depthFirstTraverse(int nodeIndex);//深度优先
	void breadthFirstTraverse(int nodeIndex);//广度优先

	void primTree(int nodeIndex);//普里姆生成树
	void kruskalTree();//克鲁斯卡尔生成树
private:
	bool getValueFromMatrix(int row,int col,int &value);
	void breadthFirstTraverseImpl(vector<int> preVec);
	int getMinEdge(vector<Edge> edgeVec);

	bool isInset(vector<int> nodeSets,int target);//判断点是否在集合中
	void mergeNodeSet(vector<int> &nodeSetA,vector<int> nodeSetB);//合并两个顶点集合
private:
	int m_iCapacity;
	int m_iNodeCount;
	Node *m_pNodeArray;//顶点数组
	int *m_pMatrix;//邻接矩阵

	Edge *m_pEdge;
};
#endif