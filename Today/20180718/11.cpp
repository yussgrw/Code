#include <cstdio>

inline void print(int n) {
	if(n>9) {
		print(n/10);
	}
	putchar(n%10+'0');
}

int main() {
	int i;
	for(i=1;i<=1000000;i++) {
		print(i);
		putchar('\n');
	}
	return 0;
}
