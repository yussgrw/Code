#include <cstdio>
#include <memory.h>

long long c1[200000+5],c2[200000+5],v[200000+5],S;
int N,M,L[200000+5],R[200000+5],w[200000+5],MAX=0;

void read() {
	scanf("%d%d%lld",&N,&M,&S);
	int n,m;
	for(n=1;n<=N;n++) {
		scanf("%d%lld",&w[n],&v[n]);
		MAX=w[n]>MAX?w[n]:MAX;
	}
	for(m=1;m<=M;m++) {
		scanf("%d%d",&L[m],&R[m]);
	}
}

long long run(int W) {
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	int n;
	for(n=1;n<=N;n++) {
		if(w[n]>=W) {
			c1[n]+=1;
			c2[n]+=v[n];
		}
		c1[n]+=c1[n-1];
		c2[n]+=c2[n-1];
	}
	long long res=0;
	for(n=1;n<=M;n++) {
		res+=(c1[R[n]]-c1[L[n]-1])*(c2[R[n]]-c2[L[n]-1]);
	}
	return res;
}

inline long long abs(long long x) {
	return x<0?-x:x;
}

inline long long min(long long x, long long y) {
	return x<y?x:y;
}

int main() {
	read();
	int l=0,r=MAX,mid;
	long long ret,res=0x7fffffffffffffff;
	while(l<r) {
		mid=(l+r)>>1;
		ret=run(mid+1);
		res=min(res,abs(S-ret));
		if(S>ret) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	printf("%lld\n",res);
	return 0;
}
