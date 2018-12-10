#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
	long long x,y,z;
} t[50000+5];

bool comp(Node a, Node b) {
	return a.z<b.z;
}

double dist(int a, int b) {
	return sqrt((double)((t[b].x-t[a].x)*(t[b].x-t[a].x)
				+(t[b].y-t[a].y)*(t[b].y-t[a].y)
				+(t[b].z-t[a].z)*(t[b].z-t[a].z)));
}

int main() {
	int N;
	scanf("%d",&N);
	int n;
	long long a,b,c;
	for(n=1;n<=N;n++) {
		scanf("%lld%lld%lld",&a,&b,&c);
		t[n].x=a;
		t[n].y=b;
		t[n].z=c;
	}
	sort(t+1,t+1+N,comp);
	double res=0.0;
	for(n=2;n<=N;n++) {
		res+=dist(n-1,n);
	}
	printf("%.3f\n",res);
	return 0;
}
