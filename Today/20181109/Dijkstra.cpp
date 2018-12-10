#include <cstdio>
#include <queue>
using namespace std;

struct Dis {
	int n;
	int v;
	bool operator < (Dis d) const {
		return v>d.v;
	}
};
struct Edge {
	int to;
	int nex;
	int v;
} l[200000+5];
int dis[100000+5],vis[100000+5]={0},head[100000+5]={0},N,M,S,nextl=1;
const int INF = 2147483647;
priority_queue<Dis> dist;

void read() {
	scanf("%d%d%d",&N,&M,&S);
	int m,i,j,w;
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&i,&j,&w);
		l[nextl].v=w;
		l[nextl].to=j;
		l[nextl].nex=head[i];
		head[i]=nextl++;
	}
}

void Dijkstra() {
	int n;
	for(n=1;n<=N;n++) {
		dis[n]=INF;
	}
	dis[S]=0;
	dist.push((Dis){S,0});
	while(!dist.empty()) {
		int nu=dist.top().n;
		int d=dist.top().v;
		dist.pop();
		if(vis[nu]) {
			continue;
		}
		vis[nu]=1;
		for(n=head[nu];n!=0;n=l[n].nex) {
			if(dis[l[n].to]>d+l[n].v) {
				dis[l[n].to]=d+l[n].v;
				dist.push((Dis){l[n].to,dis[l[n].to]});
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
