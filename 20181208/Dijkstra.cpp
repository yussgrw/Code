#include <cstdio>

template <typename T>
struct priority_queue {
	T t[200000];
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
	int to;
	int nex;
	int v;
} t[200000+5];
struct Dis {
	int n;
	int v;
};
int N,M,S,head[100000+5]={0},dis[100000+5],fa[100000+5];
bool vis[100000+5]={false};

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
	scanf("%d%d%d",&N,&M,&S);
	int n,x,y,z,ne=1;
	for(n=1;n<=N;n++) {
		dis[n]=0x7fffffff;
		fa[n]=n;
	}
	for(n=1;n<=M;n++) {
		scanf("%d%d%d",&x,&y,&z);
		t[ne].to=y;
		t[ne].v=z;
		t[ne].nex=head[x];
		head[x]=ne++;
	}
}

void Dijkstra() {
	priority_queue<Dis> d(comp);
	dis[S]=0;
	d.push((Dis){S,dis[S]});
	int n,v,m,cnt=1;
	while(!d.empty()&&cnt<N) {
		Dis tmp=d.top();
		d.pop();
		n=tmp.n;
		v=tmp.v;
		if(vis[n]) {
			continue;
		}
		vis[n]=true;
		cnt++;
		for(m=head[n];m!=0;m=t[m].nex) {
			if(!vis[t[m].to]) {
				if(dis[t[m].to]>v+t[m].v) {
					dis[t[m].to]=v+t[m].v;
					d.push((Dis){t[m].to,dis[t[m].to]});
				}
			}
		}
	}
}

void print() {
	int n;
	for(n=1;n<N;n++) {
		printf("%d ",dis[n]);
	}
	printf("%d\n",dis[N]);
}

int main() {
	read();
	Dijkstra();
	print();
	return 0;
}
