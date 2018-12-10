#include <cstdio>
#include <cmath>

long long k;

long long run1() {
	int sq=sqrt(k);
	int n;
	for(n=sq;n>2;n--) {
		if(!(k%n)) {
			if(n%2) {
				if((k/n)-(n/2)>0) {
					return n;
				}
			}
		}
	}
	return 1;
}

int main() {
	scanf("%lld",&k);
	long long x,y=1;
	x=run1();
	long long tmp=k/x;
	while(tmp%2==0) {
		tmp>>=1;
		y<<=1;
	}
	y=y*2*x;
	if((k/y-y/2+1)>0) {
		printf("%lld %lld\n",k/y-y/2+1,k/y-y/2+y);
	} else {
		printf("%lld %lld\n",k/x-x/2,k/x+x/2);
	}
	return 0;
}
