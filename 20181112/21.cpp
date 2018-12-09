#include <cstdio>

long long t[400000+5],a[100000+5];
int N,M;

inline long long min(long long i1, long long i2) {
	return i1<i2?i1:i2;
}

void build(int n, int l, int r) {
	if(l==r) {
		t[n]=a[l];
	} else {
		int mid=(l+r)>>1;
		build(n<<1,l,mid);
		build((n<<1)+1,mid+1,r);
		t[n]=min(t[n<<1],t[(n<<1)+1]);
	}
}

long long sum(int n, int l, int r, int dl, int dr) {
	if(l>dr||r<dl) {
		return 0x7fffffff;
	} else if(dl<=l&&dr>=r) {
		return t[n];
	} else {
		int mid=(l+r)>>1;
		return min(sum(n<<1,l,mid,dl,dr),sum((n<<1)+1,mid+1,r,dl,dr));
	}
}

void read() {
	scanf("%d%d",&N,&M);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%lld",&a[n]);
	}
}

void run() {
	int m,x,y;
	for(m=1;m<=M;m++) {
		scanf("%d%d",&x,&y);
		printf("%lld\n",sum(1,1,N,x,y));
	}
}

int main() {
	read();
	build(1,1,N);
	run();
	return 0;
}
