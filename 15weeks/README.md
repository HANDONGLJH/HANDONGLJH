### 1. DS081.cpp
- **설명**: 이 파일은 사용자로부터 입력받은 데이터로 이진 트리를 구성하고, 중위 순회를 통해 출력하는 예제입니다.
- **주요 함수**:
  - `buildTree(int* nums, int size)`: 주어진 배열로 이진 트리를 구성합니다.
  - `printInOrderTree(TreeNode* root)`: 중위 순회를 통해 트리를 출력합니다.

### 2. DS082.cpp
- **설명**: 이 파일은 이진 트리를 구성하고 다양한 순회 방법(중위, 전위, 후위 순회)으로 트리를 출력하는 예제입니다.
- **주요 함수**:
  - `buildTree(int* nums, int size)`: 주어진 배열로 이진 트리를 구성합니다.
  - `printInOrderTree(TreeNode* root)`: 중위 순회를 통해 트리를 출력합니다.
  - `printPreOrderTree(TreeNode* root)`: 전위 순회를 통해 트리를 출력합니다.
  - `printPostOrderTree(TreeNode* root)`: 후위 순회를 통해 트리를 출력합니다.
  
### 3. DS083.cpp
- **설명**: 이 파일은 최대 힙(MaxHeap)을 구현한 코드입니다. 사용자는 힙에 값을 삽입하고 삭제하며, 힙을 레벨 순서대로 출력할 수 있습니다.
- **주요 함수**:
  - `insert(int value)`: 새로운 값을 힙에 추가합니다.
  - `deleteMax()`: 힙의 최대 값을 제거합니다.
  - `maxHeapify(int rootIndex)`: 힙 특성을 유지하기 위해 재귀적으로 힙을 정리합니다.
  - `printHeap()`: 힙을 출력합니다.

### 4. DS091.cpp
- **설명**: 이 파일은 사용자로부터 문자열 입력을 받아 스택을 사용해 커서를 이동하며 출력하는 예제입니다.
- **주요 함수**:
  - 이 파일은 `std::stack`을 사용하여 커서 이동 및 문자열 관리를 수행합니다.

### 5. DS092.cpp
- **설명**: 이 파일은 최대 힙을 이용하여 정수 목록에서 K번째로 큰 값을 찾는 예제입니다.
- **주요 함수**:
  - `insert(int value)`: 새로운 값을 힙에 추가합니다.
  - `deleteMax()`: 힙의 최대 값을 제거합니다.
  - `maxHeapify(int rootIndex)`: 힙 특성을 유지하기 위해 재귀적으로 힙을 정리합니다.
  - `main()`: 정수 목록과 K를 입력받아 K번째로 큰 값을 출력합니다.

### Heaptree.cpp
- **설명**: 이 파일은 힙 트리의 삽입, 삭제 연산을 구현한 예제입니다.
- **주요 함수**:
  - `insertKey(int arr[], int N, int value)`: 배열에 값을 삽입합니다.
  - `deleteKey(int arr[], int N)`: 힙의 최대 값을 제거합니다.
  - `maxHeapify(int arr[], int rootIndex)`: 힙 특성을 유지하기 위해 배열을 정리합니다.
  - `printArray(int* arr, int size)`: 힙을 출력합니다.

### MyLinkedStack.cpp, MyLinkedStack.h
- **설명**: 이 두 파일은 연결리스트를 사용한 스택 구현 파일입니다.
- **주요 함수**:
  - `push(const int& elem)`: 스택에 값을 추가합니다.
  - `pop()`: 스택에서 값을 제거하고 반환합니다.
  - `peek()`: 스택의 최상단 값을 반환합니다.
  - `clear()`: 스택을 초기화합니다.
  - `printAll()`: 스택의 모든 요소를 출력합니다.

### Arraytotree.cpp
- **설명**: 이 파일은 주어진 배열을 이진 트리로 변환한 후 중위 순회하여 출력하는 예제입니다.
- **주요 함수**:
  - `buildTree(int* nums, int size)`: 주어진 배열로 이진 트리를 구성합니다.
  - `printInOrderTree(TreeNode* root)`: 중위 순회를 통해 트리를 출력합니다.

