// flowchart.h
#ifndef FLOWCHART_H
#define FLOWCHART_H

// Simple linked list node for storing flowchart text steps
typedef struct QNode {
    char step[100];
    struct QNode *next;
} QNode;

// Queue functions
void enqueue(QNode **head, QNode **tail, const char *step);
void displayQueue(QNode *head);

// Main flowchart dispatcher – called from main.c with problem 1..20
void displayFlowchart(int problem);

#endif
