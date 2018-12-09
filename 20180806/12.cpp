#include <cstdio>
#include <thread>
using namespace std;

void f(int n) {
	while(true) {
		printf("Thread %d\n",n);
	}
}

int main() {
	thread th1,th2;
	th1=thread(f,1);
	th2=thread(f,2);
	th1.join();
	th2.join();
	return 0;
}
