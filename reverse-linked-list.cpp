#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createLinkedList(vector<int> values);
void printLinkedList(ListNode* head);
ListNode* reverseList(ListNode* head);

int main(int argc, char const* argv[]) {
  vector<int> v1 = {5, 32, 1, 2, 93, 75, 89};
  vector<int> v2 = {6, 2, 30, 34};

  ListNode* list1 = createLinkedList(v1);
  ListNode* list2 = createLinkedList(v2);
  ListNode *rlist1, *rlist2;  // reverse of list1 and list2

  printLinkedList(list1);
  printLinkedList(list2);

  rlist1 = reverseList(list1);
  rlist2 = reverseList(list2);

  printLinkedList(rlist1);
  printLinkedList(rlist2);

  return 0;
}

// Reverses a linked list
ListNode* reverseList_old(ListNode* head) {
  ListNode* node = head;                        // used to traverse linked list
  ListNode* secondLastNode;                     // second last node of original linked list
  ListNode *reverseListHead, *reverseListTail;  // head and tail of reversed linked list

  if ((head == nullptr) || (head->next == nullptr))
    return head;

  // create a temporary node
  reverseListHead = new ListNode(0);
  // reverse list's last node is also the head as there is only one node in the list
  reverseListTail = reverseListHead;

  while (head->next != nullptr) {
    node = head;
    // iterate through original linked list
    while (node->next != nullptr) {
      // get second last node of list
      secondLastNode = node;
      // get tail node of list
      node = node->next;
    }
    // add tail node to back reverse list
    reverseListTail->next = node;
    // set the tail node of reverse list
    reverseListTail = node;
    reverseListTail->next = nullptr;
    // remove reference to tail
    secondLastNode->next = nullptr;
  }
  // remove the temporary node created above from the head of the reversed list
  node = reverseListHead;
  reverseListHead = reverseListHead->next;
  delete (node);
  // add the head of original list to the reversed list
  reverseListTail->next = head;

  // printLinkedList(reverseListHead);
  // cout << "secondLastNode: " << secondLastNode->val << endl;

  return reverseListHead;
}

// Optimized solution
ListNode* reverseList(ListNode* head) {
  if (head == NULL)
    return NULL;
  if (head->next == NULL)
    return head;

  ListNode* old_head;
  ListNode* node = head->next;
  ListNode* next_node;
  ListNode* org_head = head;
  while (node != NULL) {
    next_node = node->next;
    old_head = head;
    head = node;
    head->next = old_head;
    node = next_node;
  }
  org_head->next = NULL;
  return head;
}

// Create Linked list given a vector of int values
// returns pointer to head of lined list
ListNode* createLinkedList(vector<int> values) {
  ListNode* head;
  ListNode* node = new ListNode();
  head = node;
  for (int value : values) {
    node->next = new ListNode(value);
    node = node->next;
  }
  head = head->next;
  return head;
}

// Prints Linked List
// e.g. 5->8->3->NULL
void printLinkedList(ListNode* head) {
  ListNode* node = head;

  while (node != nullptr) {
    cout << node->val << "->";
    node = node->next;
  }
  cout << "NULL\n";
}
