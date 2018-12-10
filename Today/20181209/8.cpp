#include <cstdio>

int N,K;
long long a[100000+5],z[100000+5],f[2][300+5]={0ll};
long long p=1000000007;

void read() {
	scanf("%d%d",&N,&K);
	int n;
	z[0]=1;
	for(n=1;n<=N;n++) {
		scanf("%lld",&a[n]);
		a[n]%=p;
		z[n]=(z[n-1]*a[n])%p;
	}
}

void dp() {
	int i,j;
	for(i=1;i<=N;i++) {
		f[i%2][0]=1;
		for(j=1;j<=i&&j<=K;j++) {
			if(j==i) {
				f[i%2][j]=z[i];
			} else {
				f[i%2][j]=((a[i]*f[(i-1)%2][j-1])%p+f[(i-1)%2][j])%p;
			}
		}
	}
	printf("%lld\n",f[N%2][K]%p);
}

int main() {
	read();
	dp();
	return 0;
}
