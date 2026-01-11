# Kenguru Project

Client-server application for solving Kenguru 2001 competition problem (9-10 grades) with full CI/CD pipeline.

## Problem Statement

From Kenguru 2001 competition (grades 9-10):

> Jean-Christophe continues to study Russian. He writes on the board in digits and words all numbers where all digits are different and there are exactly two words. What is the tens digit of the largest such number?

## Architecture

The project consists of:

- **Client**: Reads parameters from JSON file and sends to server via TCP
- **Server**: Processes the problem using mathematical library, logs operations
- **MathLib**: Dynamic shared library with mathematical functions
- **Common**: Shared code (protocol, logging, utilities)
- **CI/CD**: Jenkins pipeline with parameterized builds

## Requirements

- CMake 3.10+
- C++11 compatible compiler
- JSONCPP library
- Jenkins (for CI/CD)
- Doxygen + Graphviz (for documentation)

## Build Instructions

```bash
# Clone repository
git clone https://github.com/yourusername/kenguru-project.git
cd kenguru-project

# Build project
make build

# Run tests
make test

# Generate documentation
make doc

# Format code
make format

# Static analysis
make check
make run-server
# or directly:
./build/server/server --port 8080
