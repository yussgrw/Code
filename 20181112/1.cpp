#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	int N=100000;
	printf("%d\n",N);
	srand(time(NULL));
	int n,i;
	for(n=1;n<=10;n++) {
		for(i=10000;i>0;i--) {
			printf("%d ",i);
		}
	}
	putchar('\n');
	return 0;
}
