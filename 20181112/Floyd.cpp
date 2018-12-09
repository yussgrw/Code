#include <cstdio>

unsigned int a[1000+5][1000+5];
int N,M,S;

unsigned int min(unsigned int i1, unsigned int i2) {
	return i1<i2?i1:i2;
}

void init() {
	scanf("%d%d%d",&N,&M,&S);
	unsigned z;
	int n,m,x,y;
	for(n=1;n<=N;n++) {
		for(m=1;m<=N;m++) {
			a[n][m]=2147483647;
		}
		a[n][n]=0;
	}
	for(m=1;m<=M;m++) {
		scanf("%d%d%u",&x,&y,&z);
		a[x][y]=min(a[x][y],z);
	}
}

void Floyd() {
	int i,j,k;
	for(k=1;k<=N;k++) {
		for(i=1;i<=N;i++) {
			for(j=1;j<=N;j++) {
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
}

void print() {
	int i;
	for(i=1;i<N;i++) {
		printf("%u ",a[S][i]);
	}
	printf("%u\n",a[S][N]);
}

int main() {
	init();
	Floyd();
	print();
	return 0;
}
