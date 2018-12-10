#include <cstdio>
#include <cmath>

int main() {
	int a;
	int i;
	int sq;
	int flag;
	while(true) {
		scanf("%d",&a);
		if(!(a%2)) {
			printf("2*%d\n",a/2);
		} else {
			flag=1;
			sq=(int)sqrt(a);
			for(i=3;i<=sq;i++) {
				if(!(a%i)) {
					printf("%d*%d\n",i,a/i);
					flag=0;
					break;
				}
			}
			if(flag) {
				printf("prime\n");
			}
		}
	}
	return 0;
}
