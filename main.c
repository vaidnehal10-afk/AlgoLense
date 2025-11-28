// main.c
#include <stdio.h>
#include "codebase.h"
#include "flowchart.h"

// Function to display problem descriptions
void showProblemDescription(int problem) {
    switch (problem) {
        case 1:
            printf("\nProblem 1: Find GCD and LCM\n");
            printf("Description: Calculate the Greatest Common Divisor and Least Common Multiple of two integers.\n");
            break;
        case 2:
            printf("\nProblem 2: Check Prime Number\n");
            printf("Description: Determine whether a given number is prime.\n");
            break;
        case 3:
            printf("\nProblem 3: Factorial\n");
            printf("Description: Calculate factorial of a number using iterative / recursive / big integer approach.\n");
            break;
        case 4:
            printf("\nProblem 4: Sum of Digits\n");
            printf("Description: Find the sum of digits of a number using iterative or recursive approach.\n");
            break;
        case 5:
            printf("\nProblem 5: Check Armstrong Number\n");
            printf("Description: Determine if a number is an Armstrong number.\n");
            break;
        case 6:
            printf("\nProblem 6: Check if Two Strings are Anagrams\n");
            printf("Description: Check whether two strings are anagrams of each other.\n");
            break;
        case 7:
            printf("\nProblem 7: Find First Non-Repeating Character\n");
            printf("Description: Find the first non-repeating character in a string.\n");
            break;
        case 8:
            printf("\nProblem 8: Remove Duplicates from Array\n");
            printf("Description: Remove duplicate elements from an array.\n");
            break;
        case 9:
            printf("\nProblem 9: Find Second Largest in Array\n");
            printf("Description: Find the second largest distinct element in an array.\n");
            break;
        case 10:
            printf("\nProblem 10: Find All Pairs with Given Sum\n");
            printf("Description: Find all pairs in an array whose sum equals a target value.\n");
            break;
        case 11:
            printf("\nProblem 11: Check Balanced Parentheses\n");
            printf("Description: Check if an expression has balanced parentheses using stack.\n");
            break;
        case 12:
            printf("\nProblem 12: Reverse a Linked List\n");
            printf("Description: Reverse a singly linked list using iterative or recursive method.\n");
            break;
        case 13:
            printf("\nProblem 13: Find Middle Node of Linked List\n");
            printf("Description: Find the middle node of a singly linked list.\n");
            break;
        case 14:
            printf("\nProblem 14: Merge Two Sorted Linked Lists\n");
            printf("Description: Merge two sorted linked lists into a single sorted list.\n");
            break;
        case 15:
            printf("\nProblem 15: Implement Queue Using Two Stacks\n");
            printf("Description: Implement queue operations using two stacks.\n");
            break;
        case 16:
            printf("\nProblem 16: Kruskal Algorithm\n");
            printf("Description: Find Minimum Spanning Tree (MST) of a graph using Kruskal.\n");
            break;
        case 17:
            printf("\nProblem 17: Store Weighted Graph\n");
            printf("Description: Store weighted graph using adjacency list.\n");
            break;
        case 18:
            printf("\nProblem 18: Create BST and Count Leaf Nodes\n");
            printf("Description: Create a Binary Search Tree and count number of leaf nodes.\n");
            break;
        case 19:
            printf("\nProblem 19: Binary Tree Traversals\n");
            printf("Description: Perform inorder (recursive / iterative) and preorder traversal of a binary tree.\n");
            break;
        case 20:
            printf("\nProblem 20: Detect Cycle in Graph\n");
            printf("Description: Detect cycle in a graph using DFS (directed) or Union-Find (undirected).\n");
            break;
        default:
            printf("Problem description not available.\n");
    }
}

// Function to show variations menu
void showVariation(int problem) {
    int varChoice;
    while (1) {
        printf("\n--- Variations ---\n");
        switch (problem) {
            case 1:
                printf("1. Euclidean (Iterative)\n");
                printf("2. Euclidean (Recursive)\n");
                printf("3. Binary GCD (Stein)\n");
                break;
            case 2:
                printf("1. Simple sqrt check\n");
                printf("2. 6k ± 1 optimization\n");
                break;
            case 3:
                printf("1. Iterative (long long)\n");
                printf("2. Recursive (long long)\n");
                printf("3. Big integer using array\n");
                break;
            case 4:
                printf("1. Iterative\n");
                printf("2. Recursive\n");
                break;
            case 5:
                printf("1. Classic 3-digit Armstrong\n");
                printf("2. General n-digit Armstrong\n");
                break;
            case 6:
                printf("1. Frequency array\n");
                printf("2. Sort & compare\n");
                break;
            case 7:
                printf("1. Frequency then scan\n");
                printf("2. Index array approach\n");
                break;
            case 8:
                printf("1. O(n^2) – preserve order\n");
                printf("2. Sort & unique\n");
                break;
            case 9:
                printf("1. Single-pass tracking\n");
                printf("2. Sort & pick from end\n");
                break;
            case 10:
                printf("1. Brute-force O(n^2)\n");
                printf("2. Sort + two-pointer\n");
                break;
            case 11:
                printf("1. Only () parentheses\n");
                printf("2. (), {}, [] parentheses\n");
                break;
            case 12:
                printf("1. Iterative reverse\n");
                printf("2. Recursive reverse\n");
                break;
            case 13:
                printf("1. Slow/Fast pointers\n");
                printf("2. Two-pass counting\n");
                break;
            case 14:
                printf("1. Linked list merge\n");
                printf("2. Array-based merge\n");
                break;
            case 15:
                printf("1. Interactive queue menu\n");
                printf("2. Operation-based queue\n");
                break;
            case 16:
                printf("1. Kruskal using qsort + DSU\n");
                printf("2. Kruskal using Min-Heap + DSU\n");
                break;
            case 17:
                printf("1. Adjacency list (basic)\n");
                printf("2. Adjacency list with tail pointer\n");
                break;
            case 18:
                printf("1. BST insert + recursive leaf count\n");
                printf("2. BST insert + iterative leaf count\n");
                break;
            case 19:
                printf("1. Inorder (recursive)\n");
                printf("2. Inorder (iterative)\n");
                printf("3. Preorder (recursive)\n");
                break;
            case 20:
                printf("1. Cycle detection using DFS (directed, adjacency matrix)\n");
                printf("2. Cycle detection using Union-Find (undirected, edge list)\n");
                break;
            default:
                printf("No variations available.\n");
                return;
        }
        printf("0. Back\n");
        printf("Enter choice: ");
        if (scanf("%d", &varChoice) != 1) return;
        if (varChoice == 0) break;

        printf("\n--- OUTPUT ---\n");
        switch (problem) {
            case 1:
                if      (varChoice == 1) findGcdLcm_A1();
                else if (varChoice == 2) findGcdLcm_A2();
                else if (varChoice == 3) findGcdLcm_A3();
                else printf("Invalid variation!\n");
                break;
            case 2:
                if      (varChoice == 1) checkPrime_A1();
                else if (varChoice == 2) checkPrime_A2();
                else printf("Invalid variation!\n");
                break;
            case 3:
                if      (varChoice == 1) findFactorial_A1();
                else if (varChoice == 2) findFactorial_A2();
                else if (varChoice == 3) findFactorial_A3();
                else printf("Invalid variation!\n");
                break;
            case 4:
                if      (varChoice == 1) sumOfDigits_A1();
                else if (varChoice == 2) sumOfDigits_A2();
                else printf("Invalid variation!\n");
                break;
            case 5:
                if      (varChoice == 1) checkArmstrong_A1();
                else if (varChoice == 2) checkArmstrong_A2();
                else printf("Invalid variation!\n");
                break;
            case 6:
                if      (varChoice == 1) checkAnagram_A1();
                else if (varChoice == 2) checkAnagram_A2();
                else printf("Invalid variation!\n");
                break;
            case 7:
                if      (varChoice == 1) firstNonRepeatingChar_A1();
                else if (varChoice == 2) firstNonRepeatingChar_A2();
                else printf("Invalid variation!\n");
                break;
            case 8:
                if      (varChoice == 1) removeDuplicates_A1();
                else if (varChoice == 2) removeDuplicates_A2();
                else printf("Invalid variation!\n");
                break;
            case 9:
                if      (varChoice == 1) secondLargest_A1();
                else if (varChoice == 2) secondLargest_A2();
                else printf("Invalid variation!\n");
                break;
            case 10:
                if      (varChoice == 1) findPairsWithSum_A1();
                else if (varChoice == 2) findPairsWithSum_A2();
                else printf("Invalid variation!\n");
                break;
            case 11:
                if      (varChoice == 1) checkBalancedParentheses_A1();
                else if (varChoice == 2) checkBalancedParentheses_A2();
                else printf("Invalid variation!\n");
                break;
            case 12:
                if      (varChoice == 1) reverseLinkedList_A1();
                else if (varChoice == 2) reverseLinkedList_A2();
                else printf("Invalid variation!\n");
                break;
            case 13:
                if      (varChoice == 1) findMiddleNode_A1();
                else if (varChoice == 2) findMiddleNode_A2();
                else printf("Invalid variation!\n");
                break;
            case 14:
                if      (varChoice == 1) mergeSortedLists_A1();
                else if (varChoice == 2) mergeSortedLists_A2();
                else printf("Invalid variation!\n");
                break;
            case 15:
                if      (varChoice == 1) queueUsingStacks_A1();
                else if (varChoice == 2) queueUsingStacks_A2();
                else printf("Invalid variation!\n");
                break;
            case 16:
                if      (varChoice == 1) kruskal_qsort_A1();
                else if (varChoice == 2) kruskal_heap_A2();
                else printf("Invalid variation!\n");
                break;
            case 17:
                if      (varChoice == 1) storeWeightedGraph_A1();
                else if (varChoice == 2) storeWeightedGraph_A2();
                else printf("Invalid variation!\n");
                break;
            case 18:
                if      (varChoice == 1) bst_count_leaves_A1();
                else if (varChoice == 2) bst_count_leaves_A2();
                else printf("Invalid variation!\n");
                break;
            case 19:
                if      (varChoice == 1) treeTraversal_A1();
                else if (varChoice == 2) treeTraversal_A2();
                else if (varChoice == 3) treeTraversal_A3();
                else printf("Invalid variation!\n");
                break;
            case 20:
                if      (varChoice == 1) detectCycle_A1();
                else if (varChoice == 2) detectCycle_A2();
                else printf("Invalid variation!\n");
                break;
            default:
                printf("Variation not implemented yet.\n");
        }
    }
}

// Time/space complexity
void showComplexity(int problem) {
    printf("\n--- Time and Space Complexity ---\n");
    switch (problem) {
        case 1:  printf("GCD & LCM: Time O(log min(a,b)), Space O(1)\n"); break;
        case 2:  printf("Prime: Time O(sqrt(n)), Space O(1)\n"); break;
        case 3:  printf("Factorial: O(n) time, big-int has extra digit handling; space O(1)/O(n)\n"); break;
        case 4:  printf("Sum of Digits: Time O(d), Space O(1) / O(d)\n"); break;
        case 5:  printf("Armstrong: Time O(d), Space O(1)\n"); break;
        case 6:  printf("Anagram: Time O(n) / O(n log n), Space O(1)/O(n)\n"); break;
        case 7:  printf("First Non-Repeating Char: Time O(n), Space O(1)\n"); break;
        case 8:  printf("Remove Duplicates: O(n^2) or O(n log n), Space O(1)/O(n)\n"); break;
        case 9:  printf("Second Largest: O(n) or O(n log n), Space O(1)\n"); break;
        case 10: printf("Pairs with Sum: Time O(n^2) or O(n log n), Space O(1)\n"); break;
        case 11: printf("Balanced Parentheses: Time O(n), Space O(n)\n"); break;
        case 12: printf("Reverse Linked List: Time O(n), Space O(1)/O(n)\n"); break;
        case 13: printf("Middle Node: Time O(n), Space O(1)\n"); break;
        case 14: printf("Merge Sorted Lists: Time O(n+m), Space O(1)\n"); break;
        case 15: printf("Queue using Two Stacks: Amortized O(1), Space O(n)\n"); break;
        case 16: printf("Kruskal: Time O(E log E), Space O(V+E)\n"); break;
        case 17: printf("Store Weighted Graph: Build O(V+E), Space O(V+E)\n"); break;
        case 18: printf("BST Leaf Count: Time O(n), Space O(h)/O(n)\n"); break;
        case 19: printf("Traversals: Time O(n), Space O(h)/O(n)\n"); break;
        case 20: printf("Cycle Detection: DFS O(V+E), Union-Find O(E α(V)), Space O(V+E)\n"); break;
        default: printf("Complexity not available.\n");
    }
}

// Problem submenu
void problemMenu(int problem) {
    showProblemDescription(problem);
    int choice;
    while (1) {
        printf("\n--- Problem %d Menu ---\n", problem);
        printf("1. Variations\n2. Flowchart\n3. Time/Space Complexity\n0. Back to Main Menu\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) return;
        if (choice == 0) break;

        switch (choice) {
            case 1: showVariation(problem);    break;
            case 2: displayFlowchart(problem); break;
            case 3: showComplexity(problem);   break;
            default: printf("Invalid choice!\n");
        }
    }
}

int main(void) {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf("         DSA MINI PROJECT\n");
        printf("==============================\n");
        printf(" 1. GCD & LCM\n");
        printf(" 2. Prime Check\n");
        printf(" 3. Factorial\n");
        printf(" 4. Sum of Digits\n");
        printf(" 5. Armstrong Number\n");
        printf(" 6. Anagram Check\n");
        printf(" 7. First Non-Repeating Character\n");
        printf(" 8. Remove Duplicates from Array\n");
        printf(" 9. Second Largest in Array\n");
        printf("10. Pairs with Given Sum\n");
        printf("11. Balanced Parentheses\n");
        printf("12. Reverse Linked List\n");
        printf("13. Middle Node of Linked List\n");
        printf("14. Merge Two Sorted Linked Lists\n");
        printf("15. Queue Using Two Stacks\n");
        printf("16. Kruskal Algorithm\n");
        printf("17. Store Weighted Graph\n");
        printf("18. BST Leaf Count\n");
        printf("19. Binary Tree Traversals\n");
        printf("20. Detect Cycle in Graph\n");
        printf(" 0. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 0) {
            printf("Exiting program... Goodbye!\n");
            break;
        }

        if (choice >= 1 && choice <= 20) {
            problemMenu(choice);
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
