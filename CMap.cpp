#include "CMap.h"
#include <iostream>
#include <vector>
using namespace std;
CMap::CMap(int capacity){
	m_iCapacity=capacity;
	m_iNodecount=0;
	m_pNodeArray=new Node[m_iCapacity];
	m_pMatrix=new int[m_iCapacity *m_iCapacity];
	memset(m_pMatrix,0,m_iCapacity *m_iCapacity *sizeof(int));
	/*for(int i=0;i<m_iCapacity*m_iCapacity;i++){
		m_pMatrix[i]=0;
	}*/
}
CMap::~CMap(){
	delete []m_pNodeArray;
	delete []m_pMatrix;
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
bool CMap::setValueToMatrixForDirectedGraph(int row,inr col,int val=1){
	if(row<0||row>m_iCapacity){
		return false;
	}
	if(col<0||col>m_iCapacity){
		return false;
	}
	m_pMatrix[row *m_iCapacity+col]=val;
	return true;
}
bool CMap::setValueToMatrixForDirectedGraph(int row,inr col,int val=1){
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
		for(k-0;k<m_iCapacity;k++){
			cout<<m_pMatrix[i*m_iCapacity+k]<<" ";
		}
		cout<<endl;
	}
}
bool CMap::getValueFromMatrix(int row,inr col,int &val){
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
	breadthFirstTraverseImpl(vurVec);
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