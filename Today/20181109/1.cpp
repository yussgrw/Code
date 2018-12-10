#include <cstdio>
#include <queue>
using namespace std;

typedef struct {
	int to;
	int v;
	int nex;
} Edge;
struct Dis {
	int n;
	int v;
	bool operator < (Dis d) const {
		return v>d.v;
	}
};
Edge l[200000+5];
priority_queue<Dis> dist;
int nextl=1,head[100000+5]={0};
int N,M,S;
int vis[100000+5]={0},dis[100000+5];
const int INF = 2147483647;

void read() {
	scanf("%d%d%d",&N,&M,&S);
	int i,j,w,m;
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&i,&j,&w);
		l[nextl].to=j;
		l[nextl].v=w;
		l[nextl].nex=head[i];
		head[i]=nextl;
		nextl++;
	}
}

void Dijkstra() {
	int n;
	for(n=0;n<=N;n++) {
		dis[n]=INF;
	}
	dist.push((Dis){S,0});
	dis[S]=0;
	int min,d;
	while(!dist.empty()) {
		min=dist.top().n;
		d=dist.top().v;
		dist.pop();
		if(vis[min]==1) {
			continue;
		}
		vis[min]=1;
		for(n=head[min];n!=0;n=l[n].nex) {
			if(dis[l[n].to]>(d+l[n].v)) {
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
