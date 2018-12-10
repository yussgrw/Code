#include <cstdio>

int main() {
	float a[11];
	a[1]=3.0/2.0;
	float sum=1.0/a[1];
	int i;
	for(i=2;i<=10;i++) {
		printf("%f %f\n",sum,a[i-1]);
		a[i]=a[i-1]*(a[i-1]-1)+1.0;
		sum+=1.0/a[i];
	}
	printf("%f %f\n",sum,a[i-1]);
	return 0;
}
