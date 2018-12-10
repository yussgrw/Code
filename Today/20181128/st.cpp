#include <cstdio>
#include <cmath>

int f[100000+5][18];
int N,M;

int max(int x, int y) {
	return x>y?x:y;
}

void read() {
	scanf("%d%d",&N,&M);
	int n,k;
	for(n=1;n<=N;n++) {
		scanf("%d",&f[n][0]);
	}
	for(k=1;k<=log2(N);k++) {
		for(n=1;n+(1<<k)-1<=N;n++) {
			f[n][k]=max(f[n][k-1],f[n+(1<<(k-1))][k-1]);
		}
	}
}

int query(int l, int r) {
	int k=log2(r-l+1);
	return max(f[l][k],f[r-(1<<k)+1][k]);
}

int main() {
	read();
	int m,l,r;
	for(m=1;m<=M;m++) {
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r));
	}
	return 0;
}
