#include <cstdio>
#include <queue>
using namespace std;

struct Edge {
	int to;
	int nex;
	int v;
} line[200000+5];
struct Dis {
	int n;
	int v;
	bool operator < (Dis d) const {
		return d.v<v;
	}
};
int head[100000+5]={0},dis[100000+5],vis[100000+5]={0},N,M,nextl=1,S;
priority_queue<Dis> dist;

void read() {
	scanf("%d%d%d",&N,&M,&S);
	int m;
	int x,y,z;
	for(m=1;m<=N;m++) {
		dis[m]=0x7fffffff;
	}
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&x,&y,&z);
		line[nextl].to=y;
		line[nextl].v=z;
		line[nextl].nex=head[x];
		head[x]=nextl++;
	}
}

void Dijkstra() {
	int n,v,m;
	dis[S]=0;
	dist.push((Dis){S,dis[S]});
	while(!dist.empty()) {
		n=dist.top().n;
		v=dist.top().v;
		dist.pop();
		if(vis[n]) {
			continue;
		}
		vis[n]=1;
		for(m=head[n];m!=0;m=line[m].nex) {
			if(dis[line[m].to]>v+line[m].v) {
				dis[line[m].to]=v+line[m].v;
				dist.push((Dis){line[m].to,dis[line[m].to]});
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
