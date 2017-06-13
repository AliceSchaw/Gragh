#include <iostream>
#include <stdlib.h>
#include "CMap.h"
using namespace std;
int main(void){
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

	system("pause");
	return 0;
}