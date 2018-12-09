#include <cstdio>
int N,M,T;

int max(int i1, int i2) {
	return i1<i2?i2:i1;
}

int a[200+5],b[200+5],f[200+5][200+5]={0};

int main() {
	scanf("%d%d%d",&N,&M,&T);
	int n,m,t;
	for(n=1;n<=N;n++) {
		scanf("%d%d",&a[n],&b[n]);
		for(m=M;m>=a[n];m--) {
			for(t=T;t>=b[n];t--) {
				f[m][t]=max(f[m-a[n]][t-b[n]]+1,f[m][t]);
			}
		}
	}
	printf("%d\n",f[M][T]);
	return 0;
}
