#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M, P, TC, T, C[31];
bool v[101000];
struct student{
	char name[23];
	int shot, height;
	bool operator <(const student &s1)const{
		return shot != s1.shot ? shot < s1.shot : height < s1.height;
	}
}w[31];
struct Result{
	char name[23];
	bool operator <(const Result &s1)const{
		return strcmp(name, s1.name) < 0;
	}
}R[31];
void Do(int a){
	int i, MM, x, y;
	MM = 0;
	for (i = a; i <= N; i += 2){
		if (v[i] && MM <= C[i])MM = C[i], x = i;
	}
	MM = 99999999;
	for (i = a; i <= N; i += 2){
		if (!v[i] && MM > C[i])MM = C[i], y = i;
	}
	v[x] = false, v[y] = true;
}
int main()
{
	int i, j, c;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
		scanf("%d%d%d", &N, &M, &P);
		for (i = 1; i <= N; i++){
			scanf("%s%d%d", w[i].name, &w[i].shot, &w[i].height);
			w[i].shot = 100 - w[i].shot, w[i].height = 300 - w[i].height;
		}
		sort(w + 1, w + N + 1);
		for (i = 1; i <= 2*P; i++)v[i] = true;
		for (i = 2 * P + 1; i <= N; i++)v[i] = false;
		for (i = 1; i <= M; i++){
			for (j = 1; j <= N; j++)if (v[j])C[j]++;
			if (N > P * 2)
				Do(1);
			if (N > P * 2 + 1)
				Do(2);
		}
		c = 0;
		for (i = 1; i <= N; i++){
			C[i] = 0;
			if (v[i]){
				for (j = 0; w[i].name[j]; j++){
					R[c].name[j] = w[i].name[j];
				}
				R[c].name[j] = 0;
				c++;
			}
		}
		sort(R, R + c);
		for (i = 0; i < c; i++){
			printf("%s ", R[i].name);
		}
		printf("\n");
	}
}