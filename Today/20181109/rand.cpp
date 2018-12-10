#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));
	int N,M,S;
	N=5;M=20;
	S=rand()%N+1;
	int i,j;
	do {
		i=rand()%N+1;
	} while(i==S);
	printf("%d %d %d\n",N,M,S);
	printf("%d %d %d\n",S,i,rand()%65536+1);
	int m;
	for(m=1;m<M;m++) {
		i=rand()%N+1;
		do {
			j=rand()%N+1;
		} while(j==i);
		printf("%d %d %d\n",i,j,rand()%65536+1);
	}
	return 0;
}
