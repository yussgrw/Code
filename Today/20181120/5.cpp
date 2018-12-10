#include <cstdio>

int a[20];
long long f[1<<17][17]={0ll};
int N,M;

void read() {
	scanf("%d%d",&N,&M);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
		f[1<<(n-1)][n]=1;
	}
}

int abs(int x) {
	return x<0?-x:x;
}

void dp() {
	int i,n,tmp,tmp2,j,k;
	for(i=1;i<(1<<N);i++) {
		if(i&(i-1)) {
			tmp=i;
			n=1;
			while(tmp) {
				if(tmp&1) {
					j=i-(1<<(n-1));
					tmp2=j;
					k=1;
					while(tmp2) {
						if(tmp2&1) {
							if(abs(a[n]-a[k])>M) {
								f[i][n]+=f[j][k];
							}
						}
						tmp2>>=1;
						k++;
					}
				}
				tmp>>=1;
				n++;
			}
		}
	}
	long long res=0;
	for(n=1;n<=N;n++) {
		res+=f[(1<<N)-1][n];
	}
	printf("%lld\n",res);
}

int main() {
	read();
	dp();
	return 0;
}
