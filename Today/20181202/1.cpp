#include <cstdio>
#include <queue>
using namespace std;

int f[1<<11],a[100+5]={0},b[100+5]={0};
int N,M;
const int INF = 0x7fffffff;

void read() {
	scanf("%d%d",&N,&M);
	int i;
	for(i=0;i<1<<N;i++) {
		f[i]=INF;
	}
	int n,m;
	int x;
	for(m=1;m<=M;m++) {
		for(n=1;n<=N;n++) {
			b[m]<<=1;
			a[m]<<=1;
			scanf("%d",&x);
			if(x!=0) {
				if(x==-1) {
					a[m]|=1;
				}
			} else {
				b[m]|=1;
			}
		}
	}
}

struct F {
	int n;
	int v;
};

void run() {
	queue<F> q;
	f[(1<<N)-1]=0;
	q.push((F){(1<<N)-1,f[(1<<N)-1]});
	int i,v,m,j;
	while(!q.empty()) {
		i=q.front().n;
		v=q.front().v;
		q.pop();
		for(m=1;m<=M;m++) {
			j=(i&b[m])+(a[m]&(~b[m]));
			if(f[j]>v+1) {
				f[j]=v+1;
				q.push((F){j,f[j]});
			}
		}
	}
	if(f[0]==INF) {
		printf("-1\n");
	} else {
		printf("%d\n",f[0]);
	}
}

int main() {
	read();
	run();
	return 0;
}
