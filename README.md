# Head-First-Design-Patterns-CPP

This repository contains a selection of examples from the [Head First Design Patterns, 2nd Edition](https://wickedlysmart.com/head-first-design-patterns/) book, rewritten in C++. The code is primarily for my own learning and deepening of my knowledge of design patterns, and is not intended to serve as a complete conversion of the Java source code in the book (which can be found on the official website). I have made an effort to leverage modern C++ features, such as using smart pointers instead of traditional raw pointers. The source files were created using the VSCode editor.

## Repository Structure

This repository follows the structure of the **Head First Design Patterns** book. The examples are organized to mirror the chapters and patterns presented in the book, making it easy to navigate through the different design patterns covered. Each folder typically corresponds to a chapter from the book, and inside you’ll find the C++ implementation of the respective design pattern.

## Table of Contents

1. [Design Patterns Implemented](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/blob/main/README.md#table-of-contents)
    - [Strategy - Chapter 1](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter1-Strategy)
    - [Observer - Chapter 2](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter2-Observer)
    - [Decorator - Chapter 3](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter3-Decorator)
    - [Factory - Chapter 4](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter4-Factory)
    - [Singleton - Chapter 5](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter5-Singleton)
    - [Command - Chapter 6](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter6-Command)
    - Chapter 7
      * [Adapter](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter7-Adapter)
      * [Facade](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter7-Facade)
    - [Template Method - Chapter 8](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter8-Template)
    - Chapter 9
      * [Iterator](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter9-Iterator)
      * [Composite](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter9-Composite)
    - [State - Chapter 10](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter10-State)
    - [Proxy - Chapter 11](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter11-Proxy)
    - [Leftover Patterns - Chapter14](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter14-Appendix)
      * [Bridge](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter14-Appendix/Bridge)
      * [Builder](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter14-Appendix/Builder)
      * [Flyweight](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter14-Appendix/Flyweight)
      * [Prototype](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/tree/main/Chapter14-Appendix/Prototype)
  
2. [Usage](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/blob/main/README.md#usage) 
3. [Compilation](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/blob/main/README.md#compilation)
4. [Contributing](https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP/blob/main/README.md#contributing)

## Usage

To get started with the examples in this repository, you can clone it using the following command:

      git clone https://github.com/BeagleBasset/Head-First-Design-Patterns-CPP.git

Once you have cloned the repository, you can open the individual files in a C++ IDE or editor such as VSCode or CLion, and start exploring the code.

## Compilation

If you want to compile and run the examples locally, you can use the following steps:
  1. Navigate to the folder containing the example you wish to compile.
  2. If you have the **g++** compiler installed, use the following command to compile the code:

          g++ -std=c++17 -o main *.cpp
    
  3. After compilation, run the program using:

          ./main

This will compile and execute the C++ examples.
You can also use other C++ compilers. Just **ensure they support the C++17 standard** and modify the command accordingly to fit your compiler.

## Contributing

If you would like to contribute to this project by adding more examples or improving existing ones, feel free to fork the repository and submit a pull request. All contributions are welcome!
