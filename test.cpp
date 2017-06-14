#include <iostream>
#include <stdlib.h>
#include "CMap.h"
using namespace std;
/*图的存储与遍历
	A
   / \
  B   D
 /\   /\
C  F G——H
 \/
  E

   A B C D E F G H
 A 0 1 0 1 0 0 0 0
 B 1 0 1 0 0 1 0 0
 C 0 1 0 0 1 0 0 0
 D 1 0 0 0 0 0 1 1
 E 0 0 1 0 0 1 0 0
 F 0 1 0 0 1 0 0 0 
 G 0 0 0 1 0 0 0 1
 H 0 0 0 1 0 0 1 0 
*/

/*最小生成树
	A
 /  |  \
B - F - E
 \ / \ /
  C - D

A-B 6	A-E 5	A-F 1
B-C 3	B-F 2
C-F 8	C-D 7
D-F 4	D-E 2
E-F 9
*/
int main(void){
	//显示及遍历
	/*
	CMap *pMap=new CMap(8);
	Node *pNodeA=new Node('A');	
	Node *pNodeA=new Node('B');
	Node *pNodeA=new Node('C');
	Node *pNodeA=new Node('D');
	Node *pNodeA=new Node('E');
	Node *pNodeA=new Node('F');
	Node *pNodeA=new Node('G');
	Node *pNodeA=new Node('H');
	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);
	pMap->addNode(pNodeG);
	pMap->addNode(pNodeH);

	pMap->setValueToMatrixForUndirectedGragh(0,1);
	pMap->setValueToMatrixForUndirectedGragh(0,3);
	pMap->setValueToMatrixForUndirectedGragh(1,2);
	pMap->setValueToMatrixForUndirectedGragh(1,5);
	pMap->setValueToMatrixForUndirectedGragh(3,6);
	pMap->setValueToMatrixForUndirectedGragh(3,7);
	pMap->setValueToMatrixForUndirectedGragh(6,7);
	pMap->setValueToMatrixForUndirectedGragh(2,4);
	pMap->setValueToMatrixForUndirectedGragh(4,5);

	pMap->printMatrix();
	cout<<endl;

	pMap->resetNode();
	pMap->depthFirstTraverse(0);

	pMap->resetNode();
	pMap->breadthFirstTraverse(0);
	*/

	CMap *pMap=new CMap(6);
	Node *pNodeA=new Node('A');	
	Node *pNodeA=new Node('B');
	Node *pNodeA=new Node('C');
	Node *pNodeA=new Node('D');
	Node *pNodeA=new Node('E');
	Node *pNodeA=new Node('F');

	pMap->addNode(pNodeA);
	pMap->addNode(pNodeB);
	pMap->addNode(pNodeC);
	pMap->addNode(pNodeD);
	pMap->addNode(pNodeE);
	pMap->addNode(pNodeF);


	pMap->setValueToMatrixForUndirectedGragh(0,1,6);
	pMap->setValueToMatrixForUndirectedGragh(0,4,5);
	pMap->setValueToMatrixForUndirectedGragh(0,5,1);
	pMap->setValueToMatrixForUndirectedGragh(1,2,3);
	pMap->setValueToMatrixForUndirectedGragh(1,5,2);
	pMap->setValueToMatrixForUndirectedGragh(2,5,8);
	pMap->setValueToMatrixForUndirectedGragh(2,3,7);
	pMap->setValueToMatrixForUndirectedGragh(3,5,4);
	pMap->setValueToMatrixForUndirectedGragh(3,4,2);
	pMap->setValueToMatrixForUndirectedGragh(4,5,9);
	//primTree
	//pMap->primTree(0);
	//kruskalTree
	pMap->kruskalTree();
	cout<<endl;


	system("pause");
	return 0;
}