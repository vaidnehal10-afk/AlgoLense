// codebase.h
#ifndef CODEVARIATION_H
#define CODEVARIATION_H

#include <limits.h>

#define STACK_SIZE_1 256
#define STACK_SIZE_2 512
#define QSIZE        256
#define MAX_STACK    100

// --------- Common Structures ---------

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Edge {
    int u, v;
    int w;
} Edge;

typedef struct DSU {
    int *parent;
    int *rank;
    int n;
} DSU;

typedef struct MinHeap {
    Edge *data;
    int size;
    int cap;
} MinHeap;

typedef struct AdjNode {
    int v;
    int w;
    struct AdjNode *next;
} AdjNode;

typedef struct AdjList {
    AdjNode *head;
    AdjNode *tail;
} AdjList;

typedef struct BSTNode {
    int val;
    struct BSTNode *left, *right;
} BSTNode;

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// --------- Global stacks (for parentheses / queues) ---------
extern char _stk1[STACK_SIZE_1];
extern int  _top1;
extern char _stk2[STACK_SIZE_2];
extern int  _top2;

extern int q_stack1[QSIZE], q_stack2[QSIZE];
extern int q_top1, q_top2;
extern int s1[QSIZE], s2[QSIZE], t1, t2;

// 1. GCD & LCM
void      findGcdLcm_A1(void);
int       gcd_recursive(int x, int y);
void      findGcdLcm_A2(void);
int       binary_gcd(int u, int v);
void      findGcdLcm_A3(void);

// 2. Prime
void      checkPrime_A1(void);
void      checkPrime_A2(void);

// 3. Factorial
void      findFactorial_A1(void);
long long factorial_recursive(int n);
void      findFactorial_A2(void);
void      findFactorial_A3(void);

// 4. Sum of digits
void      sumOfDigits_A1(void);
int       sum_digits_rec(long long n);
void      sumOfDigits_A2(void);

// 5. Armstrong
void      checkArmstrong_A1(void);
int       int_pow(int base, int exp);
void      checkArmstrong_A2(void);

// 6. Anagram
void      checkAnagram_A1(void);
int       cmp_char(const void *a, const void *b);
void      checkAnagram_A2(void);

// 7. First non-repeating char
void      firstNonRepeatingChar_A1(void);
void      firstNonRepeatingChar_A2(void);

// 8. Remove duplicates
void      removeDuplicates_A1(void);
int       cmp_int(const void *a, const void *b);
void      removeDuplicates_A2(void);

// 9. Second largest
void      secondLargest_A1(void);
void      secondLargest_A2(void);

// 10. Pairs with sum
void      findPairsWithSum_A1(void);
void      findPairsWithSum_A2(void);

// 11. Balanced parentheses
void      checkBalancedParentheses_A1(void);
void      checkBalancedParentheses_A2(void);

// 12. Reverse linked list
void      reverseLinkedList_A1(void);
Node*     insert_tail(Node* head, int val);
Node*     reverse_recursive(Node* head);
void      reverseLinkedList_A2(void);

// 13. Middle node of linked list
void      findMiddleNode_A1(void);
void      findMiddleNode_A2(void);

// 14. Merge sorted linked lists
Node*     read_list_head_insert(int n);
void      mergeSortedLists_A1(void);
void      mergeSortedLists_A2(void);

// 15. Queue using two stacks
void      q_push1(int x);
void      q_push2(int x);
int       q_pop1(void);
int       q_pop2(void);
void      queueUsingStacks_A1(void);
void      enqueue_A2(int x);
int       dequeue_A2(void);
void      queueUsingStacks_A2(void);

// 16. Kruskal
DSU*      dsu_create(int n);
int       dsu_find(DSU *d, int x);
void      dsu_union(DSU *d, int x, int y);
void      dsu_free(DSU *d);
int       cmp_edge(const void *a, const void *b);
void      kruskal_qsort_A1(void);

MinHeap*  heap_create(int cap);
void      heap_swap(Edge *a, Edge *b);
void      heap_push(MinHeap *h, Edge e);
Edge      heap_pop(MinHeap *h);
int       heap_empty(MinHeap *h);
void      heap_free(MinHeap *h);
void      kruskal_heap_A2(void);

// 17. Store weighted graph
void      add_edge_basic(AdjNode **adj, int u, int v, int w);
void      storeWeightedGraph_A1(void);
void      add_edge_tail(AdjList *lists, int u, int v, int w);
void      storeWeightedGraph_A2(void);

// 18. BST leaf count
BSTNode*  bst_insert_rec(BSTNode *root, int x);
int       bst_count_leaves_rec(BSTNode *root);
void      bst_count_leaves_A1(void);
BSTNode*  bst_insert_iter(BSTNode *root, int x);
int       bst_count_leaves_iter(BSTNode *root);
void      bst_count_leaves_A2(void);

// 19. Binary tree traversals (wrappers)
void      inorder_A1(TreeNode *root);
void      inorder_A2(TreeNode *root);
void      preorder_A3(TreeNode *root);
void      treeTraversal_A1(void);  // inorder recursive
void      treeTraversal_A2(void);  // inorder iterative
void      treeTraversal_A3(void);  // preorder recursive

// 20. Cycle detection
int       dfsCycle_A1(int u, int **g, int *visited, int *recStack, int V);
int       isCyclicDFS_A1(int **g, int V);
int       isCyclicKahn_A2(int **g, int V);
int       findUF_A3(int parent[], int i);
int       unionUF_A3(int parent[], int x, int y);
int       isCyclicUF_A3(int edges[][2], int V, int E);
void      detectCycle_A1(void);
void      detectCycle_A2(void);

#endif
