# Push Swap
The push_swap project is a sorting algorithm challenge where you must sort a stack of integers using two stacks (`a` and `b`) with a limited set of operations. The goal is to create the most efficient sorting algorithm with the smallest number of instructions.

---

## 🚀 Features

### The Rules
1. You have two stacks: `a` and `b`.
    - Stack `a`: Contains a random list of integers (positive and/or negative) at the start, with no duplicates.
    - Stack `b`: Starts empty.

2. The goal is to sort stack `a` in ascending order, using the following operations:

### Operations
- **Swap Operations:**

    - `sa`: Swap the first two elements of stack a.
    - `sb`: Swap the first two elements of stack b.
    - `ss`: Perform sa and sb simultaneously.

- **Push Operations:**

    - `pa`: Push the first element from stack b to stack a.
    - `pb`: Push the first element from stack a to stack b.

- **Rotate Operations:**

    - `ra`: Rotate stack a (shift all elements up by 1; first element becomes last).
    - `rb`: Rotate stack b (shift all elements up by 1; first element becomes last).
    - `rr`: Perform ra and rb simultaneously.

- **Reverse Rotate Operations:**

    - `rra`: Reverse rotate stack a (shift all elements down by 1; last element becomes first).
    - `rrb`: Reverse rotate stack b (shift all elements down by 1; last element becomes first).
    - `rrr`: Perform rra and rrb simultaneously.

---

## 🧠 Algorithm Overview
My `push_swap` program implements multiple sorting strategies to efficiently handle stacks of varying sizes. Each strategy is tailored to the size of the input, ensuring an optimal balance between simplicity and performance.

### **Sorting Strategies**
#### 1. Sort 3 (3 Elements)
   
- For stacks with exactly 3 elements:
  
    - The program uses a minimal number of operations (`sa`, `ra`, or `rra`) to sort the stack.
    - It checks for specific patterns and applies the necessary swaps and rotations to achieve the correct order.
      
#### 2. Sort Small (5 Elements)

- For stacks with 5 or fewer elements:
  
    - The program pushes the largest and smallest elements to stack `b`.
    - The remaining three elements in stack `a` are sorted using the `sort 3` method.
    - The two elements are then pushed back from stack `b` to their correct positions in stack `a` and rotated.
      
#### 3. Sort Big (More than 5 Elements)

- For stacks larger than 5 elements, the program implements a two-step algorithm to efficiently sort the stacks (See below)

---

##  🗂️ Sort Big Algorithm
### **Step 1: Sorting by Mean Value**

#### Initial Split:

- The mean (average) value of all numbers in stack `a` is calculated.
- Numbers less than the mean value are pushed to stack `b`.
- This step reduces the size of stack `a` and ensures smaller values are handled separately, simplifying the sorting process.

  
### **Step 2: Sorting Stack b and Merging Back**

#### Targeting the Closest Larger Value:

- For each number in stack `b`, the program identifies the closest larger number in stack `a` as its target.
- The stacks are rotated or reverse-rotated to align the elements for efficient merging.
- The number from stack `b` is pushed back to stack `a` in its correct position.


### Optimization Techniques
- **Dual Rotations**: Simultaneous rotations (`rr` or `rrr`) are used when possible to minimize the total number of operations.
- **Cheapest Moves**: The program calculates the cost of each move (number of operations required) and always selects the move with the lowest cost.
  
By combining these strategies, my program ensures an efficient and systematic sorting process, regardless of stack size. Smaller stacks are handled with specialized methods (`sort 3` and `sort small`), while larger stacks leverage the `sort big` algorithm for optimal performance.

---

## 🛠️ How to Build
1. Clone the repository:
```bash
git clone https://github.com/adzhl/push_swap.git
```
2. Navigate to the project directory:
```bash
cd push_swap
```
3. Build the program:
```bash
make
```

---

## 📋 Usage
### Running Push Swap
To sort a list of integers:

```bash
./push_swap <list_of_integers>
```

### Example
```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

### Error Handling
The program outputs `Error` in the following cases:

- Non-integer arguments.
- Arguments out of the integer range.
- Duplicate integers.
- No arguments provided.

Example:

```bash
$ ./push_swap 0 one 2 3
Error
```

---

## 🧩 Bonus: Checker Program
The bonus part of the project includes a checker program to verify the sorting instructions produced by my `push_swap` program.

### Running Checker
```bash
./checker <list_of_integers>
```

1. Enter sorting instructions (e.g., `sa`, `pb`, etc.) via standard input.
2. The program will execute the instructions and check the result.
   
### Outputs
- `OK`: If stack a is sorted in ascending order and stack b is empty.
- `KO`: If the result is incorrect.
- `Error`: For invalid inputs or instructions.

### Example
```bash
$ ./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

---

## ⚙️ Makefile Targets
- `make` or `make all`: Build the project.
- `make bonus`: Build the bonus (checker) program.
- `make clean`: Remove object files.
- `make fclean`: Remove object files and the executables.
- `make re`: Rebuild the entire project.
