#include <cstdio>

int dis[15][15],N,M;
int a[15];
int f[1<<13][15]={0},head[15]={0};

struct Edge {
	int to;
	int nex;
} t[200];

int min(int i1, int i2) {
	return i1<i2?i1:i2;
}

void read() {
	scanf("%d%d",&N,&M);
	int n,m;
	for(n=1;n<=N;n++) {
		for(m=1;m<=N;m++) {
			dis[n][m]=0x7fffffff;
		}
		dis[n][n]=0;
	}
	int x,y,z;
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&x,&y,&z);
		dis[x][y]=min(dis[x][y],z);
		dis[y][x]=dis[x][y];
	}
	int ne=1;
	for(n=1;n<=N;n++) {
		for(m=n+1;m<=M;m++) {
			if(map[n][m]!=0x7fffffff) {
				t[ne].to=m;
				t[ne].nex=head[n];
				head[n]=ne++;
				t[ne].to=n;
				t[ne].nex=head[m];
				head[m]=ne++;
			}
		}
	}
}

int dfs(int i, int now, int frm, int depth) {
	a[now]=(depth-1)*dis[frm][now];
	int m,n,res=0;
	for(m=head[now];m!=0;m=t[m].nex) {
		n=t[m].to;
		if(i&1<<(n-1)) {
			if(n!=frm) {
				res+=dfs(i,n,now,depth+1);
			}
		}
	}
	if(res) {
		return res;
	} else {
		return 1<<(now-1);
	}
}

void run() {
	int i,j,k,n;
	for(i=1;i<(1<<N);i++) {
		for(j=1;j<=N;j++) {
			f[i][j]=0x7fffffff;
			if(i&(1<<(j-1))) {
				k=dfs(i,j,0,1);
				n=1;
				while(k>0) {
					if(k&1) {
						f[i][j]=min(f[i][j],f[i-(1<<(n-1))][j]+a[n]);
					}
					k>>=1;
					n++;
				}
			}
		}
	}
}

int main() {
	return 0;
}
