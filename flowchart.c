#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "flowchart.h"
// Function to enqueue a step
void enqueue(QNode **head, QNode **tail, const char *step) {
    QNode *newNode = (QNode*)malloc(sizeof(QNode));
    strcpy(newNode->step, step);
    newNode->next = NULL;
    if (*tail) {
        (*tail)->next = newNode;
        *tail = newNode;
    } else {
        *head = *tail = newNode;
    }
}

// Function to display queue
void displayQueue(QNode *head) {
    while (head) {
        printf("%s\n", head->step);
        head = head->next;
    }
}
void displayFlowchart(int choice) {
    QNode *head = NULL, *tail = NULL;

    switch(choice) {
        case 1: show_flowchart_gcd_iterative(&head, &tail); break;
        case 2: show_flowchart_gcd_recursive(&head, &tail); break;
        case 3: show_flowchart_prime_naive(&head, &tail); break;
        case 4: show_flowchart_prime_optimized(&head, &tail); break;
        case 5: show_flowchart_factorial_iterative(&head, &tail); break;
        case 6: show_flowchart_factorial_recursive(&head, &tail); break;
        case 7: show_flowchart_sum_digits_iterative(&head, &tail); break;
        case 8: show_flowchart_sum_digits_recursive(&head, &tail); break;
        case 9: show_flowchart_armstrong(&head, &tail); break;
        case 10: show_flowchart_anagram(&head, &tail); break;
        case 11: show_flowchart_first_nonrepeat(&head, &tail); break;
        case 12: show_flowchart_remove_duplicates(&head, &tail); break;
        case 13: show_flowchart_remove_duplicates_two_pointer(&head, &tail); break;
        case 14: show_flowchart_second_largest(&head, &tail); break;
        case 15: show_flowchart_second_largest_sorting(&head, &tail); break;

        default:
            printf("Invalid choice\n");
            return;
    }

    displayQueue(head);
}

// =====================================
// 1. GCD & LCM
// =====================================
void show_flowchart_gcd_iterative(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read number1 and number2");
    enqueue(h, t, "Set a = number1, b = number2");
    enqueue(h, t, "While b != 0");
    enqueue(h, t, "   temp = b");
    enqueue(h, t, "   b = a % b");
    enqueue(h, t, "   a = temp");
    enqueue(h, t, "End While");
    enqueue(h, t, "GCD = a");
    enqueue(h, t, "LCM = (number1 * number2) / GCD");
    enqueue(h, t, "Print GCD and LCM");
    enqueue(h, t, "End");
}

void show_flowchart_gcd_recursive(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read number1 and number2");
    enqueue(h, t, "Call GCD(number1, number2)");
    enqueue(h, t, "   If number2 == 0 -> Return number1");
    enqueue(h, t, "   Else -> Return GCD(number2, number1 % number2)");
    enqueue(h, t, "LCM = (number1 * number2) / GCD");
    enqueue(h, t, "Print GCD and LCM");
    enqueue(h, t, "End");
}

// =====================================
// 2. Prime Check
// =====================================
void show_flowchart_prime_optimized(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read n");
    enqueue(h, t, "If n < 2 -> Not Prime");
    enqueue(h, t, "Set i = 2");
    enqueue(h, t, "While i*i <= n");
    enqueue(h, t, "   If n % i == 0 -> Not Prime");
    enqueue(h, t, "   Else i = i + 1; repeat check");
    enqueue(h, t, "End While -> Prime");
    enqueue(h, t, "End");
}

void show_flowchart_prime_naive(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read n");
    enqueue(h, t, "If n < 2 -> Not Prime");
    enqueue(h, t, "For i = 2 to n-1");
    enqueue(h, t, "   If n % i == 0 -> Not Prime");
    enqueue(h, t, "End For -> Prime");
    enqueue(h, t, "End");
}

// =====================================
// 3. Factorial
// =====================================
void show_flowchart_factorial_iterative(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read n");
    enqueue(h, t, "fact = 1");
    enqueue(h, t, "For i = 1 to n");
    enqueue(h, t, "   fact = fact * i");
    enqueue(h, t, "End For");
    enqueue(h, t, "Print fact");
    enqueue(h, t, "End");
}

void show_flowchart_factorial_recursive(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read n");
    enqueue(h, t, "Call factorial(n)");
    enqueue(h, t, "   If n == 0 or 1 -> Return 1");
    enqueue(h, t, "   Else -> Return n * factorial(n-1)");
    enqueue(h, t, "Print factorial(n)");
    enqueue(h, t, "End");
}

// =====================================
// 4. Sum of digits
// =====================================
void show_flowchart_sum_digits_iterative(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read n");
    enqueue(h, t, "sum = 0");
    enqueue(h, t, "While n > 0");
    enqueue(h, t, "   digit = n % 10");
    enqueue(h, t, "   sum = sum + digit");
    enqueue(h, t, "   n = n / 10");
    enqueue(h, t, "End While");
    enqueue(h, t, "Print sum");
    enqueue(h, t, "End");
}

void show_flowchart_sum_digits_recursive(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read n");
    enqueue(h, t, "Call sum_digits(n)");
    enqueue(h, t, "   If n == 0 -> Return 0");
    enqueue(h, t, "   Else -> Return (n%10) + sum_digits(n/10)");
    enqueue(h, t, "Print sum_digits(n)");
    enqueue(h, t, "End");
}

// =====================================
// 5. Armstrong Number
// =====================================
void show_flowchart_armstrong(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read n");
    enqueue(h, t, "sum = 0, temp = n");
    enqueue(h, t, "While temp != 0");
    enqueue(h, t, "   digit = temp % 10");
    enqueue(h, t, "   sum = sum + digit^3");
    enqueue(h, t, "   temp = temp / 10");
    enqueue(h, t, "End While");
    enqueue(h, t, "If sum == n -> Armstrong");
    enqueue(h, t, "Else -> Not Armstrong");
    enqueue(h, t, "End");
}

// =====================================
// 6. Check if two strings are anagrams
// =====================================
void show_flowchart_anagram(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read strings s1 and s2");
    enqueue(h, t, "If length(s1) != length(s2) -> Not Anagram");
    enqueue(h, t, "Sort both strings");
    enqueue(h, t, "If sorted s1 == sorted s2 -> Anagram");
    enqueue(h, t, "Else -> Not Anagram");
    enqueue(h, t, "End");
}

// =====================================
// 7. First non-repeating character in string
// =====================================
void show_flowchart_first_nonrepeat(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read string s");
    enqueue(h, t, "Create frequency array freq[256] = {0}");
    enqueue(h, t, "For each char in s -> freq[char]++");
    enqueue(h, t, "For each char in s -> If freq[char] == 1 -> Print char and exit");
    enqueue(h, t, "If no such char -> Print 'None'");
    enqueue(h, t, "End");
}

// =====================================
// 8. Remove duplicates from array
// =====================================
void show_flowchart_remove_duplicates(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read array a[] of size n");
    enqueue(h, t, "Create empty array b[]");
    enqueue(h, t, "For i = 0 to n-1");
    enqueue(h, t, "   If a[i] not in b -> Add a[i] to b");
    enqueue(h, t, "Print b[]");
    enqueue(h, t, "End");
}
void show_flowchart_remove_duplicates_two_pointer(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read sorted array a[] of size n");
    enqueue(h, t, "Set i = 0");
    enqueue(h, t, "For j = 1 to n-1");
    enqueue(h, t, "   If a[j] != a[i]");
    enqueue(h, t, "       i = i + 1");
    enqueue(h, t, "       a[i] = a[j]");
    enqueue(h, t, "End For");
    enqueue(h, t, "Print a[0 to i] as array without duplicates");
    enqueue(h, t, "End");
}


// =====================================
// 9. Find second largest number in array
// =====================================
void show_flowchart_second_largest(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read array a[] of size n");
    enqueue(h, t, "Set largest = second = 0");
    enqueue(h, t, "For i = 0 to n-1");
    enqueue(h, t, "   If a[i] > largest -> second = largest, largest = a[i]");
    enqueue(h, t, "   Else if a[i] > second and a[i] != largest -> second = a[i]");
    enqueue(h, t, "Print second");
    enqueue(h, t, "End");
}
void show_flowchart_second_largest_sorting(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read array a[] of size n");
    enqueue(h, t, "Sort the array in ascending order");
    enqueue(h, t, "Set i = n-2");
    enqueue(h, t, "While i >= 0 and a[i] == a[n-1] -> i = i - 1");
    enqueue(h, t, "If i >= 0 -> Print a[i] as second largest");
    enqueue(h, t, "Else -> No second largest element exists");
    enqueue(h, t, "End");
}

// =====================================
// 10. Find all pairs with given sum
// =====================================
void show_flowchart_pairs_sum(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read array a[] of size n and target sum");
    enqueue(h, t, "For i = 0 to n-2");
    enqueue(h, t, "   For j = i+1 to n-1");
    enqueue(h, t, "       If a[i] + a[j] == target -> Print (a[i], a[j])");
    enqueue(h, t, "End nested loops");
    enqueue(h, t, "End");
}

// =====================================
// 11. Check balanced parentheses (stack)
// =====================================
void show_flowchart_balanced_parentheses(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read expression exp");
    enqueue(h, t, "Initialize empty stack");
    enqueue(h, t, "For each char in exp");
    enqueue(h, t, "   If char is '(' -> push to stack");
    enqueue(h, t, "   If char is ')' -> If stack empty -> Not Balanced, else pop");
    enqueue(h, t, "If stack empty -> Balanced");
    enqueue(h, t, "Else -> Not Balanced");
    enqueue(h, t, "End");
}
void show_flowchart_pairs_sum_sorting(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read array a[] of size n and target sum");
    enqueue(h, t, "Sort the array in ascending order");
    enqueue(h, t, "Set left = 0, right = n-1");
    enqueue(h, t, "While left < right");
    enqueue(h, t, "   If a[left] + a[right] == target -> Print (a[left], a[right]), left++, right--");
    enqueue(h, t, "   Else if a[left] + a[right] < target -> left++");
    enqueue(h, t, "   Else -> right--");
    enqueue(h, t, "End While");
    enqueue(h, t, "End");
}


// =====================================
// 12. Reverse singly linked list
// =====================================
void show_flowchart_reverse_sll_iterative(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read linked list");
    enqueue(h, t, "prev = NULL, curr = head");
    enqueue(h, t, "While curr != NULL");
    enqueue(h, t, "   next = curr->next");
    enqueue(h, t, "   curr->next = prev");
    enqueue(h, t, "   prev = curr");
    enqueue(h, t, "   curr = next");
    enqueue(h, t, "head = prev");
    enqueue(h, t, "Print reversed list");
    enqueue(h, t, "End");
}

void show_flowchart_reverse_sll_recursive(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read linked list");
    enqueue(h, t, "Call reverse_recursive(head)");
    enqueue(h, t, "   If head == NULL or head->next == NULL -> return head");
    enqueue(h, t, "   rest = reverse_recursive(head->next)");
    enqueue(h, t, "   head->next->next = head");
    enqueue(h, t, "   head->next = NULL");
    enqueue(h, t, "Return rest");
    enqueue(h, t, "Print reversed list");
    enqueue(h, t, "End");
}

// =====================================
// 13. Find middle node of linked list
// =====================================
void show_flowchart_middle_node(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read linked list");
    enqueue(h, t, "slow = head, fast = head");
    enqueue(h, t, "While fast != NULL and fast->next != NULL");
    enqueue(h, t, "   slow = slow->next");
    enqueue(h, t, "   fast = fast->next->next");
    enqueue(h, t, "Print slow->data as middle node");
    enqueue(h, t, "End");
}
void show_flowchart_middle_node_length(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read linked list");
    enqueue(h, t, "Set length = 0, temp = head");
    enqueue(h, t, "While temp != NULL");
    enqueue(h, t, "   length = length + 1");
    enqueue(h, t, "   temp = temp->next");
    enqueue(h, t, "End While");
    enqueue(h, t, "mid = length / 2");
    enqueue(h, t, "Set temp = head");
    enqueue(h, t, "For i = 0 to mid-1 -> temp = temp->next");
    enqueue(h, t, "Print temp->data as middle node");
    enqueue(h, t, "End");
}


// =====================================
// 14. Merge two sorted linked lists
// =====================================
void show_flowchart_merge_sorted_ll(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read two sorted linked lists L1 and L2");
    enqueue(h, t, "Initialize dummy node and tail pointer");
    enqueue(h, t, "While L1 != NULL and L2 != NULL");
    enqueue(h, t, "   If L1->data < L2->data -> append L1 to merged, L1 = L1->next");
    enqueue(h, t, "   Else -> append L2 to merged, L2 = L2->next");
    enqueue(h, t, "Append remaining nodes of L1 or L2");
    enqueue(h, t, "Print merged list");
    enqueue(h, t, "End");
}
void show_flowchart_merge_sorted_ll_recursive(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read two sorted linked lists L1 and L2");
    enqueue(h, t, "Call merge_recursive(L1, L2)");
    enqueue(h, t, "   If L1 == NULL -> Return L2");
    enqueue(h, t, "   If L2 == NULL -> Return L1");
    enqueue(h, t, "   If L1->data < L2->data");
    enqueue(h, t, "       L1->next = merge_recursive(L1->next, L2)");
    enqueue(h, t, "       Return L1");
    enqueue(h, t, "   Else");
    enqueue(h, t, "       L2->next = merge_recursive(L1, L2->next)");
    enqueue(h, t, "       Return L2");
    enqueue(h, t, "Print merged list");
    enqueue(h, t, "End");
}


// =====================================
// 15. Queue using two stacks
// =====================================
void show_flowchart_queue_two_stacks(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Initialize two empty stacks S1 and S2");
    enqueue(h, t, "For Enqueue(x) -> push x to S1");
    enqueue(h, t, "For Dequeue()");
    enqueue(h, t, "   If S2 is empty -> While S1 not empty -> pop from S1 and push to S2");
    enqueue(h, t, "   Pop from S2 and return");
    enqueue(h, t, "End");
}

// =====================================
