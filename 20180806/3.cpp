#include <cstdio>

int main() {
	int a,b,max;
	scanf("%d,%d",&a,&b);
	if(a>b) {
		max=a;
	} else if(a<b) {
		max=b;
	}
	printf("max=%d\n",max);
	return 0;
}
