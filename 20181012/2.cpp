#include <cstdio>

int main() {
	int _;
	char __;
	int ___=8;
	scanf("%d %c",&_,&__);
	if(__=='y') {
		___+=5;
	}
	if(_>1000) {
		_-=1000;
		___+=_/500*4+(_%500==0?0:4);
	}
	printf("%d\n",___);
	return 0;
}
