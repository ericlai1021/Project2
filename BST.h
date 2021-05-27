#include <stdlib.h>
//#include <stdio.h>

typedef struct tnode{
	int key;
	struct tnode *left;
	struct tnode *right;
}tnode;

tnode* BST_build(int key, tnode *cur){
    if(cur != NULL){
        if(key < cur->key) cur->left = BST_build(key, cur->left);
        else if(key > cur->key) cur->right = BST_build(key, cur->right);
    }
    else{
        cur =(tnode *) malloc(sizeof(tnode));
        cur->key = key;
        cur->left = NULL;
        cur->right = NULL;
    }
    return cur;
}

void BST_search(int num, tnode *cur){
    while(cur){
        if(num == cur->key){
			//printf("find: %d\n", cur->key);
			return;
		}
        if(num < cur->key) cur = cur->left;
        else if(num > cur->key) cur = cur->right;
    }
    return;
}