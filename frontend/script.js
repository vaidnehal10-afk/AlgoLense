// ---- Problem & Variation metadata (frontend only) ----
const problems = [
    {
        id: 1,
        name: "GCD & LCM",
        desc: "Find GCD and LCM of two integers.",
        variations: [
            { menu: 1, label: "Iterative GCD & LCM", placeholder: "Example: 12 18" },
            { menu: 2, label: "Recursive GCD & LCM", placeholder: "Example: 12 18" },
            { menu: 3, label: "Binary GCD (Stein’s Algorithm)", placeholder: "Example: 12 18" }
        ]
    },
    {
        id: 2,
        name: "Prime Check",
        desc: "Check whether a number is prime.",
        variations: [
            { menu: 1, label: "Naive Prime Check", placeholder: "Example: 29" },
            { menu: 2, label: "Optimized Prime Check (√n)", placeholder: "Example: 29" }
        ]
    },
    {
        id: 3,
        name: "Factorial",
        desc: "Compute factorial of a number.",
        variations: [
            { menu: 1, label: "Iterative Factorial", placeholder: "Example: 5" },
            { menu: 2, label: "Recursive Factorial", placeholder: "Example: 5" },
            { menu: 3, label: "Big Integer Factorial", placeholder: "Example: 20" }
        ]
    },
    {
        id: 4,
        name: "Sum of Digits",
        desc: "Find the sum of digits of a number.",
        variations: [
            { menu: 1, label: "Iterative Sum of Digits", placeholder: "Example: 12345" },
            { menu: 2, label: "Recursive Sum of Digits", placeholder: "Example: 12345" }
        ]
    },
    {
        id: 5,
        name: "Armstrong Number",
        desc: "Check if a number is an Armstrong number.",
        variations: [
            { menu: 1, label: "Classic 3-digit Armstrong", placeholder: "Example: 153" },
            { menu: 2, label: "General n-digit Armstrong", placeholder: "Example: 9474" }
        ]
    },
    {
        id: 6,
        name: "Anagram Check",
        desc: "Check if two strings are anagrams.",
        variations: [
            { menu: 1, label: "Frequency Array Method", placeholder: "Example:\nlisten\nsilent" },
            { menu: 2, label: "Sorting-based Check", placeholder: "Example:\nlisten\nsilent" }
        ]
    },
    {
        id: 7,
        name: "First Non-Repeating Character",
        desc: "Find the first non-repeating character in a string.",
        variations: [
            { menu: 1, label: "Frequency Array Scan", placeholder: "Example: swiss" },
            { menu: 2, label: "Index Map Method", placeholder: "Example: swiss" }
        ]
    },
    {
        id: 8,
        name: "Remove Duplicates from Array",
        desc: "Remove duplicate elements from an array.",
        variations: [
            { menu: 1, label: "O(n²) Preserve Order", placeholder: "Example: 1 2 2 3 1 4" },
            { menu: 2, label: "Sort + Unique", placeholder: "Example: 1 2 2 3 1 4" }
        ]
    },
    {
        id: 9,
        name: "Second Largest in Array",
        desc: "Find the second largest element in an array.",
        variations: [
            { menu: 1, label: "Single Pass", placeholder: "Example: 1 2 9 4 9 3" },
            { menu: 2, label: "Sorting Based", placeholder: "Example: 1 2 9 4 9 3" }
        ]
    },
    {
        id: 10,
        name: "Pairs with Given Sum",
        desc: "Find all pairs in an array whose sum equals a target value.",
        variations: [
            { menu: 1, label: "Brute Force O(n²)", placeholder: "Array: 1 5 7 -1 5\nTarget: 6" },
            { menu: 2, label: "Sorting + Two Pointer", placeholder: "Array: 1 5 7 -1 5\nTarget: 6" }
        ]
    },
    {
        id: 11,
        name: "Balanced Parentheses",
        desc: "Check if an expression has balanced parentheses.",
        variations: [
            { menu: 1, label: "Simple ( ) Stack", placeholder: "Example: (()())" },
            { menu: 2, label: "Multi-type (), {}, []", placeholder: "Example: ({[]})" }
        ]
    },
    {
        id: 12,
        name: "Reverse Linked List",
        desc: "Reverse a singly linked list.",
        variations: [
            { menu: 1, label: "Iterative Reverse", placeholder: "List nodes: 1 2 3 4" },
            { menu: 2, label: "Recursive Reverse", placeholder: "List nodes: 1 2 3 4" }
        ]
    },
    {
        id: 13,
        name: "Middle Node of Linked List",
        desc: "Find the middle node of a linked list.",
        variations: [
            { menu: 1, label: "Slow–Fast Pointer", placeholder: "List nodes: 1 2 3 4 5" },
            { menu: 2, label: "Count & Index", placeholder: "List nodes: 1 2 3 4 5" }
        ]
    },
    {
        id: 14,
        name: "Merge Two Sorted Linked Lists",
        desc: "Merge two sorted linked lists.",
        variations: [
            { menu: 1, label: "Pointer Merge on Lists", placeholder: "List1: 1 3 5\nList2: 2 4 6" },
            { menu: 2, label: "Array-based Merge", placeholder: "List1: 1 3 5\nList2: 2 4 6" }
        ]
    },
    {
        id: 15,
        name: "Queue Using Two Stacks",
        desc: "Implement a queue using two stacks.",
        variations: [
            { menu: 1, label: "Menu-driven Queue", placeholder: "Will prompt operations internally" },
            { menu: 2, label: "Operation Sequence", placeholder: "Will prompt operations internally" }
        ]
    },
    {
        id: 16,
        name: "Kruskal Algorithm (MST)",
        desc: "Find MST using Kruskal's algorithm.",
        variations: [
            { menu: 1, label: "qsort + Union-Find", placeholder: "Follow graph input." },
            { menu: 2, label: "Min-Heap + Union-Find", placeholder: "Follow graph input." }
        ]
    },
    {
        id: 17,
        name: "Store Weighted Graph",
        desc: "Store weighted graph using adjacency structures.",
        variations: [
            { menu: 1, label: "Basic Adjacency List", placeholder: "Follow graph input." },
            { menu: 2, label: "Tail-pointer Adjacency List", placeholder: "Follow graph input." }
        ]
    },
    {
        id: 18,
        name: "BST Leaf Count",
        desc: "Create a BST and count the leaf nodes.",
        variations: [
            { menu: 1, label: "Recursive Insert + Count", placeholder: "Tree nodes: 8 3 10 1 6 14 4 7 13" },
            { menu: 2, label: "Iterative Insert + Count", placeholder: "Tree nodes: 8 3 10 1 6 14 4 7 13" }
        ]
    },
    {
        id: 19,
        name: "Binary Tree Traversals",
        desc: "Perform different tree traversal algorithms.",
        variations: [
            { menu: 1, label: "Inorder Traversal", placeholder: "Tree input required" },
            { menu: 2, label: "Iterative Inorder", placeholder: "Tree input required" },
            { menu: 3, label: "Preorder Traversal", placeholder: "Tree input required" }
        ]
    },
    {
        id: 20,
        name: "Detect Cycle in Graph",
        desc: "Detect cycles in a graph using DFS / Union-Find.",
        variations: [
            { menu: 1, label: "DFS Cycle Detection", placeholder: "Graph input required" },
            { menu: 2, label: "Union-Find Cycle Detection", placeholder: "Graph input required" }
        ]
    }
];

let currentProblem = null;
let currentVariation = null;

// ---- INITIALIZE SIDEBAR ----
window.addEventListener("DOMContentLoaded", () => {
    const list = document.getElementById("problemList");
    problems.forEach(p => {
        const li = document.createElement("li");
        li.textContent = `${p.id}. ${p.name}`;
        li.addEventListener("click", () => selectProblem(p));
        list.appendChild(li);
    });
});

// ---- SELECT PROBLEM ----
function selectProblem(p) {
    currentProblem = p;
    currentVariation = null;

    document.getElementById("welcomeBox").classList.add("hidden");
    document.getElementById("problemBox").classList.remove("hidden");

    document.getElementById("problemTitle").textContent = `${p.id}. ${p.name}`;
    document.getElementById("problemDesc").textContent = p.desc;

    document.getElementById("variationSection").classList.add("hidden");
    document.getElementById("inputSection").classList.add("hidden");
    document.getElementById("outputBox").textContent = "";
}

// ---- OPEN VARIATIONS ----
function openVariations() {
    if (!currentProblem) return alert("Select a problem first!");

    const vSection = document.getElementById("variationSection");
    const vList = document.getElementById("variationList");
    const inputSection = document.getElementById("inputSection");

    vSection.classList.remove("hidden");
    inputSection.classList.add("hidden");
    vList.innerHTML = "";

    currentProblem.variations.forEach(v => {
        const btn = document.createElement("button");
        btn.className = "variation-btn";
        btn.textContent = v.label;
        btn.addEventListener("click", () => selectVariation(v, btn));
        vList.appendChild(btn);
    });
}

// ---- SELECT VARIATION ----
function selectVariation(v, btn) {
    currentVariation = v;

    document.querySelectorAll(".variation-btn").forEach(b => b.classList.remove("active"));
    btn.classList.add("active");

    const inputSection = document.getElementById("inputSection");

    document.getElementById("variationTitle").textContent = v.label;
    document.getElementById("variationInput").value = "";
    document.getElementById("variationInput").placeholder = v.placeholder;

    inputSection.classList.remove("hidden");
}

// ---- BACKEND CALL ----
function callBackend(input, cleanerFn, targetElementId) {
    const out = document.getElementById(targetElementId);
    out.textContent = "Running AlgoLense.exe...\n\n" + input;

    fetch("http://localhost:5000/run", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ input })
    })
    .then(res => res.json())
    .then(data => {
        let raw = data.output || "";
        if (cleanerFn) raw = cleanerFn(raw);
        out.textContent = raw;
    })
    .catch(err => {
        out.textContent = "ERROR: " + err;
    });
}

// ---- CLEAN ALGORITHM OUTPUT ----
function cleanAlgorithmOutput(raw) {
    // Start from OUTPUT marker
    let idx = raw.indexOf("--- OUTPUT ---");

    if (idx >= 0) {
        let sliced = raw.slice(idx + 13);

        // Remove ALL menus
        sliced = sliced.replace(/--- Variations ---[\s\S]*/g, "");
        sliced = sliced.replace(/--- Problem[\s\S]*/g, "");
        sliced = sliced.replace(/==============================[\s\S]*/g, "");
        sliced = sliced.replace(/Enter choice:[\s\S]*/g, "");
        sliced = sliced.replace(/0\. Back[\s\S]*/g, "");

        return sliced.trim();
    }

    return raw.replace(/--- Problem[\s\S]*/g, "").trim();
}

// ---- RUN VARIATION ----
function runSelectedVariation() {
    if (!currentProblem || !currentVariation) {
        return alert("Please select a problem and variation first!");
    }

    const userData = document.getElementById("variationInput").value.trim();
    if (!userData) return alert("Please enter input!");

    let stdin =
        currentProblem.id + "\n" +
        "1\n" +              // Variations
        currentVariation.menu + "\n" +
        userData + "\n" +
        "0\n" +              // back
        "0\n";               // exit

    callBackend(stdin, cleanAlgorithmOutput, "outputBox");
}

// ---- FLOWCHART CLEAN ----
const cleanerFlowchart = raw => {
    let idx = raw.indexOf("--- FLOWCHART");

    if (idx >= 0) {
        let sliced = raw.slice(idx);

        sliced = sliced.replace(/--- Problem[\s\S]*/g, "");
        sliced = sliced.replace(/==============================[\s\S]*/g, "");
        sliced = sliced.replace(/Enter choice:[\s\S]*/g, "");

        return sliced.trim();
    }
    return raw.trim();
};

// ---- SHOW FLOWCHART ----
function showFlowchart() {
    if (!currentProblem) return alert("Select a problem first!");

    const stdin = `${currentProblem.id}\n2\n0\n0\n`;

    document.getElementById("flowchartContent").textContent = "Loading...";
    document.getElementById("flowchartModal").classList.remove("hidden");

    callBackend(stdin, cleanerFlowchart, "flowchartContent");
}

function closeFlowchartModal() {
    document.getElementById("flowchartModal").classList.add("hidden");
}

// ---- COMPLEXITY CLEAN ----
const cleanerComplexity = raw => {
    let idx = raw.indexOf("--- Time and Space Complexity ---");

    if (idx >= 0) {
        let sliced = raw.slice(idx);

        sliced = sliced.replace(/--- Problem[\s\S]*/g, "");
        sliced = sliced.replace(/==============================[\s\S]*/g, "");
        sliced = sliced.replace(/Enter choice:[\s\S]*/g, "");

        return sliced.trim();
    }
    return raw.trim();
};

// ---- SHOW COMPLEXITY ----
function showComplexity() {
    if (!currentProblem) return alert("Select a problem first!");

    const stdin = `${currentProblem.id}\n3\n0\n0\n`;

    document.getElementById("complexityContent").textContent = "Loading...";
    document.getElementById("complexityModal").classList.remove("hidden");

    callBackend(stdin, cleanerComplexity, "complexityContent");
}

function closeComplexityModal() {
    document.getElementById("complexityModal").classList.add("hidden");
}
