#include <cstdio>
#include <memory.h>

struct node {
	int w,l,r;
} t[300+5];

int N,M,c[300+5]={0},f[300+5][300+5]={0};
bool vis[300+5][300+5]={false};

int max(int x, int y) {
	return x>y?x:y;
}

int dp(int n, int k) {
	if(k==0) {
		vis[n][k]=true;
		f[n][k]=0;
		return 0;
	}
	int i;
	int res=-1;
	int res1,res2;
	if(t[n].r) {
		res=dp(t[n].r,k);
	}
	for(i=0;i<k;i++) {
		if(t[n].l==0) {
			res1=0;
		} else {
			if(vis[t[n].l][i]) {
				res1=f[t[n].l][i];
			} else {
				res1=dp(t[n].l,i);
			}
		}
		if(res1==-1) {
			continue;
		}
		if(t[n].r==0) {
			res2=0;
		} else {
			if(vis[t[n].r][k-i-1]) {
				res2=f[t[n].r][k-i-1];
			} else {
				res2=dp(t[n].r,k-i-1);
			}
		}
		if(res2==-1) {
			continue;
		}
		res=max(res,res1+res2+t[n].w);
	}
	vis[n][k]=true;
	f[n][k]=res;
	return res;
}

void read() {
	scanf("%d%d",&N,&M);
	int n;
	int x,y;
	memset(t,0,sizeof(t));
	for(n=1;n<=N;n++) {
		scanf("%d%d",&x,&y);
		t[n].w=y;
		if(!c[x]) {
			t[x].l=n;
		} else {
			t[c[x]].r=n;
		}
		c[x]=n;
	}
}

int main() {
	read();
	printf("%d\n",dp(0,M+1));
	return 0;
}
