#include <stdlib.h>
#include <stdio.h>

typedef struct lnode{
	int key;
	struct lnode *next;
}lnode;

lnode* linked_list_bulid(int data[], int num, lnode *cur){
	int i;
	lnode* head = cur; // initial state of cur is NULL
	lnode *pre = NULL;
	for(i = 0; i< num; i++){
		if(head != NULL){
			pre = cur;
			cur = cur->next;
		}
		// creat new lnode
		cur =(lnode *) malloc(sizeof(lnode));
		cur->key = data[i];
		cur->next = NULL;
		if(head != NULL){ pre->next = cur; }
		else{ head = cur; }
	}
	return head;
}

void linked_list_search(int num, lnode* cur){
	while(cur != NULL){
		if(num == cur->key){
			//printf("find: %d\n", cur->key);
			break;
		}
		cur = cur->next;
	}
}