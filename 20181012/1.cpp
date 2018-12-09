#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct {
	int last;
	int num;
} s;
s a[1000000+5],b[1000000+5];
int N,p[1000000+5],q[1000000+5];
int cnt=0;
const int P = 99999997;

inline int readin() {
	register int x=0;
	register char c=getchar();
	while(c<'0'||c>'9') {
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void read() {
	N=readin();
	register int n;
	for(n=1;n<=N;n++) {
		a[n].num=readin();
		a[n].last=n;
	}
	for(n=1;n<=N;n++) {
		b[n].num=readin();
		b[n].last=n;
	}
}

void msort(int l, int r, bool (*_comp) (int, int)) {
	if(l==r) {
		return ;
	} else if(r-l==1) {
		if(!_comp(p[l],p[r])) {
			int tmp=p[l];
			p[l]=p[r];
			p[r]=tmp;
			cnt ++;
			cnt%=P;
		}
	} else {
		int mid=(l+r)/2;
		msort(l,mid,_comp);msort(mid+1,r,_comp);
		int i=l,j=mid+1,k;
		for(k=l;k<=r;k++) {
			if(i>mid) {
				q[k]=p[j++];
			} else if(j>r) {
				q[k]=p[i++];
			} else if(!_comp(p[i],p[j])) {
				cnt += (mid-i+1);
				cnt%=P;
				q[k]=p[j++];
			} else {
				q[k]=p[i++];
			}
		}
		for(k=l;k<=r;k++) {
			p[k]=q[k];
		}
	}
}

bool comp(s s1, s s2) {
	return s1.num<s2.num;
}

bool comp2(int i1, int i2) {
	return i1<=i2;
}

int main() {
	read();
	sort(a+1,a+N+1,comp);
	sort(b+1,b+N+1,comp);
	int n;
	for(n=1;n<=N;n++) {
		p[a[n].last]=b[n].last;
	}
	msort(1,N,comp2);
	printf("%d\n",cnt);
	return 0;
}
