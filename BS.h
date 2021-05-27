#include <stdio.h>
#define MAX 1000000 // 1e6

int bsData[MAX];

void bs_build(int data[], int N){ // use insertion sort
	int i, j;
	bsData[0] = data[0];
	for(i=1; i<N; i++){
		for(j = 0; j<i; j++){
			if(data[i] < bsData[j]) break;
		}
		int tmp = bsData[j];
		bsData[j] = data[i];
		for(int k = i; k>j; k--){
			bsData[k+1] = bsData[k];
		}
		bsData[j+1] = tmp;
	}
	//for(i = 0; i<N; i++) printf("%d ", bsData[i]);
	//printf("\n");
}

void bs_search(int num, int head, int tail){
	if(head > tail) return;
	int mid = (head+tail)/2;
	if(num == bsData[mid]){
		//printf("find: %d\n", bsData[mid]);
		return;
	}
	else if(num > bsData[mid]) bs_search(num, mid+1, tail);
	else bs_search(num, head, mid-1);
}
