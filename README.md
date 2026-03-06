# Data Structures & Algorithms – Production & Optimization Sprint

## Overview

This repository contains solutions for **Assignment 1: Production & Optimization Sprint**.
The problems focus on applying advanced data structures and algorithms to solve real-world computational problems efficiently.

Each solution emphasizes **high performance and optimal complexity**, similar to problems used in technical assessments at major technology companies.

---

# Problem 1: Global Autocomplete System (Trie)

## Objective

Design a system that stores a large dictionary of strings and returns the **top 5 most frequent suggestions** for a given prefix.

## Approach

A **Trie (Prefix Tree)** is used because it enables fast prefix-based searching.

Each node in the trie stores:

* Child nodes for characters
* A list of the **top 5 most frequent words** passing through that node

### Steps

1. Insert each word into the trie.
2. While inserting, update the node's top suggestions based on frequency.
3. When searching for a prefix, traverse the trie using the prefix characters.
4. Return the stored top suggestions from the final node.

## Complexity

| Operation     | Complexity |
| ------------- | ---------- |
| Insertion     | O(L)       |
| Prefix Search | O(L)       |

Where **L = length of the word/prefix**.

## Data Structure Used

Trie (Prefix Tree)

---

# Problem 2: Streaming Max Analytics (Sliding Window Maximum)

## Objective

Given a stream of server latency values and a window size **K**, determine the **maximum latency for each sliding window**.

## Approach

A **Monotonic Deque** is used to maintain elements in decreasing order.

### Steps

1. Maintain a deque containing indices of useful elements.
2. Remove indices that fall outside the current window.
3. Remove smaller elements from the back of the deque.
4. The front of the deque always represents the **maximum value of the window**.

## Complexity

| Operation               | Complexity     |
| ----------------------- | -------------- |
| Processing each element | O(1) amortized |
| Total runtime           | O(N)           |

## Data Structure Used

Deque (Double-ended Queue)

---

# Problem 3: Dynamic Network Vulnerability (Tarjan's Algorithm)

## Objective

Identify **critical links (bridges)** in a network graph.

A link is considered critical if removing it increases the number of connected components in the graph.

## Approach

Tarjan’s Algorithm is used with **Depth First Search (DFS)**.

Two arrays are maintained:

* `tin[v]` → time when node is first visited
* `low[v]` → earliest visited vertex reachable from that node

### Bridge Condition

An edge `(u, v)` is a bridge if:

low[v] > tin[u]

This means node `v` cannot reach `u` or its ancestors through any other path.

## Complexity

| Operation     | Complexity |
| ------------- | ---------- |
| DFS traversal | O(V + E)   |

Where:

* **V = vertices**
* **E = edges**

## Algorithm Used

Tarjan's Bridge Finding Algorithm

---

# Problem 4: Range Performance Monitor (Segment Tree)

## Objective

Design a system to efficiently handle two operations:

* `update(index, value)` → update stock price
* `queryMax(L, R)` → find maximum price in a range

## Approach

A **Segment Tree** is used because it allows efficient range queries and updates.

The array is divided into segments where each node stores the maximum value of its segment.

### Operations

**Build**
Construct the segment tree from the input array.

**Update**
Update a leaf node and propagate changes upward.

**Query**
Combine results from overlapping segments to compute the maximum value.

## Complexity

| Operation   | Complexity |
| ----------- | ---------- |
| Update      | O(log N)   |
| Range Query | O(log N)   |

## Data Structure Used

Segment Tree

---

# Problem 5: Optimal Resource Allocation (Bitmask Dynamic Programming)

## Objective

Assign **N workers to N tasks** such that the total cost is minimized.

Constraints:

* Each worker performs exactly one task
* Each task is assigned to exactly one worker
* N < 20

## Approach

Using brute force would require evaluating **N! permutations**, which is infeasible.

Instead, **Bitmask Dynamic Programming** is used.

A bitmask represents which workers have already been assigned.

Example (N = 3):

| Mask | Meaning              |
| ---- | -------------------- |
| 000  | No workers assigned  |
| 001  | Worker 0 assigned    |
| 010  | Worker 1 assigned    |
| 111  | All workers assigned |

### Transition

For each mask:

1. Determine the task number using the number of set bits.
2. Assign an unused worker.
3. Update the cost of the new mask.

## Complexity

| Operation | Complexity  |
| --------- | ----------- |
| Time      | O(2^N × N²) |
| Space     | O(2^N)      |

## Algorithm Used

Bitmask Dynamic Programming with State Compression

---

# Repository Structure

```
dsa-assignment/
│
├── autocomplete_trie.cpp
├── sliding_window_max.cpp
├── tarjan_bridges.cpp
├── segment_tree.cpp
├── bitmask_dp_assignment.cpp
│
└── README.md
```

---

# Key Concepts Covered

* Trie Data Structure
* Sliding Window Optimization
* Monotonic Queue
* Graph Algorithms
* Tarjan's Bridge Algorithm
* Segment Trees
* Bitmask Dynamic Programming
* State Compression

---

# Conclusion

This assignment demonstrates how advanced data structures and algorithms can be used to efficiently solve complex computational problems.

The implementations emphasize **performance optimization, scalability, and algorithmic efficiency**, which are critical in real-world systems and technical interviews.
