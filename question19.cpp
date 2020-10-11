class Solution {
private:
	int length = 0;
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int cnt = 0;
		ListNode* p = head;
		while (p) {
			length++;
			p = p->next;
		}
		ListNode** lists = new ListNode*[length];
		p = head;
		while (p) {
			lists[cnt++] = p;
			p = p->next;
		}
		if (length == n ) head = head->next;
		else { lists[length - n - 1]->next = lists[length - n]->next; }
		delete[]lists;
		return head;
	}
};


public ListNode removeNthFromEnd(ListNode head, int n) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    ListNode first = dummy;
    ListNode second = dummy;
    // Advances first pointer so that the gap between first and second is n nodes apart
    for (int i = 1; i <= n + 1; i++) {
        first = first.next;
    }
    // Move first to the end, maintaining the gap
    while (first != null) {
        first = first.next;
        second = second.next;
    }
    second.next = second.next.next;
    return dummy.next;
}
