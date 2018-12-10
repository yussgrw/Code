#include <cstdio>

int a[100000+5],b[100000+5]={0},vis[100000+5]={0};

int main() {
	int i,l,r,max,mid,res=0,N=0;
	while(scanf("%d",&i)==1) {
		a[++N]=i;
	}
	for(i=1;i<=N;i++) {
		l=0;
		r=i-1;
		while(l<r) {
			mid=(l+r)/2;
			if(b[mid+1]==0||b[mid+1]<a[i]) {
				r=mid;
			} else {
				l=mid+1;
			}
		}
		if(b[r+1]==0) {
			b[r+1]=a[i];
		} else {
			b[r+1]=a[i]<b[r+1]?b[r+1]:a[i];
		}
	}
	for(max=N;b[max]==0;max--);
	int cnt=0;
	int n;
	while(cnt<N) {
		n=0x7fffffff;
		res++;
		for(i=1;i<=N;i++) {
			if(!vis[i]&&n>=a[i]) {
				vis[i]=1;
				n=a[i];
				cnt++;
			}
		}
	}
	printf("%d\n%d\n",max,res);
	return 0;
}
