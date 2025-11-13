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
           switch(choice) {
        case 1: show_flowchart_gcd_iterative(&head, &tail); break;
        case 2: show_flowchart_gcd_recursive(&head, &tail); break;
        case 3: show_flowchart_binary_gcd(&head, &tail); break;
        case 4: show_flowchart_prime_naive(&head, &tail); break;
        case 5: show_flowchart_prime_optimized(&head, &tail); break;
        case 6: show_flowchart_factorial_iterative(&head, &tail); break;
        case 7: show_flowchart_factorial_recursive(&head, &tail); break;
        case 8: show_flowchart_factorial_A3(&head, &tail); break;
        case 9: show_flowchart_sum_digits_iterative(&head, &tail); break;
        case 10: show_flowchart_sum_digits_recursive(&head, &tail); break;
        case 11: show_flowchart_armstrong(&head, &tail); break;
        case 12: show_flowchart_armstrong_recursive(&head, &tail); break;
        case 13: show_flowchart_anagram(&head, &tail); break;
        case 14: show_flowchart_anagram_A2(&head, &tail); break;
        case 15: show_flowchart_first_nonrepeat(&head, &tail); break;
        case 16: show_flowchart_firstNonRepeatingChar_A2(&head, &tail); break;
        case 17: show_flowchart_remove_duplicates(&head, &tail); break;
        case 18: show_flowchart_remove_duplicates_two_pointer(&head, &tail); break;
        case 19: show_flowchart_second_largest(&head, &tail); break;
        case 20: show_flowchart_second_largest_sorting(&head, &tail); break;
        case 21: show_flowchart_pairs_sum(&head, &tail); break;
        case 22: show_flowchart_findPairsWithSum_A2(&head, &tail); break;
        case 23: show_flowchart_balanced_parentheses(&head, &tail); break;
        case 24: show_flowchart_checkBalancedParentheses_A2(&head, &tail); break;
        case 25: show_flowchart_reverse_sll_iterative(&head, &tail); break;
        case 26: show_flowchart_reverse_sll_recursive(&head, &tail); break;
        case 27: show_flowchart_middle_node(&head, &tail); break;
        case 28: show_flowchart_findMiddleNode_A2(&head, &tail); break;
        case 29: show_flowchart_merge_sorted_ll(&head, &tail); break;
        case 30: show_flowchart_mergeSortedLists_A2(&head, &tail); break;
        case 31: show_flowchart_queue_two_stacks_A1(&head, &tail); break;
        case 32: show_flowchart_queue_two_stacks_A2(&head, &tail); break;
        case 33: show_flowchart_kruskal(&head, &tail); break;
        case 34: show_flowchart_kruskal_heap(&head, &tail); break;
        case 35: show_flowchart_storeWeightedGraph_A1(&head, &tail); break;
        case 36: show_flowchart_storeWeightedGraph_A2(&head, &tail); break;
        case 37: show_flowchart_bst_count_leaves(&head, &tail); break;
        case 38: show_flowchart_bst_count_leaves_iter(&head, &tail); break;
        case 39: show_flowchart_inorder_A1(&head, &tail); break;
        case 40: show_flowchart_inorder_A2(&head, &tail); break;
        case 41: show_flowchart_preorder_A3(&head, &tail); break;
        case 42: show_flowchart_dfsCycle_A1(&head, &tail); break;
        case 43: show_flowchart_isCyclicUF_A3(&head, &tail); break;
        default: printf("Invalid choice! Please try again.\n");
    }


        default:
            printf("Invalid choice\n");
            return;
    }

    displayQueue(head);
}
// 1. GCD & LCM
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
void show_flowchart_binary_gcd(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read two integers a and b");
    enqueue(h, t, "Call binary_gcd(a, b) to find GCD");
    enqueue(h, t, "Compute LCM = (a / GCD) * b (handle zero and negative cases)");
    enqueue(h, t, "Print GCD and LCM");
    enqueue(h, t, "End");

    enqueue(h, t, "--- Function: binary_gcd(u, v) ---");
    enqueue(h, t, "If u == 0 -> Return |v|");
    enqueue(h, t, "If v == 0 -> Return |u|");
    enqueue(h, t, "Make u and v positive");
    enqueue(h, t, "Initialize shift = 0");
    enqueue(h, t, "While both u and v are even -> u /= 2, v /= 2, shift++");
    enqueue(h, t, "While u is even -> u /= 2");
    enqueue(h, t, "Repeat until v == 0:");
    enqueue(h, t, "   While v is even -> v /= 2");
    enqueue(h, t, "   If u > v -> swap(u, v)");
    enqueue(h, t, "   v = v - u");
    enqueue(h, t, "End Repeat");
    enqueue(h, t, "Return u << shift");
    enqueue(h, t, "End Function");
}
// 2. Prime Check
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

// 3. Factorial
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
void show_flowchart_factorial_A3(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read integer n");
    enqueue(h, t, "If n < 0 -> Print 'Factorial not defined' and Stop");
    enqueue(h, t, "If n == 0 or n == 1 -> Print 'Factorial = 1' and Stop");
    enqueue(h, t, "Initialize res[2000] with res[0] = 1, res_size = 1");
    enqueue(h, t, "For x = 2 to n:");
    enqueue(h, t, "   Set carry = 0");
    enqueue(h, t, "   For i = 0 to res_size - 1:");
    enqueue(h, t, "       prod = res[i] * x + carry");
    enqueue(h, t, "       res[i] = prod % 10");
    enqueue(h, t, "       carry = prod / 10");
    enqueue(h, t, "   End Inner For");
    enqueue(h, t, "   While carry != 0:");
    enqueue(h, t, "       res[res_size] = carry % 10");
    enqueue(h, t, "       carry /= 10");
    enqueue(h, t, "       res_size++");
    enqueue(h, t, "   End While");
    enqueue(h, t, "End For");
    enqueue(h, t, "Print 'Factorial = ' followed by digits of res[] in reverse order");
    enqueue(h, t, "End");
}


// 4. Sum of digits
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
// 5. Armstrong Number
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
void show_flowchart_armstrong_recursive(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read number n");
    enqueue(h, t, "Store original = n");
    enqueue(h, t, "Find number of digits using recursion (countDigits function)");
    enqueue(h, t, "Set result = findArmstrongSum(n, digits)");
    enqueue(h, t, "If result == original");
    enqueue(h, t, "   Print 'Armstrong Number'");
    enqueue(h, t, "Else");
    enqueue(h, t, "   Print 'Not Armstrong Number'");
    enqueue(h, t, "End If");
    enqueue(h, t, "End");

    // Recursive helper flow
    enqueue(h, t, "--- Recursive Function: findArmstrongSum(num, digits) ---");
    enqueue(h, t, "If num == 0 -> Return 0");
    enqueue(h, t, "Else -> digit = num % 10");
    enqueue(h, t, "Return (pow(digit, digits) + findArmstrongSum(num / 10, digits))");
    enqueue(h, t, "End Function");
}

// 6. Check if two strings are anagrams
void show_flowchart_anagram(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read strings s1 and s2");
    enqueue(h, t, "If length(s1) != length(s2) -> Not Anagram");
    enqueue(h, t, "Sort both strings");
    enqueue(h, t, "If sorted s1 == sorted s2 -> Anagram");
    enqueue(h, t, "Else -> Not Anagram");
    enqueue(h, t, "End");
}
void show_flowchart_anagram_A2(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read first string s1");
    enqueue(h, t, "Read second string s2");
    enqueue(h, t, "Find lengths n1 = len(s1), n2 = len(s2)");
    enqueue(h, t, "If n1 != n2 -> Print 'Not Anagram' and Stop");
    enqueue(h, t, "Sort s1 using qsort()");
    enqueue(h, t, "Sort s2 using qsort()");
    enqueue(h, t, "Compare sorted s1 and s2 using strcmp()");
    enqueue(h, t, "If equal -> Print 'Anagram Strings'");
    enqueue(h, t, "Else -> Print 'Not Anagram'");
    enqueue(h, t, "End");

    enqueue(h, t, "--- Helper Function: cmp_char(a, b) ---");
    enqueue(h, t, "Return (character pointed by a) - (character pointed by b)");
    enqueue(h, t, "End Function");
}



// 7. First non-repeating character in string
void show_flowchart_first_nonrepeat(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read string s");
    enqueue(h, t, "Create frequency array freq[256] = {0}");
    enqueue(h, t, "For each char in s -> freq[char]++");
    enqueue(h, t, "For each char in s -> If freq[char] == 1 -> Print char and exit");
    enqueue(h, t, "If no such char -> Print 'None'");
    enqueue(h, t, "End");
}
void show_flowchart_firstNonRepeatingChar_A2(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read string s");
    enqueue(h, t, "Initialize idx[256] = -1 for all characters");
    enqueue(h, t, "For each character s[i] in string:");
    enqueue(h, t, "   Let c = s[i]");
    enqueue(h, t, "   If idx[c] == -1 -> store first occurrence idx[c] = i");
    enqueue(h, t, "   Else -> mark as repeated idx[c] = -2");
    enqueue(h, t, "End For");
    enqueue(h, t, "Set pos = INT_MAX");
    enqueue(h, t, "For each character code i = 0 to 255:");
    enqueue(h, t, "   If idx[i] >= 0 and idx[i] < pos -> update pos = idx[i]");
    enqueue(h, t, "End For");
    enqueue(h, t, "If pos == INT_MAX -> Print 'No non-repeating character found'");
    enqueue(h, t, "Else -> Print 'First non-repeating character: s[pos]'");
    enqueue(h, t, "End");
}
// 8. Remove duplicates from array
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

// 9. Find second largest number in array
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


// 10. Find all pairs with given sum
void show_flowchart_pairs_sum(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read array a[] of size n and target sum");
    enqueue(h, t, "For i = 0 to n-2");
    enqueue(h, t, "   For j = i+1 to n-1");
    enqueue(h, t, "       If a[i] + a[j] == target -> Print (a[i], a[j])");
    enqueue(h, t, "End nested loops");
    enqueue(h, t, "End");
}
void show_flowchart_findPairsWithSum_A2(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read number of elements n");
    enqueue(h, t, "Allocate memory for array arr of size n");
    enqueue(h, t, "If allocation fails -> Stop");
    enqueue(h, t, "Read n elements into arr");
    enqueue(h, t, "Read target sum value");
    enqueue(h, t, "Sort arr using qsort()");
    enqueue(h, t, "Set i = 0, j = n - 1");
    enqueue(h, t, "Print 'Pairs with given sum:'");
    enqueue(h, t, "While i < j:");
    enqueue(h, t, "   s = arr[i] + arr[j]");
    enqueue(h, t, "   If s == target:");
    enqueue(h, t, "       Print (arr[i], arr[j])");
    enqueue(h, t, "       Store ai = arr[i], aj = arr[j]");
    enqueue(h, t, "       Move i forward while arr[i] == ai");
    enqueue(h, t, "       Move j backward while arr[j] == aj");
    enqueue(h, t, "   Else if s < target -> i++");
    enqueue(h, t, "   Else -> j--");
    enqueue(h, t, "End While");
    enqueue(h, t, "Free allocated memory");
    enqueue(h, t, "End");
}

// 11. Check balanced parentheses (stack)
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
void show_flowchart_checkBalancedParentheses_A2(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read expression exp");
    enqueue(h, t, "Initialize stack _stk2[STACK_SIZE_2], set _top2 = -1");
    enqueue(h, t, "For each character c in exp:");
    enqueue(h, t, "   If c is '(', '{', or '[':");
    enqueue(h, t, "       If stack not full -> Push c onto stack (_stk2[++_top2] = c)");
    enqueue(h, t, "   Else if c is ')', '}', or ']':");
    enqueue(h, t, "       If stack empty (_top2 == -1) -> Print 'Not Balanced' and Stop");
    enqueue(h, t, "       Pop top element t = _stk2[_top2--]");
    enqueue(h, t, "       If (c and t) are not matching types -> Print 'Not Balanced' and Stop");
    enqueue(h, t, "End For");
    enqueue(h, t, "If stack empty (_top2 == -1) -> Print 'Balanced'");
    enqueue(h, t, "Else -> Print 'Not Balanced'");
    enqueue(h, t, "End");
}

// 12. Reverse singly linked list

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

// 13. Find middle node of linked list

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
void show_flowchart_findMiddleNode_A2(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Initialize head = NULL, tail = NULL");
    enqueue(h, t, "Read number of nodes n");
    enqueue(h, t, "For i = 0 to n - 1:");
    enqueue(h, t, "   Allocate new node nn");
    enqueue(h, t, "   If allocation fails -> Stop");
    enqueue(h, t, "   Read value val and assign nn->data = val");
    enqueue(h, t, "   Set nn->next = NULL");
    enqueue(h, t, "   If head == NULL -> head = tail = nn");
    enqueue(h, t, "   Else -> tail->next = nn; tail = nn");
    enqueue(h, t, "End For");

    enqueue(h, t, "Set cnt = 0, t = head");
    enqueue(h, t, "While t != NULL:");
    enqueue(h, t, "   cnt++");
    enqueue(h, t, "   t = t->next");
    enqueue(h, t, "End While");

    enqueue(h, t, "If cnt == 0 -> Print 'List empty' and Stop");

    enqueue(h, t, "Set mid = cnt / 2");
    enqueue(h, t, "Set t = head");
    enqueue(h, t, "For i = 0 to mid - 1 -> t = t->next");
    enqueue(h, t, "Print 'Middle node = t->data'");

    enqueue(h, t, "Free all nodes to release memory");
    enqueue(h, t, "End");
}

// 14. Merge two sorted linked lists

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
void show_flowchart_mergeSortedLists_A2(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Read number of nodes in List1 (n1)");
    enqueue(h, t, "Allocate memory for array a1 of size n1");
    enqueue(h, t, "Read n1 values into a1");
    enqueue(h, t, "Read number of nodes in List2 (n2)");
    enqueue(h, t, "Allocate memory for array a2 of size n2");
    enqueue(h, t, "Read n2 values into a2");
    enqueue(h, t, "Initialize i = 0, j = 0");
    enqueue(h, t, "Print 'Merged list:'");
    enqueue(h, t, "While i < n1 and j < n2:");
    enqueue(h, t, "   If a1[i] <= a2[j] -> Print a1[i]; i++");
    enqueue(h, t, "   Else -> Print a2[j]; j++");
    enqueue(h, t, "End While");
    enqueue(h, t, "While i < n1 -> Print a1[i]; i++");
    enqueue(h, t, "While j < n2 -> Print a2[j]; j++");
    enqueue(h, t, "Print newline");
    enqueue(h, t, "Free memory of a1 and a2");
    enqueue(h, t, "End");
}

// 15. Queue using two stacks

void show_flowchart_queue_two_stacks_A1(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Initialize two empty stacks S1 and S2");
    enqueue(h, t, "Repeat until user chooses Exit");
    enqueue(h, t, "   Display menu:");
    enqueue(h, t, "      1. Enqueue");
    enqueue(h, t, "      2. Dequeue");
    enqueue(h, t, "      3. Display");
    enqueue(h, t, "      0. Exit");
    enqueue(h, t, "   Input user's choice");

    enqueue(h, t, "   If choice == 1 (Enqueue)");
    enqueue(h, t, "      Input value x");
    enqueue(h, t, "      Push x onto Stack S1");

    enqueue(h, t, "   Else if choice == 2 (Dequeue)");
    enqueue(h, t, "      If Stack S2 is empty");
    enqueue(h, t, "         While Stack S1 not empty");
    enqueue(h, t, "            Pop element from S1 and push onto S2");
    enqueue(h, t, "      If Stack S2 is empty after transfer");
    enqueue(h, t, "         Print 'Queue Empty'");
    enqueue(h, t, "      Else");
    enqueue(h, t, "         Pop element from S2 and display as dequeued");

    enqueue(h, t, "   Else if choice == 3 (Display)");
    enqueue(h, t, "      Print elements of S2 (top to bottom)");
    enqueue(h, t, "      Then print elements of S1 (bottom to top)");

    enqueue(h, t, "   Else print 'Invalid choice'");
    enqueue(h, t, "End while loop when choice == 0");
    enqueue(h, t, "End");
}
void show_flowchart_queue_two_stacks_A2(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Initialize two empty stacks S1 and S2");
    enqueue(h, t, "Input number of operations (ops)");
    enqueue(h, t, "For i = 1 to ops");
    enqueue(h, t, "   Input operation type (1-enqueue, 2-dequeue, 3-display)");
    
    enqueue(h, t, "   If operation == 1 (enqueue)");
    enqueue(h, t, "      Input value x");
    enqueue(h, t, "      Push x onto Stack S1");
    
    enqueue(h, t, "   Else if operation == 2 (dequeue)");
    enqueue(h, t, "      If Stack S2 is empty");
    enqueue(h, t, "         While Stack S1 not empty");
    enqueue(h, t, "            Pop element from S1 and push onto S2");
    enqueue(h, t, "      If Stack S2 is empty after transfer");
    enqueue(h, t, "         Print 'Queue Empty'");
    enqueue(h, t, "      Else");
    enqueue(h, t, "         Pop element from S2 and display as dequeued");

    enqueue(h, t, "   Else if operation == 3 (display)");
    enqueue(h, t, "      Print elements of S2 (top to bottom)");
    enqueue(h, t, "      Then print elements of S1 (bottom to top)");

    enqueue(h, t, "   Else print 'Invalid operation'");
    enqueue(h, t, "Repeat for all operations");
    enqueue(h, t, "End");
}


/* 16. Kruskal's Algorithm (use Union-Find).             */

void show_flowchart_kruskal(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input number of vertices (n) and edges (m)");
    enqueue(h, t, "Initialize an array of edges of size m");
    enqueue(h, t, "For each edge i = 1 to m -> Input (u, v, w)");
    enqueue(h, t, "Sort all edges in non-decreasing order of weight using qsort()");
    enqueue(h, t, "Create DSU structure for n vertices");
    enqueue(h, t, "Set parent[i] = i and rank[i] = 0 for all vertices");
    enqueue(h, t, "Initialize count = 0 and total_w = 0");
    enqueue(h, t, "For each edge (u, v, w) in sorted edge list");
    enqueue(h, t, "   If count == n - 1 -> Stop (MST completed)");
    enqueue(h, t, "   Find roots of u and v using DSU find()");
    enqueue(h, t, "   If roots are different -> perform DSU union(u, v)");
    enqueue(h, t, "       Add edge (u, v) to MST");
    enqueue(h, t, "       Increase count by 1");
    enqueue(h, t, "       Add weight w to total_w");
    enqueue(h, t, "   Else -> Skip edge (cycle detected)");
    enqueue(h, t, "After all edges processed:");
    enqueue(h, t, "   If count != n - 1 -> Print 'MST not possible (graph not connected)'");
    enqueue(h, t, "   Else -> Print MST edges and total weight");
    enqueue(h, t, "Free all allocated memory");
    enqueue(h, t, "End");
}
void show_flowchart_kruskal_heap(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input number of vertices (n) and edges (m)");
    enqueue(h, t, "Create an empty Min-Heap of capacity m");
    enqueue(h, t, "For each edge i = 1 to m -> Input (u, v, w) and push into Min-Heap");
    enqueue(h, t, "Create DSU structure for n vertices");
    enqueue(h, t, "Set parent[i] = i and rank[i] = 0 for all vertices");
    enqueue(h, t, "Initialize count = 0 and total_w = 0");
    enqueue(h, t, "While Min-Heap not empty AND count < n - 1");
    enqueue(h, t, "   Extract minimum weight edge (u, v, w) using heap_pop()");
    enqueue(h, t, "   If u or v is invalid -> Skip edge");
    enqueue(h, t, "   Find roots of u and v using DSU find()");
    enqueue(h, t, "   If roots are different -> perform DSU union(u, v)");
    enqueue(h, t, "       Add edge (u, v) to MST");
    enqueue(h, t, "       Increase count by 1");
    enqueue(h, t, "       Add w to total_w");
    enqueue(h, t, "   Else -> Skip edge (cycle detected)");
    enqueue(h, t, "After loop:");
    enqueue(h, t, "   If count != n - 1 -> Print 'MST not possible (graph not connected)'");
    enqueue(h, t, "   Else -> Print MST edges and total weight");
    enqueue(h, t, "Free Min-Heap and DSU memory");
    enqueue(h, t, "End");
}
/* 17. Store weighted graph details using array-of-pointers + linked lists    */
void show_flowchart_storeWeightedGraph_A1(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input number of vertices (n) and edges (m)");
    enqueue(h, t, "If invalid input (n <= 0 or m < 0) -> Exit");
    enqueue(h, t, "Create adjacency list array 'adj' of size (n + 1)");
    enqueue(h, t, "Initialize adj[i] = NULL for all vertices 1 to n");
    enqueue(h, t, "For each edge i = 1 to m:");
    enqueue(h, t, "   Input u, v, w (edge endpoints and weight)");
    enqueue(h, t, "   If u or v is invalid -> Skip this edge");
    enqueue(h, t, "   Call add_edge_basic(adj, u, v, w)");
    enqueue(h, t, "   (If undirected -> also call add_edge_basic(adj, v, u, w))");
    enqueue(h, t, "After all edges are read:");
    enqueue(h, t, "   Print adjacency list in format:");
    enqueue(h, t, "   vertex: (neighbor, weight) ...");
    enqueue(h, t, "For each vertex i = 1 to n:");
    enqueue(h, t, "   Traverse linked list adj[i]");
    enqueue(h, t, "   Print all connected vertices and weights");
    enqueue(h, t, "Free memory for all adjacency lists");
    enqueue(h, t, "Free adjacency array");
    enqueue(h, t, "End");
}
void show_flowchart_storeWeightedGraph_A2(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input number of vertices (n) and edges (m)");
    enqueue(h, t, "If invalid input (n <= 0 or m < 0) -> Exit");
    enqueue(h, t, "Create adjacency list array 'lists' of size (n + 1)");
    enqueue(h, t, "Initialize each lists[i].head = lists[i].tail = NULL for 1 to n");
    enqueue(h, t, "For each edge i = 1 to m:");
    enqueue(h, t, "   Input u, v, w (edge endpoints and weight)");
    enqueue(h, t, "   If u or v is invalid -> Skip this edge");
    enqueue(h, t, "   Call add_edge_tail(lists, u, v, w)");
    enqueue(h, t, "   (If undirected -> also call add_edge_tail(lists, v, u, w))");
    enqueue(h, t, "After all edges are read:");
    enqueue(h, t, "   Print adjacency list as:");
    enqueue(h, t, "   vertex: (neighbor, weight) ...");
    enqueue(h, t, "For each vertex i = 1 to n:");
    enqueue(h, t, "   Set p = lists[i].head");
    enqueue(h, t, "   While p != NULL:");
    enqueue(h, t, "       Print (p->v, p->w)");
    enqueue(h, t, "       Move p = p->next");
    enqueue(h, t, "Free all dynamically allocated AdjNode structures");
    enqueue(h, t, "Free adjacency list array");
    enqueue(h, t, "End");
}
/* 18. Create a BST and count number of leaf nodes                            */

void show_flowchart_bst_count_leaves(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input number of nodes (n)");
    enqueue(h, t, "Initialize root = NULL");
    enqueue(h, t, "For i = 1 to n:");
    enqueue(h, t, "   Input value v");
    enqueue(h, t, "   Call bst_insert_rec(root, v)");
    enqueue(h, t, "Function bst_insert_rec(root, x):");
    enqueue(h, t, "   If root == NULL → create new node and return");
    enqueue(h, t, "   Else if x < root->val → insert in left subtree");
    enqueue(h, t, "   Else → insert in right subtree");
    enqueue(h, t, "Return root");
    enqueue(h, t, "After insertion, call bst_count_leaves_rec(root)");
    enqueue(h, t, "Function bst_count_leaves_rec(root):");
    enqueue(h, t, "   If root == NULL → return 0");
    enqueue(h, t, "   If root->left == NULL && root->right == NULL → return 1");
    enqueue(h, t, "   Return sum of left and right subtree leaf counts");
    enqueue(h, t, "Display 'Number of leaf nodes'");
    enqueue(h, t, "Free all BST nodes using post-order traversal");
    enqueue(h, t, "End");
}
void show_flowchart_bst_count_leaves_iter(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Input number of nodes (n)");
    enqueue(h, t, "Initialize root = NULL");
    enqueue(h, t, "For i = 1 to n:");
    enqueue(h, t, "   Input value v");
    enqueue(h, t, "   If root == NULL → root = bst_insert_iter(NULL, v)");
    enqueue(h, t, "   Else → bst_insert_iter(root, v)");
    
    enqueue(h, t, "Function bst_insert_iter(root, x):");
    enqueue(h, t, "   Create new node nn with value x");
    enqueue(h, t, "   If root == NULL → return nn");
    enqueue(h, t, "   Initialize cur = root, parent = NULL");
    enqueue(h, t, "   While cur != NULL:");
    enqueue(h, t, "       parent = cur");
    enqueue(h, t, "       If x < cur->val → cur = cur->left");
    enqueue(h, t, "       Else → cur = cur->right");
    enqueue(h, t, "   If x < parent->val → parent->left = nn");
    enqueue(h, t, "   Else → parent->right = nn");
    enqueue(h, t, "   Return root");

    enqueue(h, t, "After all insertions, call bst_count_leaves_iter(root)");
    enqueue(h, t, "Function bst_count_leaves_iter(root):");
    enqueue(h, t, "   If root == NULL → return 0");
    enqueue(h, t, "   Initialize empty stack and push root");
    enqueue(h, t, "   While stack not empty:");
    enqueue(h, t, "       Pop node from stack");
    enqueue(h, t, "       If node has no left and right child → increment leaf count");
    enqueue(h, t, "       If right child exists → push right");
    enqueue(h, t, "       If left child exists → push left");
    enqueue(h, t, "   Return leaf count");

    enqueue(h, t, "Display 'Number of leaf node");}

/* 19. Binary Tree Traversals (Inorder, Preorder, Postorder)   */

void show_flowchart_inorder_A1(QNode **h, QNode **t) 
{
    enqueue(h, t, "Start");
    enqueue(h, t, "Call inorder_A1(root)");
    
    enqueue(h, t, "Function inorder_A1(root):");
    enqueue(h, t, "   If root == NULL → return");
    enqueue(h, t, "   Else:");
    enqueue(h, t, "       Call inorder_A1(root->left)");
    enqueue(h, t, "       Print root->data");
    enqueue(h, t, "       Call inorder_A1(root->right)");
    
    enqueue(h, t, "End Function");
    enqueue(h, t, "Stop");
}
void show_flowchart_inorder_A2(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "Initialize stack[MAX_STACK], top = -1");
    enqueue(h, t, "Set curr = root");

    enqueue(h, t, "WHILE (curr != NULL OR top != -1)");
    enqueue(h, t, "   WHILE (curr != NULL)");
    enqueue(h, t, "       Push curr onto stack (++top)");
    enqueue(h, t, "       Move curr = curr->left");
    enqueue(h, t, "   END INNER WHILE");

    enqueue(h, t, "   Pop from stack (curr = stack[top--])");
    enqueue(h, t, "   Print curr->data");
    enqueue(h, t, "   Move curr = curr->right");
    enqueue(h, t, "END OUTER WHILE");

    enqueue(h, t, "Stop");
}
void show_flowchart_preorder_A3(QNode **h, QNode **t) {
    enqueue(h, t, "Start");
    enqueue(h, t, "IF root == NULL → Return");
    enqueue(h, t, "Print root->data");
    enqueue(h, t, "Call preorder_A3(root->left)");
    enqueue(h, t, "Call preorder_A3(root->right)");
    enqueue(h, t, "Stop");
}
/* 20. Detect Cycle in a Graph                                                 */
void show_flowchart_dfsCycle_A1(QNode **h, QNode **t) {
    enqueue(h, t, "Start DFS Cycle Detection (u)");
    enqueue(h, t, "IF visited[u] == 0 THEN");
    enqueue(h, t, "   Mark visited[u] = 1");
    enqueue(h, t, "   Mark recStack[u] = 1");
    enqueue(h, t, "   FOR i = 0 to V-1");
    enqueue(h, t, "       IF g[u][i] == 1 THEN");
    enqueue(h, t, "           IF visited[i] == 0 AND dfsCycle_A1(i) == 1 → RETURN 1");
    enqueue(h, t, "           ELSE IF recStack[i] == 1 → RETURN 1");
    enqueue(h, t, "       END IF");
    enqueue(h, t, "   END FOR");
    enqueue(h, t, "END IF");
    enqueue(h, t, "Set recStack[u] = 0");
    enqueue(h, t, "RETURN 0");
    enqueue(h, t, "Stop");
}
void show_flowchart_isCyclicUF_A3(QNode **h, QNode **t) {
    enqueue(h, t, "Start Union-Find Cycle Detection");
    enqueue(h, t, "Initialize parent[] = -1 for all vertices");
    enqueue(h, t, "FOR each edge (u, v) in edges");
    enqueue(h, t, "   Find parent of u → xset = findUF_A3(parent, u)");
    enqueue(h, t, "   Find parent of v → yset = findUF_A3(parent, v)");
    enqueue(h, t, "   IF xset == yset THEN");
    enqueue(h, t, "       RETURN 1 (Cycle Detected)");
    enqueue(h, t, "   ELSE");
    enqueue(h, t, "       Perform Union: parent[xset] = yset");
    enqueue(h, t, "   END IF");
    enqueue(h, t, "END FOR");
    enqueue(h, t, "RETURN 0 (No Cycle Found)");
    enqueue(h, t, "Stop");
}



