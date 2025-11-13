
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>

/* -------------------------------------------------------------------------- */
/* 1. GCD & LCM                                                              */
/* -------------------------------------------------------------------------- */

/* Approach 1: Euclidean algorithm (iterative) */
void findGcdLcm_A1() {
    int a, b;
    printf("Enter two numbers: ");
    if (scanf("%d %d", &a, &b) != 2) return;
    int n1 = a, n2 = b;
    int aa = abs(a), bb = abs(b);
    while (bb != 0) {
        int temp = bb;
        bb = aa % bb;
        aa = temp;
    }
    int gcd = aa;
    long long lcm = (gcd == 0) ? 0LL : (long long)(n1 / gcd) * n2;
    if (lcm < 0) lcm = -lcm;
    printf("GCD = %d, LCM = %lld\n", gcd, lcm);
}

/* Approach 2: Euclidean algorithm (recursive) */
int gcd_recursive(int x, int y) {
    if (y == 0) return x;
    return gcd_recursive(y, x % y);
}
void findGcdLcm_A2() {
    int a, b;
    printf("Enter two numbers: ");
    if (scanf("%d %d", &a, &b) != 2) return;
    int aa = abs(a), bb = abs(b);
    int g = gcd_recursive(aa, bb);
    long long lcm = (g == 0) ? 0LL : (long long)(a / g) * b;
    if (lcm < 0) lcm = -lcm;
    printf("GCD = %d, LCM = %lld\n", g, lcm);
}

/* Approach 3: Binary GCD (Stein's algorithm) */
int binary_gcd(int u, int v) {
    if (u == 0) return abs(v);
    if (v == 0) return abs(u);
    u = abs(u); v = abs(v);
    int shift = 0;
    while (((u | v) & 1) == 0) { u >>= 1; v >>= 1; ++shift; }
    while ((u & 1) == 0) u >>= 1;
    do {
        while ((v & 1) == 0) v >>= 1;
        if (u > v) { int t = v; v = u; u = t; }
        v = v - u;
    } while (v != 0);
    return u << shift;
}
void findGcdLcm_A3() {
    int a, b;
    printf("Enter two numbers: ");
    if (scanf("%d %d", &a, &b) != 2) return;
    int g = binary_gcd(a, b);
    long long lcm = (g == 0) ? 0LL : (long long)(a / g) * b;
    if (lcm < 0) lcm = -lcm;
    printf("GCD = %d, LCM = %lld\n", g, lcm);
}

/* -------------------------------------------------------------------------- */
/* 2. Prime Number Check                                                      */
/* -------------------------------------------------------------------------- */

/* Approach 1: Simple sqrt check (odd step) */
void checkPrime_A1() {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) return;
    if (n <= 1) { printf("Not Prime\n"); return; }
    if (n <= 3) { printf("Prime\n"); return; }
    if (n % 2 == 0) { printf("Not Prime\n"); return; }
    for (int i = 3; i <= (int)sqrt((double)n); i += 2) {
        if (n % i == 0) { printf("Not Prime\n"); return; }
    }
    printf("Prime\n");
}

/* Approach 2: 6k ± 1 optimization */
void checkPrime_A2() {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) return;
    if (n <= 1) { printf("Not Prime\n"); return; }
    if (n <= 3) { printf("Prime\n"); return; }
    if (n % 2 == 0 || n % 3 == 0) { printf("Not Prime\n"); return; }
    for (int i = 5; (long long)i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) { printf("Not Prime\n"); return; }
    }
    printf("Prime\n");
}

/* -------------------------------------------------------------------------- */
/* 3. Factorial                                                               */
/* -------------------------------------------------------------------------- */

/* Approach 1: Iterative using long long */
void findFactorial_A1() {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) return;
    if (n < 0) { printf("Factorial not defined for negative numbers\n"); return; }
    long long fact = 1;
    for (int i = 2; i <= n; ++i) fact *= i;
    printf("Factorial = %lld\n", fact);
}

/* Approach 2: Recursive (long long) */
long long factorial_recursive(int n) {
    if (n <= 1) return 1;
    return n * factorial_recursive(n - 1);
}
void findFactorial_A2() {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) return;
    if (n < 0) { printf("Factorial not defined for negative numbers\n"); return; }
    long long fact = factorial_recursive(n);
    printf("Factorial = %lld\n", fact);
}

/* Approach 3: Big integer using array (handles larger n up to a reasonable limit) */
void findFactorial_A3() {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) return;
    if (n < 0) { printf("Factorial not defined for negative numbers\n"); return; }
    if (n == 0 || n == 1) { printf("Factorial = 1\n"); return; }
    int res[2000];
    int res_size = 1;
    res[0] = 1;
    for (int x = 2; x <= n; ++x) {
        int carry = 0;
        for (int i = 0; i < res_size; ++i) {
            long long prod = (long long)res[i] * x + carry;
            res[i] = prod % 10;
            carry = prod / 10;
        }
        while (carry) {
            res[res_size++] = carry % 10;
            carry /= 10;
        }
    }
    printf("Factorial = ");
    for (int i = res_size - 1; i >= 0; --i) printf("%d", res[i]);
    printf("\n");
}

/* -------------------------------------------------------------------------- */
/* 4. Sum of Digits                                                           */
/* -------------------------------------------------------------------------- */

/* Approach 1: Iterative (handles negatives) */
void sumOfDigits_A1() {
    long long n;
    printf("Enter a number: ");
    if (scanf("%lld", &n) != 1) return;
    n = llabs(n);
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    printf("Sum of digits = %d\n", sum);
}

/* Approach 2: Recursive */
int sum_digits_rec(long long n) {
    if (n == 0) return 0;
    return (int)(n % 10) + sum_digits_rec(n / 10);
}
void sumOfDigits_A2() {
    long long n;
    printf("Enter a number: ");
    if (scanf("%lld", &n) != 1) return;
    n = llabs(n);
    printf("Sum of digits = %d\n", sum_digits_rec(n));
}

/* -------------------------------------------------------------------------- */
/* 5. Armstrong Number                                                        */
/* -------------------------------------------------------------------------- */

/* Approach 1: Classic 3-digit Armstrong (cube sum) */
void checkArmstrong_A1() {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) return;
    int temp = n, digit, sum = 0;
    while (temp != 0) {
        digit = temp % 10;
        sum += digit * digit * digit;
        temp /= 10;
    }
    if (sum == n) printf("Armstrong Number\n"); else printf("Not Armstrong\n");
}

/* Approach 2: Generalized (n-digit Armstrong) */
int int_pow(int base, int exp) {
    int r = 1;
    while (exp--) r *= base;
    return r;
}
void checkArmstrong_A2() {
    int n;
    printf("Enter a number: ");
    if (scanf("%d", &n) != 1) return;
    int temp = n, digits = 0;
    while (temp != 0) { ++digits; temp /= 10; }
    temp = n;
    int sum = 0;
    while (temp != 0) {
        int d = temp % 10;
        sum += int_pow(d, digits);
        temp /= 10;
    }
    if (sum == n) printf("Armstrong Number\n"); else printf("Not Armstrong\n");
}

/* -------------------------------------------------------------------------- */
/* 6. Anagram Check                                                           */
/* -------------------------------------------------------------------------- */

/* Approach 1: Frequency array (case-sensitive) */
void checkAnagram_A1() {
    char s1[256], s2[256];
    printf("Enter first string: ");
    if (scanf("%s", s1) != 1) return;
    printf("Enter second string: ");
    if (scanf("%s", s2) != 1) return;
    if (strlen(s1) != strlen(s2)) { printf("Not Anagram\n"); return; }
    int freq[256] = {0};
    for (int i = 0; s1[i]; ++i) {
        unsigned char a = (unsigned char)s1[i];
        unsigned char b = (unsigned char)s2[i];
        freq[a]++;
        freq[b]--;
    }
    for (int i = 0; i < 256; ++i) {
        if (freq[i] != 0) { printf("Not Anagram\n"); return; }
    }
    printf("Anagram Strings\n");
}

/* Approach 2: Sort both strings and compare */
int cmp_char(const void *a, const void *b) {
    return (*(const char*)a - *(const char*)b);
}
void checkAnagram_A2() {
    char s1[256], s2[256];
    printf("Enter first string: ");
    if (scanf("%s", s1) != 1) return;
    printf("Enter second string: ");
    if (scanf("%s", s2) != 1) return;
    int n1 = strlen(s1), n2 = strlen(s2);
    if (n1 != n2) { printf("Not Anagram\n"); return; }
    qsort(s1, n1, sizeof(char), cmp_char);
    qsort(s2, n2, sizeof(char), cmp_char);
    if (strcmp(s1, s2) == 0) printf("Anagram Strings\n"); else printf("Not Anagram\n");
}

/* -------------------------------------------------------------------------- */
/* 7. First Non-Repeating Character                                           */
/* -------------------------------------------------------------------------- */

/* Approach 1: Frequency array then scan for first unique */
void firstNonRepeatingChar_A1() {
    char s[512];
    printf("Enter string: ");
    if (scanf("%s", s) != 1) return;
    int freq[256] = {0};
    for (int i = 0; s[i]; ++i) freq[(unsigned char)s[i]]++;
    for (int i = 0; s[i]; ++i) {
        if (freq[(unsigned char)s[i]] == 1) { printf("First non-repeating character: %c\n", s[i]); return; }
    }
    printf("No non-repeating character found\n");
}

/* Approach 2: Store first index or mark repeated, then find minimal index */
void firstNonRepeatingChar_A2() {
    char s[512];
    printf("Enter string: ");
    if (scanf("%s", s) != 1) return;
    int idx[256];
    for (int i = 0; i < 256; ++i) idx[i] = -1;
    for (int i = 0; s[i]; ++i) {
        unsigned char c = (unsigned char)s[i];
        if (idx[c] == -1) idx[c] = i;
        else idx[c] = -2; /* repeated */
    }
    int pos = INT_MAX;
    for (int i = 0; i < 256; ++i) if (idx[i] >= 0 && idx[i] < pos) pos = idx[i];
    if (pos == INT_MAX) printf("No non-repeating character found\n");
    else printf("First non-repeating character: %c\n", s[pos]);
}

/* -------------------------------------------------------------------------- */
/* 8. Remove Duplicates from Array                                            */
/* -------------------------------------------------------------------------- */

/* Approach 1: Preserve first occurrences (O(n^2)) */
void removeDuplicates_A1() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return;
    int *arr = malloc(n * sizeof(int));
    if (!arr) return;
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++) if (arr[i] == arr[j]) break;
        if (i == j) printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}

/* Approach 2: Sort and print unique values (order not preserved) */
int cmp_int(const void *a, const void *b) {
    int va = *(const int*)a;
    int vb = *(const int*)b;
    return (va > vb) - (va < vb);
}
void removeDuplicates_A2() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return;
    int *arr = malloc(n * sizeof(int));
    if (!arr) return;
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp_int);
    printf("Array after removing duplicates: ");
    if (n > 0) {
        printf("%d ", arr[0]);
        for (int i = 1; i < n; ++i) if (arr[i] != arr[i-1]) printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
}

/* -------------------------------------------------------------------------- */
/* 9. Second Largest Number                                                   */
/* -------------------------------------------------------------------------- */

/* Approach 1: Single pass track first and second */
void secondLargest_A1() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return;
    int *arr = malloc(n * sizeof(int));
    if (!arr) return;
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    long long first = LLONG_MIN, second = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > first) { second = first; first = arr[i]; }
        else if (arr[i] > second && arr[i] != first) second = arr[i];
    }
    if (second == LLONG_MIN) printf("No second largest element\n"); else printf("Second largest element = %lld\n", second);
    free(arr);
}

/* Approach 2: Sort and pick second distinct from end */
void secondLargest_A2() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return;
    int *arr = malloc(n * sizeof(int));
    if (!arr) return;
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp_int);
    int i = n - 1;
    int max = arr[i];
    while (i >= 0 && arr[i] == max) i--;
    if (i < 0) printf("No second largest element\n"); else printf("Second largest element = %d\n", arr[i]);
    free(arr);
}

/* -------------------------------------------------------------------------- */
/* 10. All Pairs with Given Sum                                               */
/* -------------------------------------------------------------------------- */

/* Approach 1: Brute-force O(n^2) */
void findPairsWithSum_A1() {
    int n, target;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return;
    int *arr = malloc(n * sizeof(int));
    if (!arr) return;
    printf("Enter elements: ");
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    printf("Enter target sum: ");
    if (scanf("%d", &target) != 1) { free(arr); return; }
    printf("Pairs with sum %d:\n", target);
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (arr[i] + arr[j] == target) printf("(%d, %d)\n", arr[i], arr[j]);
    free(arr);
}

/* Approach 2: Sort and two-pointer (prints unique pairs on sorted values) */
void findPairsWithSum_A2() {
    int n, target;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return;
    int *arr = malloc(n * sizeof(int));
    if (!arr) return;
    printf("Enter elements: ");
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    printf("Enter target sum: ");
    if (scanf("%d", &target) != 1) { free(arr); return; }
    qsort(arr, n, sizeof(int), cmp_int);
    int i = 0, j = n - 1;
    printf("Pairs with sum %d:\n", target);
    while (i < j) {
        int s = arr[i] + arr[j];
        if (s == target) {
            printf("(%d, %d)\n", arr[i], arr[j]);
            int ai = arr[i], aj = arr[j];
            while (i < j && arr[i] == ai) i++;
            while (i < j && arr[j] == aj) j--;
        } else if (s < target) i++;
        else j--;
    }
    free(arr);
}

/* -------------------------------------------------------------------------- */
/* 11. Balanced Parentheses                                                    */
/* -------------------------------------------------------------------------- */

/* Approach 1: Single-type parentheses using a simple stack */
#define STACK_SIZE_1 256
char _stk1[STACK_SIZE_1];
int _top1 = -1;
void checkBalancedParentheses_A1() {
    char exp[512];
    printf("Enter expression: ");
    if (scanf("%s", exp) != 1) return;
    _top1 = -1;
    for (int i = 0; exp[i]; ++i) {
        if (exp[i] == '(') {
            if (_top1 + 1 < STACK_SIZE_1) _stk1[++_top1] = '(';
        } else if (exp[i] == ')') {
            if (_top1 == -1) { printf("Not Balanced\n"); return; }
            _top1--;
        }
    }
    printf((_top1 == -1) ? "Balanced\n" : "Not Balanced\n");
}

/* Approach 2: Handle (), {}, [] using stack */
#define STACK_SIZE_2 512
char _stk2[STACK_SIZE_2];
int _top2 = -1;
void checkBalancedParentheses_A2() {
    char exp[512];
    printf("Enter expression: ");
    if (scanf(" %511[^\n]", exp) != 1) return;
    _top2 = -1;
    for (int i = 0; exp[i]; ++i) {
        char c = exp[i];
        if (c == '(' || c == '{' || c == '[') {
            if (_top2 + 1 < STACK_SIZE_2) _stk2[++_top2] = c;
        } else if (c == ')' || c == '}' || c == ']') {
            if (_top2 == -1) { printf("Not Balanced\n"); return; }
            char t = _stk2[_top2--];
            if ((c == ')' && t != '(') || (c == '}' && t != '{') || (c == ']' && t != '[')) { printf("Not Balanced\n"); return; }
        }
    }
    printf((_top2 == -1) ? "Balanced\n" : "Not Balanced\n");
}

/* -------------------------------------------------------------------------- */
/* 12. Reverse Linked List                                                     */
/* -------------------------------------------------------------------------- */

struct Node {
    int data;
    struct Node* next;
};

/* Approach 1: Iterative reverse */
void reverseLinkedList_A1() {
    struct Node* head = NULL;
    struct Node* temp;
    int n, val;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return;
    for (int i = 0; i < n; ++i) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        if (!temp) return;
        printf("Enter value: ");
        scanf("%d", &val);
        temp->data = val;
        temp->next = head;
        head = temp;
    }
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    printf("Reversed list: ");
    while (prev != NULL) {
        printf("%d ", prev->data);
        struct Node* t = prev;
        prev = prev->next;
        free(t);
    }
    printf("\n");
}

/* Approach 2: Recursive reverse (build by tail insertion to preserve input order) */
struct Node* insert_tail(struct Node* head, int val) {
    struct Node* nn = malloc(sizeof(struct Node));
    if (!nn) return head;
    nn->data = val;
    nn->next = NULL;
    if (!head) return nn;
    struct Node* t = head;
    while (t->next) t = t->next;
    t->next = nn;
    return head;
}
struct Node* reverse_recursive(struct Node* head) {
    if (!head || !head->next) return head;
    struct Node* rest = reverse_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
void reverseLinkedList_A2() {
    struct Node* head = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return;
    for (int i = 0; i < n; ++i) {
        printf("Enter value: ");
        scanf("%d", &val);
        head = insert_tail(head, val);
    }
    head = reverse_recursive(head);
    printf("Reversed list: ");
    while (head) {
        printf("%d ", head->data);
        struct Node* t = head;
        head = head->next;
        free(t);
    }
    printf("\n");
}

/* -------------------------------------------------------------------------- */
/* 13. Find Middle Node of Linked List                                         */
/* -------------------------------------------------------------------------- */

/* Approach 1: Slow-Fast pointer method */
void findMiddleNode_A1() {
    struct Node* head = NULL;
    struct Node* temp;
    int n, val;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return;
    for (int i = 0; i < n; ++i) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value: ");
        scanf("%d", &val);
        temp->data = val;
        temp->next = head;
        head = temp;
    }
    if (!head) { printf("List empty\n"); return; }
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle node = %d\n", slow->data);
    while (head) { struct Node* nx = head->next; free(head); head = nx; }
}

/* Approach 2: Two-pass (count then traverse) - prints second middle when even length */
void findMiddleNode_A2() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return;
    for (int i = 0; i < n; ++i) {
        struct Node* nn = malloc(sizeof(struct Node));
        if (!nn) return;
        printf("Enter value: ");
        scanf("%d", &val);
        nn->data = val;
        nn->next = NULL;
        if (!head) head = tail = nn;
        else { tail->next = nn; tail = nn; }
    }
    int cnt = 0;
    struct Node* t = head;
    while (t) { cnt++; t = t->next; }
    if (cnt == 0) { printf("List empty\n"); return; }
    int mid = cnt / 2;
    t = head;
    for (int i = 0; i < mid; ++i) t = t->next;
    printf("Middle node = %d\n", t->data);
    while (head) { struct Node* nx = head->next; free(head); head = nx; }
}

/* -------------------------------------------------------------------------- */
/* 14. Merge Two Sorted Linked Lists                                           */
/* -------------------------------------------------------------------------- */

/* Approach 1: Merge by pointer manipulation (assumes lists are sorted) */
struct Node* read_list_head_insert(int n) {
    struct Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        struct Node* nn = malloc(sizeof(struct Node));
        if (!nn) return head;
        printf("Enter value: ");
        scanf("%d", &nn->data);
        nn->next = head;
        head = nn;
    }
    return head;
}
void mergeSortedLists_A1() {
    struct Node *head1 = NULL, *head2 = NULL, *temp;
    int n1, n2, val;
    printf("Enter number of nodes in List1: ");
    if (scanf("%d", &n1) != 1) return;
    head1 = read_list_head_insert(n1);
    printf("Enter number of nodes in List2: ");
    if (scanf("%d", &n2) != 1) { while (head1) { temp = head1->next; free(head1); head1 = temp; } return; }
    head2 = read_list_head_insert(n2);
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;
    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    tail->next = head1 ? head1 : head2;
    printf("Merged list: ");
    temp = dummy.next;
    while (temp) {
        printf("%d ", temp->data);
        struct Node* t = temp;
        temp = temp->next;
        free(t);
    }
    printf("\n");
}

/* Approach 2: Merge by converting to arrays and merging (assumes inputs sorted) */
void mergeSortedLists_A2() {
    int n1, n2;
    printf("Enter number of nodes in List1: ");
    if (scanf("%d", &n1) != 1) return;
    int *a1 = malloc((n1 > 0 ? n1 : 1) * sizeof(int));
    for (int i = 0; i < n1; ++i) { printf("Enter value: "); scanf("%d", &a1[i]); }
    printf("Enter number of nodes in List2: ");
    if (scanf("%d", &n2) != 1) { free(a1); return; }
    int *a2 = malloc((n2 > 0 ? n2 : 1) * sizeof(int));
    for (int i = 0; i < n2; ++i) { printf("Enter value: "); scanf("%d", &a2[i]); }
    int i = 0, j = 0;
    printf("Merged list: ");
    while (i < n1 && j < n2) {
        if (a1[i] <= a2[j]) printf("%d ", a1[i++]);
        else printf("%d ", a2[j++]);
    }
    while (i < n1) printf("%d ", a1[i++]);
    while (j < n2) printf("%d ", a2[j++]);
    printf("\n");
    free(a1); free(a2);
}

/* -------------------------------------------------------------------------- */
/* 15. Queue using Two Stacks                                                  */
/* -------------------------------------------------------------------------- */

/* Approach 1: Menu-driven with two fixed-size arrays (as original style) */
#define QSIZE 256
int q_stack1[QSIZE], q_stack2[QSIZE];
int q_top1 = -1, q_top2 = -1;
void q_push1(int x) { if (q_top1 + 1 < QSIZE) q_stack1[++q_top1] = x; }
void q_push2(int x) { if (q_top2 + 1 < QSIZE) q_stack2[++q_top2] = x; }
int q_pop1() { return (q_top1 == -1) ? INT_MIN : q_stack1[q_top1--]; }
int q_pop2() { return (q_top2 == -1) ? INT_MIN : q_stack2[q_top2--]; }
void queueUsingStacks_A1() {
    int choice, x;
    q_top1 = q_top2 = -1;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit Queue Menu\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) return;
        if (choice == 0) break;
        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &x) != 1) return;
                q_push1(x);
                break;
            case 2:
                if (q_top2 == -1) {
                    while (q_top1 != -1) q_push2(q_pop1());
                }
                if (q_top2 == -1) printf("Queue Empty\n");
                else {
                    int v = q_pop2();
                    printf("Dequeued: %d\n", v);
                }
                break;
            case 3:
                printf("Queue elements: ");
                for (int i = q_top2; i >= 0; --i) printf("%d ", q_stack2[i]);
                for (int i = 0; i <= q_top1; ++i) printf("%d ", q_stack1[i]);
                printf("\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}

/* Approach 2: Encapsulated enqueue/dequeue functions (no interactive menu required) */
int s1[QSIZE], s2[QSIZE], t1 = -1, t2 = -1;
void enqueue_A2(int x) { if (t1 + 1 < QSIZE) s1[++t1] = x; }
int dequeue_A2() {
    if (t2 == -1) {
        while (t1 != -1) s2[++t2] = s1[t1--];
    }
    if (t2 == -1) return INT_MIN;
    return s2[t2--];
}
void queueUsingStacks_A2() {
    int ops;
    printf("Enter number of operations: ");
    if (scanf("%d", &ops) != 1) return;
    for (int i = 0; i < ops; ++i) {
        int op;
        printf("Operation (1-enqueue 2-dequeue 3-display): ");
        if (scanf("%d", &op) != 1) return;
        if (op == 1) {
            int v; printf("Enter value: "); scanf("%d", &v);
            enqueue_A2(v);
        } else if (op == 2) {
            int v = dequeue_A2();
            if (v == INT_MIN) printf("Queue Empty\n"); else printf("Dequeued: %d\n", v);
        } else if (op == 3) {
            printf("Queue elements: ");
            for (int j = t2; j >= 0; --j) printf("%d ", s2[j]);
            for (int j = 0; j <= t1; ++j) printf("%d ", s1[j]);
            printf("\n");
        } else {
            printf("Invalid op\n");
        }
    }
}



/* -------------------------------------------------------------------------- */
/* 16. Kruskal's Algorithm (use Union-Find).             */
/* -------------------------------------------------------------------------- */

typedef struct Edge {
    int u, v;
    int w;
} Edge;

/* ---- Utility: Disjoint Set Union (path compression + rank) ---- */
typedef struct DSU {
    int *parent;
    int *rank;
    int n;
} DSU;

DSU* dsu_create(int n) {
    DSU *d = malloc(sizeof(DSU));
    d->n = n;
    d->parent = malloc((n+1) * sizeof(int));
    d->rank = malloc((n+1) * sizeof(int));
    for (int i = 0; i <= n; ++i) { d->parent[i] = i; d->rank[i] = 0; }
    return d;
}
int dsu_find(DSU *d, int x) {
    if (d->parent[x] != x) d->parent[x] = dsu_find(d, d->parent[x]);
    return d->parent[x];
}
void dsu_union(DSU *d, int x, int y) {
    int rx = dsu_find(d, x);
    int ry = dsu_find(d, y);
    if (rx == ry) return;
    if (d->rank[rx] < d->rank[ry]) d->parent[rx] = ry;
    else if (d->rank[ry] < d->rank[rx]) d->parent[ry] = rx;
    else { d->parent[ry] = rx; d->rank[rx]++; }
}
void dsu_free(DSU *d) { if (!d) return; free(d->parent); free(d->rank); free(d); }

/* ------------------ Approach 1: qsort edges + DSU ------------------ */
int cmp_edge(const void *a, const void *b) {
    const Edge *ea = a; const Edge *eb = b;
    return (ea->w > eb->w) - (ea->w < eb->w);
}
void kruskal_qsort_A1() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return;
    if (n <= 0 || m < 0) return;
    Edge *edges = malloc(m * sizeof(Edge));
    printf("Enter edges (u v w) each on new line:\n");
    for (int i = 0; i < m; ++i) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    qsort(edges, m, sizeof(Edge), cmp_edge);
    DSU *d = dsu_create(n);
    int count = 0;
    long long total_w = 0;
    printf("MST edges:\n");
    for (int i = 0; i < m && count < n-1; ++i) {
        int u = edges[i].u, v = edges[i].v;
        if (u < 1 || u > n || v < 1 || v > n) continue;
        if (dsu_find(d, u) != dsu_find(d, v)) {
            dsu_union(d, u, v);
            printf("(%d, %d) weight=%d\n", u, v, edges[i].w);
            total_w += edges[i].w;
            count++;
        }
    }
    if (count != n-1) printf("MST not possible (graph not connected)\n");
    else printf("Total weight = %lld\n", total_w);
    free(edges); dsu_free(d);
}

/* ------------------ Approach 2: Min-heap of edges + DSU ------------------ */
typedef struct MinHeap {
    Edge *data;
    int size;
    int cap;
} MinHeap;
MinHeap* heap_create(int cap) {
    MinHeap *h = malloc(sizeof(MinHeap));
    h->data = malloc((cap+1) * sizeof(Edge)); // 1-based
    h->size = 0; h->cap = cap;
    return h;
}
void heap_swap(Edge *a, Edge *b) { Edge t = *a; *a = *b; *b = t; }
void heap_push(MinHeap *h, Edge e) {
    if (h->size + 1 > h->cap) {
        h->cap = h->cap * 2 + 1;
        h->data = realloc(h->data, (h->cap+1) * sizeof(Edge));
    }
    int i = ++h->size;
    h->data[i] = e;
    while (i > 1 && h->data[i].w < h->data[i/2].w) { heap_swap(&h->data[i], &h->data[i/2]); i /= 2; }
}
Edge heap_pop(MinHeap *h) {
    Edge ret = h->data[1];
    h->data[1] = h->data[h->size--];
    int i = 1;
    while (1) {
        int l = 2*i, r = 2*i+1, smallest = i;
        if (l <= h->size && h->data[l].w < h->data[smallest].w) smallest = l;
        if (r <= h->size && h->data[r].w < h->data[smallest].w) smallest = r;
        if (smallest == i) break;
        heap_swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }
    return ret;
}
int heap_empty(MinHeap *h) { return h->size == 0; }
void heap_free(MinHeap *h) { if (!h) return; free(h->data); free(h); }

void kruskal_heap_A2() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return;
    if (n <= 0 || m < 0) return;
    MinHeap *h = heap_create(m > 0 ? m : 4);
    printf("Enter edges (u v w) each on new line:\n");
    for (int i = 0; i < m; ++i) {
        Edge e; scanf("%d %d %d", &e.u, &e.v, &e.w);
        heap_push(h, e);
    }
    DSU *d = dsu_create(n);
    int count = 0;
    long long total_w = 0;
    printf("MST edges:\n");
    while (!heap_empty(h) && count < n-1) {
        Edge e = heap_pop(h);
        int u = e.u, v = e.v;
        if (u < 1 || u > n || v < 1 || v > n) continue;
        if (dsu_find(d, u) != dsu_find(d, v)) {
            dsu_union(d, u, v);
            printf("(%d, %d) weight=%d\n", u, v, e.w);
            total_w += e.w;
            count++;
        }
    }
    if (count != n-1) printf("MST not possible (graph not connected)\n");
    else printf("Total weight = %lld\n", total_w);
    heap_free(h); dsu_free(d);
}

/* -------------------------------------------------------------------------- */
/* 17. Store weighted graph details using array-of-pointers + linked lists    */
/* -------------------------------------------------------------------------- */

/* Approach 1: basic adjacency list */
typedef struct AdjNode {
    int v;
    int w;
    struct AdjNode *next;
} AdjNode;

void add_edge_basic(AdjNode **adj, int u, int v, int w) {
    AdjNode *nn = malloc(sizeof(AdjNode));
    nn->v = v; nn->w = w; nn->next = adj[u]; adj[u] = nn;
}

void storeWeightedGraph_A1() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return;
    if (n <= 0 || m < 0) return;
    AdjNode **adj = malloc((n+1) * sizeof(AdjNode*));
    for (int i = 0; i <= n; ++i) adj[i] = NULL;
    printf("Enter edges (u v w) each on new line:\n");
    for (int i = 0; i < m; ++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        if (u < 1 || u > n || v < 1 || v > n) continue;
        add_edge_basic(adj, u, v, w); /* directed/add as per need */
        /* If undirected, also add reverse:
           add_edge_basic(adj, v, u, w);
        */
    }
    printf("Adjacency list (vertex: (neighbor,weight) ... )\n");
    for (int i = 1; i <= n; ++i) {
        printf("%d: ", i);
        for (AdjNode *p = adj[i]; p; p = p->next) printf("(%d,%d) ", p->v, p->w);
        printf("\n");
    }
    /* free memory */
    for (int i = 1; i <= n; ++i) {
        AdjNode *p = adj[i];
        while (p) { AdjNode *nx = p->next; free(p); p = nx; }
    }
    free(adj);
}

/* Approach 2: adjacency list using tail pointers for O(1) append (keeps insertion order) */
typedef struct AdjList {
    AdjNode *head;
    AdjNode *tail;
} AdjList;

void add_edge_tail(AdjList *lists, int u, int v, int w) {
    AdjNode *nn = malloc(sizeof(AdjNode));
    nn->v = v; nn->w = w; nn->next = NULL;
    if (!lists[u].head) lists[u].head = lists[u].tail = nn;
    else { lists[u].tail->next = nn; lists[u].tail = nn; }
}

void storeWeightedGraph_A2() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    if (scanf("%d %d", &n, &m) != 2) return;
    if (n <= 0 || m < 0) return;
    AdjList *lists = malloc((n+1) * sizeof(AdjList));
    for (int i = 0; i <= n; ++i) { lists[i].head = lists[i].tail = NULL; }
    printf("Enter edges (u v w) each on new line:\n");
    for (int i = 0; i < m; ++i) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        if (u < 1 || u > n || v < 1 || v > n) continue;
        add_edge_tail(lists, u, v, w);
        /* for undirected graphs, also call add_edge_tail(lists, v, u, w); */
    }
    printf("Adjacency list (vertex: (neighbor,weight) ... )\n");
    for (int i = 1; i <= n; ++i) {
        printf("%d: ", i);
        for (AdjNode *p = lists[i].head; p; p = p->next) printf("(%d,%d) ", p->v, p->w);
        printf("\n");
    }
    /* free memory */
    for (int i = 1; i <= n; ++i) {
        AdjNode *p = lists[i].head;
        while (p) { AdjNode *nx = p->next; free(p); p = nx; }
    }
    free(lists);
}

/* -------------------------------------------------------------------------- */
/* 18. Create a BST and count number of leaf nodes                            */
/* -------------------------------------------------------------------------- */

typedef struct BSTNode {
    int val;
    struct BSTNode *left, *right;
} BSTNode;

/* Approach 1: recursive insert + recursive count */
BSTNode* bst_insert_rec(BSTNode *root, int x) {
    if (!root) {
        BSTNode *n = malloc(sizeof(BSTNode));
        n->val = x; n->left = n->right = NULL;
        return n;
    }
    if (x < root->val) root->left = bst_insert_rec(root->left, x);
    else root->right = bst_insert_rec(root->right, x);
    return root;
}
int bst_count_leaves_rec(BSTNode *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return bst_count_leaves_rec(root->left) + bst_count_leaves_rec(root->right);
}
void bst_count_leaves_A1() {
    int n;
    printf("Enter number of nodes to insert into BST: ");
    if (scanf("%d", &n) != 1) return;
    BSTNode *root = NULL;
    printf("Enter values:\n");
    for (int i = 0; i < n; ++i) {
        int v; scanf("%d", &v);
        root = bst_insert_rec(root, v);
    }
    int leaves = bst_count_leaves_rec(root);
    printf("Number of leaf nodes = %d\n", leaves);
    /* free tree (post-order) */
    BSTNode *stack[512];
    int top = -1;
    if (root) stack[++top] = root;
    while (top >= 0) {
        BSTNode *node = stack[top--];
        if (node->left) stack[++top] = node->left;
        if (node->right) stack[++top] = node->right;
        free(node);
    }
}

/* Approach 2: iterative insert + iterative count using simple stack (non-recursive) */
BSTNode* bst_insert_iter(BSTNode *root, int x) {
    BSTNode *nn = malloc(sizeof(BSTNode)); nn->val = x; nn->left = nn->right = NULL;
    if (!root) return nn;
    BSTNode *cur = root, *parent = NULL;
    while (cur) {
        parent = cur;
        if (x < cur->val) cur = cur->left;
        else cur = cur->right;
    }
    if (x < parent->val) parent->left = nn; else parent->right = nn;
    return root;
}
int bst_count_leaves_iter(BSTNode *root) {
    if (!root) return 0;
    BSTNode **stk = malloc(512 * sizeof(BSTNode*));
    int top = -1;
    stk[++top] = root;
    int leaves = 0;
    while (top >= 0) {
        BSTNode *node = stk[top--];
        if (!node->left && !node->right) leaves++;
        if (node->right) stk[++top] = node->right;
        if (node->left) stk[++top] = node->left;
    }
    free(stk);
    return leaves;
}
void bst_count_leaves_A2() {
    int n;
    printf("Enter number of nodes to insert into BST: ");
    if (scanf("%d", &n) != 1) return;
    BSTNode *root = NULL;
    printf("Enter values:\n");
    for (int i = 0; i < n; ++i) {
        int v; scanf("%d", &v);
        if (!root) root = bst_insert_iter(NULL, v);
        else bst_insert_iter(root, v);
    }
    int leaves = bst_count_leaves_iter(root);
    printf("Number of leaf nodes = %d\n", leaves);
    /* free tree using iterative post-order simulated via two stacks */
    if (root) {
        BSTNode **s1 = malloc(512 * sizeof(BSTNode*));
        BSTNode **s2 = malloc(512 * sizeof(BSTNode*));
        int t1 = -1, t2 = -1;
        s1[++t1] = root;
        while (t1 >= 0) {
            BSTNode *n = s1[t1--];
            s2[++t2] = n;
            if (n->left) s1[++t1] = n->left;
            if (n->right) s1[++t1] = n->right;
        }
        while (t2 >= 0) { free(s2[t2--]); }
        free(s1); free(s2);
    }
}
/* -------------------------------------------------------------------------- */
/* 19. Binary Tree Traversals (Inorder, Preorder, Postorder)                   */
/* -------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

/* Approach 1: Recursive inorder traversal */
void inorder_A1(TreeNode *root) {
    if (!root) return;
    inorder_A1(root->left);
    printf("%d ", root->data);
    inorder_A1(root->right);
}

/* Approach 2: Iterative inorder using array stack */
#define MAX_STACK 100
void inorder_A2(TreeNode *root) {
    TreeNode *stack[MAX_STACK];
    int top = -1;
    TreeNode *curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

/* Approach 3: Recursive preorder traversal */
void preorder_A3(TreeNode *root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder_A3(root->left);
    preorder_A3(root->right);
}

/* -------------------------------------------------------------------------- */
/* 20. Detect Cycle in a Graph                                                 */
/* -------------------------------------------------------------------------- */

/* Approach 1: DFS recursion (for directed graph) */
int dfsCycle_A1(int u, int **g, int *visited, int *recStack, int V) {
    if(!visited[u]){
        visited[u] = 1;
        recStack[u] = 1;
        for(int i=0;i<V;i++){
            if(g[u][i]){
                if(!visited[i] && dfsCycle_A1(i,g,visited,recStack,V)) return 1;
                else if(recStack[i]) return 1;
            }
        }
    }
    recStack[u] = 0;
    return 0;
}

int isCyclicDFS_A1(int **g, int V) {
    int visited[V], recStack[V];
    for(int i=0;i<V;i++) visited[i]=recStack[i]=0;
    for(int i=0;i<V;i++){
        if(dfsCycle_A1(i,g,visited,recStack,V)) return 1;
    }
    return 0;
}
/* Approach 2: Union-Find (for undirected graph) */
int findUF_A3(int parent[], int i){
    if(parent[i]==-1) return i;
    return parent[i]=findUF_A3(parent,parent[i]);
}

int unionUF_A3(int parent[], int x,int y){
    int xset=findUF_A3(parent,x), yset=findUF_A3(parent,y);
    if(xset==yset) return 0;
    parent[xset]=yset;
    return 1;
}

int isCyclicUF_A3(int edges[][2], int V, int E){
    int parent[V];
    for(int i=0;i<V;i++) parent[i]=-1;
    for(int i=0;i<E;i++){
        if(!unionUF_A3(parent,edges[i][0],edges[i][1])) return 1;
    }
    return 0;
}
