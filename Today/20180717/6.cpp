#include <cstdio>

long long data[100000+5]={0},t[100000*4+5]={0},add[400000*4+5]={0};
int N,M;

void read() {
	scanf("%d%d",&N,&M);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",&data[n]);
	}
}

void build(int n, int l, int r) {
	if(r==l) {
		t[n]=data[l];
	} else {
		int mid=(l+r)/2;
		build(n*2,l,mid);build(n*2+1,mid+1,r);
		t[n]=t[n*2]+t[n*2+1];
	}
}

void plus(int n, int l, int r, int tl, int tr, long long k) {
	if(r<tl||l>tr) {
		return ;
	} else if(l>=tl&&r<=tr) {
		add[n]+=k;
	} else {
		int mid=(l+r)/2;
		int dl=l>tl?l:tl,dr=r<tr?r:tr;
		plus(n*2,l,mid,tl,tr,k);
		plus(n*2+1,mid+1,r,tl,tr,k);
		t[n]+=(dr-dl+1)*k;
	}
}

long long search(int n, int l, int r, int tl, int tr) {
	if(r<tl||l>tr) {
		return 0;
	} else if(l>=tl&&r<=tr) {
		return add[n]*(r-l+1)+t[n];
	} else {
		int mid=(l+r)/2;
		int dl=l>tl?l:tl,dr=r<tr?r:tr;
		return search(n*2,l,mid,tl,tr)+search(n*2+1,mid+1,r,tl,tr)+add[n]*(dr-dl+1);
	}
}

void run() {
	int x,y,z,m;
	long long k;
	for(m=1;m<=M;m++) {
		scanf("%d",&z);
		if(z==1) {
			scanf("%d%d%lld",&x,&y,&k);
			plus(1,1,N,x,y,k);
		} else {
			scanf("%d%d",&x,&y);
			printf("%lld\n",search(1,1,N,x,y));
		}
	}
}

int main() {
	read();
	build(1,1,N);
	run();
	return 0;
}
