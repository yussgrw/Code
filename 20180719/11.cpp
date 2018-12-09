#include <cstdio>

int N,M,S;
int nextt=1;
int dis[10000+5];

typedef struct node;
typedef struct line;

struct node {
	int n;
	line *first;
} p[10000+5];

struct line {
	int to;
	line *nextl;
	int w;
} l[500000+5];

void read() {
	scanf("%d%d%d",&N,&M,&S);
	int f,g,w;
	int m;
	line *last;
	for(m=1;m<=M;m++) {
		scanf("%d%d%d",&f,&g,&w);
		if(p[f].first==NULL) {
			p[f].first=&l[nextt];
			l[nextt].to=g;
			l[nextt].w=w;
		} else {
			last=p[f].first;
			while(last->nextl!=NULL) {
				last=last->nextl;
			}
			last->nextl=&l[nextt];
			l[nextt].to=g;
			l[nextt].w=w;
		}
		nextt++;
	}
	int n;
	for(n=1;n<=N;n++) {
		dis[n]=2147483647;
	}
}

void bfs(int lastn, int now, int len) {
	if(len<dis[now]) {
		dis[now]=len;
		line* last;
		last=p[now].first;
		while(last!=NULL) {
			if(last->to==lastn) {
				last=last->nextl;
				continue;
			}
			bfs(now,last->to,len+last->w);
			last=last->nextl;
		}
	}
}

int main() {
	read();
	bfs(0,S,0);
	int i;
	for(i=1;i<=N;i++) {
		printf("%d ",dis[i]);
	}
	putchar('\n');
	return 0;
}
