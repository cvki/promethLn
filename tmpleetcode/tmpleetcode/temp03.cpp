/***һ�����������ɸ�������ɣ��������������������С��������
* ��{1��2��4��-5}, ����3; {-2} ����1 
***/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getthenum(vector<int>& v) {
	
	int len = v.size();
	sort(v.begin(), v.end());
	int* arr = new int[len]();	//�洢���е�����
	int idx = 0;

	//ȥ������
	for (auto e : v)
		if (e > 0)
			arr[idx++] = e;
	int lenarr = idx;
	if (!idx)	//��ʱarrΪ��
		return 1;

	int* res = new int[lenarr]();	//�洢���еķ��ظ�����
	
	//��ӡ�������
	for (int g = 0; g < lenarr; g++)
		cout << arr[g] << ",";
	cout << endl;

	//ȥ��
	res[0] = arr[0];
	int i = 0;
	for (idx = 1; idx < lenarr;) {	//i-res,idx-arr
		if (arr[idx] == res[i]) {
			idx++;
			continue;
		}
		res[++i] = arr[idx++];
	}
	lenarr = i+1;

	//��ӡ�������
	for (int g = 0; g < lenarr; g++)
		cout << res[g] << ",";
	cout << endl;

	//����
	i = 0;
	for (; i < lenarr; i++)
		if (res[i] > i + 1)
			return i+1;
	return i + 1; //���������Ҳû���أ�˵�������������򷵻��������ֵ+1
}

int main03() {
	//-4, 0, 8, -5, 7, -2, 7, 9, 11, -1, 1, 4, 3, 3, 2, -6, 2
	// { -2, 0, 2, 2, 1};
	// { -2,-23,23,2,242,-23,34,1,3,2,3,1,8,6,7,3,9,2,1,9,11,12,1,-2,1,10,12,14,5,12,3,10,817,16,6,12,4,6,5,7,8,6,10,-23,-34,-45,-657,4,7, };
	vector<int> v ={1,1,1,1,1,1,3,3,3,2};
	int r = getthenum(v);
	cout << r << endl;
	return 0;
}