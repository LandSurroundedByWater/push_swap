# push_swap
push_swap project I made in Hive Helsinki!




This projects aim is to sort all integers in stack (stack_a) by using only one extra stack (stack_b) and minimum amount of moves.

Moves are:

sa (swap a): Swap the first 2 elements at the top of stack a.
sb (swap b): Swap the first 2 elements at the top of stack b.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
pb (push b): Take the first element at the top of a and put it at the top of b.
ra (rotate a): Shift up all elements of stack a by 1.
rb (rotate b): Shift up all elements of stack b by 1.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
rrr : rra and rrb at the same time.

This was so fun and fascinating project. I tried to find out my own algorithm and wayt o do sorting. First I tried to analyze stack given so that I have as much information I need to start sorting. I tried to find out the longest increasing subsequence i.e. calculated from smallest node how many nodes are allready in order. That was not easy and I used algorithm which flags those nodes depended how big the stack is. Then I moved rest to stack B and startes to piut every node back one by one by calculating the "cheapest" node which I could move back.  I'm quite happy of my final result!

EDIT: Minor mistake in code, it gives an error even if there is no arguments. I should just exit program.
