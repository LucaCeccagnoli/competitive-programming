# Problem
Given n tasks with start/end times <s,e> and k workers, what is the max number of tasks that can be executed  by the workers?

# Solution
Value function is to choose the task that ends the earliest.
Deque W (max size k) with the e of the task a worker is currently working on.

The top element in the queue will always be the earliest task to end, so there is no need to keep track of which worker gets free.

1. sort tasks according to e -> O(nlogn)
2. for task in tasks:
    1. if elements in the queue < k:
        1.  add task to queue, executed tasks +1
    2. else if task.s < W.top:
        1. W.pop()
        2. W.push_back(task.e)

## time complexity
1. ordering the tasks takes O(nlogn)
2. Iterating through the tasks takes O(n)
3. Calculating queue size requires O(1)
4. For each task, queue operations require O(1)

total = 