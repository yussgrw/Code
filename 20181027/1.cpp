#include <cstdio>
#include <algorithm>
using namespace std;

struct person {
	int num;
	long long time;
} a[1001],b[1001];
int N;

void init() {
	scanf("%d",&N);
	int n;
	a[0].time=0;
	for(n=1;n<=N;n++) {
		scanf("%lld",&a[n].time);
		a[n].num=n;
	}
}

void msort(int l, int r, bool (*_comp) (person, person)) {
	if(l==r) {
		return ;
	} else if(r-l==1) {
		if(!_comp(a[l],a[r])) {
			person tmp=a[l];
			a[l]=a[r];
			a[r]=tmp;
		}
	} else {
		int mid=(l+r)/2;
		msort(l,mid,_comp);msort(mid+1,r,_comp);
		int i=l,j=mid+1,k;
		for(k=l;k<=r;k++) {
			if(i>mid) {
				b[k]=a[j++];
			} else if(j>r) {
				b[k]=a[i++];
			} else if(!_comp(a[i],a[j])) {
				b[k]=a[j++];
			} else {
				b[k]=a[i++];
			}
		}
		for(k=l;k<=r;k++) {
			a[k]=b[k];
		}
	}
}

bool comp(person p1, person p2) {
	return p1.time<=p2.time;
}

int main() {
	int n;
	init();
	msort(1,N,comp);
	long long total=0;
	double ave;
	for(n=1;n<=N;n++) {
		a[n].time+=a[n-1].time;
		total+=a[n-1].time;
		printf("%d ",a[n].num);
	}
	putchar('\n');
	ave=(double)total/(double)N;
	printf("%.2f\n",ave);
	return 0;
}
