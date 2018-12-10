#include <cstdio>
int a[100000+5],b[100000+5],f[100000+5]={0};
int N;

void read() {
	scanf("%d",&N);
	int n,x;
	for(n=1;n<=N;n++) {
		scanf("%d",&x);
		a[x]=n;
	}
	for(n=1;n<=N;n++) {
		scanf("%d",&b[n]);
		b[n]=a[b[n]];
	}
}

int min(int x, int y) {
	return x<y?x:y;
}

void dp() {
	int i,l,r,mid;
	for(i=1;i<=N;i++) {
		f[i]=0x7fffffff;
		l=0;
		r=i;
		while(l<r) {
			mid=(l+r)>>1;
			if(f[mid+1]<=b[i]) {
				l=mid+1;
			} else {
				r=mid;
			}
		}
		f[l+1]=min(f[l+1],b[i]);
	}
	l=0;
	r=N;
	while(l<r) {
		mid=(l+r)>>1;
		if(f[mid+1]==0x7fffffff) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	printf("%d\n",l);
}

int main() {
	read();
	dp();
	return 0;
}
