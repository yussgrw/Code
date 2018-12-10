#include <cstdio>
#include <thread>
using namespace std;

void f() {
	while(true);
}

int main() {
	thread threads[8];
	int i;
	for(i=0;i<8;i++) {
		threads[i]=thread(f);
	}
	for(i=0;i<8;i++) {
		threads[i].join();
	}
	return 0;
}
