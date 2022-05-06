#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
    int bk(0);    //货车载重
    int arr[1000];    //快递重量数组
    int weight(0);    //记录累积重量
    int idx(0);
    while (scanf_s("%d,", arr[idx++]));    //输入
    int len = idx;    //记录快递数量
    cin >> bk;
    sort(arr, arr + len);    //排序
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