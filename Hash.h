#include <stdio.h>
#define MAX_HASH_SIZE 100000

int hashTable[MAX_HASH_SIZE];

int Hash_func(int value){  
    return value % MAX_HASH_SIZE;  
}

void Hash_search(int key) {  
    int t, pos;  
    pos = Hash_func(key);  
    t = pos;  
    while(hashTable[t]!=key && hashTable[t]!=-1) {  
        t = (t+1) % MAX_HASH_SIZE;  
        if(pos==t) return;	// 如果處理完collision後的位置與原來位置相同說明hashTable裡找不到
    }  
    if(hashTable[t]!=-1){  
        //printf("find: %d\n", hashTable[t]);
		return;
	}
}

void Hash_build(int key) {  
    int pos,t;  
    pos = Hash_func(key); // Hash_func()確定元素位置
    t = pos;  
    while(hashTable[t] != -1) { // 如果該位置有元素存在則進行線性探測再散列  
        t = (t+1) % MAX_HASH_SIZE;
        if(pos == t) { // 如果處理完collision後的位置與原來位置相同說明hashTable已滿  
            //printf("Hash Table is full.\n");  
            return;  
        }  
    }  
    hashTable[t] = key;  
} 