#include <cstdio>
#include <thread>
using namespace std;

void f(int n) {
	while(true) {
		printf("thread %d\n",n);
	}
}

int main() {
	thread th[8];
	const int N = 8;
	int n;
	for(n=0;n<N;n++) {
		th[n]=thread(f,n);
	}
	for(n=0;n<N;n++) {
		th[n].join();
	}
	return 0;
}
