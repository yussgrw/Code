#include <cstdio>

void dfs(int n) {
	if(!n) {
		return ;
	}
	int a=n;
	dfs(n-1);
}

int main() {
	dfs(1000000);
	return 0;
}
