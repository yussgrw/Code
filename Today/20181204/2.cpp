#include <cstdio>

long long t[35];
long long f[35][35]={0};
int g[35][35];
int N;

void read() {
	scanf("%d",&N);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%lld",&t[n]);
		f[n][n]=t[n];
		g[n][n]=n;
	}
}

void dp() {
	int i,j,k;
	int maxn;
	for(k=2;k<=N;k++) {
		for(i=1;i<=N-k+1;i++) {
			maxn=i;
			f[i][i+k-1]=f[i+1][i+k-1]+t[i];
			for(j=i+1;j<i+k-1;j++) {
				if(f[i][i+k-1]<f[i][j-1]*f[j+1][i+k-1]+t[j]) {
					maxn=j;
					f[i][i+k-1]=f[i][j-1]*f[j+1][i+k-1]+t[j];
				}
			}
			if(f[i][i+k-1]<f[i][i+k-2]+t[i+k-1]) {
				maxn=i+k-1;
				f[i][i+k-1]=f[i][i+k-2]+t[i+k-1];
			}
			g[i][i+k-1]=maxn;
		}
	}
	printf("%lld\n",f[1][N]);
}

void print(int l, int r) {
	if(l==r) {
		printf("%d ",l);
	} else if(l<r) {
		printf("%d ",g[l][r]);
		print(l,g[l][r]-1);
		print(g[l][r]+1,r);
	}
}

int main() {
	read();
	dp();
	print(1,N);
	putchar('\n');
	return 0;
}
