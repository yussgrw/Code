#include <cstdio>
#include <queue>
using namespace std;

struct Edge {
	int to;
	int v;
	int nex;
} t[200000+5];
struct Dis {
	int n;
	int v;
	bool operator < (Dis d) const {
		return d.v<v;
	}
};
int N,M,S,head[100000+5]={0},vis[100000+5]={0},dis[100000+5];
priority_queue<Dis> dist;
const int INF = 0x3c3c3c3c;

void read() {
	scanf("%d%d%d",&N,&M,&S);
	int n,ne=1,x,y,z;
	for(n=1;n<=N;n++) {
		dis[n]=INF;
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
	int n,m,v;
	while(!dist.empty()) {
		if(vis[dist.top().n]) {
			dist.pop();
			continue;
		}
		n=dist.top().n;
		v=dist.top().v;
		dist.pop();
		vis[n]=1;
		for(m=head[n];m!=0;m=t[m].nex) {
			if(dis[t[m].to]>v+t[m].v) {
				dis[t[m].to]=v+t[m].v;
				dist.push((Dis){t[m].to,dis[t[m].to]});
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
