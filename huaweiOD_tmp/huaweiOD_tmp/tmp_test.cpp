#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
    int bk(0);    //��������
    int arr[1000];    //�����������
    int weight(0);    //��¼�ۻ�����
    int idx(0);
    while (scanf_s("%d,", arr[idx++]));    //����
    int len = idx;    //��¼�������
    cin >> bk;
    sort(arr, arr + len);    //����
    for (int i{}; i < len; i++)
        cout << arr[i] << " ";
    for (int i = 0; i < len; i++) {
        if (weight > bk) {
            idx = i + 1;
            break;
        }
    }
    cout << idx << endl;
    return 0;
}