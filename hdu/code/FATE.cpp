#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int n, m, k, s;	//����ľ����������������Ͷȣ������������������ɱ����
int dp[101][101];	//dp[i][j] = k��ʾ��ʣ���;ö�Ϊi,ɱ����Ϊjʱ�õ������exp
int exps[101], cost[101];

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	while(~scanf("%d %d %d %d", &n, &m, &k, &s)){
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= k; i++){
			scanf("%d %d", &exps[i], &cost[i]);
		}
		
		for(int u = 1; u <= k; u++){
			for(int i = cost[u]; i <= m; i++){
				for(int j = 1; j <= s; j++){
					dp[i][j] = max(dp[i][j], dp[i - cost[u]][j - 1] + exps[u]);
				}
			}
		}
		
		int i;
		for(i = 1; i <= m; i++){
			if(dp[i][s] >= n)
				break;
		}
		
		if(i <= m)	printf("%d\n", m - i);
		else printf("-1\n");
	}
	return 0;
} 
