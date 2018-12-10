#include <cstdio>
#include <thread>
using namespace std;

long long mem[101]={0};

long long f(int n) {
	if(mem[n]) {
		return mem[n];
	}
	if(n==1||n==2) {
		return 1;
	} else {
		return f(n-1)+f(n-2);
	}
}

int main() {
	thread threads[8];
	int i;
	for(i=1;i<=80;i++) {
		mem[i]=f(i);
		printf("f(%d)=%lld\n",i,mem[i]);
	}
	return 0;
}
