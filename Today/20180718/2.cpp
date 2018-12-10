#include <cstdio>
#include <cstdlib>

int main() {
	int T;
	scanf("%d",&T);
	srand(19260817);
	int t;
	for(t=1;t<=T;t++) {
		printf("%d\n",rand());
	}
	return 0;
}
