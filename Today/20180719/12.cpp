#include <cstdio>

typedef struct node;
typedef struct line;

int N,M,S;

struct node {
	int n;
	line* first;
} t[10000+5];

struct line {
	int to;
	line* nextl;
	int w;
} l[500000+5];

int next=1;

void read() {
	scanf("%d%d%d",&N,&M,&S);
	int m;
	int f,g,w;
	line *last;
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&f,&g,&w);
		if(t[f].first==NULL) {
			t[f].first=&l[next];
		} else {
			last=t[f].first;
			while(last->nextl!=NULL) {
				last=last->nextl;
			}
			last->nextl=&l[next];
		}
		l[next].to=g;
		l[next++].w=w;
	}
}

int vis[10000+5]={0};
int dis[10000+5]={0};

void Dijsktra() {
	int n;
	for(n=1;n<=N;n++) {
		dis[n]=2147483647;
	}
	dis[S]=0;
	vis[S]=1;
	int focus=S;
	line *last;
	int minx,minn;
	int len;
	int flag;
	last=t[S].first;
	while(last!=NULL) {
		dis[last->to]=last->w;
		last=last->nextl;
	}
	while(true) {
		last=t[focus].first;
		while(last!=NULL) {
			if((last->w+dis[focus])<dis[last->to]) {
				dis[last->to]=last->w+dis[focus];
			}
			last=last->nextl;
		}
		minx=2147483647;
		flag=1;
		for(n=1;n<=N;n++) {
			if(vis[n]==0) {
				flag=0;
				if(dis[n]<minx) {
					minn=n;
					minx=dis[n];
				}
			}
		}
		if(flag==1) {
			break;
		}
		focus=minn;
		vis[focus]=1;
	}
}

int main() {
	read();
	Dijsktra();
	int n;
	for(n=1;n<N;n++) {
		printf("%d ",dis[n]);
	}
	printf("%d\n",dis[N]);
	return 0;
}
