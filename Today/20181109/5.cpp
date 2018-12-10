#include <cstdio>

int v[65],w[65],u[65][3]={0};
int f[32000+5]={0};
int N,M;

void read() {
	scanf("%d%d",&M,&N);
	int n;
	int x,y,z;
	for(n=1;n<=N;n++) {
		scanf("%d%d%d",&x,&y,&z);
		v[n]=x;
		w[n]=x*y;
		if(z!=0) {
			u[z][++u[z][0]]=n;
		}
	}
	for(n=1;n<=N;n++) {
		if(u[n][0]==1) {
			w[u[n][1]]+=w[n];
			v[u[n][1]]+=v[n];
		} else if(u[n][0]==2) {
			w[++N]=w[u[n][1]]+w[u[n][2]]+w[n];
			v[N]=v[u[n][1]]+v[u[n][2]]+v[n];
			w[u[n][1]]+=w[n];
			v[u[n][1]]+=v[n];
			w[u[n][2]]+=w[n];
			v[u[n][2]]+=v[n];
		}
	}
}

int max(int i1, int i2) {
	return i1>i2?i1:i2;
}

int main() {
	read();
	int n,m;
	for(n=1;n<=N;n++) {
		for(m=M;m>=v[n];m--) {
			f[m]=max(f[m],f[m-v[n]]+w[n]);
		}
		printf("%d\n",f[M]);
	}
	printf("%d\n",f[M]);
	return 0;
}
