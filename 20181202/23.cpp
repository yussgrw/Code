#include <cstdio>

int a[1000000+5];

inline void readin(int *x) {
	*x=0;
	char c=getchar();
	while(c<'0'||c>'9') {
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		*x=*x*10+c-'0';
		c=getchar();
	}
}

int main() {
	int n,N;
	readin(&N);
	for(n=1;n<=N;n++) {
		readin(&a[n]);
	}
	return 0;
}
