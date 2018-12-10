#include <cstdio>

int f[10000+5]={0};
int L,S,T,M;

void read() {
	scanf("%d%d%d%d",&L,&S,&T,&M);
	int m;
	int tmp;
	for(m=1;m<=M;m++) {
		scanf("%d",&tmp);
		f[tmp]=1;
	}
}

int min(int i1, int i2) {
	return i1<i2?i1:i2;
}

void run() {
	int i;
	int j;
	int n;
	for(i=T+1;i<S+T&&i<=L;i++) {
		n=0x7ffffff;
		for(j=S;i-j>=S&&n!=0;j++) {
			n=min(n,f[i-j]);
		}
		f[i]+=n;
//		printf("f[%d]=%d\n",i,f[i]);
	}
	for(i=S+T;i<=L;i++) {
		n=0x7ffffff;
		for(j=S;j<=T&&n!=0;j++) {
			n=min(n,f[i-j]);
		}
		f[i]+=n;
//		printf("f[%d]=%d\n",i,f[i]);
	}
	printf("%d\n",f[L]);
}

int main() {
	read();
	run();
	return 0;
}
