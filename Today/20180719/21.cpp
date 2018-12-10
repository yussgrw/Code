#include <cstdio>

int parent[10000+5]={0};
int N,M;

int find(int n) {
	if(parent[n]!=n) {
		parent[n]=find(parent[n]);
	}
	return parent[n];
}

void prepare() {
	int n;
	for(n=1;n<=N;n++) {
		parent[n]=n;
	}
}

int readin() {
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') {
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main() {
	N=readin();M=readin();
	prepare();
	int x,y,z;
	int m;
	for(m=1;m<=M;m++) {
		z=readin();
		x=readin();
		y=readin();
		if(z==1) {
			parent[find(x)]=find(y);
		} else {
			if(find(x)==find(y)) {
				putchar('Y');
				putchar('\n');
			} else {
				putchar('N');
				putchar('\n');
			}
		}
	}
	return 0;
}
