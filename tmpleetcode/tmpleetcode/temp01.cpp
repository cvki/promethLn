
/***΢��2020���ʵϰ�������2��
* ��һ���ַ�����ÿ�ο����Ƴ�����һ���ַ��������Ƴ�һ�������Ӵ����� ȫ���Ƴ��������ٴ���
* ���磺1��4��3��1��5.  ���Ƴ� 3�� ���Ƴ� 1 4 1�� ���Ƴ� 5�� �õ����ٴ��� 3
***/

#include<iostream>
#include<vector>

using namespace std;

int getlenHW(vector<char>& arr) {
    int n = arr.size();
    cout << "arr size:" <<n<< endl;
    //dp[i][j]��ʾɾ����i��j��������������ٲ�������
    int **dp = new int* [n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int[n]();
    }
    //l��ʾ��ǰ���ֵĳ���
    for (int l = 1; l <= n; l++) {
        int i = 0, j = l - 1,k=0;
        while (j < n) {

            if (l == 1) {
                //base��ÿ�����ֵ�ɾ������Ϊ1
                dp[i][j] = 1;
            }
            else {
                //�����ǻ����Ӵ�������£�ɾ������Ϊ֮ǰ��ɾ������+1
                dp[i][j] = 1 + dp[i + 1][j];
                //���ǻ����Ӵ�
                for (k = i + 1; k <= j; k++) {
                    if (k == j) {
                        if (arr[i] == arr[j]) {
                            dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + (i + 1 == k ? 1 : 0));
                        }
                        break;
                    }
                    if (arr[i] == arr[k]) {
                        //����dp[i][j]
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j] + (i + 1 == k ? 1 : 0));
                    }
                   
         
                }

            }

            cout << "l= " << l << ", i=" << i << ", j=" << j << ", k=" << k << "... \t  dp: " << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cout << dp[i][j] << "\t";
                cout << endl;
            }


            i++;
            j++;

            

        }
    }

  /*  for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << "\t";
        cout << endl;
    }*/
    
    int val = dp[0][n - 1];

    for (int i = 0; i < n; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return val;

}

int mainx01() {

    string s;
    cin >> s;
    vector<char> v;
    for (auto e : s)
        v.push_back(e);
    
    for (auto e : v)
        cout << e;

    cout << endl;

    cout << getlenHW(v) << endl;
    return 0;
}