#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int t, n;
string s;
vector<string> v;
int main(){
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        v.resize(0);                        //�����ʱ�ȭ
        bool result = true;                 //�����ʱ�ȭ
        for(int j = 0; j < n; j++){
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());           //����
        for(int k = 0; k < v.size()-1; k++){
            int tmp = 0;
            for(int m = 0; m < v[k].length(); m++){
                if(v[k][m] == v[k+1][m])    //���ڰ� ������ 1������
                    tmp++;
            }
            if(tmp == v[k].length()){       //���ٴ� ���� ���ξ��� ��
                printf("NO\n");
                result = false;
                break;
            }
        }
        if(result == true)
            printf("YES\n");
    }
}