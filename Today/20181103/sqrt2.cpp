#include <cstdio>

int main() {
	double a=1.0,d=1.0;
	int cnt=0;
	while(cnt<10) {
		while((a+d)*(a+d)<=2.0) {
			a+=d;
		}
		printf("%f\n",a);
		d/=10.0;
		cnt++;
	}
	return 0;
}
