#include<stdio.h>
#include<stdlib.h>

int* createDynArray(int n, int v) {
	int* a = malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i) {
		a[i] = v;
	}

	return a;
}

void reverse(int* beg, int* end) {
	if(beg == end) return;

	while(1) {
		if(beg == --end) break;

		int temp = *beg;
		*beg = *end;
		*end = temp;

		if(++beg == end) break;
	}
}

void print(int* beg, int* end) {
	for(; beg != end; ++beg) {
		printf("%d ", *beg);
	}
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);

	int* a = createDynArray(n, 0);

	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	reverse(a, a + n);
	print(a, a + n);

	free(a);
}