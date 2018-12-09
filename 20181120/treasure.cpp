#include <cstdio>

long long f[1<<13][15],w[1<<13][15];
int N,M;
long long dis[15][15];

long long min(long long i1, long long i2) {
	return i1<i2?i1:i2;
}

void read() {
	scanf("%d%d",&N,&M);
	int n,m;
	for(n=1;n<=N;n++) {
		for(m=n+1;m<=N;m++) {
			dis[n][m]=0x7fffffffll;
			dis[m][n]=0x7fffffffll;
		}
		dis[n][n]=0ll;
	}
	long long x,y,z;
	for(m=1;m<=M;m++) {
		scanf("%lld%lld%lld",&x,&y,&z);
		dis[x][y]=min(dis[x][y],z);
		dis[y][x]=dis[x][y];
	}
}

void run() {
	int i,j,k;
	for(i=1;i<(1<<N);i++) {
		for(k=1;k<=N;k++) {
			w[i][k]=0x7fffffffll;
			int tmp=i,n=1;
			while(tmp>0) {
				if(tmp&1) {
					w[i][k]=min(w[i][k],dis[k][n]);
				}
				tmp>>=1;
				n++;
			}
		}
	}
	for(i=1;i<(1<<N);i++) {
		f[i][0]=0x7fffffffll;
		for(k=1;k<=N;k++) {
			f[i][k]=0x7fffffffll;
		}
		if(!(i&(i-1))) {
			f[i][1]=0;
		}
		for(j=i&(i-1);j;j=(j-1)&i) {
			int tmp=i-j;
			long long len=0ll;
			k=1;
			while(tmp>0) {
				if(tmp&1) {
					len+=w[j][k];
				}
				tmp>>=1;
				k++;
			}
			for(k=1;k<=N;k++) {
				f[i][k]=min(f[i][k],f[j][k-1]+(k-1)*len);
			}
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
