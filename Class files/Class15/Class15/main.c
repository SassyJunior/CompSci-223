#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int item;
	struct node *next;
} Node, *NodePtr;

void insert(int item, NodePtr *front)
{
	NodePtr tmp;
	tmp = (NodePtr)malloc(sizeof(Node));
	tmp->item = item;
	tmp->next = *front;
	*front = tmp;
}

void freeThemAll(NodePtr front){
	if (front == NULL){
		return;
	}
	else{
		freeThemAll(front->next);
		free(front);
	}

}

void main(){
	NodePtr x;
	x = (NodePtr)malloc(sizeof(struct node));
	x->item = 27;
	x->next = (NodePtr)malloc(sizeof(struct node));
	x->next->item = 14;
	x->next->next = (NodePtr)malloc(sizeof(struct node));
	x->next->next->item = 14;
	x->next->next->next = NULL;
	//free(x->next->next);
	//x->next->next = NULL;
	insert(19, &x);
	freeThemAll(x);
}