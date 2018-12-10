#include <cstdio>

int f[200000+5]={0},a[200000+5],t[800000+5]={0},N,L,R;
bool vis[200000+5]={false};
const int INF = -0x3c3c3c3c;

inline int max(int x, int y) {
	return x>y?x:y;
}

void add(int id, int l, int r, int x, int k) {
	if(x<l||x>r||l>r) {
		return ;
	} else if(l==r) {
		t[id]=k;
	} else {
		int mid=(l+r)>>1;
		add(id<<1,l,mid,x,k);
		add((id<<1)|1,mid+1,r,x,k);
		t[id]=max(t[id<<1],t[(id<<1)|1]);
	}
}

int query(int id, int l, int r, int tl, int tr) {
	if(tr<l||tl>r) {
		return INF;
	} else if(tl<=l&&tr>=r) {
		return t[id];
	} else {
		int mid=(l+r)>>1;
		return max(query(id<<1,l,mid,tl,tr),query((id<<1)|1,mid+1,r,tl,tr));
	}
}

void read() {
	scanf("%d%d%d",&N,&L,&R);
	int n;
	for(n=0;n<=N;n++) {
		add(1,0,N,n,INF);
		scanf("%d",&a[n]);
	}
}

void dp() {
	int i,m,l,r;
	add(1,0,N,0,0);
	for(i=L;i<=N;i++) {
		m=INF;
		l=(i-R)<0?0:(i-R);
		r=i-L;
		m=query(1,0,N,l,r);
		if(m!=INF) {
			f[i]=m+a[i];
			add(1,0,N,i,f[i]);
		}
	}
	l=(N-R+1)>0?(N-R+1):0;
	r=N;
	printf("%d\n",query(1,0,N,l,r));
}

int main() {
	read();
	dp();
	return 0;
}
