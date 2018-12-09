#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	const int N = 1000;
	int n;
	srand(time(NULL));
	for(n=1;n<=N;n++) {
		putchar(rand()%26+'a');
	}
	putchar('\n');
	for(n=1;n<=N;n++) {
		putchar(rand()%26+'a');
	}
	return 0;
}
