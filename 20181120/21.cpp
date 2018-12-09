#include <cstdio>

long long dis[15][15],w[1<<13][15],f[1<<13][15];
int N,M;

long long min(long long i1, long long i2) {
	return i1<=i2?i1:i2;
}

void read() {
	scanf("%d%d",&N,&M);
	long long x,y,z;
	int n,m;
	for(n=1;n<=N;n++) {
		for(m=1;m<=N;m++) {
			dis[n][m]=0x7fffffffll;
		}
		dis[n][n]=0;
	}
	for(m=1;m<=M;m++) {
		scanf("%lld%lld%lld\n",&x,&y,&z);
		dis[x][y]=min(dis[x][y],z);
		dis[y][x]=dis[x][y];
	}
}

void run() {
	int i,j,k,n,tmp;
	long long m;
	for(i=1;i<(1<<N);i++) {
		for(k=1;k<=N;k++) {
			w[i][k]=0x7fffffffll;
			tmp=i;
			n=1;
			while(tmp) {
				if(tmp&1) {
					w[i][k]=min(w[i][k],dis[n][k]);
				}
				tmp>>=1;
				n++;
			}
			printf("w[%d][%d]=%lld\n",i,k,w[i][k]);
		}
	}
	for(i=1;i<(1<<N);i++) {
		for(k=0;k<=N;k++) {
			f[i][k]=0x7fffffffll;
		}
		if(!(i&(i-1))) {
			f[i][1]=0ll;
			continue;
		}
		tmp=i;
		n=1;
		while(tmp) {
			if(tmp&1) {
				j=i-(1<<(n-1));
				for(k=2;k<=N;k++) {
					f[i][k]=min(f[j][k-1]+w[j][n]*(k-1),f[i][k]);
					printf("f[%d][%d]=%lld\n",i,k,f[i][k]);
				}
			}
			tmp>>=1;
			n++;
		}
	}
	long long res=0x7fffffffll;
	for(k=1;k<=N;k++) {
		res=min(res,f[(1<<N)-1][k]);
	}
	printf("%lld\n",res);
}

int main() {
	read();
	run();
	return 0;
}
