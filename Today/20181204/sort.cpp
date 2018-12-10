#include <cstdio>

int t[100000+5]={0};
int N=0;

void push(int x) {
	int j=++N,i=j>>1;
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
	int i=1,j=i<<1;
	int x=t[N--];
	while(j<=N) {
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
	int M,m,x;
	scanf("%d",&M);
	for(m=1;m<=M;m++) {
		scanf("%d",&x);
		push(x);
	}
	for(m=1;m<M;m++) {
		printf("%d ",t[1]);
		pop();
	}
	printf("%d\n",t[1]);
	return 0;
}
