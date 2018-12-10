#include <cstdio>

struct Edge {
	int to;
	int nex;
	int v;
} t[1000000+5];
struct Dis {
	int n;
	int v;
} q[1000000+5];
int N,M,S,head[1000+5]={0},vis[1000+5]={0},dis[1000+5],T=0;

inline void push(Dis d) {
	int j=++T,i=j>>1;
	while(i) {
		if(d.v<q[i].v) {
			q[j]=q[i];
			j=i;
			i=j>>1;
		} else {
			break;
		}
	}
	q[j]=d;
}

inline void pop() {
	Dis d=q[T--];
	int i=1,j=i<<1;
	while(j<=T) {
		if(d.v<=q[j].v&&d.v<=q[j|1].v) {
			break;
		} else if(q[j].v<q[j|1].v) {
			q[i]=q[j];
			i=j;
		} else {
			q[i]=q[j|1];
			i=j|1;
		}
		j=i<<1;
	}
	q[i]=d;
}

void read() {
	int ne=1,n,x,y,z;
	scanf("%d%d",&N,&M);
	for(n=1;n<=N;n++) {
		dis[n]=0x7fffffff;
	}
	for(n=1;n<=M;n++) {
		scanf("%d%d%d",&x,&y,&z);
		t[ne].to=y;
		t[ne].v=z;
		t[ne].nex=head[x];
		head[x]=ne++;
	}
	S=1;
}

void Dijkstra() {
	int n,m,v;
	dis[S]=1;
	push((Dis){S,dis[S]});
	while(T) {
		n=q[1].n;
		v=q[1].v;
		pop();
		if(vis[n]) {
			continue;
		}
		vis[n]=1;
		for(m=head[n];m!=0;m=t[m].nex) {
			if(!vis[t[m].to]) {
				if(dis[t[m].to]>v*t[m].v) {
					dis[t[m].to]=v*t[m].v;
					push((Dis){t[m].to,dis[t[m].to]});
				}
			}
		}
	}
}

void print() {
	printf("%d\n",dis[N]);
}

int main() {
	read();
	Dijkstra();
	print();
	return 0;
}
