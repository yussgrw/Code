#include <cstdio>

int main() {
	int a=4,b=6;
	int s=0,n=0;
	do {
		a=b-a;
		b=b-a;
		a=b+a;
		s=s+a;
		n++;
	} while(s<=16);
	printf("%d\n",n);
	return 0;
}
