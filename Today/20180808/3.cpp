#include <cstdio>
#include <cmath>

int isPrime[50000000+1]={0};

int main() {
	int MIN,MAX;
	scanf("%d%d",&MIN,&MAX);
	int a;
	int i;
	int tmp;
	int sq=(int)sqrt(MAX);
	if(MIN<=2&&MAX>=2) {
		putchar('2');
		putchar('\n');
	}
	for(a=3;a<=sq;) {
		for(i=3;;i+=2) {
			tmp=a*i;
			if(tmp>MAX) {
				break;
			}
			isPrime[tmp]=1;
		}
		do {
			a+=2;
		} while(isPrime[a]);
	}
	if(MIN==1) {
		i=3;
	} else if(MIN%2) {
		i=MIN;
	} else {
		i=MIN+1;
	}
	for(;i<=MAX;i+=2) {
		if(!isPrime[i]) {
			printf("%d\n",i);
		}
	}
	return 0;
}
