#include "iostream"
#include "stack"
#include "string.h"
using namespace std;

typedef struct _treeNode{
	int value;
	_treeNode *left;
	_treeNode *right;
}treeNode;

/*
	前序遍历创建二叉树
	example
				1
			2		3
		4				5
			6
		7   	8
*/
//构建由先序和中序组成序列
treeNode* creatTreeByPreInandPreOrder(char *preStartPointer,char *preEndPointer, char *inStartPointer, char *inEndPointer){
	char rootInOrderValue = *preStartPointer;
	char *rootInOrder = inStartPointer;
	//初始化根节点
	treeNode *root = new treeNode();
	root->value = *preStartPointer - '0';
	root->left = NULL;
	root->right = NULL;
	//只有一个节点
	if(preStartPointer == preEndPointer&&inStartPointer == inEndPointer&&*preStartPointer == *inStartPointer){
		return root;
	}
	//查找中序中根节点位置
	while(rootInOrder<inEndPointer&&rootInOrderValue!=*rootInOrder){
		rootInOrder++;
	}
	int leftTreeLenght = rootInOrder - inStartPointer;
	int rightTreeLenght = inEndPointer - rootInOrder;
	//左子树
	if(leftTreeLenght > 0)
		root->left = creatTreeByPreInandPreOrder(preStartPointer+1,preStartPointer+leftTreeLenght,inStartPointer,rootInOrder-1);
	//右子树
	if(rightTreeLenght > 0)
		root->right = creatTreeByPreInandPreOrder(preStartPointer+1+leftTreeLenght,preEndPointer,rootInOrder+1,inEndPointer);
	return root;
}
//输入前序和中序序列
treeNode *getinPreandInOrder(){
	cout<<"PreOrder and InOrder's length:";
	int length = 0;
	cin>>length;
	getchar();
	char preOrder[length];
	char inOrder[length];
	cin.getline(preOrder,length+1,'\n');
	cin.getline(inOrder,length+1,'\n');
	return creatTreeByPreInandPreOrder(preOrder,preOrder+length-1,inOrder,inOrder+length-1);
}
//前序递归
void recursionPreTraversal(treeNode *node){
	if(node!=NULL){
		cout<<node->value<<' ';
		recursionPreTraversal(node->left);
		recursionPreTraversal(node->right);
	}
}

int main(int argc, char const *argv[]){
	treeNode *root = NULL;
	//以前序遍历的方式读取数据
	//creatTreeByPre(root);
	root = getinPreandInOrder();
//	root = creatTreeByPreInandPreOrder(preOrder,preOrder+length-1,inOrder,inOrder+length-1);
	//前序递归遍历
	cout<<"recursionPreTraversal:";
	recursionPreTraversal(root);
	cout<<endl;
	return 0;
}
