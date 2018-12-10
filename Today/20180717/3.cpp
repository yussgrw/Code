#include <cstdio>

int prime[1000000+5]={0};
int num[1000000+5]={0};

int main() {
	prime[1]=1;
	int n;
	int i;
	for(n=2;n<=1000;n++) {
		if(prime[n]==0) {
			i=n*2;
			while(i<=1000000) {
				prime[i]=1;
				i+=n;
			}
		}
	}
	for(n=2;n<=1000000;n++) {
		num[n]+=num[n-1];
		if(prime[n]==0) {
			num[n]++;
		}
	}
	int N,M;
	int x,y;
	scanf("%d%d",&N,&M);
	for(n=1;n<=N;n++) {
		scanf("%d%d",&x,&y);
		if(x>=1&&y>=1&&x<=M&&y<=M) {
			printf("%d\n",num[y]-num[x-1]);
		} else {
			printf("Crossing the line\n");
		}
	}
	return 0;
}
