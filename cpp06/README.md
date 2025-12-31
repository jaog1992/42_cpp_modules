*This project has been created as part of the 42 curriculum by jde-orma.*

# C++ Module 06 — Advanced Concepts

## Description
This repository contains the solutions for Module 06 exercises (C++98-compatible) focused on lower-level object manipulation and type conversion. The exercises implemented in this folder are:

- `ex00` — Scalar Conversion
  - Implement a utility to parse a single literal (char, int, float, double, or pseudo-literals like `nan`/`inf`) and display its conversion to all scalar types following the exercise output format.
- `ex01` — Serializer
  - Implement a simple serializer that converts between pointer and integer representations for a sample structure (`Data`) using reinterpret cast semantics.
- `ex02` — RTTI and polymorphism
  - Implement base/derived classes (`Base`, `A`, `B`, `C`) and utilities to identify the dynamic type of an object at runtime.

All exercises follow the project rules from the subject: compile with `-Wall -Wextra -Werror -std=c++98`, avoid forbidden functions, and keep implementations self-contained per exercise.

## Instructions

Each exercise has an independent `Makefile` with the usual `all`, `clean`, `fclean`, and `re` targets. To build and run an exercise:

1. Open a terminal in the exercise folder, for example `cpp06/ex00`.
2. Run:

```sh
make
```

3. Run the produced binary (most Makefiles produce a binary named after the exercise or `scalar_conversion` etc.). Example for `ex00`:

```sh
./scalar_conversion "42"
```

Notes:
- The code is written to be compatible with the C++98 standard as required by the 42 curriculum; do not use C++11+ features (for example, `nullptr` is forbidden).
- If you want to run all exercises, change into each `exNN` folder and run `make`.

## Files and structure
- `ex00/` — `ScalarConversion.cpp`, `ScalarConversion.hpp`, `main.cpp`, `Makefile`.
- `ex01/` — `Serializer.cpp`, `Serializer.hpp`, `Data.h`, `main.cpp`, `Makefile`.
- `ex02/` — `Base.cpp`, `Base.hpp`, `A.hpp`, `B.hpp`, `C.hpp`, `utils.cpp`, `utils.hpp`, `main.cpp`, `Makefile`.
- `incs/` — shared headers (colors, helpers) used by `main.cpp` for nicer test output.

## Resources
- C++ reference for character classification and conversion: https://en.cppreference.com/
- `strtol`, `strtof`, `strtod` parsing semantics: https://en.cppreference.com/w/cpp/utility/program/strtol
- `std::isprint`, `std::isdigit`: https://en.cppreference.com/w/cpp/header/cctype
- Reinterpret cast and pointer/integer conversions: https://en.cppreference.com/w/cpp/language/reinterpret_cast

## How AI was used
- AI assistance (OpenAI) was used to help add Doxygen-style comments across `ex00/ScalarConversion.cpp` to improve documentation and readability. All functional code changes were written and reviewed manually.

## License & Notes
This repository contains educational code produced for the 42 curriculum exercises. Use it for study and reference. If you want, I can:
- Run `make` in any exercise folder and verify the binary runs.
- Update Doxygen comments or generate documentation.

---

If you want any modifications (more examples, automated test commands, or CI config), tell me which exercise to prioritize.