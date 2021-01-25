#include <iostream>
#include <vector>

using namespace std;

int n, deleteNode;
pair<int, bool> parent[51];     //�θ���, true - leaf�ƴ� false - leaf��
vector<int> ancestor[51];

int countLeaf(void){
        for(int i = 0; i < n; i++)                  //���� �߿� deleteNode�� ������ ������ ����̹Ƿ�
            for(int j = 0; j < ancestor[i].size(); j++)
                if(ancestor[i][j] == deleteNode)
                    parent[i].second = true;        //leaf�� �ƴϴ�
        for(int i = 0; i < n; i++)                  //������ ��� �����ϰ� �ٽ� �ڽ� ���� �ľ�
            if(i!=deleteNode)
                parent[parent[i].first].second = true; //leaf�� �ƴϴ�
        //leaf ��� ���� ����
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(parent[i].second == false)
                cnt++;
        return cnt;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &parent[i].first);
        parent[parent[i].first].second = true;
    }
    for(int i = 0; i < n; i++){         //����
        int curParent = parent[i].first;
        while(curParent != -1){
            ancestor[i].push_back(curParent);
            curParent = parent[curParent].first;
        }
    }
    scanf("%d", &deleteNode);
    parent[deleteNode].second = true;  //������ ���� leaf�� �ƴϴ�
    parent[parent[deleteNode].first].second = false; //������ ����� �θ�� leaf�̴�
    cout << countLeaf() << endl;
    return 0;
}