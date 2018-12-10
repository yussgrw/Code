#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	int N;
	scanf("%d",&N);
	srand(time(NULL));
	int n;
	FILE *fout;
	fout=fopen("sort.in","w");
	fprintf(fout,"%d\n",N);
	for(n=1;n<N;n++) {
		fprintf(fout,"%d ",rand());
	}
	fprintf(fout,"%d\n",rand());
	fclose(fout);
	return 0;
}
