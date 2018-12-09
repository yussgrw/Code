#include <cstdio>

struct node {
	int v;
	int lc,rc;
} t[100+5];
struct Edge {
	int nex;
	int to;
	int v;
} t2[200+5];
int N,Q,head[100+5]={0};
int f[100+5][100+5];
const int INF = -999999999;

int max(int x, int y) {
	return x>y?x:y;
}

int search(int n, int k) {
//	printf("n=%d k=%d\n",n,k);
	if(t[n].lc==0&&t[n].rc==0) {
		if(k==0) {
			return t[n].v;
		} else if(k==1) {
			return 0;
		} else {
			return -999999999;
		}
	}
	int res=-999999999;
	int j,tmp;
	for(j=0;j<=k;j++) {
		if(f[t[n].lc][j]==INF||f[t[n].rc][k-j]==INF) {
			tmp=search(t[n].lc,j)+search(t[n].rc,k-j)+t[n].v;
		} else {
			tmp=f[t[n].lc][j]+f[t[n].rc][k-j]+t[n].v;
		}
		res=max(tmp,res);
//		printf("%d %d %d %d\n",n,j,k-j,tmp);
	}
	if(n!=1) {
		for(j=0;j<k;j++) {
			if(search(t[n].lc,j)+search(t[n].rc,k-j-1)>=0) {
				res=max(0,res);
				break;
			}
		}
	}
	f[n][k]=max(f[n][k],res);
	return res;
}

void init(int n, int v, int frm) {
	printf("%d ",n);
	t[n].v=v;
	int m;
	int cnt=0;
	for(m=head[n];m!=0;m=t2[m].nex) {
		if(t2[m].to==frm) {
			continue;
		}
		init(t2[m].to,t2[m].v,n);
		cnt++;
		if(cnt==1) {
			t[n].lc=t2[m].to;
		} else {
			t[n].rc=t2[m].to;
		}
	}
}

void read() {
	scanf("%d%d",&N,&Q);
	int n,x,y,z,ne=1;
	for(n=1;n<N;n++) {
		t[n].lc=0;
		t[n].rc=0;
		scanf("%d%d%d",&x,&y,&z);
		t2[ne].to=y;
		t2[ne].nex=head[x];
		t2[ne].v=z;
		head[x]=ne++;
		t2[ne].to=x;
		t2[ne].nex=head[y];
		t2[ne].v=z;
		head[y]=ne++;
	}
	int k;
	for(n=1;n<=N;n++) {
		for(k=0;k<=N;k++) {
			f[n][k]=INF;
		}
	}
	t[n].lc=0;
	t[n].rc=0;
}

int main() {
	read();
	init(1,0,0);
	putchar('\n');
/*	int n;
	for(n=1;n<=N;n++) {
		printf("%d %d %d\n",n,t[n].lc,t[n].rc);
	}
*/	printf("%d\n",search(1,N-1-Q));
	return 0;
}
