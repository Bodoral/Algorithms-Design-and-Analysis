## Task

Implement the clustering algorithm for computing a max-spacing k-clustering.and find what is the largest value of k such that there is a k-clustering with spacing at least 3

## Data

This file describes a distance function (equivalently, a complete graph with edge costs). It has the following format:


[# of nodes] [# of bits for each node's label]

[first bit of node 1] ... [last bit of node 1]

[first bit of node 2] ... [last bit of node 2]

...

For example, the third line of the file "0 1 1 0 0 1 1 0 0 1 0 1 1 1 1 1 1 0 1 0 1 1 0 1" denotes the 24 bits associated with node #2.The distance between two nodes u and v in this problem is defined as the "Hamming distance"