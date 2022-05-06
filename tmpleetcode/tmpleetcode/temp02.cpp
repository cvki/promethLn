/****318. ��󵥴ʳ��ȳ˻�
����һ���ַ������� words ���ҳ������� length(words[i]) * length(words[j]) �����ֵ���������������ʲ����й�����ĸ��
����������������������ʣ����� 0 ��

ʾ�� 1��
���룺words = ["abcw","baz","foo","bar","xtfn","abcdef"]
�����16 
���ͣ�����������Ϊ "abcw", "xtfn"��

ʾ�� 2��
���룺words = ["a","ab","abc","d","cd","bcd","abcd"]
�����4 
���ͣ�����������Ϊ "ab", "cd"��

ʾ�� 3��
���룺words = ["a","aa","aaa","aaaa"]
�����0 
���ͣ��������������������ʡ�
 

��ʾ��

2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] ������Сд��ĸ***/


#include<iostream>
#include<vector>
#include<string>

using namespace std;

int maxProduct(vector<string>& words) {
	int len = words.size();
	//���ٿռ�
	int** arr26 = new int* [len];
	for (int i = 0; i < len; i++)
		arr26[i] = new int[26]();
	//תΪ26λ������
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < words[i].size(); j++) {
			arr26[i][words[i][j] - 'a'] = 1;
		}
	}


	//���ԣ�ת�����
	for (int i = 0; i < len; i++) {
		cout << "arr" << "-" << i << ":  " ;
		for (int j = 0; j <26; j++) {
			cout<<arr26[i][j];
		}
		cout << endl;
	}


	int tem = 0, res = 0;	//��¼��ʱ�����ս��
	//����Ѱ�Ҳ�ͬ�ַ���
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			bool itag = true;
			for (int k = 0; k < 26; k++) {
				if (arr26[i][k] && arr26[j][k]) {//����ͬ��ĸ
					itag = false;
					break;
				}	
			} 
			if(itag)
			{
				tem = words[i].size() * words[j].size();
				if (tem > res) //ȡ���ֵ
					res = tem;
			}
		}
	}

	//�ͷſռ�
	for (int i = 0; i < len; i++)
		delete[] arr26[i];
	delete[] arr26;

	return res;
}


//����
int main2() {

	// { "abcw","baz","foo","bar","xtfn","abcdef" };
	// { "a", "ab", "abc", "d", "cd", "bcd", "abcd" };
	vector<string> v = { "a","aa","aaa","aaaa" };
	int r = maxProduct(v);
	cout << r << endl;
	return 0;
}