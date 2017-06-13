#include <vector>
using namespace std;
#include "Node.h"
class CMap{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node *pNode);
	void resetNode();
	bool setValueToMatrixForDirectedGraph(int row,int col,int val=1);//设定有向图邻接矩阵（行，列，值）
	bool setValueToMatrixForUndirectedGragh(int row,int col,int val=1);
	void printMatrix();
private:
	bool getValueFromMatrix(int row,int col,int &value);
	void depthFirstTraverse(int nodeIndex);
	void breadFirstTraverse(int nodeIndex);
private:
	int m_iCapacity;
	int m_iNodeCount;
	Node *m_pNodeArray;//顶点数组
	int *m_pMatrix;
}
#endif