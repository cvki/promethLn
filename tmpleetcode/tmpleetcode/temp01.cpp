
/***微软2020暑假实习笔试题第2题
* 给一个字符串，每次可以移除其中一个字符，或者移除一个回文子串，求 全部移除所需最少次数
* 例如：1，4，3，1，5.  先移除 3， 再移除 1 4 1， 再移除 5， 得到最少次数 3
***/

#include<iostream>
#include<vector>

using namespace std;

int getlenHW(vector<char>& arr) {
    int n = arr.size();
    cout << "arr size:" <<n<< endl;
    //dp[i][j]表示删除从i到j的数字所需的最少操作次数
    int **dp = new int* [n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int[n]();
    }
    //l表示当前数字的长度
    for (int l = 1; l <= n; l++) {
        int i = 0, j = l - 1,k=0;
        while (j < n) {

            if (l == 1) {
                //base，每个数字的删除次数为1
                dp[i][j] = 1;
            }
            else {
                //不考虑回文子串的情况下，删除次数为之前的删除次数+1
                dp[i][j] = 1 + dp[i + 1][j];
                //考虑回文子串
                for (k = i + 1; k <= j; k++) {
                    if (k == j) {
                        if (arr[i] == arr[j]) {
                            dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + (i + 1 == k ? 1 : 0));
                        }
                        break;
                    }
                    if (arr[i] == arr[k]) {
                        //更新dp[i][j]
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