#include <cstdio>

struct Edge {
	int to;
	int nex;
} t[100000+5];

int head[100000+5]={0},vis[100000+5]={0};
int N,M;

int dfs(int a, int b, int frm) {
//	printf("%d %d %d\n",a,b,frm);
	if(a==b) {
		return 1;
	}
	int m;
	for(m=head[a];m!=0;m=t[m].nex) {
		if(t[m].to!=frm&&(!vis[t[m].to])) {
			vis[t[m].to]=1;
			if(dfs(t[m].to,b,a)) {
				vis[t[m].to]=0;
				return 1;
			}
			vis[t[m].to]=0;
		}
	}
	return 0;
}

int main() {
	scanf("%d%d",&N,&M);
	int m,x,a,b,z,ne=1;
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&x,&a,&b);
		if(x==1) {
			scanf("%d",&z);
			if(z==1) {
				t[ne].to=b;
				t[ne].nex=head[a];
				head[a]=ne++;
			} else if(z==2) {
				t[ne].to=a;
				t[ne].nex=head[b];
				head[b]=ne++;
			} else {
				t[ne].to=b;
				t[ne].nex=head[a];
				head[a]=ne++;
				t[ne].to=a;
				t[ne].nex=head[b];
				head[b]=ne++;
			}
		} else {
			vis[a]=1;
			x=dfs(a,b,0);
			vis[a]=0;
			vis[b]=1;
			z=dfs(b,a,0);
			vis[b]=0;
			if((!x)&&(!z)) {
				putchar('0');
			} else if(x&&(!z)) {
				putchar('1');
			} else if((!x)&&z) {
				putchar('2');
			} else {
				putchar('3');
			}
			putchar('\n');
		}
	}
	return 0;
}
