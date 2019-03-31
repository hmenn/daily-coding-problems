/*
his problem was asked by Google.

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
*/
#include <iostream>
#include <string>

struct Node{
  int val;
  Node* left;
  Node* right;
};

int findUnivalCount(Node *root){

  if(root==nullptr){
    return 0;
  }

  int res = 0;
  if(root->left == nullptr && root->right==nullptr){
    res =  1;
  }else if(root->left != nullptr && root->right !=nullptr && root->left->val ==   root->right->val){
    res = 1;
  }

  res += findUnivalCount(root->left)+findUnivalCount(root->right);

  return res;
}

int main() {

  Node tree1 = {.val = 1, .left=nullptr, .right=nullptr};
  std::cout<<findUnivalCount(&tree1)<<std::endl;

  Node tree2 = {.val = 1, .left=new Node{1, nullptr, nullptr}, .right=nullptr};
  std::cout<<findUnivalCount(&tree2)<<std::endl;

  Node tree3 = {0, new Node{1,nullptr, nullptr},
                   new Node{0, 
                        new Node{1, 
                          new Node{1, nullptr, nullptr}, 
                          new Node{1, nullptr, nullptr}}, 
                        new Node{0,nullptr, nullptr}}};
  std::cout<<findUnivalCount(&tree3)<<std::endl;

  return 0;
}
