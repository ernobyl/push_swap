# About the project:
 The Push swap project is a simple sorting algorithm written in C:
 You have at your disposal a set of integer values, 2 stacks, and a limited set of instructions to manipulate both stacks.
 Your goal? Write a program that calculates and displays (on the standard output) the smallest amount of moves to sort the integers.
# Running the program:
  Once the program is compiled. Run it with any number of integer values as parameters. (eg. ./push_swap 30 1 58 -26 8 900 40)
  The program will not accept other arguments than integers. It will also not accept duplicate values.
# List of allowed instructions used:
  **sa (swap a):** Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.  
  **sb (swap b):** Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
  **ss :** sa and sb at the same time.
  **pa (push a):** Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  **pb (push b):** Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  **ra (rotate a):** Shift up all elements of stack a by 1. The first element becomes the last one.
  **rb (rotate b):** Shift up all elements of stack b by 1. The first element becomes the last one.
  **rr:** ra and rb at the same time.
  **rra (reverse rotate a):** Shift down all elements of stack a by 1. The last element becomes the first one.
  **rrb (reverse rotate b):** Shift down all elements of stack b by 1. The last element becomes the first one.
  **rrr:** rra and rrb at the same time
