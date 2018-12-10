#include <cstdio>
#include <cmath>

long long a0,a1,b0,b1;

long long gcd(long long x, long long y) {
	return y?gcd(y,x%y):x;
}

void solve() {
	if(b1%b0!=0) {
		printf("0\n");
		return;
	}
	long long x=b1/b0;
	long long a;
	int res=0;
	for(a=1;a<=(long long)sqrt(b0);a++) {
		if(b0%a==0) {
			if(gcd(a*x,b0)==a) {
				if(gcd(a*x,a0)==a1) {
//					printf("%lld ",a*x);
					res++;
				}
			}
			if(a*a==b0) {
				continue;
			}
			a=b0/a;
			if(gcd(a*x,b0)==a) {
				if(gcd(a*x,a0)==a1) {
//					printf("%lld ",a*x);
					res++;
				}
			}
			a=b0/a;
		}
	}
	printf("%d\n",res);
}

int main() {
	int T,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++) {
		scanf("%lld%lld%lld%lld",&a0,&a1,&b0,&b1);
		solve();
	}
	return 0;
}
