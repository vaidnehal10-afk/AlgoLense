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

// Flowchart functions
void displayFlowchart(int choice);

void show_flowchart_gcd_iterative(QNode **h, QNode **t);
void show_flowchart_gcd_recursive(QNode **h, QNode **t);
void show_flowchart_prime_naive(QNode **h, QNode **t);
void show_flowchart_prime_optimized(QNode **h, QNode **t);
void show_flowchart_factorial_iterative(QNode **h, QNode **t);
void show_flowchart_factorial_recursive(QNode **h, QNode **t);
void show_flowchart_sum_digits_iterative(QNode **h, QNode **t);
void show_flowchart_sum_digits_recursive(QNode **h, QNode **t);
void show_flowchart_armstrong(QNode **h, QNode **t);
void show_flowchart_anagram(QNode **h, QNode **t);
void show_flowchart_first_nonrepeat(QNode **h, QNode **t);
void show_flowchart_remove_duplicates(QNode **h, QNode **t);
void show_flowchart_remove_duplicates_two_pointer(QNode **h, QNode **t);
void show_flowchart_second_largest(QNode **h, QNode **t);
void show_flowchart_second_largest_sorting(QNode **h, QNode **t);
void show_flowchart_pairs_sum(QNode **h, QNode **t);
void show_flowchart_pairs_sum_sorting(QNode **h, QNode **t);
void show_flowchart_balanced_parentheses(QNode **h, QNode **t);
void show_flowchart_reverse_sll_iterative(QNode **h, QNode **t);
void show_flowchart_reverse_sll_recursive(QNode **h, QNode **t);
void show_flowchart_middle_node(QNode **h, QNode **t);
void show_flowchart_middle_node_length(QNode **h, QNode **t);
void show_flowchart_merge_sorted_ll(QNode **h, QNode **t);
void show_flowchart_merge_sorted_ll_recursive(QNode **h, QNode **t);
void show_flowchart_queue_two_stacks(QNode **h, QNode **t);

#endif
