#include <cstdio>

int a[1000000+5];

inline bool comp(int i1, int i2) {
	return i1>=i2;
}

int main() {
	int N;
	scanf("%d",&N);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
	}
	int i,j;
	for(i=1;i<N;i++) {
		for(j=1;j<N;j++) {
			if(!comp(a[j],a[j+1])) {
				int tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	for(n=1;n<N;n++) {
		printf("%d ",a[n]);
	}
	if(N>0) {
		printf("%d\n",a[n]);
	}
	return 0;
}
