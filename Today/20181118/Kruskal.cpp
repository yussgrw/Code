#include <cstdio>
#include <queue>
using namespace std;

struct Edge {
	int a;
	int b;
	int v;
	bool operator < (Edge e) const {
		return e.v<v;
	}
};

int N,M,fa[5000+5]={0};
bool vis[5000+5]={0};
priority_queue<Edge> t;

inline int find(int x) {
	if(fa[x]!=x) {
		fa[x]=find(fa[x]);
	}
	return fa[x];
}

void read() {
	scanf("%d%d",&N,&M);
	int x,y,z,m,n;
	for(n=1;n<=N;n++) {
		fa[n]=n;
	}
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&x,&y,&z);
		t.push((Edge){x,y,z});
	}
}

void Kruskal() {
	int res=0,cnt=0,x,y,v;
	while(cnt<N) {
		x=t.top().a;
		y=t.top().b;
		v=t.top().v;
		t.pop();
		if(find(x)!=find(y)) {
			fa[find(x)]=find(y);
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
