#include <iostream>
#include <algorithm>

using namespace std;

int n, maximum = 0;
int t[16],p[16], dp[16] = {0};

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &t[i], &p[i]);
    for(int i = 0; i < n; i++){
        maximum = *max_element(dp, dp + i);         //���� �߰��Ǵ� �� ���������� ������ ���� ū��
        if(i+t[i] <= n){
            dp[i+t[i]-1] = max(maximum + p[i], dp[i+t[i]-1]);       //t��ŭ�� �ð� �� ������ �ִٰ� ����
        }
    }
    maximum = *max_element(dp, dp + n);
    printf("%d", maximum);
}