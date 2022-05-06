
/***
1. ����֮��
����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
����԰�����˳�򷵻ش𰸡�

ʾ�� 1��
���룺nums = [2,7,11,15], target = 9
�����[0,1]
���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��

ʾ�� 2��
���룺nums = [3,2,4], target = 6
�����[1,2]
ʾ�� 3��
���룺nums = [3,3], target = 6
�����[0,1]
 
��ʾ��
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
ֻ�����һ����Ч��
���ף���������һ��ʱ�临�Ӷ�С�� O(n2) ���㷨��
**/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//����ΪO(n^2), O(n)������hashtable����
vector<int> twoSum(vector<int>& nums, int target) {
    //O(n^2)
    int left = 0, right = 1;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < len && j != i; j++) {
            if (nums[i] + nums[j] == target)
                return vector<int> {left = i, right = j};
        }
    }
    return vector<int>{left, right};
}

int main_04() {
    vector<int> v1{ 3,2,4 };
    int target = 6;
    vector<int> v2;
    v2 = twoSum(v1, target);
    for (int e : v2)
        cout << e << " ";
    cout << endl;
    return 0;
}


/**88. �ϲ�������������
���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�
ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��

ʾ�� 1��
���룺nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
�����[1,2,2,3,5,6]
���ͣ���Ҫ�ϲ� [1,2,3] �� [2,5,6] ��
�ϲ������ [1,2,2,3,5,6] ������б��Ӵֱ�ע��Ϊ nums1 �е�Ԫ�ء�

ʾ�� 2��
���룺nums1 = [1], m = 1, nums2 = [], n = 0
�����[1]
���ͣ���Ҫ�ϲ� [1] �� [] ��
�ϲ������ [1] ��

ʾ�� 3��
���룺nums1 = [0], m = 0, nums2 = [1], n = 1
�����[1]
���ͣ���Ҫ�ϲ��������� [] �� [1] ��
�ϲ������ [1] ��
ע�⣬��Ϊ m = 0 ������ nums1 ��û��Ԫ�ء�nums1 �н���� 0 ������Ϊ��ȷ���ϲ��������˳����ŵ� nums1 �С�

��ʾ��
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

���ף���������ʵ��һ��ʱ�临�Ӷ�Ϊ O(m + n) ���㷨�����������
**/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int* tmp = new int[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) 
            tmp[k++] = nums1[i++];
        else 
            tmp[k++] = nums2[j++];
    }
    while (i < m) 
       tmp[k++] = nums1[i++];
    while (j < n) 
       tmp[k++] = nums2[j++];
    for (i = 0; i < k; i++)
        nums1[i] = tmp[i];
    for (int e : nums1)
        cout << e << " ";
    delete[] tmp;
    cout << endl;
}
int mainx04() {
    /*vector<int> v1{ 1,2,3,0,0,0 }, v2{2,5,6};
    int m = 3;
    int n = 3;
    merge(v1, m, v2, n);*/

    /*vector<int> v;
    v.insert(v.end(), 3, 2);    //��vectorβ������3��2
    for (int e : v)
        cout << e << " ";
    cout << endl;*/

    return 0;
}


/***����
���ݱ��¼��������������ֵ��int��Χ��������������Ա�������ͬ�ļ�¼���кϲ���������ͬ��������ֵ����������㣬�������keyֵ������������

��ʾ:
0 <= index <= 11111111
1 <= value <= 100000

����������
�������ֵ�Եĸ���n��1 <= n <= 500��
Ȼ������ɶԵ�index��valueֵ���Կո����

���������
����ϲ���ļ�ֵ�ԣ����У�

ʾ��1
���룺
4
0 1
0 2
1 2
3 4

�����
0 3
1 2
3 4

ʾ��2
���룺
3
0 1
0 2
8 9

�����
0 3
8 9****/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int main_05() {
    vector<unordered_map<int, int>> vecxx; //��ϣmap
    vector<pair<int, int>> vec;  
    //��Ϊvector�ڲ����Ϊmap<x,y>��key-vaule��ʽʱ��for�����õ���Ԫ��������pair(��ʹ����auto��Ҳ�ǣ�ָ�����ͻ����������Ҳ�����á�
    //�����ײ�(ʵ����)����hashmap�ṹ��Ч�ʻ���hash��Ч�ʣ�ֻ���﷨�ϣ�������Ҫpair�Ĳ���ƥ��)
    unordered_map<int, int> hashmap;
    int len, key, val;
    cin >> len;
    if (!len)
        return 0;
    for (int i = 0; i < len; ++i) {
        cin >> key >> val;
        //hashmap��������ڲ������ֲ��������������������һֱ��map����䣬Ȼ��ÿ�μӽ�vector�ͻ��ظ����������ڲ�ÿ��ѭ���������ͷš�
        //vec��pushʱ��Ҳ��Ҫʹ������(��������ƶ����죬��ôѭ���������ͱ��ͷţ�hashmap�ͱ����Ұָ�룬vec��������Ұָ��)
        //����ʱҲ�����⣬����Ҫ��hashmapѰ���Ƿ����ظ�����ÿ��ѭ���ͷ�һ�Σ���ÿ��ֻ��һ��Ԫ�أ��϶��Ҳ���������
        //���������hashmap�д����Ͳ���������ʧ��~������˻��Ƿ�������
        
        if (hashmap.find(key) != hashmap.end())
            hashmap.at(key) += val;
        else
            hashmap.emplace(key, val);
    }
    //����ֻ����hashmap����������vector��������
    for (auto e : hashmap) //����e��pair<>�������ͣ������Ҫ��vectorģ������ĳ�pair
        vec.push_back(e); 

    //����������pair���ͣ�������unordered_map���ͣ������﷨����
    sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first; });
    //Ҳ���Բ���auto��ָ�����ͣ����ǣ����it���ص������Ǹ�pair������ָ��map��vectorģ��Ҳ����pair���������Ͳ�ƥ��
    /*unordered_map<int, int>::iterator it = hashmap.begin();
    while (it != hashmap.end()) {
        vec.push_back(*it);
    }*/





    //�����⣬������д���������ӽ׶ζ�������Ҫԭ����sort�ӿڸ㲻����
    /*sort(hashmap.begin(), hashmap.end(), 
        [](unordered_map<int, int>::iterator it1, unordered_map<int, int>::iterator it2) {return it1->first < it2->first; });*/
    /*sort(hashmap.begin(), hashmap.end(),
        [](unordered_map<int, int> a, unordered_map<int, int> b) {return a.begin()->first < a.begin()->first; });*/
    /*sort(hashmap.begin(), hashmap.end(),
        [](pair<int, int> a, pair<int, int> b) {return a.first<b.first; });*/
    
    //����vector�ĳ���pairģ�壬���lambda���ʽ����Ӧ�øı�
   /*sort(vec.begin(), vec.end(),
        [](unordered_map<int, int> a, unordered_map<int, int> b) {return a.begin()->first < b.begin()->first; });*/
    //��������д����bool��ʡ�ԣ���������return����
    /*sort(vec.begin(), vec.end(),
        [](unordered_map<int, int> a, unordered_map<int, int> b) -> bool {return a.begin()->first < b.begin()->first; });*/
   for (auto& v : vec)
       cout << v.first << " " << v.second << endl;
    return 0;
}



//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//class mymap {
//public:
//    int key;
//    int val;
//};
//
//int mainTest() {
//    int len;
//    cin >> len;
//    if (!len)
//        return 0;
//    mymap* mp = new mymap[len]();
//    for (int i = 0; i < len; i++)
//        cin >> mp[i].key >> mp[i].val;
//    sort(mp, mp + len, [](mymap mp1, mymap mp2) {return mp1.key < mp2.key; });
//    //����д����� sort(mp, mp + len, [](mymap* mp1, mymap* mp2) {return mp1->key < mp2->key; });
//    for (int i = 0; i < len; i++)
//        cout << mp[i].key << " " << mp[i].val << endl;
//    delete[] mp;
//    return 0;
//}




