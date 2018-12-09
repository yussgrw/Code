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

int N,M,fa[5000+5];;
bool vis[5000+5]={false};
priority_queue<Edge> t;

void read() {
	scanf("%d%d",&N,&M);
	int x,y,z,m;
	for(m=1;m<=N;m++) {
		fa[m]=m;
	}
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&x,&y,&z);
		t.push((Edge){x,y,z});
	}
}

int find(int x) {
	if(fa[x]!=x) {
		fa[x]=find(fa[x]);
	}
	return fa[x];
}

void Kruskal() {
	int res=0,cnt=0;
	int x,y,v;
	while(cnt<N) {
		x=t.top().a;
		y=t.top().b;
		v=t.top().v;
		t.pop();
		if(x==y) {
			continue;
		}
		if((!vis[x])&&(!vis[y])) {
			vis[x]=true;
			vis[y]=true;
			cnt+=2;
			res+=v;
			fa[find(x)]=find(y);
		} else if(vis[x]&&vis[y]) {
			if(find(x)!=find(y)) {
				res+=v;
				fa[find(x)]=find(y);
			}
		} else {
			if(!vis[x]) {
				vis[x]=true;
				fa[find(x)]=find(y);
				res+=v;
				cnt++;
			} else if(!vis[y]) {
				vis[y]=true;
				fa[find(y)]=find(x);
				res+=v;
				cnt++;
			}
		}
	}
	printf("%d\n",res);
}

int main() {
	read();
	Kruskal();
	return 0;
}
