#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int n, m;
string str;
map<string, bool> mp;
int result = 0;

int main(){
    scanf("%d %d",&n, &m);
    for(int i = 0; i < n; i++){
        cin >> str;
        mp[str] = true;            // == mp = {{str,true}}
    }
    for(int i = 0; i < m; i++){
        cin >> str;
        if(mp[str])
            result++;
    }
    printf("%d", result);
}
/*
1. map<Ÿ��, Ÿ��> ������ :: ���� ���
2. �������� m�̶�� ������ ��
m[0] = 1�� m1 = { {0,1} }�� ���� �ǹ�
�� �ܿ��� Vector STL�� ���� �Լ� ����� �̷�� �ִ�.
3. Ư���� ���� �ִٸ� map STL������ map<string, Ÿ��> m;�� �����ϸ�
m["abc"] = �� �̷������� [ ]���̿� string�� �� �� �ִ�.
*/