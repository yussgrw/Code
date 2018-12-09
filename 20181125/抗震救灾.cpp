#include <cstdio>
#include <memory.h>

int v[2000+5];
int w[2000+5];
int f[100+5];
int N,M,S;

void read() {
	scanf("%d%d",&M,&N);
	int n;
	int x,y,z;
	int ne=1;
	int m;
	for(n=1;n<=N;n++) {
		scanf("%d%d%d",&x,&y,&z);
		for(m=1;m<=z;m++) {
			v[ne]=x;
			w[ne++]=y;
		}
	}
	S=ne-1;
}

int max(int x, int y) {
	return x>y?x:y;
}

void dp() {
	int n,m;
	for(n=1;n<=S;n++) {
		for(m=M;m>0;m--) {
			if(v[n]>m) {
				break;
			} else {
				f[m]=max(f[m],f[m-v[n]]+w[n]);
			}
		}
	}
	printf("%d\n",f[M]);
}

int main() {
	int T,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++) {
		memset(f,0,sizeof(f));
		read();
		dp();
	}
	return 0;
}
