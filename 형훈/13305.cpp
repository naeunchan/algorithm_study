#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long tmp, result = 0;
vector<long long> dis;
vector<long long> city;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d", &tmp);
        dis.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &tmp);
        city.push_back(tmp);
    }
    long long cost_oil = city[0];
    for(int i = 0; i < n-1; i++){
        cost_oil = min(cost_oil, city[i]);      //������ ���� �� ���ÿ� ���� ������ �⸧�� ��
        result += (cost_oil * dis[i]);          //�� �� ���ÿ��� �Ÿ���ŭ�� �⸧�� ��
    }
    printf("%lld", result);
}