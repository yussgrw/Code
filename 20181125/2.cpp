#include <cstdio>
#include <cmath>
#include <memory.h>

int prime[300];
int isPrime[500+5]={0};
int pcnt=0;
long long b[1<<20]={0ll};
long long p;
long long w[1<<20]={0ll};
long long c[1<<20]={0ll};
int N;
int MAX;

void Prime() {
	prime[++pcnt]=2;
	int a,i;
	for(a=3;a<=500;a+=2) {
		if(!isPrime[a]) {
			prime[++pcnt]=a;
		}
		for(i=2;i<=pcnt;i++) {
			if(a*prime[i]>500) {
				break;
			}
			isPrime[a*prime[i]]=1;
			if(!(a%prime[i])) {
				break;
			}
		}
	}
	for(i=1;prime[i]<=N;i++) ;
	MAX=i-1;
//	printf("MAX=%d\n",MAX);
}

long long quickpow(long long x, long long y) {
	long long res=1ll;
//	x%=p;
	while(y) {
		if(y&1) {
			res=(res*x)%p;
		}
		x=(x*x)%p;
		y>>=1;
	}
	return res;
}

void init() {
	int i,k,n,j;
	int arr[26],cnt;
	int a[500+5];
	long long res;
	for(i=1;i<(1<<MAX);i++) {
		cnt=0;
		memset(a,0,sizeof(a));
		for(k=1;k<=MAX;k++) {
			if(i&(1<<(k-1))) {
				arr[++cnt]=prime[k];
				a[prime[k]]=1;
			}
		}
		res=0ll;
		for(k=2;k<=N;k++) {
			if(a[k]) {
//				printf("%d ",k);
				res++;
				for(n=1;n<=cnt;n++) {
					if(arr[n]*k<=N) {
						a[arr[n]*k]=1;
					}
				}
			}
		}
		w[i]=res;
//		printf("\n%d %lld\n",i,w[i]);
	}
	w[0]=0ll;
	long long sum;
	for(i=1;i<(1<<MAX);i++) {
		sum=0ll;
		for(j=i&(i-1);j;j=i&(j-1)) {
			sum=(sum+b[j])%p;
		}
		sum++;
		b[i]=quickpow(2,w[i])-sum%p;
		b[i]+=p;
		b[i]%=p;
		c[i]=(b[i]+sum)%p;
//		printf("b[%d]=%lld\n",i,b[i]);
//		printf("%d %lld\n",i,b[i]);
	}
	b[0]=1ll%p;
	c[0]=1ll%p;
}

void dp() {
	int x=(1<<MAX)-1,i;
	long long res=0ll;
	for(i=x;i;i=x&(i-1)) {
		res=(res+(b[i]*quickpow(2,w[i^x]))%p)%p;
	}
	res=(res+(b[0]*quickpow(2,w[x]))%p)%p;
	printf("%lld\n",res);
}

void run() {
	long long res=0;
	int i,k;
	for(i=0;i<(1<<MAX);i++) {
		k=(1<<MAX)-1-i;
/*		for(j=k;j;j=k&(j-1)) {
			res=(res+b[i]*b[j])%p;
		}
*/		res=(res+(b[i]*c[k])%p)%p;
	}
	printf("%lld\n",res);
}

int main() {
	scanf("%d %lld",&N,&p);
	Prime();
	init();
	run();
	dp();
	return 0;
}
