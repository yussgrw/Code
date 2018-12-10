#include <cstdio>

int f[1<<15][15];
int map[15][15],N,M;
int a[15],b[15];

int min(int, int);

void dfs2(int now, int last, int exc, int depth, int zt) {
	b[now]=depth;
	int n;
	for(n=1;n<=N;n++) {
		b[n]=0;
	}
	int i;
	for(i=1;i<=N;i++) {
		if(zt&(1<<(i-1))) {
			if(i!=exc&&i!=last&&map[i][now]!=0x3c3c3c3c) {
				dfs2(i,now,exc,depth+1,zt);
			}
		}
	}
}

void dfs(int last, int depth, int n) {
	printf("%d %d %d\n",last,depth,n);
	if(depth<n) {
		int i;
		for(i=last+1;i<=N;i++) {
			a[depth+1]=i;
			dfs(i,depth+1,n);
		}
	} else if(depth==n) {
		int i;
		for(i=1;i<=n;i++) {
			int zt1=0,zt2=0;
			int j;
			for(j=1;j<=n;j++) {
				if(j!=i) {
					zt2+=(1<<(a[j]-1));
				}
				zt1+=(1<<(a[j]-1));
			}
			printf("zt %d %d\n",zt1,zt2);
			for(j=1;j<=N;j++) {
				f[zt1][j]=0x7fffffff;
			}
			for(j=1;j<=n;j++) {
				if(i!=j&&map[a[i]][a[j]]!=0x3c3c3c3c) {
					dfs2(j,0,i,1,zt2);
					int tmp=zt2,k=1;
					while(tmp>0) {
						if((tmp&1)&&k!=i) {
							f[zt1][k]=min(f[zt1][k],f[zt2][k]+map[a[i]][a[j]]*b[k]);
						}
						tmp>>=1;
						k++;
					}
//					f[zt1][]=min(f[zt1][],f[zt2][]+map[a[i]][a[j]]*);
				}
			}
		}
	}
}

void run() {
	int i,res=0x7fffffff;
	for(i=1;i<=N;i++) {
		dfs(0,0,i);
	}
	for(i=1;i<=N;i++) {
		res=min(res,f[(1<<N)-1][i]);
	}
	printf("%d\n",res);
}

int min(int i1, int i2) {
	return i1<i2?i1:i2;
}

void read() {
	scanf("%d%d",&N,&M);
	int n,m;
	for(n=1;n<=N;n++) {
		for(m=1;m<=M;m++) {
			map[n][m]=0x3c3c3c3c;
		}
		map[n][n]=0;
	}
	int x,y,z;
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&x,&y,&z);
		map[n][m]=min(map[n][m],z);
		map[m][n]=map[n][m];
	}
}

int main() {
	read();
	run();
	return 0;
}
