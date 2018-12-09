#include <cstdio>

int a[100+5][100+5]={0},b[100+5][100+5]={0},f[100+5][100+5]={0};
int N,M;

int main() {
	scanf("%d%d",&N,&M);
	int n,m;
	for(n=1;n<=N;n++) {
		for(m=1;m<=M;m++) {
			scanf("%d",&a[n][m]);
			b[n][m]=a[n][m]+b[n][m-1]+b[n-1][m]-b[n-1][m-1];
		}
	}
	int i,j;
	int max=0;
	for(n=1;n<=N;n++) {
		for(m=1;m<=M;m++) {
			if(!a[n][m]) {
				continue;
			}
			f[n][m]=1;
			max=max>f[n][m]?max:f[n][m];
			for(i=n+1,j=m+1;i<=N&&j<=M;i++,j++) {
				if(b[i][j]+b[n-1][m-1]-b[i][m-1]-b[n-1][j]==(i-n+1)*(i-n+1)) {
					f[i][j]=f[i-1][j-1]+1;
					max=max>f[i][j]?max:f[i][j];
				} else {
					break;
				}
			}
		}
	}
	printf("%d\n",max);
	return 0;
}
