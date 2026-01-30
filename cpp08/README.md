*This project has been created as part of the 42 curriculum.*

# C++ Module 08 — Containers and Iterators

## Description
This folder contains solutions for Module 08 exercises focused on container-like classes, iterator behaviour, and generic algorithms. The exercises implemented here are:

- `ex00` — `easyfind`
  - Implement a function template `easyfind` that searches for an integer value in standard containers and returns an iterator or throws if not found.
- `ex01` — `Span`
  - Implement a `Span` class that stores integers and provides `addNumber`, `shortestSpan` and `longestSpan` with exception handling and efficient behavior.
- `ex02` — `MutantStack`
  - Implement a `MutantStack` template that inherits `std::stack` and exposes iterator access to allow range-based algorithms.

All exercises follow the project rules from the subject: compile with `-Wall -Wextra -Werror -std=c++98`, avoid forbidden functions, and keep implementations self-contained per exercise.

## Instructions

Each exercise has an independent `Makefile` with the usual `all`, `clean`, `fclean`, and `re` targets. To build and run an exercise:

1. Open a terminal in the exercise folder, for example `cpp08/ex00`.
2. Run:

```sh
make
```

3. Run the produced binary. Example for `ex00`:

```sh
./easyfind
```

Notes:
- The code is written to be compatible with the C++98 standard as required by the 42 curriculum; do not use C++11+ features.
- Templates must be defined in header files (this is expected for these exercises).

## Exercises

- ex00: `Easyfind.hpp` — function template to search containers.
- ex01: `Span.hpp`, `Span.cpp` — `Span` class implementation.
- ex02: `MutantStack.hpp`, `MutantStack.tpp` — templated `MutantStack` implementation exposing iterators.

## Resources
- C++ containers and iterators reference: https://en.cppreference.com/w/cpp/container
- C++ template reference: https://en.cppreference.com/w/cpp/language/templates

## How AI was used
- AI assistance was used to harmonize documentation and Makefile styles. All functional logic remains authored and verified manually.
