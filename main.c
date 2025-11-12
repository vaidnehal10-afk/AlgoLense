#include <stdio.h>
#include "codebase.h"
#include "flowchart.h"

// Function to display problem descriptions
void showProblemDescription(int problem) {
    switch(problem) {
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
            printf("Description: Calculate factorial of a number using iterative or recursive approach.\n");
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
            printf("Description: Determine if two strings are anagrams of each other.\n");
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
            printf("Description: Find the second largest element in an array.\n");
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
            printf("Description: Find the middle node of a singly linked list using two-pointer or counting method.\n");
            break;
        case 14:
            printf("\nProblem 14: Merge Two Sorted Linked Lists\n");
            printf("Description: Merge two sorted linked lists into a single sorted list iteratively or recursively.\n");
            break;
        case 15:
            printf("\nProblem 15: Implement Queue Using Two Stacks\n");
            printf("Description: Implement queue operations using two stacks.\n");
            break;
        default:
            printf("Problem description not available.\n");
    }
}

// Function to show variations menu
void showVariation(int problem) {
    int varChoice;
    while(1) {
        printf("\n--- Variations ---\n");
        switch(problem) {
            case 1:
                printf("1. Iterative\n");
                break;
            case 2:
                printf("1. Naive\n2. Optimized\n");
                break;
            case 3: case 4:
                printf("1. Iterative\n2. Recursive\n");
                break;
            case 8: case 9: case 12: case 14:
                printf("1. Iterative\n2. Recursive\n");
                break;
            default:
                printf("No variations available\n");
                return;
        }
        printf("0. Back\n");
        printf("Enter choice: ");
        scanf("%d", &varChoice);
        if(varChoice == 0) break;

        printf("\n--- OUTPUT ---\n");
        switch(problem) {
            case 1:
                if (varChoice==1) findGcdLcm_A1();
                else if(varChoice==2) findGcdLcm_A2();
                else if(varChoice==3) findGcdLcm_A3();
                break;
            case 2:
                if(varChoice==1) checkPrime_A1();       // Naive
                else if(varChoice==2) checkPrime_A2(); // Optimized
                break;
            case 3:
                if(varChoice==1) findFactorial_A1();
                else if(varChoice==2) findFactorial_A2();
                else if(varChoice==3) findFactorial_A3();
                break;
            case 4:
                if(varChoice==1)sumOfDigits_A1();
                else if(varChoice==2) sumOfDigits_A2();
                break;
            case 5:
                if(varChoice==1)checkArmstrong_A1();
                else if(varChoice==2) checkArmstrong_A2();
                break;
            case 6:
                if(varChoice==1)checkAnagram_A1();
                else if(varChoice==2) checkAnagram_A2();
                break;
             case 7:
                if(varChoice==1)firstNonRepeatingChar_A1();
                else if(varChoice==2) firstNonRepeatingChar_A2();
                break;
            
            case 8:
                if(varChoice==1)  removeDuplicates_A1();
                else if(varChoice==2)  removeDuplicates_A2();
                break;
            case 9:
                if(varChoice==1) secondLargest_A1();
                else if(varChoice==2) secondLargest_A2() ;
                break;
             case 10:
                if(varChoice==1) findPairsWithSum_A1();
                else if(varChoice==2)findPairsWithSum_A2() ;
                break;
             case 11:
                if(varChoice==1) checkBalancedParentheses_A1();
                else if(varChoice==2)checkBalancedParentheses_A2() ;
                break;
            
            case 12:
                if(varChoice==1) reverseLinkedList_A1 ();
                else if(varChoice==2) reverseLinkedList_A2();
                break;
             case 13:
                if(varChoice==1)  findMiddleNode_A1();
                else if(varChoice==2)  findMiddleNode_A2();
                break;
            case 14:
                if(varChoice==1) mergeSortedLists_A1() ;
                else if(varChoice==2)mergeSortedLists_A2() ;
                break;
            
            default:
                printf("Variation not implemented yet.\n");
        }
    }
}

// Placeholder for time/space complexity
void showComplexity(int problem) {
    printf("\n--- Time and Space Complexity ---\n");
    switch(problem) {
        case 1: printf("GCD & LCM: Time O(log min(a,b)), Space O(1)\n"); break;
        case 2: printf("Prime (Naive): Time O(n), Optimized: O(sqrt(n)), Space O(1)\n"); break;
        case 3: printf("Factorial: Iterative O(n), Recursive O(n), Space Iterative O(1), Recursive O(n)\n"); break;
        case 4: printf("Sum of Digits: Iterative O(log n), Recursive O(log n), Space O(1) / O(log n)\n"); break;
        case 5: printf("Armstrong: Time O(log n), Space O(1)\n"); break;
        case 6: printf("Anagram: Time O(n + m), Space O(256)\n"); break;
        case 7: printf("First Non-Repeating Char: Time O(n), Space O(256)\n"); break;
        case 8: printf("Remove Duplicates: Time O(n^2) / O(n), Space O(n)\n"); break;
        case 9: printf("Second Largest: Time O(n) / O(n log n), Space O(1)\n"); break;
        case 10: printf("Pairs with Sum: Time O(n^2), Space O(1)\n"); break;
        case 11: printf("Balanced Parentheses: Time O(n), Space O(n)\n"); break;
        case 12: printf("Reverse Linked List: Time O(n), Space O(1) / O(n)\n"); break;
        case 13: printf("Middle Node: Time O(n), Space O(1)\n"); break;
        case 14: printf("Merge Sorted Linked List: Time O(n+m), Space O(1)\n"); break;
        case 15: printf("Queue using Two Stacks: Time O(1) amortized enqueue/dequeue, Space O(n)\n"); break;
        default: printf("Complexity not available.\n");
    }
}

// Problem submenu
void problemMenu(int problem) {
    showProblemDescription(problem);
    int choice;
    while(1) {
        printf("\n--- Problem %d Menu ---\n", problem);
        printf("1. Variations\n2. Flowchart\n3. Time/Space Complexity\n0. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if(choice == 0) break;

        switch(choice) {
            case 1: showVariation(problem); break;
            case 2: displayFlowchart(problem); break;
            case 3: showComplexity(problem); break;
            default: printf("Invalid choice!\n");
        }
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n==============================\n");
        printf("     DSA MINI PROJECT MENU\n");
        printf("==============================\n");
        printf("1. Find GCD and LCM\n");
        printf("2. Check Prime Number\n");
        printf("3. Factorial (Recursion & Iteration)\n");
        printf("4. Sum of Digits (Recursion & Iteration)\n");
        printf("5. Check Armstrong Number\n");
        printf("6. Check if Two Strings are Anagrams\n");
        printf("7. Find First Non-Repeating Character\n");
        printf("8. Remove Duplicates from Array\n");
        printf("9. Find Second Largest in Array\n");
        printf("10. Find All Pairs with Given Sum\n");
        printf("11. Check Balanced Parentheses\n");
        printf("12. Reverse a Linked List\n");
        printf("13. Find Middle Node of Linked List\n");
        printf("14. Merge Two Sorted Linked Lists\n");
        printf("15. Implement Queue Using Two Stacks\n");
        printf("0. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 0) {
            printf("Exiting program... Goodbye!\n");
            break;
        }

        if(choice >=1 && choice <=15) {
            problemMenu(choice);
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
