#include <cstdio>

int t[100000000+5];
int T=0;

inline void push(int x) {
	int j=++T,i=j>>1;
	while(i) {
		if(x>=t[i]) {
			break;
		}
		t[j]=t[i];
		j=i;
		i=j>>1;
	}
	t[j]=x;
}

inline void pop() {
	int x=t[T--];
	int i=1,j=i<<1;
	while(j<=T) {
		if(x<=t[j]&&x<=t[j|1]) {
			break;
		} else if(t[j]<t[j|1]) {
			t[i]=t[j];
			i=j;
		} else {
			t[i]=t[j|1];
			i=j|1;
		}
		j=i<<1;
	}
	t[i]=x;
}

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
	int N;
	int n,x;
	readin(&N);
	for(n=1;n<=N;n++) {
		readin(&x);
		push(x);
	}
	for(n=1;n<N;n++) {
		printf("%d ",t[1]);
		pop();
	}
	printf("%d\n",t[1]);
	return 0;
}
