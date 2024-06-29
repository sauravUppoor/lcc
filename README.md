# lcc - little c compiler

A compiler for subset of C language. The aim of the project is to create a self-compiling compiler which will generate assembly for actual hardware: choosing ARM Aarch64 due to its RISC architecture. Following are few of the goals for the first version of the compiler:

### Goals

| Milestone                               | Task                                            | Priority |    Status    |
|-----------------------------------------|-------------------------------------------------|----------|:------------:|
| Frontend support for C--                | Lexer for numeric values                        | P0       | Complete     |
|                                         | Recursive Descent Parser                        | P0       | In progress  |
|                                         | Support for more types                          | P0       | Yet to start |
|                                         | Support for loops                               | P0       | Yet to start |
|                                         | Support for functions                           | P0       | Yet to start |
|                                         | Support for pointers                            | P0       | Yet to start |
| IR and CodeGen support  for ARM Aarch64 | SSA IR form                                     | P0       | Yet to start |
|                                         | Fold optimistation                              | P0       | Yet to start |
|                                         | Code generation for Aarch64                     | P0       | Yet to start |
| Frontend support for C89                | Additional support for  C89 language constructs | P1       | Yet to start |
| Backend support for x86_64              |                                                 | P2       | Yet to start |

### References

1. C-- language reference: https://www.microsoft.com/en-us/research/wp-content/uploads/1998/01/pal-manual.pdf
2. C89 language reference: https://en.cppreference.com/w/c
3. Compiler writing journey: https://github.com/DoctorWkt/acwj
4. Awesome compilers: https://github.com/aalhour/awesome-compilers 
