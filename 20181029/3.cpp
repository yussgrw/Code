#include <cstdio>

int N,a[100+5]={0},f1[100+5]={0},f2[100+5]={0};

int max(int i1, int i2) {
	return i1>i2?i1:i2;
}

int main() {
	scanf("%d",&N);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",a+n);
	}
	int i,j;
	for(i=1;i<=N;i++) {
		for(j=0;j<i;j++) {
			if(a[i]>a[j]) {
				f1[i]=max(f1[j]+1,f1[i]);
			}
		}
	}
	for(i=N;i>0;i--) {
		for(j=N+1;j>i;j--) {
			if(a[i]>a[j]) {
				f2[i]=max(f2[j]+1,f2[i]);
			}
		}
	}
	int res=0;
	for(i=1;i<=N;i++) {
		res=max(res,f1[i]+f2[i]-1);
	}
	printf("%d\n",N-res);
	return 0;
}
