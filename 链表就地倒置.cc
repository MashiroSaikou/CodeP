#include "iostream"
#include "stdlib.h"
using namespace std;
typedef struct _Node{
	int data;
	_Node *next;
}Node;
typedef struct _List{
	_Node *listHead;
	_Node *listTail;
}List;
List *head = new List;
Node* reverse(Node *pNode){
	if(pNode->next == NULL){
		head->listHead = pNode;
		return pNode;
	}
	Node *pNodeNext = reverse(pNode->next);
	pNodeNext->next = pNode;
	pNode->next = NULL;
	return pNode;
}

void nodePrint(){
	for(head->listTail = head->listHead;head->listTail != NULL;head->listTail = head->listTail->next){
		cout<<head->listTail->data<<' ';
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	head->listHead = NULL;
	head->listTail = head->listHead;

	for (int i = 0; i < 10; ++i){
		Node *p = (Node*)malloc(sizeof(Node));
		p->data = i;
		p->next = NULL;
		if(i == 0) head->listHead = p;
		else {
			head->listTail->next = p;
		}
		head->listTail = p;
	}
	nodePrint();
	Node *fake = reverse(head->listHead);
	nodePrint();
	return 0;
}
