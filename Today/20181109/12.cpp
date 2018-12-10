#include <cstdio>

int main() {
	double a=0;
	int i;
	int N;
	scanf("%d",&N);
	if(N==1) {
		printf("0.00000\n");
	} else if(N==2) {
		printf("2.00000\n");
	} else {
		for(i=1;i<=N-2;i++) {
			a+=(double)1/(double)i;
		}
		a+=(double)N/(double)(N-1);
		printf("%.5f\n",a);
	}
	return 0;
}
