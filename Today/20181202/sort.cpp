#include <cstdio>

int t[100000+5];
int T=0;

void push(int x) {
	int j=++T,i=j>>1;
	while(i) {
		if(x<t[i]) {
			t[j]=t[i];
			j=i;
			i=j>>1;
		} else {
			break;
		}
	}
	t[j]=x;
}

void pop() {
	int x=t[T--];
	int i=1,j=i<<1;
	while(j<=T) {
		if(x<t[j]&&x<t[j|1]) {
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

int main() {
	int N,n,x;
	scanf("%d",&N);
	for(n=1;n<=N;n++) {
		scanf("%d",&x);
		push(x);
	}
	for(n=1;n<N;n++) {
		printf("%d ",t[1]);
		pop();
	}
	printf("%d\n",t[1]);
	return 0;
}
