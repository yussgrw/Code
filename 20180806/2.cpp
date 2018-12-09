#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));
	FILE *fin,*fout;
	fin=fopen("IN","r");
	fout=fopen("sort.in","w");
	int N;
	fscanf(fin,"%d",&N);
	fprintf(fout,"%d\n",N);
	register int n;
	for(n=1;n<N;n++) {
		fprintf(fout,"%u ",rand());
	}
	fprintf(fout,"%u\n",rand());
	return 0;
}
