<h1 align="center">push_swap</h1>

<p align="center">
<img src="https://i.imgur.com/XUaDkkE.png" alt="drawing" width="120"/>
</p>

>[Check out my article on medium to understand how the algorith works](https://medium.com/@lucafischer_11396/two-stacks-one-goal-understanding-the-push-swap-algorithm-e08e5986f657)

[![lde-ross's 42 push_swap Score](https://badge42.vercel.app/api/v2/clcrkbbp700300fkxp8nykj3n/project/2929110)](https://github.com/JaeSeoKim/badge42)

This project is a sorting algorithm project from the 42 School curriculum. The goal is to sort an array of integers using only very limited operations. 

- [How it works](#how-it-works)
- [Available Commands](#available-commands)
- [Usage](#usage)
- [Visualizer](#visualizer)
- [My Stats](#my-stats)

## How it works


The program takes an array of integers as an argument and sorts it using the push swap algorithm. The algorithm is composed of two stacks, named `a` and `b`. `a` initially contains a random number of positive or negative integers without any duplicates, and `b` is empty. The goal is to sort the numbers in `a` in ascending order.

### Available Commands

The program is limited to these commands to sort the numbers:

| Command | Description |
| --- | --- |
| `pa` | push the first element of stack b to the top of stack a. |
| `pb` | push the first element of stack a to the top of stack b. |
| `sa` | swap the first two elements of the stack a. |
| `sb` | swap the first two elements of the stack b. |
| `ss` | swap a and b |
| `ra` | rotate the stack a, move the first element to the bottom. |
| `rb` | rotate the stack b, move the first element to the bottom. |
| `rr` | rotate both stacks |
| `rra` | reverse rotate the stack a, move the last element to the top. |
| `rrb` | reverse rotate the stack b, move the last element to the top. |
| `rrr` | reverse rotate both stacks |

## Usage

First clone this repository:

```
git clone git@github.com:lucafisc/push_swap.git
```

Enter the directory:

```
cd push_swap
```

To start the sorting program, frist compile the files with the command `make`. Then, run the program with the command `./push_swap int1 int2 int3 ...`. The program will output the sequence of commands needed to sort the array.

## Visualizer

You can see an animation of how the algorithm works using the visualizer found in this repo: https://github.com/o-reo/push_swap_visualizer

| ![Visualizer](https://i.imgur.com/Aus5PDh.gif) | 
|:--:| 
| *The animation shows the Push Swap algorithm in action, sorting 100 numbers in ascending order.* |

## My Stats

| Stack size | Average no. of commands |
| --- | --- |
| 5 | 7 |
| 100 | 605 |
| 500 | 5219 |

I got the highscore in the stats (means my algorithm used very few commands) and tested with this repo: https://github.com/louisabricot/push_swap_tester

