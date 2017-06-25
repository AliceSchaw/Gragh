#include "CMap.h"
#include <iostream>
#include <vector>
using namespace std;
CMap::CMap(int capacity){
	m_iCapacity=capacity;
	m_iNodeCount=0;
	m_pNodeArray=new Node[m_iCapacity];
	m_pMatrix=new int[m_iCapacity *m_iCapacity];
	memset(m_pMatrix,0,m_iCapacity *m_iCapacity *sizeof(int));
	/*for(int i=0;i<m_iCapacity*m_iCapacity;i++){
		m_pMatrix[i]=0;
	}*/

	m_pEdge=new Edge[m_iCapacity-1];

}
CMap::~CMap(){
	delete []m_pNodeArray;
	delete []m_pMatrix;
	delete []m_pEdge;
}
bool CMap::addNode(Node *pNode){
	if(pNode==NULL){
		return false;
	}
	m_pNodeArray[m_iNodeCount].m_cData=pNode->m_cData;
	m_iNodeCount++;
	return true;

}
void CMap::resetNode(){
	for(int i=0;i<m_iNodeCount;i++){
		m_pNodeArray[i].m_bIsVisited=false;
	} 
	
}
bool CMap::setValueToMatrixForDirectedGraph(int row,int col,int val){
	if(row<0||row>m_iCapacity){
		return false;
	}
	if(col<0||col>m_iCapacity){
		return false;
	}
	m_pMatrix[row *m_iCapacity+col]=val;
	return true;
}
bool CMap::setValueToMatrixForUndirectedGragh(int row,int col,int val){
	if(row<0||row>m_iCapacity){
		return false;
	}
	if(col<0||col>m_iCapacity){
		return false;
	}
	m_pMatrix[row *m_iCapacity+col]=val;
	m_pMatrix[col *m_iCapacity+row]=val;
	return true;
}
void CMap::printMatrix(){
	for(int i=0;i<m_iCapacity;i++){
		for(int k=0;k<m_iCapacity;k++){
			cout<<m_pMatrix[i*m_iCapacity+k]<<" ";
		}
		cout<<endl;
	}
}
bool CMap::getValueFromMatrix(int row,int col,int &val){
	if(row<0||row>m_iCapacity){
		return false;
	}
	if(col<0||col>m_iCapacity){
		return false;
	}
	val=m_pMatrix[row *m_iCapacity+col];
	
	return true;
}
void CMap::depthFirstTraverse(int nodeIndex){
	int value=0;
	cout<<m_pNodeArray[nodeIndex].m_cData<<" ";
	m_pNodeArray[nodeIndex].m_bIsVisited=true;
	for(int i=0;i<m_iCapacity;i++){
		getValueFromMatrix(nodeIndex,i,value);
		if(value!=0){
			if(m_pNodeArray[i].m_bIsVisited){
				continue;
			}
			else
			{
				depthFirstTraverse(i);
			}
		}
		else{
			continue;
		}
	}
}
void CMap::breadthFirstTraverse(int nodeIndex){
	cout<<m_pNodeArray[nodeIndex].m_cData<<" ";
	m_pNodeArray[nodeIndex].m_bIsVisited=true;
	vector<int> curVec;
	curVec.push_back(nodeIndex);
	breadthFirstTraverseImpl(curVec);
}
void CMap::breadthFirstTraverseImpl(vector<int> preVec){
	int value=0;
	vector<int> curVec;
	for(int j=0;j<(int)preVec.size();j++){
		for(int i=0;i<m_iCapacity;i++){
			getValueFromMatrix(preVec[j],i,value);
			if(value!=0){
				if(m_pNodeArray[i].m_bIsVisited){
					continue;
				}
				else{
					cout<<m_pNodeArray[i].m_cData<<" ";
					m_pNodeArray[i].m_bIsVisited=true;

					curVec.push_back(i);
				}
			}
		}
	}
	if(curVec.size()==0){
		return;
	}
	else{
		breadthFirstTraverseImpl(curVec);
	}
}

//PrimTree
void CMap::primTree(int nodeIndex){
	int value=0;
	int edgeCount=0;
	vector<int> nodeVec;
	vector<Edge> edgeVec;

	cout<<m_pNodeArray[nodeIndex].m_cData<<endl;

	nodeVec.push_back(nodeIndex);
	m_pNodeArray[nodeIndex].m_bIsVisited=true;//标志为已访问
	//
	while(edgeCount<m_iCapacity-1){
		int temp=nodeVec.back();//取最尾部元素
		for(int i=0;i<m_iCapacity;i++){
			getValueFromMatrix(temp,i,value);
			if(value==0){
				continue;
			}
			else{
				if(m_pNodeArray[i].m_bIsVisited)
					{continue;}
				else{
					Edge edge(temp,i,value);
					edgeVec.push_back(edge);
				}
			}

		}
		//从可选边集合中找出最小边
		int edgeIndex=getMinEdge(edgeVec);
		edgeVec[edgeIndex].m_bSelected=true;

		cout<<edgeVec[edgeIndex].m_iNodeIndexA<<"----"<<edgeVec[edgeIndex].m_iNodeIndexB<<" ";
		cout<<edgeVec[edgeIndex].m_iWeightValue<<endl;

		m_pEdge[edgeCount]=edgeVec[edgeIndex];
		edgeCount++;

		int nextNodeIndex=edgeVec[edgeIndex].m_iNodeIndexB;
		nodeVec.push_back(nextNodeIndex);
		m_pNodeArray[nextNodeIndex].m_bIsVisited=true;
		cout<<m_pNodeArray[nextNodeIndex].m_cData<<endl;
	}
}

int CMap::getMinEdge(vector<Edge> edgeVec){
	int minWeight=0;
	int edgeIndex=0;
	for(int i=0;i<edgeVec.size();i++){
		if(!edgeVec[i].m_bSelected){
			minWeight=edgeVec[i].m_iWeightValue;
			edgeIndex=i;
			break;//找到一个未被选中的边即跳出
		}

	}
	if(minWeight==0){
		return -1;
	}
	for(int i=0;i<edgeVec.size();i++){
		if(!edgeVec[i].m_bSelected){
			if(minWeight>edgeVec[i].m_iWeightValue){
				minWeight=edgeVec[i].m_iWeightValue;
				edgeIndex=i;
			}
		}
		else{
			continue;
		}

	}
	return edgeIndex;
		
}
//kruskalTree
void CMap::kruskalTree(){
	int value=0;
	int edgeCount=0;
	//定义存放结点集合的数组
	vector<vector<int> > nodeSets;
	//取出所有边
	vector<Edge> edgeVec;
	for(int i=0;i<m_iCapacity;i++){
		for(int k=i+1;k<m_iCapacity;k++)
		{
			getValueFromMatrix(i,k,value);
			if(value!=0)
			{
				Edge edge(i,k,value);
				edgeVec.push_back(edge);
			}
		}
	}
	//1.结束条件
	while(edgeCount<m_iCapacity-1){
		//2.从边集合找最小边
		int minEdgeIndex=getMinEdge(edgeVec);
		edgeVec[minEdgeIndex].m_bSelected=true;
		//3.找最小边连接的点
		int nodeAIndex=edgeVec[minEdgeIndex].m_iNodeIndexA;
		int nodeBIndex=edgeVec[minEdgeIndex].m_iNodeIndexB;

		bool nodeAIsInset=false;
		bool nodeBIsInset=false;

		int nodeAInsetLabel=-1;
		int nodeBInsetLabel=-1;

		//4.找点所在的点集合
		for(int i=0;i<(int)nodeSets.size();i++)
		{
			nodeAIsInset=isInset(nodeSets[i],nodeAIndex);
			if(nodeAIsInset){
				nodeAInsetLabel=i;
			}
		}
		for(int i=0;i<(int)nodeSets.size();i++)
		{
			nodeBIsInset=isInset(nodeSets[i],nodeBIndex);
			if(nodeBIsInset){
				nodeBInsetLabel=i;
			}
		}
		//5.根据点所在集合不同做不同处理
		if(nodeAInsetLabel==-1&&nodeBInsetLabel==-1)
		{
			vector<int> vec;
			vec.push_back(nodeAIndex);
			vec.push_back(nodeBIndex);
			nodeSets.push_back(vec);
		}
		else if(nodeAInsetLabel==-1&&nodeBInsetLabel!=-1)
		{
			nodeSets[nodeBInsetLabel].push_back(nodeAIndex);
		}
		else if(nodeBInsetLabel==-1&&nodeAInsetLabel!=-1)
		{
			nodeSets[nodeAInsetLabel].push_back(nodeBIndex);
		}
		else if(nodeBInsetLabel!=-1&&nodeAInsetLabel!=-1&&nodeAInsetLabel!=nodeBInsetLabel)
		{
			mergeNodeSet(nodeSets[nodeAInsetLabel],nodeSets[nodeBInsetLabel]);
			for(int k=nodeBInsetLabel;k<(int)nodeSets.size()-1;k++){
				nodeSets[k]=nodeSets[k+1];
			}
		}
		else if(nodeBInsetLabel!=-1&&nodeAInsetLabel!=-1&&nodeAInsetLabel==nodeBInsetLabel)
		{
			continue;
		}
		m_pEdge[edgeCount]=edgeVec[minEdgeIndex];
		edgeCount++;

		cout<<edgeVec[minEdgeIndex].m_iNodeIndexA<<"----"<<edgeVec[minEdgeIndex].m_iNodeIndexB<<" ";
		cout<<edgeVec[minEdgeIndex].m_iWeightValue<<endl;
	}
}

bool CMap::isInset(vector<int> nodeSets,int target){
	for(int i=0;i<nodeSets.size();i++){
		if(nodeSets[i]==target){
			return true;
		}
	}
	return false;
}
void CMap::mergeNodeSet(vector<int> &nodeSetA,vector<int> nodeSetB){
	for(int i=0;i<nodeSetB.size();i++){
		nodeSetA.push_back(nodeSetB[i]);
	}
}