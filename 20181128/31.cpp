#include <cstdio>

template <typename T>
struct priority_queue {
	int K;
	T t[100000+5];
	bool (*_comp) (T, T);
	inline void push(T x) {
		int i,j;
		j=++K;
		i=j>>1;
		while(i) {
			if(!_comp(t[i],x)) {
				t[j]=t[i];
				j=i;
				i=j>>1;
			} else {
				break;
			}
		}
		t[j]=x;
	}
	inline T top() {
		return t[1];
	}
	inline void pop() {
		int i=1,j;
		T x=t[K--];
		j=i<<1;
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
	inline bool empty() {
		return K?false:true;
	}
	priority_queue(bool (*__comp) (T, T)) {
		K=0;
		_comp=__comp;
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
inline bool comp(Dis d1, Dis d2) {
	return d1.v<d2.v;
}

int N,M,S,head[100000+5]={0},dis[100000+5];
bool vis[100000+5]={false};
priority_queue<Dis> q(comp);

void read() {
	scanf("%d%d%d",&N,&M,&S);
	int n;
	for(n=1;n<=N;n++) {
		dis[n]=0x7fffffff;
	}
	int m,ne=1;
	int x,y,z;
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&x,&y,&z);
		t[ne].to=y;
		t[ne].v=z;
		t[ne].nex=head[x];
		head[x]=ne++;
	}
}

void Dijkstra() {
	priority_queue<Dis> q(comp);
	int n,v,m;
	dis[S]=0;
	q.push((Dis){S,dis[S]});
	Dis tmp;
	while(!q.empty()) {
		tmp=q.top();
		q.pop();
		n=tmp.n;
		if(vis[n]) {
			continue;
		}
		vis[n]=true;
		v=tmp.v;
		for(m=head[n];m;m=t[m].nex) {
			if(!vis[t[m].to]) {
				if(dis[t[m].to]>v+t[m].v) {
					dis[t[m].to]=v+t[m].v;
					q.push((Dis){t[m].to,dis[t[m].to]});
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
