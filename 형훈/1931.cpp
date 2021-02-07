#include <iostream>
#include <algorithm>
#include <vector>;
using namespace std;
struct time
{
	int start;
	int end;
};
bool compare(time t1, time t2);
int main() {
	int n, cnt = 0, tmp = 0;	//cnt�� ȸ�� Ƚ������ tmp�� �ӽú���
	bool check = false;
	scanf("%d", &n);
	vector<time> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].start, &v[i].end);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].start >= tmp) {
			tmp = v[i].end;
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}

bool compare(time t1, time t2) {	//compare���� �����½ð����� ����, ���ٸ� ���۽ð� ������
	if (t1.end == t2.end)
		return t1.start < t2.start;
	else
		return t1.end < t2.end;
}