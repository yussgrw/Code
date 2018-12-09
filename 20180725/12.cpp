#include <cstdio>
#include <cmath>

int main() {
	int a;
	int i;
	int sq;
	int flag;
	while(true) {
		scanf("%d",&a);
		if(a==2) {
			putchar('Y');
			putchar('\n');
			continue;
		}
		if(a%2==0) {
			printf("N 2\n");
			continue;
		}
		sq=(int)sqrt(a);
		flag=1;
		for(i=3;i<=sq;i+=2) {
			if(a%i==0) {
				flag=0;
				break;
			}
		}
		if(flag==0) {
			printf("N %d\n",i);
		} else {
			putchar('Y');
			putchar('\n');
		}
	}
	return 0;
}
