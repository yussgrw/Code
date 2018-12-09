#include <cstdio>

template <typename T>
struct priority_queue {
	T t[200000+5];
	int K;
	bool (*_comp) (T,T);
	priority_queue(bool (*_cmp) (T, T)) {
		K=0;
		_comp=_cmp;
	}
	inline void push(T x) {
		int j=++K,i=j>>1;
		while(i) {
			if(_comp(t[i],x)) {
				break;
			} else {
				t[j]=t[i];
				j=i;
				i=j>>1;
			}
		}
		t[j]=x;
	}
	inline void pop() {
		int i=1,j=i<<1;
		T x=t[K--];
		while(j<=K) {
			if(_comp(x,t[j])&&_comp(x,t[j|1])) {
				break;
			} else if(_comp(t[j],t[j|1])) {
				t[i]=t[j];
				i=j;
			} else {
				t[i]=t[j|1];
				i=j|1;
			}
			j=i<<1;
		}
		t[i]=x;
	}
	inline T top() {
		return t[1];
	}
	inline bool empty() {
		return K?false:true;
	}
};
struct Edge {
	int frm;
	int to;
	int nex;
	int v;
} t[200000+5];
struct Dis {
	int n;
	int v;
};
int N,M,fa[5000+5];
bool vis[5000+5]={false};

inline bool comp(Dis x, Dis y) {
	return x.v<=y.v;
}

int find(int x) {
	if(fa[x]!=x) {
		fa[x]=find(fa[x]);
	}
	return fa[x];
}

void read() {
	scanf("%d%d",&N,&M);
	int n,x,y,z,ne=1;
	for(n=1;n<=N;n++) {
		fa[n]=n;
	}
	for(n=1;n<=M;n++) {
		scanf("%d%d%d",&x,&y,&z);
		t[ne].to=y;
		t[ne].v=z;
		t[ne++].frm=x;
	}
}

void Kruskal() {
	priority_queue<Dis> dist(comp);
	int n,v,cnt=0,res=0,x,y;
	Dis tmp;
	for(n=1;n<=M;n++) {
		dist.push((Dis){n,t[n].v});
	}
	while(cnt<N) {
		tmp=dist.top();
		dist.pop();
		n=tmp.n;
		v=tmp.v;
		x=t[n].frm;
		y=t[n].to;
		if(find(x)==find(y)) {
			continue;
		} else {
			fa[find(x)]=fa[y];
			res+=v;
		}
		if(!vis[x]) {
			cnt++;
			vis[x]=true;
		}
		if(!vis[y]) {
			cnt++;
			vis[y]=true;
		}
	}
	printf("%d\n",res);
}

int main() {
	read();
	Kruskal();
	return 0;
}
