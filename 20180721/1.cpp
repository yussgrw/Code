#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	int N;
	FILE *fin,*fout;
	fin=fopen("IN","r");
	fout=fopen("sort.in","w");
	fscanf(fin,"%d",&N);
	fprintf(fout,"%d\n",N);
	int n;
	srand(time(NULL)*time(NULL));
	for(n=1;n<N;n++) {
		fprintf(fout,"%u ",rand());
	}
	if(N>0) {
		fprintf(fout,"%u\n",rand());
	}
	return 0;
}
