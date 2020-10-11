class Solution {
public:
	ListNode* l3 = new ListNode(0);
	ListNode* p = l3;
	bool flag = false;
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		while (l1 && l2) {
			l3->val = l1->val + l2->val;
			if (flag == true) {
				l3->val += 1;
				flag = false;
			}
			if (l3->val >= 10) {
				l3->val %= 10;
				flag = true;
			}
			if (l2->next || l1->next) {
				l3->next = new ListNode(0);
			}
			else if (flag) {
				l3->next = new ListNode(1);
			}
			else {
				l3->next = NULL;
			}
			l3 = l3->next; l1 = l1->next; l2 = l2->next;
		}
		while (l1) {

			l3->val = l1->val;
			if (flag == true) {
				l3->val += 1;
				flag = false;
			}
			if (l3->val >= 10) {
				l3->val %= 10;
				flag = true;
			}
			if (l1->next) {
				l3->next = new ListNode(0);
			}
			else if (flag) {
				l3->next = new ListNode(1);
			}
			else {
				l3->next = NULL;
			}
			l3 = l3->next; l1 = l1->next;

		}
		while (l2) {

			l3->val = l2->val;
			if (flag == true) {
				l3->val += 1;
				flag = false;
			}
			if (l3->val >= 10) {
				l3->val %= 10;
				flag = true;
			}
			if (l2->next) {
				l3->next = new ListNode(0);
			}
			else if (flag) {
				l3->next = new ListNode(1);
			}
			else {
				l3->next = NULL;
			}
			l3 = l3->next; l2 = l2->next;
		}
		
		return p;

	}
};


//Ë¼Â·2--µÝ¹é
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return dfs(l1, l2, 0);
    }

    ListNode* dfs(ListNode* l, ListNode* r, int i) {
        if (!l && !r && !i) return nullptr;
        int sum = (l ? l->val : 0) + (r ? r->val : 0) + i;
        ListNode* node = new ListNode(sum % 10);
        node->next = dfs(l ? l->next : nullptr, r ? r->next : nullptr, sum / 10);
        return node;
    } 
};
