




# C++ Project 08 - Containers, iterators, algorithms
###  General Rules for these projects: 
The purpose of these c++ projects is to get introduced into OOP. We are allowed to use standard c++17. 

- code must be coiled with `c++` and the flags `-Wall -Werror -Wextra`.
- there must be a Makefile for each exercise.
- Class names and corresponding filenames must be written in UpperCamelCase format.
- The `using namespace <ns_name>` and `friend` keywords are forbidden.
- There must be no memory leaks.
- Classes must be designed in the Orthodox Canonical Form.
- There can be no function implementations in headerfiles.
- Headers must be able to be used independently from others.
- Use of STL in the Module 08 and 09 only
- finally here we can /have to use containers and the algorithm header


## 🔶 ex00   Easy find
### Objective: Write a function template easyfind that accepts a type T. It takes two parameters. The first one has type T and the second one is an integer.

### Usage:
  ```
  cd ex00
  make
  ./container
```


### My thoughts: 
- could it really be that simple?? there is a complete implementation of find and other conveniences for containers? im amazed!


## 🔶 ex01 Span
### Ojective: Develop a Span class that can store a maximum of N integers. Implement addNumber(), shortestSpan() and longestSpan(). Lastly implement a addnumber for a range of iterators.
### Usage:
  ```
  cd ex02
  make
  ./span
```

### My thoughts:
- It was a bit tricky to get the shortest span bc to use containters you have to understand them and its behaviours. I learned about iterators and the deciding function here: adjacent_difference using also lambda fuctions.
  
## 🔶 ex02 Mutated abomination
### Ojective: The std::stack container is very nice. Unfortunately, it is one of the only STL Containers that is NOT iterable. To repair this injustice, you have to make the std::stack container iterable.
### Usage:
  ```
  cd ex01
  make
  ./MutantStack
```

### My thoughts:
- crazy to learn about the syntax for this exercise. To simply use the underlying container iterators is really convienient but feels wierd.
