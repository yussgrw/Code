#include <cstdio>

int a[100],f[100][100]={0},N;

int max(int i1, int i2) {
	return i1>i2?i1:i2;
}

void print() {
	int i,j;
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			printf("%d ",f[i][j]);
		}
		putchar('\n');
	}
}

int main() {
	scanf("%d",&N);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
	}
	int i,j,k;
	int p=1;
	for(i=1,j=N;i<=j;i++,j--) {
		p*=2;
		for(k=1;k<=i;k++) {
			f[k][i]=max(f[k-1][i-1],f[N-i+k+1][i-1])+a[k]*p;
			f[N-k+1][i]=max(f[N-k+2][i-1],f[i-k][i-1])+a[N-k+1]*p;
		}
	}
	while(i<=N) {
		p<<=1;
		for(k=1;k<=N;k++) {
			f[k][i]=max(f[k-1][i-1],f[N-i+k+1][i-1])+a[k]*p;
		}
		i++;
	}
	print();
	int max=0;
	for(n=1;n<=N;n++) {
		max=max>f[n][N]?max:f[n][N];
	}
	printf("%d\n",max);
	return 0;
}
