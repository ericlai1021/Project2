#include "Linked_list.h"
#include "Array.h"
#include "BS.h"
#include "BST.h"
#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX 1000000 // 1e6

int data[MAX];
int query[MAX];

void CreatData(int N, int M){
	srand(time(NULL));
	int i, j;
	
	for(i = 0; i<N; i++){
		int flag = 0;
		data[i] = rand();
		for(j = 0; j<i; j++){
			if(data[i] == data[j]){
				flag = 1;
				break;
			}
		}
		if(flag) i--;
	}
	for(i = 0; i<M; i++){
		int flag = 0;
		query[i] = rand();
		for(j = 0; j<i; j++){
			if(query[i] == query[j]){
				flag = 1;
				break;
			}
		}
		if(flag) i--;
	}
}

int main(int argc, char *argv[]){
	int i, j;
	int N , M;
	struct timeval start;
	struct timeval end;
	long period;
	
	// 處理N的科學記號
	char temp1[8], temp2[8];
	strcpy(temp1, argv[2]);
	char *ptr = temp1;
	char *qtr = temp2;
	while(*ptr != 'e' && *ptr != '\0'){
		*qtr++ = *ptr++;
	}
	*qtr = '\0';
	if(*ptr == 'e'){
		float num1 = atof(temp2);
		ptr++;
		int num2 = atoi(ptr);
		for(i = 0; i<num2; i++){
			num1 = num1*10;
		}
		N =(int) num1;
	}
	else{
		N = atoi(temp2);
	}
	printf("N: %d\n", N);
	
	// 處理M的科學記號
	memset(temp2, 0, sizeof(temp2));
	strcpy(temp1, argv[4]);
	ptr = temp1;
	qtr = temp2;
	while(*ptr != 'e' && *ptr != '\0'){
		*qtr++ = *ptr++;
	}
	*qtr = '\0';
	if(*ptr == 'e'){
		float num1 = atof(temp2);
		ptr++;
		int num2 = atoi(ptr);
		for(i = 0; i<num2; i++){
			num1 = num1*10;
		}
		M =(int) num1;
	}
	else{
		M = atoi(temp2);
	}
	printf("M: %d\n", M);
	
	// 產生不重複的亂數
	CreatData(N, M);
	
	for(i = 5; i<argc; i++){
		if(strcmp(argv[i], "-bst") == 0){
			printf("bst\n");
			gettimeofday(&start, NULL);
			tnode *head = NULL;
			for(j = 0; j<N; j++){
				head = BST_build(data[j], head);
			}
			gettimeofday(&end, NULL);
			period = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("building time: %ld usec\n", period);
			
			gettimeofday(&start, NULL);
			for(j = 0; j<M; j++){
				BST_search(query[j], head);
			}
			gettimeofday(&end, NULL);
			period = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("query time: %ld usec\n\n", period);
		}
		else if(strcmp(argv[i], "-bs") == 0){
			printf("bs\n");
			gettimeofday(&start, NULL);
			bs_build(data, N);
			gettimeofday(&end, NULL);
			period = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("building time: %ld usec\n", period);
			
			gettimeofday(&start, NULL);
			for(j = 0; j<M; j++){
				bs_search(query[j], 0, N);
			}
			gettimeofday(&end, NULL);
			period = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("query time: %ld usec\n\n", period);
		}
		else if(strcmp(argv[i], "-arr") == 0){
			printf("arr\n");
			gettimeofday(&start, NULL);
			array_build(data, N);
			gettimeofday(&end, NULL);
			period = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("building time: %ld usec\n", period);
			
			gettimeofday(&start, NULL);
			for(j = 0; j<M; j++){
				array_search(query[j], N);
			}
			gettimeofday(&end, NULL);
			period = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("query time: %ld usec\n\n", period);
		}
		else if(strcmp(argv[i], "-ll") == 0){
			printf("ll\n");
			gettimeofday(&start, NULL);
			lnode *head = NULL;
			head = linked_list_bulid(data, N, head);
			gettimeofday(&end, NULL);
			period = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("building time: %ld usec\n", period);
			
			gettimeofday(&start, NULL);
			for(j = 0; j<M; j++){
				linked_list_search(query[j], head);
			}
			gettimeofday(&end, NULL);
			period = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("query time: %ld usec\n\n", period);
		}
		else if(strcmp(argv[i], "-hash") == 0){
			printf("hash\n");
			// initial hashTable
			for(j = 0; j<MAX_HASH_SIZE; j++){
				hashTable[j] = -1;
			}
			gettimeofday(&start, NULL);
			for(j = 0; j<N; j++){
				Hash_build(data[j]);
			}
			gettimeofday(&end, NULL);
			period = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("building time: %ld usec\n", period);
			
			gettimeofday(&start, NULL);
			for(j = 0; j<M; j++){
				Hash_search(query[j]);
			}
			gettimeofday(&end, NULL);
			period = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
			printf("query time: %ld usec\n\n", period);
		}
	}
	
	return 0;
}
