#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	int N;
	srand(time(NULL));
	scanf("%d",&N);
	int n;
	printf("%d\n",N);
	for(n=1;n<N;n++) {
		printf("%d ",rand());
	}
	printf("%d\n",rand());
	return 0;
}
