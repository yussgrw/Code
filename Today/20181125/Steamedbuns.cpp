#include <cstdio>
#include <algorithm>
using namespace std;

int a[100+5];
int f[10000+5]={0};
int N,g;

int gcd(int x, int y) {
	return y?gcd(y,x%y):x;
}

void read() {
	scanf("%d",&N);
	int n;
	g=0;
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
		g=gcd(g,a[n]);
	}
}

void dp() {
	if(g!=1) {
		printf("INF\n");
		return ;
	}
	int i,n;
	sort(a+1,a+N+1);
	int MAX=a[N-1]*a[N]-a[N-1]-a[N];
	int res=0;
	for(i=1;i<=MAX;i++) {
		for(n=1;n<=N&&a[n]<=i;n++) {
			if(i==a[n]) {
				f[i]=1;
			} else if(f[i-a[n]]) {
				f[i]=1;
				break;
			}
		}
		if(!f[i]) {
			res++;
		}
	}
	printf("%d\n",res);
}

int main() {
	read();
	dp();
	return 0;
}
