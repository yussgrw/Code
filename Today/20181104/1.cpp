#include <cstdio>

int main() {
	int M;
	scanf("%d",&M);
	int a1=1,a2=1,an;
	int n;
	int flag=0;
	for(n=3;;n++) {
		an=(a1+a2)%M;
		if(an==1) {
			if(flag!=0) {
				printf("%d\n",flag);
				return 0;
			}
		}
		if(an==0) {
			flag=n;
		} else {
			flag=0;
		}
		a1=a2;
		a2=an;
	}
	return 0;
}
