# Parallel Processing Course - Practice Codes and Assignments

## Overview

This repository contains all the practice codes and assignments completed during my Parallel Processing course. The primary focus of the course was on parallel computing techniques using C and CUDA.

## Table of Contents

- [Introduction](#introduction)
- [Technologies Used](#technologies-used)
- [Directory Structure](#directory-structure)
- [Getting Started](#getting-started)
- [Practice Codes](#practice-codes)
- [Assignments](#assignments)
- [Resources](#resources)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Parallel processing is a form of computation in which many calculations or processes are carried out simultaneously. This course covered various parallel computing paradigms and techniques, focusing on GPU programming with CUDA.

## Technologies Used

- **C**: A general-purpose programming language that provides low-level access to memory.
- **CUDA**: A parallel computing platform and programming model developed by NVIDIA for general computing on graphical processing units (GPUs).

## Getting Started

To get started with the practice codes and assignments in this repository, follow these steps:

1. **Clone the repository**:
    ```bash
    git clone https://github.com/your-username/parallel-processing-course.git
    cd parallel-processing-course
    ```

2. **Compile and run a C code**:
    ```bash
    gcc -o output practice_codes/code1.c
    ./output
    ```

3. **Compile and run a CUDA code**:
    ```bash
    nvcc -o output assignments/assignment1/code.cu
    ./output
    ```

## Practice Codes

The `practice_codes` directory contains various examples and exercises that were used to understand the basics of parallel processing. Each code file is aimed at demonstrating different concepts such as:

- Parallel loop execution
- Synchronization
- Memory management in CUDA
- Optimization techniques

## Assignments

The `assignments` directory contains the course assignments. Each assignment folder includes:

- Source code (`.cu` files)
- Documentation or reports (`.pdf` files)

### Assignment 1: [Title of Assignment 1]

- **Description**: Brief description of what Assignment 1 is about.
- **Files**:
  - `code.cu`: The CUDA source code.
  - `report.pdf`: The detailed report explaining the implementation, results, and any challenges faced.

### Assignment 2: [Title of Assignment 2]

- **Description**: Brief description of what Assignment 2 is about.
- **Files**:
  - `code.cu`: The CUDA source code.
  - `report.pdf`: The detailed report explaining the implementation, results, and any challenges faced.

(Repeat the above section for all assignments)

## Resources

- [CUDA Programming Guide](https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html)
- [Parallel Programming in C with MPI and OpenMP](https://mitpress.mit.edu/books/parallel-programming-c-mpi-and-openmp)
- [Introduction to Parallel Computing](https://computing.llnl.gov/tutorials/parallel_comp/)

## Contributing

Contributions are welcome! If you have any improvements or suggestions, feel free to submit a pull request or open an issue.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

