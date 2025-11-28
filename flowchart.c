// flowchart.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flowchart.h"

// Enqueue a step (text line)
void enqueue(QNode **head, QNode **tail, const char *step) {
    QNode *newNode = (QNode*)malloc(sizeof(QNode));
    if (!newNode) return;
    strncpy(newNode->step, step, sizeof(newNode->step) - 1);
    newNode->step[sizeof(newNode->step) - 1] = '\0';
    newNode->next = NULL;
    if (*tail) {
        (*tail)->next = newNode;
        *tail = newNode;
    } else {
        *head = *tail = newNode;
    }
}

// Print and free the queue
void displayQueue(QNode *head) {
    while (head) {
        printf("%s\n", head->step);
        QNode *tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Helper for each problem to add steps
static void flowchart_problem1(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input two integers a, b");
    enqueue(h, t, "Store originals n1=a, n2=b");
    enqueue(h, t, "While b != 0:");
    enqueue(h, t, "  temp = b");
    enqueue(h, t, "  b = a % b");
    enqueue(h, t, "  a = temp");
    enqueue(h, t, "End while");
    enqueue(h, t, "GCD = a");
    enqueue(h, t, "LCM = (n1 * n2) / GCD (handle zero/negative)");
    enqueue(h, t, "Print GCD, LCM");
    enqueue(h, t, "End");
}

static void flowchart_problem2(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input n");
    enqueue(h, t, "If n <= 1: Not Prime");
    enqueue(h, t, "Else if n <= 3: Prime");
    enqueue(h, t, "Else if n divisible by 2 or 3: Not Prime");
    enqueue(h, t, "Else:");
    enqueue(h, t, "  Check divisibility by i = 5, 11, 17, ... (6k±1) up to sqrt(n)");
    enqueue(h, t, "If any divisor found: Not Prime; otherwise Prime");
    enqueue(h, t, "End");
}

static void flowchart_problem3(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input n");
    enqueue(h, t, "If n < 0 → factorial not defined");
    enqueue(h, t, "Else:");
    enqueue(h, t, "  fact = 1");
    enqueue(h, t, "  For i = 2 to n: fact *= i");
    enqueue(h, t, "  Print fact");
    enqueue(h, t, "Also recursive and big-integer versions follow similar structure");
    enqueue(h, t, "End");
}

static void flowchart_problem4(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input integer n");
    enqueue(h, t, "sum = 0; n = |n|");
    enqueue(h, t, "While n > 0:");
    enqueue(h, t, "  digit = n % 10");
    enqueue(h, t, "  sum += digit");
    enqueue(h, t, "  n /= 10");
    enqueue(h, t, "Print sum");
    enqueue(h, t, "End");
}

static void flowchart_problem5(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input n");
    enqueue(h, t, "Copy temp = n, sum = 0");
    enqueue(h, t, "Count digits d in n");
    enqueue(h, t, "While temp != 0:");
    enqueue(h, t, "  digit = temp % 10");
    enqueue(h, t, "  sum += digit^d");
    enqueue(h, t, "  temp /= 10");
    enqueue(h, t, "If sum == n → Armstrong; else Not Armstrong");
    enqueue(h, t, "End");
}

static void flowchart_problem6(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input strings s1, s2");
    enqueue(h, t, "If lengths differ → Not Anagram");
    enqueue(h, t, "Else:");
    enqueue(h, t, "  Either:");
    enqueue(h, t, "   (a) Count frequency of chars in s1, subtract for s2; all zeros → Anagram");
    enqueue(h, t, "  Or:");
    enqueue(h, t, "   (b) Sort s1, sort s2; if equal → Anagram");
    enqueue(h, t, "End");
}

static void flowchart_problem7(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input string s");
    enqueue(h, t, "freq[256] = 0");
    enqueue(h, t, "For each character c in s: freq[c]++");
    enqueue(h, t, "For each character c in s from left to right:");
    enqueue(h, t, "  If freq[c] == 1 → print c and stop");
    enqueue(h, t, "If no such char → print 'No non-repeating character'");
    enqueue(h, t, "End");
}

static void flowchart_problem8(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input array arr of size n");
    enqueue(h, t, "For i from 0 to n-1:");
    enqueue(h, t, "  Check if arr[i] appeared before index i");
    enqueue(h, t, "  If not → print arr[i]");
    enqueue(h, t, "Alternatively: sort arr and skip equal neighbors");
    enqueue(h, t, "End");
}

static void flowchart_problem9(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input array arr of size n");
    enqueue(h, t, "Initialize first = -∞, second = -∞");
    enqueue(h, t, "For each arr[i]:");
    enqueue(h, t, "  Update first and second appropriately");
    enqueue(h, t, "If second unchanged → no second largest exists");
    enqueue(h, t, "Else print second");
    enqueue(h, t, "End");
}

static void flowchart_problem10(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input array arr of size n, and target sum");
    enqueue(h, t, "Brute-force: nested loops over (i, j>i), check arr[i]+arr[j]==target");
    enqueue(h, t, "Optimized: sort arr, use two-pointer i=0, j=n-1; move pointers based on sum");
    enqueue(h, t, "Print all matching pairs");
    enqueue(h, t, "End");
}

static void flowchart_problem11(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input expression exp");
    enqueue(h, t, "Initialize empty stack");
    enqueue(h, t, "For each character c in exp:");
    enqueue(h, t, "  If c is opening bracket → push");
    enqueue(h, t, "  If c is closing bracket:");
    enqueue(h, t, "     If stack empty or types don't match → Not Balanced");
    enqueue(h, t, "After processing:");
    enqueue(h, t, "  If stack empty → Balanced; else Not Balanced");
    enqueue(h, t, "End");
}

static void flowchart_problem12(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Build linked list from input");
    enqueue(h, t, "Set prev = NULL, curr = head");
    enqueue(h, t, "While curr != NULL:");
    enqueue(h, t, "  next = curr->next");
    enqueue(h, t, "  curr->next = prev");
    enqueue(h, t, "  prev = curr");
    enqueue(h, t, "  curr = next");
    enqueue(h, t, "head = prev");
    enqueue(h, t, "Print reversed list");
    enqueue(h, t, "End");
}

static void flowchart_problem13(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Build linked list");
    enqueue(h, t, "Set slow = head, fast = head");
    enqueue(h, t, "While fast != NULL and fast->next != NULL:");
    enqueue(h, t, "  slow = slow->next");
    enqueue(h, t, "  fast = fast->next->next");
    enqueue(h, t, "Print slow->data as middle");
    enqueue(h, t, "End");
}

static void flowchart_problem14(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input two sorted lists L1, L2");
    enqueue(h, t, "Use dummy node and tail pointer");
    enqueue(h, t, "While L1 and L2 not NULL:");
    enqueue(h, t, "  Attach smaller node to tail; move corresponding list forward");
    enqueue(h, t, "Attach any remaining nodes");
    enqueue(h, t, "Print merged list");
    enqueue(h, t, "End");
}

static void flowchart_problem15(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Initialize two stacks S1, S2");
    enqueue(h, t, "Enqueue(x): push x onto S1");
    enqueue(h, t, "Dequeue(): if S2 empty, move all from S1 to S2; pop from S2");
    enqueue(h, t, "Display: show elements from S2 then S1");
    enqueue(h, t, "End");
}

static void flowchart_problem16(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input n (vertices), m (edges)");
    enqueue(h, t, "Store all edges (u, v, w)");
    enqueue(h, t, "Sort edges or push into Min-Heap by weight");
    enqueue(h, t, "Initialize DSU for n vertices");
    enqueue(h, t, "For each edge in increasing weight:");
    enqueue(h, t, "  If endpoints in different sets → union them & add edge to MST");
    enqueue(h, t, "Stop when MST has n-1 edges or edges exhausted");
    enqueue(h, t, "If not n-1 edges → MST not possible");
    enqueue(h, t, "End");
}

static void flowchart_problem17(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input n (vertices), m (edges)");
    enqueue(h, t, "Create adjacency list of size n");
    enqueue(h, t, "For each of m edges:");
    enqueue(h, t, "  Input u, v, w");
    enqueue(h, t, "  Allocate new node and attach to list of u (and v if undirected)");
    enqueue(h, t, "Print adjacency list");
    enqueue(h, t, "Free all nodes");
    enqueue(h, t, "End");
}

static void flowchart_problem18(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input number of nodes");
    enqueue(h, t, "Insert each value into BST");
    enqueue(h, t, "To count leaves recursively:");
    enqueue(h, t, "  If node is NULL → 0");
    enqueue(h, t, "  If node has no children → 1");
    enqueue(h, t, "  Else → leftLeaves + rightLeaves");
    enqueue(h, t, "Print number of leaves");
    enqueue(h, t, "End");
}

static void flowchart_problem19(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Build binary tree from preorder with -1 as NULL");
    enqueue(h, t, "Inorder (recursive): left, root, right");
    enqueue(h, t, "Inorder (iterative): use stack to simulate recursion");
    enqueue(h, t, "Preorder (recursive): root, left, right");
    enqueue(h, t, "End");
}

static void flowchart_problem20(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Directed graph (DFS):");
    enqueue(h, t, "  Maintain visited[] and recStack[]");
    enqueue(h, t, "  DFS: mark node on stack, recurse to neighbors; if neighbor already in recStack → cycle");
    enqueue(h, t, "Undirected graph (Union-Find):");
    enqueue(h, t, "  Initialize parent[] = -1");
    enqueue(h, t, "  For each edge (u,v):");
    enqueue(h, t, "    Find parents of u, v; if same → cycle; else union them");
    enqueue(h, t, "End");
}

// Dispatcher
void displayFlowchart(int problem) {
    QNode *head = NULL, *tail = NULL;
    switch (problem) {
        case 1:  flowchart_problem1(&head, &tail);  break;
        case 2:  flowchart_problem2(&head, &tail);  break;
        case 3:  flowchart_problem3(&head, &tail);  break;
        case 4:  flowchart_problem4(&head, &tail);  break;
        case 5:  flowchart_problem5(&head, &tail);  break;
        case 6:  flowchart_problem6(&head, &tail);  break;
        case 7:  flowchart_problem7(&head, &tail);  break;
        case 8:  flowchart_problem8(&head, &tail);  break;
        case 9:  flowchart_problem9(&head, &tail);  break;
        case 10: flowchart_problem10(&head, &tail); break;
        case 11: flowchart_problem11(&head, &tail); break;
        case 12: flowchart_problem12(&head, &tail); break;
        case 13: flowchart_problem13(&head, &tail); break;
        case 14: flowchart_problem14(&head, &tail); break;
        case 15: flowchart_problem15(&head, &tail); break;
        case 16: flowchart_problem16(&head, &tail); break;
        case 17: flowchart_problem17(&head, &tail); break;
        case 18: flowchart_problem18(&head, &tail); break;
        case 19: flowchart_problem19(&head, &tail); break;
        case 20: flowchart_problem20(&head, &tail); break;
        default:
            printf("Flowchart not available for this problem.\n");
            return;
    }
    printf("\n--- FLOWCHART (TEXT STEPS) ---\n");
    displayQueue(head);
}
