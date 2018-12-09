#include <cstdio>
#include <queue>
using namespace std;

int a[200+5],N,A,B,res[200+5];

struct Dis {
	int n;
	int v;
};

void read() {
	scanf("%d%d%d",&N,&A,&B);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
		res[n]=0x7fffffff;
	}
}

void bfs() {
	queue<Dis> q;
	q.push((Dis){A,0});
	int n,v;
	while(!q.empty()) {
		n=q.front().n;
		v=q.front().v;
		q.pop();
		if(v>=res[n]) {
			continue;
		}
		res[n]=v;
		if(n+a[n]<=N) {
			q.push((Dis){n+a[n],v+1});
		}
		if(n-a[n]>0) {
			q.push((Dis){n-a[n],v+1});
		}
	}
	if(res[B]==0x7fffffff) {
		printf("-1\n");
	} else {
		printf("%d\n",res[B]);
	}
}

int main() {
	read();
	bfs();
	return 0;
}
