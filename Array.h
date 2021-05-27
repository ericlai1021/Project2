#include <stdio.h>
#define MAX 1000000 // 1e6

int arrayData[MAX];

void array_build(int data[], int N){
	int i;
	for(i=0; i<N; i++){
		arrayData[i] = data[i];
	}
}

void array_search(int num, int N){
	int i;
	for(i=0; i<N; i++){
		if(num == arrayData[i]){
			//printf("find: %d\n", arrayData[i]);
			break;
		}
	}
}
