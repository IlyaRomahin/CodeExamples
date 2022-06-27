#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j) {
	int t = *i;
	*i = *j;
	*j = t;
}

void sift_down(int *mas, int i, int n) {
	int max_child;
	while (i * 2 + 1 < n) {
		if ((i * 2 + 1 == n - 1) || (mas[i * 2 + 1] > mas[i * 2 + 2]))
			max_child = i * 2 + 1;
		else
			max_child = i * 2 + 2;
		if (mas[i] < mas[max_child]) {
			swap(&mas[i], &mas[max_child]);
			i = max_child;
		}
		else
			break;
	}
}

void heap_sort(int *mas, int n) {
	int i = 0;
	for (i = n / 2 - 1; i >= 0; --i)
		sift_down(mas, i, n);
	for (i = n - 1; i > 0; --i) {
		swap(&mas[0], &mas[i]);
		sift_down(mas, 0, i);
	}
}


int main(){
	int i = 0;
	int N = 0;
	scanf("%d\n", &N);
	int *mas = malloc(sizeof(int)*N);
	for (i = 0; i < N; ++ i){
		scanf("%d", &mas[i]);
	}
	heap_sort(mas, N);
	for (i = 0; i < N; ++i){
		printf("%d ", mas[i]);
	}
	printf("\n");
	free(mas);
	return 0;
}