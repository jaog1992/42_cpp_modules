````markdown
*This project has been created as part of the 42 curriculum by jde-orma.*

# C++ Module 09 — Performance & Containers

## Description
This folder contains the solutions for Module 09 exercises (C++98-compatible) focused on container usage and small-performance utilities. The exercises implemented in this folder are:

- `ex00` — `BitcoinExchange`
  - Read a small CSV database of historical Bitcoin rates and evaluate input transactions of the form `YYYY-MM-DD | value` using the nearest available rate (not after the date).
- `ex01` — `RPN`
  - Evaluate Reverse Polish Notation expressions supplied as a single argument (space-separated tokens). Supports single-digit operands and `+ - * /` operators.
- `ex02` — `PmergeMe`
  - Demonstrates a Ford–Johnson (merge-insertion) style sorting wrapper for `std::vector` and `std::list`, measuring elapsed time for each container.

All exercises follow the project rules from the subject: compile with `-Wall -Wextra -Werror -std=c++98`, avoid forbidden functions, and keep implementations self-contained per exercise.

## Instructions

Each exercise has an independent `Makefile` with the usual `all`, `clean`, `fclean`, and `re` targets. To build and run an exercise:

1. Open a terminal in the exercise folder, for example `cpp09/ex00`.
2. Run:

```sh
make
```

3. Run the produced binary. Examples:

```sh
# ex00: BitcoinExchange
./btc input.csv

# ex01: RPN
./rpn "5 1 2 + 4 * + 3 -"

# ex02: PmergeMe
./pmergeme 3 5 1 9 2
```

Notes:
- The code is written to be compatible with the C++98 standard as required by the 42 curriculum; do not use C++11+ features.
- Helper headers (e.g. `incs/Colors.hpp`) provide simple colored output for diagnostics; their usage is non-essential to algorithm correctness.

## Exercises

- **ex00**: `BitcoinExchange` — parse `data.csv` and process `input.csv`-style files. The program uses a `std::map<std::string,float>` keyed by date and finds the nearest earlier rate when an exact date is not present.

- **ex01**: `RPN` — small RPN evaluator; accepts a single command-line argument containing the expression tokens separated by spaces. Errors are reported via `std::runtime_error` and printed to `stderr`.

- **ex02**: `PmergeMe` — demonstrates sorting with `std::vector` and `std::list` using a Ford–Johnson approach; timings for each container are printed in microseconds with five decimal places.

## Resources
- `std::map`, `std::vector`, `std::list`: https://en.cppreference.com/
- C++98 compatibility notes: prefer header-only template implementations and avoid C++11 features.

## How AI was used
- AI assistance was used to harmonize documentation and add Doxygen-style comments, and to add minor recipient-facing improvements (colored diagnostic output and formatting). All functional algorithm logic remains authored and verified manually.
````