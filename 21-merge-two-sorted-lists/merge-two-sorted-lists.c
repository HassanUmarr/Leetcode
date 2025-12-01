struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode dummy;
    struct ListNode *tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;   // append list1 node
            list1 = list1->next;  // move list1 forward
        } else {
            tail->next = list2;   
            list2 = list2->next;  
        }
        tail = tail->next;       
    }

    // Append whichever list is nonemptyy
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    return dummy.next;
}
