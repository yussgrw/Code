#include <cstdio>
#include <queue>
using namespace std;

struct Edge {
	int to;
	int nex;
	int v;
} t[200000+5];
struct Dis {
	int n;
	int v;
	bool operator < (Dis d) const {
		return d.v<v;
	}
};

int N,M,S,head[100000+5]={0},vis[100000+5]={0},dis[100000+5]={0};
priority_queue<Dis> dist;

void read() {
	scanf("%d%d%d",&N,&M,&S);
	int n,x,y,z,ne=1;
	for(n=1;n<=N;n++) {
		dis[n]=0x3f3f3f3f;
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
	dis[S]=0;
	dist.push((Dis){S,dis[S]});
	int n,m,v,cnt=0;
	while(cnt<N) {
		n=dist.top().n;
		v=dist.top().v;
		dist.pop();
		if(vis[n]) {
			continue;
		}
		vis[n]=1;
		cnt++;
		for(m=head[n];m;m=t[m].nex) {
			if(!vis[t[m].to]) {
				if(dis[t[m].to]>v+t[m].v) {
					dis[t[m].to]=v+t[m].v;
					dist.push((Dis){t[m].to,dis[t[m].to]});
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
