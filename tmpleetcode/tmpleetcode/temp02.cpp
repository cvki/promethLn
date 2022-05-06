/****318. 最大单词长度乘积
给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，并且这两个单词不含有公共字母。
如果不存在这样的两个单词，返回 0 。

示例 1：
输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
输出：16 
解释：这两个单词为 "abcw", "xtfn"。

示例 2：
输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
输出：4 
解释：这两个单词为 "ab", "cd"。

示例 3：
输入：words = ["a","aa","aaa","aaaa"]
输出：0 
解释：不存在这样的两个单词。
 

提示：

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] 仅包含小写字母***/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

int maxProduct(vector<string>& words) {
	int len = words.size();
	//开辟空间
	int** arr26 = new int* [len];
	for (int i = 0; i < len; i++)
		arr26[i] = new int[26]();
	//转为26位二进制
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < words[i].size(); j++) {
			arr26[i][words[i][j] - 'a'] = 1;
		}
	}


	//测试：转换结果
	for (int i = 0; i < len; i++) {
		cout << "arr" << "-" << i << ":  " ;
		for (int j = 0; j <26; j++) {
			cout<<arr26[i][j];
		}
		cout << endl;
	}


	int tem = 0, res = 0;	//记录临时和最终结果
	//暴力寻找不同字符串
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			bool itag = true;
			for (int k = 0; k < 26; k++) {
				if (arr26[i][k] && arr26[j][k]) {//有相同字母
					itag = false;
					break;
				}	
			} 
			if(itag)
			{
				tem = words[i].size() * words[j].size();
				if (tem > res) //取最大值
					res = tem;
			}
		}
	}

	//释放空间
	for (int i = 0; i < len; i++)
		delete[] arr26[i];
	delete[] arr26;

	return res;
}


//测试
int main2() {

	// { "abcw","baz","foo","bar","xtfn","abcdef" };
	// { "a", "ab", "abc", "d", "cd", "bcd", "abcd" };
	vector<string> v = { "a","aa","aaa","aaaa" };
	int r = maxProduct(v);
	cout << r << endl;
	return 0;
}