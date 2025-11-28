// flowchart.h
#ifndef FLOWCHART_H
#define FLOWCHART_H

// Flowchart queue node
typedef struct QNode {
    char step[100];
    struct QNode *next;
} QNode;

// Queue functions
void enqueue(QNode **head, QNode **tail, const char *step);
void displayQueue(QNode *head);

// Main flowchart dispatcher – called from main.c with problem 1..20
void displayFlowchart(int problem);

// Flowchart functions for individual algorithms
void show_flowchart_gcd_iterative(QNode **h, QNode **t);
void show_flowchart_gcd_recursive(QNode **h, QNode **t);
void show_flowchart_binary_gcd(QNode **h, QNode **t);

void show_flowchart_prime_optimized(QNode **h, QNode **t);
void show_flowchart_prime_naive(QNode **h, QNode **t);

void show_flowchart_factorial_iterative(QNode **h, QNode **t);
void show_flowchart_factorial_recursive(QNode **h, QNode **t);
void show_flowchart_factorial_A3(QNode **h, QNode **t);

void show_flowchart_sum_digits_iterative(QNode **h, QNode **t);
void show_flowchart_sum_digits_recursive(QNode **h, QNode **t);

void show_flowchart_armstrong(QNode **h, QNode **t);
void show_flowchart_armstrong_recursive(QNode **h, QNode **t);

void show_flowchart_anagram(QNode **h, QNode **t);
void show_flowchart_anagram_A2(QNode **h, QNode **t);

void show_flowchart_first_nonrepeat(QNode **h, QNode **t);
void show_flowchart_firstNonRepeatingChar_A2(QNode **h, QNode **t);

void show_flowchart_remove_duplicates(QNode **h, QNode **t);
void show_flowchart_remove_duplicates_two_pointer(QNode **h, QNode **t);

void show_flowchart_second_largest(QNode **h, QNode **t);
void show_flowchart_second_largest_sorting(QNode **h, QNode **t);

void show_flowchart_pairs_sum(QNode **h, QNode **t);
void show_flowchart_findPairsWithSum_A2(QNode **h, QNode **t);

void show_flowchart_balanced_parentheses(QNode **h, QNode **t);
void show_flowchart_checkBalancedParentheses_A2(QNode **h, QNode **t);

void show_flowchart_reverse_sll_iterative(QNode **h, QNode **t);
void show_flowchart_reverse_sll_recursive(QNode **h, QNode **t);

void show_flowchart_middle_node(QNode **h, QNode **t);
void show_flowchart_findMiddleNode_A2(QNode **h, QNode **t);

void show_flowchart_merge_sorted_ll(QNode **h, QNode **t);
void show_flowchart_mergeSortedLists_A2(QNode **h, QNode **t);

void show_flowchart_queue_two_stacks_A1(QNode **h, QNode **t);
void show_flowchart_queue_two_stacks_A2(QNode **h, QNode **t);

void show_flowchart_kruskal(QNode **h, QNode **t);
void show_flowchart_kruskal_heap(QNode **h, QNode **t);

void show_flowchart_storeWeightedGraph_A1(QNode **h, QNode **t);
void show_flowchart_storeWeightedGraph_A2(QNode **h, QNode **t);

void show_flowchart_bst_count_leaves(QNode **h, QNode **t);
void show_flowchart_bst_count_leaves_iter(QNode **h, QNode **t);

void show_flowchart_inorder_A1(QNode **h, QNode **t);
void show_flowchart_inorder_A2(QNode **h, QNode **t);
void show_flowchart_preorder_A3(QNode **h, QNode **t);

void show_flowchart_dfsCycle_A1(QNode **h, QNode **t);
void show_flowchart_isCyclicUF_A3(QNode **h, QNode **t);

#endif
