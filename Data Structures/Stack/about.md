# The Stack
Last In First Out LIFO

## Uses:
* Great for parsing. Reverse Polish Notation calculators use stacks to hold the values.
* Evaluating postfix expressions
* Great for tree/graph traversal.  DFS uses a stack

## Complexity
* Access: O(n)
* Search: O(n)
* Insert: O(1)
* Delete: O(1)
* Space:  O(n)

Insert and delete assumes that only using push and pop.  Didn't support searching
