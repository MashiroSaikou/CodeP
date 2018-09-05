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

void creatTreeByPre(treeNode *&node){
	char c_value;
	c_value = getchar();
	if(c_value == '*'){
		node = NULL;
	}
	else{
		node = new treeNode;
		node->value = (int)(c_value-'0');
		creatTreeByPre(node->left);
		creatTreeByPre(node->right);
	}
}
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
//前序非递归
void PreTraversal(treeNode *root){
	stack<treeNode*> treeNodeStack;
	treeNode *node = root;
	//当不是叶结点或者栈为空就一直循环
	while(node != NULL||treeNodeStack.empty()==false){
		//一直寻找左子结点并入栈
		while(node!=NULL){
			cout<<node->value<<' ';
			treeNodeStack.push(node);
			node = node->left;
		}
		if(treeNodeStack.empty()!=true){
			node = treeNodeStack.top();
			treeNodeStack.pop();
			node = node->right;
		}
	}
}

//中序递归
void recursionInTraversal(treeNode *node){
	if(node!=NULL){
		recursionInTraversal(node->left);
		cout<<node->value<<' ';
		recursionInTraversal(node->right);
	}
}
//中序非递归
void InTraversal(treeNode *root){
	stack<treeNode*> treeNodeStack;
	treeNode *node = root;
	//当不是叶结点或者栈为空就一直循环
	while(node != NULL||treeNodeStack.empty()==false){
		//一直寻找左子结点并入栈
		while(node!=NULL){
			treeNodeStack.push(node);
			node = node->left;
		}
		if(treeNodeStack.empty()!=true){
			node = treeNodeStack.top();
			cout<<node->value<<' ';
			treeNodeStack.pop();
			node = node->right;
		}
	}
}
//后序递归
void recursionPostorderTraversal(treeNode *node){
	if(node!=NULL){
		recursionPostorderTraversal(node->left);
		recursionPostorderTraversal(node->right);
		cout<<node->value<<' ';
	}
}
//后序非递归
void PostorderTraversal(treeNode *root){
	stack<treeNode*> treeNodeStack;
	treeNode *node = root;
	//建立一个游标，当node->right = flag时表示右节点遍历完毕
	treeNode *flag = root;
	while(node != NULL||treeNodeStack.empty()==false){
		while(node!=NULL){
			treeNodeStack.push(node);
			node = node->left;
		}
		node = treeNodeStack.top();
		if(node->right==NULL||node->right==flag){
			cout<<node->value<<' ';
			flag = node;
			node = NULL;
			treeNodeStack.pop();
		}
		else{
			node = node->right;
		}
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
	//前序非递归遍历
	cout<<"PreTraversal:";
	PreTraversal(root);
	cout<<endl;

	//中序递归遍历
	cout<<"recursionInTraversal:";
	recursionInTraversal(root);
	cout<<endl;
	//中序非递归遍历
	cout<<"InTraversal:";
	InTraversal(root);
	cout<<endl;

	//后序递归遍历
	cout<<"recursionPostorderTraversal:";
	recursionPostorderTraversal(root);
	cout<<endl;
	//后序非递归遍历
	cout<<"PostorderTraversal:";
	PostorderTraversal(root);

	return 0;
}
