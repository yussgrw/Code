#include <cstdio>

inline void print(char *A, char *B, int *depth) {
	printf("Move %d From %c To %c\n",*depth,*A,*B);
}

void hnt(char A, char B, char C, int depth) {
	if(depth==1) {
		print(&A,&B,&depth);
	} else {
		hnt(A,C,B,depth-1);
		print(&A,&B,&depth);
		hnt(C,B,A,depth-1);
	}
}

int main() {
	int N;
	hnt('A','B','C',scanf("%d",&N)?N:0);
	return 0;
}
