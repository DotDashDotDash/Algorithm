#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
 
using namespace std;
double a[33];
double dp[33][33];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,i,t;
    double q,s,A,B,C;
    char c,cc;
    while(scanf("%lf%d",&q,&n)&&n)
    {
        memset(a,0,sizeof(a));
        memset(dp, 0, sizeof dp);
        int cnt=0;
        double ans=0;
        while(n--)
        {
            A=B=C=0;
            scanf("%d",&t);
            while(t--)
            {
                cin>>c>>cc>>s;//ע�������ʽ
                if(c!='A'&&c!='B'&&c!='C')//��ABC�಻��
                {
                    A=B=C=0;
                    break;
                }
                if(c=='A')
                    A+=s;
                if(c=='B')
                    B+=s;
                if(c=='C')
                    C+=s;
            }
            if(A<=600&&B<=600&&C<=600)//ÿһ�������600
                a[cnt]=A+B+C;
            if(a[cnt]>1000)//�ܺͲ�����1000
                a[cnt]=0;
            ++cnt;
        }
        sort(a,a+cnt,cmp);//����
        double res = 0;
        for(i = 1; i <= cnt; i++){
        	for(int j = 1; j <= i; j++){
        		dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i]);
        		if(dp[i][j] <= q)
        			res = max(dp[i][j], res);
			}
		}
        printf("%.2lf\n",res);
    }
    return 0;
}
