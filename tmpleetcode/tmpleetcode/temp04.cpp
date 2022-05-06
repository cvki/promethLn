
/***
1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
 
提示：
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
**/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//这里为O(n^2), O(n)可以用hashtable来做
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


/**88. 合并两个有序数组
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

示例 1：
输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

示例 2：
输入：nums1 = [1], m = 1, nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。

示例 3：
输入：nums1 = [0], m = 0, nums2 = [1], n = 1
输出：[1]
解释：需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。

提示：
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？
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
    v.insert(v.end(), 3, 2);    //向vector尾部插入3个2
    for (int e : v)
        cout << e << " ";
    cout << endl;*/

    return 0;
}


/***描述
数据表记录包含表索引和数值（int范围的正整数），请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。

提示:
0 <= index <= 11111111
1 <= value <= 100000

输入描述：
先输入键值对的个数n（1 <= n <= 500）
然后输入成对的index和value值，以空格隔开

输出描述：
输出合并后的键值对（多行）

示例1
输入：
4
0 1
0 2
1 2
3 4

输出：
0 3
1 2
3 4

示例2
输入：
3
0 1
0 2
8 9

输出：
0 3
8 9****/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int main_05() {
    vector<unordered_map<int, int>> vecxx; //哈希map
    vector<pair<int, int>> vec;  
    //因为vector内部如果为map<x,y>等key-vaule形式时，for遍历得到的元素类型是pair(即使不用auto它也是，指定类型或迭代器类型也不管用。
    //但它底层(实际上)仍是hashmap结构，效率还是hash的效率，只是语法上，类型是要pair的才能匹配)
    unordered_map<int, int> hashmap;
    int len, key, val;
    cin >> len;
    if (!len)
        return 0;
    for (int i = 0; i < len; ++i) {
        cin >> key >> val;
        //hashmap如果放在内部当作局部变量，如果放外面它会一直向map中填充，然后每次加进vector就会重复。而放在内部每次循环它都被释放。
        //vec在push时，也不要使用引用(如果不是移动构造，那么循环结束它就被释放，hashmap就变成了野指针，vec便存了这个野指针)
        //但此时也有问题，我们要在hashmap寻找是否有重复键，每次循环释放一次，那每次只有一个元素，肯定找不到啊！！
        //所以如果在hashmap中处理，就不能让他消失啊~！！因此还是放在外面
        
        if (hashmap.find(key) != hashmap.end())
            hashmap.at(key) += val;
        else
            hashmap.emplace(key, val);
    }
    //于是只能在hashmap处理完后加入vector进行排序
    for (auto e : hashmap) //这里e是pair<>对组类型，因此需要将vector模板参数改成pair
        vec.push_back(e); 

    //排序，这里用pair类型，不能用unordered_map类型，否则语法报错
    sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first; });
    //也可以不用auto而指定类型，但是，这个it返回的照样是个pair，即便指定map，vector模板也得是pair，否则类型不匹配
    /*unordered_map<int, int>::iterator it = hashmap.begin();
    while (it != hashmap.end()) {
        vec.push_back(*it);
    }*/





    //有问题，这三种写法编译链接阶段都出错，主要原因是sort接口搞不明白
    /*sort(hashmap.begin(), hashmap.end(), 
        [](unordered_map<int, int>::iterator it1, unordered_map<int, int>::iterator it2) {return it1->first < it2->first; });*/
    /*sort(hashmap.begin(), hashmap.end(),
        [](unordered_map<int, int> a, unordered_map<int, int> b) {return a.begin()->first < a.begin()->first; });*/
    /*sort(hashmap.begin(), hashmap.end(),
        [](pair<int, int> a, pair<int, int> b) {return a.first<b.first; });*/
    
    //由于vector改成了pair模板，因此lambda表达式类型应该改变
   /*sort(vec.begin(), vec.end(),
        [](unordered_map<int, int> a, unordered_map<int, int> b) {return a.begin()->first < b.begin()->first; });*/
    //或者下面写法，bool可省略，函数体内return不行
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
//    //这样写会出错： sort(mp, mp + len, [](mymap* mp1, mymap* mp2) {return mp1->key < mp2->key; });
//    for (int i = 0; i < len; i++)
//        cout << mp[i].key << " " << mp[i].val << endl;
//    delete[] mp;
//    return 0;
//}




