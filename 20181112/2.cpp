#include <cstdio>

long long t[400000+5],add[400000+5]={0},a[100000+5];
int N,M;

void build(int n, int l, int r) {
	if(l==r) {
		t[n]=a[l];
	} else {
		int mid=(l+r)>>1;
		build(n<<1,l,mid);
		build((n<<1)+1,mid+1,r);
		t[n]=t[n<<1]+t[(n<<1)+1];
	}
}

void plus(int n, int l, int r, int dl, int dr, long long k) {
	if(r<dl||l>dr) {
		return ;
	} else if(l>=dl&&r<=dr) {
		add[n]+=k;
	} else {
		int mid=(l+r)>>1;
		int tr=r<dr?r:dr,tl=l>dl?l:dl;
		plus(n<<1,l,mid,dl,dr,k);
		plus((n<<1)+1,mid+1,r,dl,dr,k);
		t[n]+=(tr-tl+1)*k;
	}
}


long long sum(int n, int l, int r, int dl, int dr) {
	if(r<dl||l>dr) {
		return 0;
	} else if(l>=dl&&r<=dr) {
		return t[n]+(r-l+1)*add[n];
	} else {
		int mid=(l+r)>>1;
		int tr=r<dr?r:dr,tl=l>dl?l:dl;
		return sum(n<<1,l,mid,dl,dr)+sum((n<<1)+1,mid+1,r,dl,dr)+(tr-tl+1)*add[n];
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
	int m,x,y,z;
	long long k;
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&z,&x,&y);
		if(z==1) {
			scanf("%lld",&k);
			plus(1,1,N,x,y,k);
		} else {
			printf("%lld\n",sum(1,1,N,x,y));
		}
	}
}

int main() {
	read();
	build(1,1,N);
	run();
	return 0;
}
