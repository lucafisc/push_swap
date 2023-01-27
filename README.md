<h1 align="center">push_swap</h1>

<p align="center">
<img src="https://i.imgur.com/XUaDkkE.png" alt="drawing" width="120"/>
</p>
This project is a sorting algorithm project from the 42 School curriculum. The goal is to sort an array of integers using only very limited operations.


- [How it works](#how-it-works)
- [Available Commands](#available-commands)
- [Usage](#usage)
- [My Stats](#my-stats)
- [Visualizer](#visualizer)

## How it works

The program takes an array of integers as an argument and sorts it using the push swap algorithm. The algorithm is composed of two stacks, named `a` and `b`. `a` initially contains a random number of positive or negative integers without any duplicates, and `b` is empty. The goal is to sort the numbers in `a` in ascending order.

### Available Commands

The program is limited to these commands to sort the numbers:

| Command | Description |
| --- | --- |
| `sa` | swap the first two elements of the stack a. |
| `ra` | rotate the stack a, move the first element to the bottom. |
| `rra` | reverse rotate the stack a, move the last element to the top. |
| `pa` | push the first element of stack b to the top of stack a. |
| `sb` | swap the first two elements of the stack b. |
| `rb` | rotate the stack b, move the first element to the bottom. |
| `rrb` | reverse rotate the stack b, move the last element to the top. |
| `pb` | push the first element of stack a to the top of stack b. |
| `ss` | swap a and b |
| `rr` | rotate both stacks |
| `rrr` | reverse rotate both stacks |

## Usage

To use the sorting program, compile the files with the command `make`. Then, run the program with the command `./push_swap [int1 int2 int3 ...]`. The program will output the sequence of commands needed to sort the array.

## My Stats

| Numbers | Operations |
| --- | --- |
| 8 | X |
| 100 | Y |
| 500 | Z |

I got the highscore in the stats (means my algorithm used very few commands) and tested with this repo: https://github.com/louisabricot/push_swap_tester

## Visualizer

You can see an animation of how the algorithm works using the visualizer found in this repo: https://github.com/o-reo/push_swap_visualizer
