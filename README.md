<div align="center">

# 🖥️ C++ Modules — 42 School

**A complete journey through Object-Oriented Programming in C++98**

![C++](https://img.shields.io/badge/C++-98-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![42](https://img.shields.io/badge/42-School-000000?style=for-the-badge)
![Valgrind](https://img.shields.io/badge/Valgrind-no%20leaks-brightgreen?style=for-the-badge)

</div>

---

## 📖 About

This repository contains my solutions to all **10 C++ modules** (CPP00–CPP09) from the 42 School curriculum. The modules form a progressive introduction to **Object-Oriented Programming** using the **C++98 standard**, covering everything from basic classes to advanced STL algorithms.

Every solution is written with a focus on:
- ✅ **Correctness** — all edge cases handled, no undefined behavior
- ✅ **Robustness** — all errors caught and reported gracefully
- ✅ **Memory safety** — zero leaks verified with `valgrind`
- ✅ **Code quality** — compiles clean under `-Wall -Wextra -Werror`

---

## 🛠️ Build

Each module/exercise has its own `Makefile`. From any exercise directory:

```bash
make        # Build the binary
make clean  # Remove object files
make fclean # Remove object files and binary
make re     # Full rebuild
```

**Compiler flags used across all modules:**
```
c++ -Wall -Wextra -Werror -std=c++98
```

---

## 📚 Module Overview

| Module | Topic | Key Concepts |
|--------|-------|-------------|
| [CPP00](#cpp00--namespaces-classes--streams) | Namespaces, Classes & Streams | Classes, member functions, `iostream`, `static`, `const` |
| [CPP01](#cpp01--memory--references) | Memory & References | Heap vs stack, `new`/`delete`, references, pointers to members |
| [CPP02](#cpp02--ad-hoc-polymorphism--fixed-point) | Ad-hoc Polymorphism & Fixed-Point | Orthodox Canonical Form, operator overloading, fixed-point arithmetic |
| [CPP03](#cpp03--inheritance) | Inheritance | Base/derived classes, constructor chaining, diamond problem |
| [CPP04](#cpp04--subtype-polymorphism) | Subtype Polymorphism | Virtual functions, abstract classes, interfaces, deep copy |
| [CPP05](#cpp05--exceptions) | Exceptions | `try`/`catch`/`throw`, exception hierarchies, RAII |
| [CPP06](#cpp06--c-casts) | C++ Casts | `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast` |
| [CPP07](#cpp07--templates) | Templates | Function templates, class templates, template specialization |
| [CPP08](#cpp08--stl-containers--algorithms) | STL Containers & Algorithms | Iterators, `std::vector`, `std::list`, `std::stack`, `std::find` |
| [CPP09](#cpp09--stl-advanced) | STL Advanced | `std::map`, `std::stack`, `std::vector`, `std::deque`, Ford-Johnson sort |

---

## CPP00 — Namespaces, Classes & Streams

> *First contact with C++ classes, member functions, and the standard I/O stream.*

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Megaphone | String uppercasing via `std::toupper`; handles empty input |
| ex01 | My Awesome PhoneBook | In-memory phonebook with `std::cin`/`std::cout`, formatted output, field truncation |
| ex02 | The Job Of Your Dreams | Reconstruct a missing `Account` class from logs and expected output |

**Concepts:** Namespaces · Classes · Member functions · `stdio` streams · Initialization lists · `static` · `const`

---

## CPP01 — Memory & References

> *Understanding when to use the heap, when to use the stack, and how references differ from pointers.*

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | BraiiiiiiinnnzzzZ | Zombie class: stack vs heap allocation |
| ex01 | Moar brainz! | Zombie horde: array allocation with `new[]`/`delete[]` |
| ex02 | HI THIS IS BRAIN | Pointer vs reference aliasing — same address, different syntax |
| ex03 | Unnecessary violence | `HumanA` (always armed, ref) vs `HumanB` (optionally armed, pointer) |
| ex04 | Sed is for losers | File I/O with `std::ifstream`/`std::ofstream`; string replacement without `std::replace` |
| ex05 | Harl 2.0 | Pointer-to-member-function array — eliminating `if/else` chains |
| ex06 | Harl filter | `switch` on complaint levels; filters output by minimum severity |

**Concepts:** `new`/`delete` · References vs pointers · File streams · Pointers to member functions · `switch`

---

## CPP02 — Ad-hoc Polymorphism & Fixed-Point

> *Building a fixed-point number class from scratch using operator overloading and the Orthodox Canonical Form.*

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | My First Class in Orthodox Canonical Form | Fixed-point class with integer representation |
| ex01 | Towards a more useful fixed-point number class | Constructors from `int` and `float`; conversion back; `toFloat()`/`toInt()` |
| ex02 | Now we're talking | Full operator overloading: arithmetic, comparison, increment/decrement, stream insertion |
| ex03 | BSP | Binary Space Partitioning — point-in-triangle test using fixed-point math |

**Concepts:** Orthodox Canonical Form (OCF) · Operator overloading · Fixed-point arithmetic · `static` member functions

---

## CPP03 — Inheritance

> *Class hierarchies, constructor chaining, and the diamond inheritance problem.*

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Aaaaand… OPEN! | `ClapTrap` base class with energy/hit points and attack/repair |
| ex01 | Serena, my love! | `ScavTrap` inherits `ClapTrap`; overrides attack; adds `guardGate()` |
| ex02 | Repetitive work | `FragTrap` inherits `ClapTrap`; different stats; adds `highFivesGuys()` |
| ex03 | Now it's weird! | `DiamondTrap` inherits both `ScavTrap` and `FragTrap`; diamond resolution |

**Concepts:** Single & multiple inheritance · Virtual inheritance · Constructor/destructor chaining · `protected` attributes

---

## CPP04 — Subtype Polymorphism

> *Virtual dispatch, abstract base classes, and deep vs shallow copy.*

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Polymorphism | `Animal`/`Dog`/`Cat` hierarchy; `makeSound()` dispatched virtually |
| ex01 | I don't want to set the world on fire | `Brain` class; deep copy via copy constructor and assignment operator |
| ex02 | Abstract class | `Animal` becomes `AAnimal` — pure virtual prevents direct instantiation |
| ex03 | Interface & recap | `AMateria` abstract class + `Ice`/`Cure` concretions; `ICharacter` / `IMateriaSource` interfaces |

**Concepts:** Virtual functions · Pure virtual / abstract classes · Deep copy · Interfaces (pure virtual classes) · `dynamic_cast`

---

## CPP05 — Exceptions

> *Modelling bureaucratic hell with C++ exception handling and nested exception classes.*

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Mommy, when I grow up, I want to be a bureaucrat! | `Bureaucrat` with grade bounds; throws `GradeTooHighException` / `GradeTooLowException` |
| ex01 | Form up, maggots! | `Form` class; sign/execute grade checks; `beSigned()` throws on failure |
| ex02 | No, you need form 28B, not 28C… | `AForm` abstract base; `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm` |
| ex03 | At least this beats coffee-making | `Intern` class with factory: creates any form by name using a function-pointer dispatch table |

**Concepts:** `try`/`catch`/`throw` · Nested exception classes · Abstract forms · Factory pattern · RAII

---

## CPP06 — C++ Casts

> *Understanding the four C++ cast operators and type identification at runtime.*

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Scalar types | `ScalarConverter`: converts a string literal to `char`, `int`, `float`, `double`; handles pseudo-literals (`nan`, `inf`) |
| ex01 | Serialization | `Serializer`: `uintptr_t`-based pointer serialization with `reinterpret_cast` |
| ex02 | Identify real type | `Base` with `A`/`B`/`C` derived; runtime type identification via `dynamic_cast` on pointer and reference |

**Concepts:** `static_cast` · `dynamic_cast` · `reinterpret_cast` · `const_cast` · RTTI · `uintptr_t`

---

## CPP07 — Templates

> *Writing generic code with function and class templates.*

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Start with a few functions | `swap`, `min`, `max` function templates working on any comparable type |
| ex01 | Iter | `iter` function template: applies a function to every element of an array |
| ex02 | Array | `Array<T>` class template with bounds-checked `operator[]`, size tracking, deep copy |

**Concepts:** Function templates · Class templates · Template instantiation · Bounds checking · Deep copy in templates

---

## CPP08 — STL Containers & Algorithms

> *Leveraging the Standard Template Library — containers, iterators, and algorithms.*

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Easy find | `easyfind<T>` template: finds first occurrence of integer in any STL container; throws on miss |
| ex01 | Span | `Span` class: stores up to N integers; computes `shortestSpan()` / `longestSpan()`; range-iterator fill |
| ex02 | Mutated abomination | `MutantStack<T>`: extends `std::stack` with full iterator support; behaviorally equivalent to `std::list` |

**Concepts:** STL containers · Iterators · `std::find` · `std::min_element`/`std::max_element` · Container adaptors · Template inheritance

---

## CPP09 — STL Advanced

> *Real-world STL usage: financial data parsing, stack-based expression evaluation, and a theoretically optimal sorting algorithm.*

| Exercise | Name | Description |
|----------|------|-------------|
| ex00 | Bitcoin Exchange | Reads a CSV price database (`std::map`) and evaluates wallet values at historical dates; full date/value validation |
| ex01 | Reverse Polish Notation | Stack-based RPN calculator (`std::stack`); handles operator precedence implicitly; validates all malformed input |
| ex02 | PmergeMe | **Ford-Johnson merge-insertion sort** on both `std::vector` and `std::deque`; Jacobsthal-ordered insertion; bounded binary search; performance timing comparison |

**Concepts:** `std::map` · `std::stack` · `std::vector` · `std::deque` · File parsing · RPN evaluation · Ford-Johnson algorithm · Jacobsthal sequence · Binary search

---

## 🔑 Global Rules (all modules)

- Language standard: **C++98** — no C++11 or later features
- **Orthodox Canonical Form** required from CPP02 onward (default ctor, copy ctor, copy assignment operator, destructor)
- **No memory leaks** — all heap allocations properly freed; verified with `valgrind --leak-check=full`
- **No STL** (containers/algorithms) before CPP08
- Headers must be self-sufficient and include-guarded
- No function implementations in header files (except templates)
- `using namespace std` and `friend` are forbidden

---

## 🧪 Testing

Run any exercise binary and test with:

```bash
# Memory leak check
valgrind --leak-check=full --track-origins=yes ./program

# Example — CPP09 ex02 PmergeMe
./PmergeMe 3 5 9 7 4 1 8 6 2

# Example — CPP09 ex01 RPN
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

# Example — CPP09 ex00 Bitcoin Exchange
./btc data.csv
```

---

## 📂 Repository Structure

```
cpp-modules/
├── CPP00/
│   ├── ex00/ - ex02/
├── CPP01/
│   ├── ex00/ – ex06/
├── CPP02/
│   ├── ex00/ – ex03/
├── CPP03/
│   ├── ex00/ – ex03/
├── CPP04/
│   ├── ex00/ – ex03/
├── CPP05/
│   ├── ex00/ – ex03/
├── CPP06/
│   ├── ex00/ – ex02/
├── CPP07/
│   ├── ex00/ – ex02/
├── CPP08/
│   ├── ex00/ – ex02/
├── CPP09/
│   ├── ex00/ - ex02/
└── README.md
```

---

<div align="center">

*Made with ☕ and a lot of `-Werror` warnings at 42 School*

</div>
