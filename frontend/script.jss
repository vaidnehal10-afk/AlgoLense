// script.js

const problems = [
    {
        id: 1,
        title: "Problem 1: GCD & LCM",
        desc: "Compute the Greatest Common Divisor and Least Common Multiple of two integers.",
        variations: [
            "Euclidean Algorithm (Iterative)",
            "Euclidean Algorithm (Recursive)",
            "Binary GCD (Stein's Algorithm)"
        ],
        complexity: "GCD: O(log min(a,b)), LCM computed in O(1) once GCD is known.",
        flowchart: [
            "[Iterative] Read a, b → while b != 0: temp=b, b=a%b, a=temp → GCD=a → LCM=(n1*n2)/GCD",
            "[Recursive] GCD(a,b): if b==0 return a, else return GCD(b,a%b)",
            "[Binary GCD] Repeatedly factor out powers of 2 and subtract smaller from larger."
        ]
    },
    {
        id: 2,
        title: "Problem 2: Prime Check",
        desc: "Check whether a given number is prime.",
        variations: [
            "Naive trial division up to n-1 / sqrt(n)",
            "Optimized 6k ± 1 method"
        ],
        complexity: "Naive: O(n) or O(√n). Optimized: O(√n) with fewer checks.",
        flowchart: [
            "[Naive] Read n → if n < 2 not prime → for i from 2..n-1: if n%i==0 not prime → else prime.",
            "[6k±1] Handle small cases, then test divisibility by 6k±1 up to √n."
        ]
    },
    {
        id: 3,
        title: "Problem 3: Factorial",
        desc: "Find factorial of a number using multiple approaches.",
        variations: [
            "Iterative using long long",
            "Recursive using long long",
            "Big integer factorial using array of digits"
        ],
        complexity: "O(n) multiplications; big-int version also has extra cost in digit handling.",
        flowchart: [
            "[Iterative] fact=1 → loop i=1..n: fact*=i → print fact.",
            "[Recursive] factorial(n): if n<=1 return 1 else return n*factorial(n-1).",
            "[Big-int] Store result in array, multiply by each i updating digits with carry."
        ]
    },
    {
        id: 4,
        title: "Problem 4: Sum of Digits",
        desc: "Compute the sum of digits of an integer.",
        variations: [
            "Iterative digit extraction",
            "Recursive digit sum"
        ],
        complexity: "O(d) where d is number of digits; Space O(1) iterative, O(d) recursive.",
        flowchart: [
            "[Iterative] sum=0 → while n>0: sum+=n%10, n/=10 → print sum.",
            "[Recursive] sum(n)=0 if n==0 else (n%10)+sum(n/10)."
        ]
    },
    {
        id: 5,
        title: "Problem 5: Armstrong Number",
        desc: "Check whether a number is an Armstrong number.",
        variations: [
            "Classic 3-digit Armstrong check",
            "General n-digit Armstrong check"
        ],
        complexity: "O(d) where d is number of digits.",
        flowchart: [
            "[3-digit] sum of cubes of digits == original number.",
            "[n-digit] count digits d → sum pow(digit, d) → compare to original."
        ]
    },
    {
        id: 6,
        title: "Problem 6: Anagram Check",
        desc: "Check if two strings are anagrams.",
        variations: [
            "Frequency array (increment/decrement counts)",
            "Sort both strings and compare"
        ],
        complexity: "Frequency: O(n) time, O(1) space (fixed alphabet). Sorting: O(n log n).",
        flowchart: [
            "[Freq] If lengths differ → not anagram. Increment counts for s1, decrement for s2 → if all 0, anagram.",
            "[Sort] Sort s1, sort s2, then compare strings."
        ]
    },
    {
        id: 7,
        title: "Problem 7: First Non-Repeating Character",
        desc: "Find the first character in a string that appears exactly once.",
        variations: [
            "Frequency array then left-to-right scan",
            "Index array: store first index or mark repeated"
        ],
        complexity: "O(n) time, O(1) space for fixed ASCII.",
        flowchart: [
            "[Freq] Build freq[256] → scan again to find first char with freq==1.",
            "[Index] idx[c] = first index or -2 for repeated → answer = minimum non-negative idx."
        ]
    },
    {
        id: 8,
        title: "Problem 8: Remove Duplicates from Array",
        desc: "Remove duplicate elements from an integer array.",
        variations: [
            "O(n^2) method preserving first occurrences",
            "Sort array then print unique elements"
        ],
        complexity: "O(n^2) or O(n log n); extra memory optional.",
        flowchart: [
            "[O(n^2)] For each a[i], check if it appeared before; if not, print it.",
            "[Sorted] Sort array, then print element when it differs from previous."
        ]
    },
    {
        id: 9,
        title: "Problem 9: Second Largest Element",
        desc: "Find the second largest distinct element in an array.",
        variations: [
            "Single-pass tracking of max and second max",
            "Sort array and move from end to find next smaller than max"
        ],
        complexity: "O(n) or O(n log n); O(1) extra space.",
        flowchart: [
            "[Single pass] Maintain first, second; update as you scan.",
            "[Sorted] After sort, walk backwards to first value < max."
        ]
    },
    {
        id: 10,
        title: "Problem 10: Pairs with Given Sum",
        desc: "Print all pairs of array elements whose sum equals target.",
        variations: [
            "Brute-force nested loops",
            "Sort + two-pointer technique"
        ],
        complexity: "O(n^2) or O(n log n) for sorting + O(n) scan.",
        flowchart: [
            "[Brute] For i,j with i<j, if a[i]+a[j]==target print pair.",
            "[Two-pointer] Sort, then move i,j based on sum compared to target."
        ]
    },
    {
        id: 11,
        title: "Problem 11: Balanced Parentheses",
        desc: "Check whether an expression has balanced brackets.",
        variations: [
            "Single-type parentheses () only",
            "Multiple types: (), {}, []"
        ],
        complexity: "O(n) time, O(n) stack space.",
        flowchart: [
            "[()] Push '(' on stack, pop when ')' encountered; empty stack at end means balanced.",
            "[All] Similar, but ensure opening and closing types match."
        ]
    },
    {
        id: 12,
        title: "Problem 12: Reverse a Linked List",
        desc: "Reverse a singly linked list.",
        variations: [
            "Iterative pointer reversal",
            "Recursive reversal"
        ],
        complexity: "O(n) time, O(1)/O(n) space.",
        flowchart: [
            "[Iterative] prev=NULL, curr=head → loop: next=curr->next; curr->next=prev; prev=curr; curr=next.",
            "[Recursive] Reverse rest, then fix head->next->next = head and head->next = NULL."
        ]
    },
    {
        id: 13,
        title: "Problem 13: Middle Node of Linked List",
        desc: "Find middle node of singly linked list.",
        variations: [
            "Slow/Fast pointer method",
            "Two-pass counting method"
        ],
        complexity: "O(n) time, O(1) space.",
        flowchart: [
            "[Slow/Fast] Move slow by 1, fast by 2 until fast reaches end.",
            "[Two-pass] Count nodes, then traverse to index count/2."
        ]
    },
    {
        id: 14,
        title: "Problem 14: Merge Two Sorted Linked Lists",
        desc: "Merge two sorted linked lists into one sorted sequence.",
        variations: [
            "Pointer manipulation on linked lists",
            "Read into arrays and merge"
        ],
        complexity: "O(n+m) for merge; space depends on representation.",
        flowchart: [
            "[Lists] Use dummy head and tail; at each step pick smaller of two heads.",
            "[Arrays] Similar to merge step of merge sort."
        ]
    },
    {
        id: 15,
        title: "Problem 15: Queue Using Two Stacks",
        desc: "Implement queue operations using two stacks.",
        variations: [
            "Interactive menu with fixed-size stacks",
            "Operation-based (enqueue/dequeue/display sequence)"
        ],
        complexity: "Amortized O(1) per operation using two stacks.",
        flowchart: [
            "Enqueue: push to stack1.",
            "Dequeue: if stack2 empty, move all from stack1 to stack2, then pop.",
            "Display: show stack2 (top→bottom) then stack1 (bottom→top)."
        ]
    },
    {
        id: 16,
        title: "Problem 16: Kruskal Algorithm",
        desc: "Find the Minimum Spanning Tree of a graph using Kruskal's algorithm.",
        variations: [
            "Sort edges using qsort + DSU",
            "Use Min-Heap for edges + DSU"
        ],
        complexity: "O(E log E) time, O(V+E) space.",
        flowchart: [
            "Read n, m and edges.",
            "Sort or push edges to min-heap.",
            "Initialize DSU; pick smallest edges that do not form cycle until MST has n-1 edges."
        ]
    },
    {
        id: 17,
        title: "Problem 17: Store Weighted Graph",
        desc: "Store a weighted graph using adjacency lists.",
        variations: [
            "Array of pointers with head insert",
            "Adjacency list with head & tail pointers"
        ],
        complexity: "Building: O(V+E); Space: O(V+E).",
        flowchart: [
            "Read vertices & edges.",
            "Initialize adjacency list.",
            "For each edge, create node and attach to proper list; print structure."
        ]
    },
    {
        id: 18,
        title: "Problem 18: BST Leaf Count",
        desc: "Create a BST and count its leaf nodes.",
        variations: [
            "Recursive insert + recursive leaf count",
            "Iterative insert + iterative leaf count"
        ],
        complexity: "O(n) time, O(h) or O(n) space.",
        flowchart: [
            "Insert each key into BST.",
            "Traverse tree; a node with no children is a leaf; count them."
        ]
    },
    {
        id: 19,
        title: "Problem 19: Binary Tree Traversals",
        desc: "Perform inorder and preorder traversals of a binary tree.",
        variations: [
            "Inorder traversal (recursive)",
            "Inorder traversal (iterative with stack)",
            "Preorder traversal (recursive)"
        ],
        complexity: "O(n) time; O(h) or O(n) stack space.",
        flowchart: [
            "[Inorder rec] Traverse left, visit node, traverse right.",
            "[Inorder iter] Use stack to simulate recursion.",
            "[Preorder rec] Visit node, traverse left, then right."
        ]
    },
    {
        id: 20,
        title: "Problem 20: Detect Cycle in Graph",
        desc: "Detect cycle in a graph using DFS or Union-Find.",
        variations: [
            "DFS on adjacency matrix (directed)",
            "Union-Find on edge list (undirected)"
        ],
        complexity: "DFS: O(V+E); Union-Find: O(E α(V)).",
        flowchart: [
            "[DFS] Maintain visited[] and recursion stack[]; back-edge means cycle.",
            "[Union-Find] For each edge, if endpoints already in same set, cycle exists."
        ]
    }
];

function initProblemList() {
    const list = document.getElementById("problemList");
    problems.forEach(p => {
        const li = document.createElement("li");
        const btn = document.createElement("button");
        btn.textContent = `${p.id}. ${p.title.replace("Problem " + p.id + ": ", "")}`;
        btn.addEventListener("click", () => selectProblem(p.id));
        li.appendChild(btn);
        list.appendChild(li);
    });
}

function selectProblem(id) {
    const prob = problems.find(p => p.id === id);
    if (!prob) return;

    // Highlight active button
    document.querySelectorAll("#problemList button").forEach(b => b.classList.remove("active"));
    const idx = problems.findIndex(p => p.id === id);
    const activeBtn = document.querySelectorAll("#problemList button")[idx];
    if (activeBtn) activeBtn.classList.add("active");

    document.getElementById("welcomeCard").classList.add("hidden");
    document.getElementById("problemCard").classList.remove("hidden");

    document.getElementById("problemTitle").textContent = prob.title;
    document.getElementById("problemDescription").textContent = prob.desc;

    // Variations
    const vList = document.getElementById("variationList");
    vList.innerHTML = "";
    prob.variations.forEach((v, i) => {
        const li = document.createElement("li");
        li.textContent = `${i + 1}. ${v}`;
        vList.appendChild(li);
    });

    // Complexity
    document.getElementById("complexityText").textContent = prob.complexity;

    // Flowchart
    const fc = prob.flowchart.join("\n\n");
    document.getElementById("flowchartText").textContent = fc;

    // Run steps (connect to your C menu)
    const runList = document.getElementById("runSteps");
    runList.innerHTML = "";
    const li1 = document.createElement("li");
    li1.textContent = `1. Run ./dsa_project in terminal.`;
    const li2 = document.createElement("li");
    li2.textContent = `2. In the main menu, enter ${prob.id} and press Enter.`;
    const li3 = document.createElement("li");
    li3.textContent = `3. In the problem menu, choose variation number (1..${prob.variations.length}).`;
    runList.appendChild(li1);
    runList.appendChild(li2);
    runList.appendChild(li3);
}

document.addEventListener("DOMContentLoaded", initProblemList);
