#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 트리 노드 정의
class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int x) {
    val = x;
    left = right = NULL;
  }
};

// 트리를 구성하는 함수
TreeNode *buildTree(int *nums, int size) {
  if (nums == NULL || size == 0)
    return NULL;

  TreeNode *root = new TreeNode(nums[0]);
  queue<TreeNode *> q;
  q.push(root);
  int i = 1;
  while (i < size) {
    TreeNode *curr = q.front();
    q.pop();
    if (i < size && nums[i] != 0) {
      curr->left = new TreeNode(nums[i]);
      q.push(curr->left);
    }
    i++;
    if (i < size && nums[i] != 0) {
      curr->right = new TreeNode(nums[i]);
      q.push(curr->right);
    }
    i++;
  }
  return root;
}

// 중위 순회 함수
void printInOrderTree(TreeNode *root) {
  if (!root)
    return;
  printInOrderTree(root->left);
  cout << root->val << " ";
  printInOrderTree(root->right);
}

// 전위 순회 함수
void printPreOrderTree(TreeNode *root) {
  if (!root)
    return;
  cout << root->val << " ";
  printPreOrderTree(root->left);
  printPreOrderTree(root->right);
}

// 후위 순회 함수
void printPostOrderTree(TreeNode *root) {
  if (!root)
    return;
  printPostOrderTree(root->left);
  printPostOrderTree(root->right);
  cout << root->val << " ";
}

int main() {
  int n;
  string traversalMode;
  cout << "노드의 개수와 순회 방식을 입력 : ";
  cin >> n >> traversalMode;

  int *nums = new int[n];
  cout << "순서대로 노드의 값을 입력하세요 (빈 노드는 0으로 표시): ";
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  TreeNode *root = buildTree(nums, n);

  if (traversalMode == "in") {
    cout << "이진 트리의 중위 순회 결과: ";
    printInOrderTree(root);
  } else if (traversalMode == "pre") {
    cout << "이진 트리의 전위 순회 결과: ";
    printPreOrderTree(root);
  } else if (traversalMode == "post") {
    cout << "이진 트리의 후위 순회 결과: ";
    printPostOrderTree(root);
  } else {
    cout << "in, pre, post 중 하나를 선택.";
  }
  cout << endl;

  delete[] nums;
  return 0;
}
