*This project has been created as part of the 42 curriculum by <theoppon>.*

# push_swap

## Description

The **push_swap** project consists of implementing a sorting algorithm that operates on a stack of integers using a restricted set of operations. The goal is to sort the input stack with the minimum number of operations while using two stacks (a and b) and only the allowed push, swap, rotate, and reverse rotate commands.

The project emphasizes:

* Linked list manipulation
* Algorithm optimization
* Cost calculation for moves
* Memory management and defensive programming
* Handling of edge cases such as duplicates, already sorted input, and extreme integer values

This project helps students gain a deep understanding of:

* Stack data structures
* Algorithmic efficiency and optimization
* Low-level C programming with dynamic memory
* Handling edge cases in input parsing and sorting

---

## Instructions

### Compilation

Compile the project with:

```bash
make
```

Execution

Run the program by passing integers as arguments:

```bash
./push_swap 3 2 1 6 5
```

This will print the sequence of operations needed to sort the stack.

Stress test loop:

```bash
for i in $(seq 1 20); do
    arg=$(python3 -c "import random; nums=random.sample(range(10000),500); print(' '.join(map(str,nums)))")
    result=$(./push_swap $arg | ./checker_linux $arg)
    count=$(./push_swap $arg | wc -l)
    echo "$result - $count ops"
done
```

Edge Case Testing

Handles:

- Already sorted input
- Input with negative numbers
- `INT_MAX` and `INT_MIN` values
- Duplicate values → prints `"Error\n"`
- Empty strings or invalid arguments → prints `"Error\n"`
- Small and large stacks

---

## Algorithm Overview

1. Initial Parsing
   - Convert arguments into a doubly-linked list
   - Validate integers and check for duplicates
   - Print "Error\n" on invalid input

2. Small Stack Sorting (≤5 elements)
   - Optimized moves using `sa`, `ra`, `rra`, `pb`, `pa`
   - Minimal number of moves

3. Large Stack Sorting
   - Compute `cost_a` and `cost_b` for moving elements
   - Execute optimal moves with `execute_move`
   - Move back elements from b to a using `move_b_to_a`
   - Finish with `final_rotation`

4. Operations
   - Swap (sa, sb, ss)
   - Push (pa, pb)
   - Rotate (ra, rb, rr)
   - Reverse rotate (rra, rrb, rrr)

5. Memory Management
   - All allocations checked
   - `ft_lstclear` used to free lists
   - No memory leaks

---

## Resources

Classic references:

* Linked list tutorials in C in Youtube
* https://m4nnb3ll.medium.com/my-journey-to-find-a-good-sorting-algorithm-for-the-push-swap-42-project-4a18bc38b474
*  (https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
* `push_swap visualizer` :(https://github.com/o-reo/push_swap_visualizer)

### Use of AI

AI tools were used **as a learning and review aid only**, specifically for:

* Clarify edge cases and memory managment pitfalls
* Review logic and defensive programming practices
* Validate understanding of the subject requirements
* Debug complex issues through guided reasoning

All code was written, tested, and debugged by the author. **No AI-generated code was copied directly into the project.** The learning process emphasized understanding over shortcuts, with AI serving as a mentor rather than a solution provider.

---

## Notes

* Only integers allowed; non-integer input prints "Error\n"
* Program respects 42 coding standards (no global variables)
* Adapts automatically to stack size
* Designed to pass 42 evaluation benchmarks, including edge cases and stress tests
