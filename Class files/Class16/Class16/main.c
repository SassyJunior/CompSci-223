#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	int data;
	struct node *next;
}Node, *NodePtr;

typedef struct list{
	struct node *head;
	struct node *tail;
}List, *ListPtr;

void insert(struct list *l, int x){
	if (l->tail != NULL){
		l->tail->next = (NodePtr)malloc(sizeof(struct node));
		l->tail->next->data = x;
		l->tail->next->next = NULL;
		l->tail = l->tail->next;
	}
	else{
		l->head = (NodePtr)malloc(sizeof(struct node));
		l->head->data = x;
		l->tail = l->head;
		l->head->next = NULL;
	}
}

void delete(struct list *l, int x){
	NodePtr temp, temp2;
	if (l->head == NULL){
		return;
	}
	if (l->head == l->tail){
		if (l->head->data == x){
			free(l->head);
			l->head = l->tail = NULL;
		}
		return;
	}
	temp = l->head;
	while (temp->next != NULL&&temp->next->data != x){
		temp = temp->next;
	}
	if (temp->next == NULL&&temp->next->data != x){
		if (temp->next != l->tail){
			temp2 = temp->next->next;
			free(temp->next);
			temp->next = temp2;
		}
		else{
			l->tail = temp;
			free(temp->next);
			temp->next = NULL;
		}
	}
	if (l->head->data = x){
		temp = l->head->next;
		free(l->head);
		l->head = temp;
	}
}

void main(){
	ListPtr l = (ListPtr)mallock(sizeof(List));
	l->head = NULL;
	l->tail = NULL;
	insert(l, 17);
}