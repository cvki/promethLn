#include<iostream>
using namespace std;


//�ж�һ�������Ƿ��л�




//�ҳ����������е�һ���������
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
int main() {
    class Solution {
    public:
        ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
            int lth_h1 = 0, lth_h2 = 0, tem;
            ListNode* p1 = pHead1;
            ListNode* p2 = pHead2;
            while (p1) {
                p1 = p1->next;
                ++lth_h1;
            }
            while (p2) {
                p2 = p2->next;
                ++lth_h2;
            }
            tem = lth_h1 - lth_h2;
            p1 = pHead1; p2 = pHead2;
            if (!tem) {
                while (p1 && p2) {
                    if (p1 == p2)
                        return p1;
                    else {
                        p1 = p1->next;
                        p2 = p2->next;
                    }
                }
            }
            if (tem > 0) {
                while (tem) {
                    p1 = p1->next;
                    --tem;
                }
                while (p1 && p2) {
                    if (p1 == p2)
                        return p1;
                    else {
                        p1 = p1->next;
                        p2 = p2->next;
                    }
                }
            }
               
            if (tem < 0) {
                tem *= (-1);
                while (tem) {
                    p2 = p2->next;
                    --tem;
                }
                    while (p1 && p2) {
                        if (p1 == p2)
                            return p1;
                        else {
                            p1 = p1->next;
                            p2 = p2->next;
                        }
                    }
            }
        }
    };
	return 0;
}