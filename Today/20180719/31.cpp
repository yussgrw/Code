#include <cstdio>

int main() {
	long long n,m,a;
	scanf("%I64d%I64d%I64d",&n,&m,&a);
	long long x=n/a;
	long long y=m/a;
	if(n%a!=0) {
		x++;
	}
	if(m%a!=0) {
		y++;
	}
	printf("%I64d\n",x*y);
	return 0;
}
