#include <cstdio>

int a[200000+5];
int vis[200000+5]={0},dis[200000+5]={0};
int N,res=0x7fffffff;

void read() {
	scanf("%d",&N);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
	}
}

void dfs(int depth, int n) {
	if(vis[a[n]]==1) {
		if(dis[a[n]]!=0) {
			res=res>(depth-dis[a[n]]+1)?(depth-dis[a[n]]+1):res;
		}
	} else {
		dis[n]=depth;
		vis[a[n]]=1;
		dfs(depth+1,a[n]);
		dis[n]=0;
	}
}

int main() {
	read();
	int n;
	for(n=1;n<=N;n++) {
		if(!vis[n]) {
			vis[n]=1;
			dfs(1,n);
		}
	}
	printf("%d\n",res);
	return 0;
}
