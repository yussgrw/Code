#include <cstdio>

int N,V;
int w[65],v[65],q[65][3]={0};
bool pd[65]={false};
int f[32000+5]={0};

void read() {
	scanf("%d%d",&V,&N);
	int n,tmp;
	for(n=1;n<=N;n++) {
		scanf("%d%d%d",&w[n],&v[n],&tmp);
		v[n]*=w[n];
		if(tmp!=0) {
			q[tmp][++q[tmp][0]]=n;
			pd[n]=true;
		}
	}
}

int max(int x, int y) {
	return x>y?x:y;
}

void dp() {
	int n,m;
	for(n=1;n<=N;n++) {
		if(pd[n]) {
			continue;
		}
		for(m=V;m>=w[n];m--) {
			f[m]=max(f[m],f[m-w[n]]+v[n]);
			if(q[n][0]>0) {
				if(m>=w[n]+w[q[n][1]]) {
					f[m]=max(f[m],f[m-w[n]-w[q[n][1]]]+v[n]+v[q[n][1]]);
				}
			}
			if(q[n][0]>1) {
				if(m>=w[n]+w[q[n][2]]) {
					f[m]=max(f[m],f[m-w[n]-w[q[n][2]]]+v[n]+v[q[n][2]]);
				}
				if(m>=w[n]+w[q[n][2]]+w[q[n][1]]) {
					f[m]=max(f[m],f[m-w[n]-w[q[n][2]]-w[q[n][1]]]+v[n]+v[q[n][1]]+v[q[n][2]]);
				}
			}
		}
	}
	printf("%d\n",f[V]);
}

int main() {
	read();
	dp();
	return 0;
}
