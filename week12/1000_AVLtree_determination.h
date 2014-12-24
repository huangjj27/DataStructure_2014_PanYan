// Copyright (c) 2014 Junjie_Huang@SYSU(SNO:13331087). All Rights Reserved.
// week12/1000_AVLtree_determination.h: DatStructure2014@PanYan.
// http://soj.sysu.edu.cn/show_problem.php?pid=1000&cid=1654
#ifndef AVL_NODE
#define AVL_NODE

#include <cmath>

#define max(a, b) ((a) > (b)? (a) : (b))

template <class Entry>
struct AvlNode
{
  Entry entry;
  AvlNode<Entry> *left;
  AvlNode<Entry> *right;
  int bf;                // balance factor 平衡因子
};

#endif

// 判断一颗树是否为平衡二叉树
int abs(int a) {
  if (a >= 0)
    return a;
  else
    return 0 - a;
}

template <class Entry>
int getHeight(AvlNode<Entry> *&root) {
  if (root == NULL) return 0;
  int left_height = getHeight(root->left);
  int right_height = getHeight(root->right);
  return max(left_height, right_height) + 1;
}

template <class Entry>
bool is_AVL_Tree(AvlNode<Entry> *&root) {
  if (root == NULL) return true;
  int left_height = getHeight(root->left);
  int right_height = getHeight(root->right);
  bool is_AVL = abs(left_height - right_height) <= 1;
  return is_AVL && is_AVL_Tree(root->left) && is_AVL_Tree(root->right);
}