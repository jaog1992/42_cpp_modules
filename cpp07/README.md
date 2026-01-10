*This project has been created as part of the 42 curriculum by jde-orma.*

# C++ Module 07 — Templates

## Description
This repository contains the solutions for Module 07 exercises (C++98-compatible) focused on C++ templates. The exercises implemented in this folder are:

- `ex00` — Function templates
  - Implement `swap`, `min`, and `max` as function templates working with arbitrary types.
- `ex01` — `iter`
  - Implement a generic `iter` that applies a callable to each element of an array.
- `ex02` — `Array`
  - Implement a templated dynamic array class with bounds-checked access and proper canonical form.

All exercises follow the project rules from the subject: compile with `-Wall -Wextra -Werror -std=c++98`, avoid forbidden functions, and keep implementations self-contained per exercise.

## Instructions

Each exercise has an independent `Makefile` with the usual `all`, `clean`, `fclean`, and `re` targets. To build and run an exercise:

1. Open a terminal in the exercise folder, for example `cpp07/ex00`.
2. Run:

```sh
make
```

3. Run the produced binary. Example for `ex00`:

```sh
./functions
```

Notes:
- The code is written to be compatible with the C++98 standard as required by the 42 curriculum; do not use C++11+ features.
- Templates must be defined in header files (this is expected for these exercises).

## Exercises

- ex00: `Functions.hpp` — `swap`, `min`, `max` templates.
- ex01: `Iter.hpp` — `iter` template and tests in `main.cpp`.
- ex02: `Array.hpp`, `Array.tpp` — templated `Array` implementation and tests in `main.cpp`.

## Resources
- C++ template reference: https://en.cppreference.com/w/cpp/language/templates
- Exceptions and `std::out_of_range`: https://en.cppreference.com/w/cpp/error/exception

## How AI was used
- AI assistance was used to harmonize documentation and Makefile styles across the repository and to add Doxygen-style comments. All functional logic remains authored and verified manually.