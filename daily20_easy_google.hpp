/*
This problem was asked by Google.

Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
*/
#include <iostream>

struct Node {
  Node(int val){
    m_val = val;
  }
  int m_val;
  Node * next;
};

int find_list_length(Node * root){
  if(root==NULL){
    return 0;
  }
  return 1+find_list_length(root->next);
}

Node * get_intersection_node(Node * list1, Node * list2){
  
  int list1Size = find_list_length(list1);
  int list2Size = find_list_length(list2);

  Node * smallList;
  Node * bigList;
  int diff;

  if(list1Size>list2Size){
    diff = list1Size - list2Size;
    smallList = list2;
    bigList = list1;
  }else{
    diff = list2Size - list1Size;
    smallList = list1;
    bigList = list2;
  }

  for(auto i =0; i< diff;++i){
    bigList = bigList->next;
  }


  while(bigList!=smallList){
    bigList = bigList->next;
    smallList = smallList->next;
  }

  return bigList;
}


int main() {

  Node list1Root(3);
  list1Root.next = new Node(7);
  list1Root.next->next = new Node(8);
  list1Root.next->next->next = new Node(10);

  Node list2Root(99);
  list2Root.next = new Node(1);
  list2Root.next->next = list1Root.next->next;

  Node * intersect = get_intersection_node(&list1Root, &list2Root);
  std::cout<<intersect->m_val;

  return 0;
}
