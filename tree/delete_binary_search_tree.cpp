#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

void ReplaceLeftNode(TreeNode*& repair_node) {
  TreeNode *del_node;
  TreeNode *del_right;
  TreeNode *parent, *left;
  del_node = repair_node;
  if (del_node->right == NULL) {
    repair_node = del_node->left;
  } else {
    del_right = del_node->right;
    if (del_right->left == NULL) {
      repair_node = del_right;
    } else {
      parent = del_right->left;
      left = del_right->left;
      while (left->left) {
        parent = left;
        left = left->left;
      }
      if (parent != left) {
        parent->left = left->right;
        left->left = del_node->left;
        left->right = del_node->right;
        repair_node = left;
      } else {
        del_right->left = NULL;
        left->left = del_node->left;
        left->right = del_node->right;
        repair_node = left;
      }
    }
  }
}

void ReplaceRightNode(TreeNode*& repair_node) {
  TreeNode *del_node;
  TreeNode *del_left;
  TreeNode *parent, *right;
  del_node = repair_node;
  if (del_node->left == NULL) {
    repair_node = del_node->right;
  } else {
    del_left = del_node->left;
    if (del_left->right == NULL) {
      del_left->right = repair_node->right;
      repair_node = del_left;
    } else {
      parent = del_left->right;
      right = del_left->right;
      while (right->right) {
        parent = right;
        right = right->right;
      }
      if (parent != right) {
        parent->right = right->left;
        right->left = del_node->left;
        right->right = del_node->right;
        repair_node = right;
      } else {
        del_left->right = NULL;
        right->left = del_node->left;
        right->right = del_node->right;
        repair_node = right;
      }
    }
  }
}

TreeNode *SearchValue(TreeNode *root, TreeNode *cur_root, int target) {
  if (cur_root == NULL) return root;
  if (cur_root->left == NULL && cur_root->right == NULL) {
    if (cur_root->val == target) return cur_root;
    else return root;
  }

  TreeNode *del_node;
  if (cur_root->left && cur_root->left->val == target) {
    del_node = cur_root->left;
    ReplaceLeftNode(cur_root->left);
    return del_node;
  }
  if (cur_root->right && cur_root->right->val == target) {
    del_node = cur_root->right;
    ReplaceRightNode(cur_root->right);
    return del_node;
  }
  del_node = SearchValue(root, cur_root->left, target);
  if (del_node == root) {
    del_node = SearchValue(root, cur_root->right, target);
  }

  return del_node;
}


//struct PosCount {
//  int pos;
//  int cnt;
//};
//
//bool Comp(PosCount& a, PosCount& b) {
//  if (a.cnt > b.cnt) return true;
//  else return false;
//}
//
//int MinDiffCount(vector<vector<vector<int> > >& matrix) {
//  int k = matrix.size();
//  int n = matrix[0].size();
//  int m = matrix[0][0].size();
//  vector<set<int> > diff_pos;
//  unordered_map<int, int> pos_cnt;
//  for (int i = 0; i < k; ++i) {
//    for (int j = i+1; j < k; ++j) {
//      int pos;
//      set<int> dpos;
//      vector<vector<int> > mat1 = matrix[i];
//      vector<vector<int> > mat2 = matrix[j];
//      for (int p = 0; p < n; ++p) {
//        for (int q = 0; q < m; ++q) {
//          if (mat1[p][q] != mat2[p][q]) {
//            pos = p * m + q;
//            dpos.insert(pos);
//            pos_cnt[pos]++;
//          }
//        }
//      }
//      if (dpos.empty()) return -1;
//      diff_pos.push_back(dpos);
//    }
//  }
//  vector<PosCount> pos_cnt_arr(pos_cnt.size());
//  PosCount temp;
//  int i = 0;
//  for (auto pair : pos_cnt) {
//    temp.pos = pair.first;
//    temp.cnt = pair.second;
//    pos_cnt_arr[i] = temp;
//    ++i;
//  }
//  sort(pos_cnt_arr.begin(), pos_cnt_arr.end(), Comp);
//  unordered_set<int> res;
//  for (int i = 0; i < diff_pos.size(); ++i) {
//    for (int j = 0; j < pos_cnt_arr.size(); ++j) {
//      if (diff_pos[i].count(pos_cnt_arr[j].pos)) {
//        res.insert(pos_cnt_arr[j].pos);
//        break;
//      }
//    }
//  }
//  return res.size();
//}
//
//int main() {
//  int n, m, k;
//  cin >> n >> m >> k;
//  vector<vector<vector<int> > > matrix(k, vector<vector<int> >(n, vector<int>(m)));
//  for (int i = 0; i < k; ++i) {
//    for (int j = 0; j < n; ++j) {
//      for (int p = 0; p < m; ++p) {
//        cin >> matrix[i][j][p];
//      }
//    }
//  }
//  cout << MinDiffCount(matrix);
//
//  return 0;
//}
