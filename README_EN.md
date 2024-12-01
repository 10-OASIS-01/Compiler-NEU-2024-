# Compiler Principles Course Design at Northeastern University

## Environment

- Visual Studio 2022

## Project Overview

### Project Description

This project is the design and implementation of a simple grammar-based compiler frontend, which includes the following features:

- Definition of a simple programming language grammar (including variable declaration statements, arithmetic expressions, and assignment statements; extensions include logical expressions, If statements, While statements, etc.).
- Design and implementation of a lexical analyzer.
- Design and implementation of a syntax analyzer.
- Design and implementation of intermediate code generation.
- Implementation of code optimization.
- Visualization interface based on Windows API.
- Virtual machine simulation of target instruction execution, based on multiple registers and memory.

### Supported Grammar

```
PROGRAM  program id SUB_PROGRAM.
SUB_PROGRAM  VARIABLE COM_SENTENCE
VARIABLE  var ID_SEQUENCE ：TYPE ；
ID_SEQUENCE  id {，id}
TYPE  integer | real | char
COM_SENTENCE  begin SEN_SEQUENCE {; SEN_SEQUENCE} end
SEN_SEQUENCE EVA_SENTENCE|COND_SENTENCE|LOOP_SENTENCE|COM_SENTENCE

EVA_SENTENCE  id PUSH(id):= EXPRESSION ASSI(=)     //Assignment statement grammar
EXPRESSION  TERM{w1 TERM GEQ(w1)}
TERM  FACTOR{w2 FACTOR GEQ(w2)}
FACTOR  id PUSH(id) | cons PUSH(cons) | (EXPRESSION)
//EXPRESSION  EXPRESSION + TERM | TERM
//TERM  TERM *  FACTOR | FACTOR
//FACTOR  id | cons | ( EXPRESSION )

COND_SENTENCE  if LEXP then SEN_SEQUENCE [else SEN_SEQUENCE]   //Conditional statement
LOOP_SENTENCE  while LEXP do SEN_SEQUENCE                      //Loop statement
LEXP  EXPRESSION LOP EXPRESSION
LOP   < |　> | <= | >= | ==
```

## File Description

### ProjectFiles
- keshe_final.sln: Solution file.
- keshe_final.vcxproj: Project file.
- keshe_final.vcxproj.filters: Project filter file.
- keshe_final.ico: Project icon file.
- small.ico: Small icon file.
- grammer.txt: Grammar description.
- test1.txt: Test file 1.
- test2.txt: Test file 2.
- targetver.h: Target version header file.
- Resource.h: Resource header file.
- framework.h: Framework header file.

### SourceFiles
- main.cpp: Main program.
- lexanalyse.cpp: Lexical analyzer implementation.
- objectivecode.cpp: Target code generation implementation.
- parser.cpp: Syntax analysis implementation.
- synbl.cpp: Symbol table implementation.
- pretreat.cpp: Preprocessing implementation.
- VirtualMachine.cpp: Virtual machine implementation.

### HeaderFiles
- datastructure.h: Defines data structures.
- lexanalyse.h: Defines lexical analysis class.
- objectivecode.h: Defines target code generation class.
- parser.h: Defines syntax analysis class.
- SYNBL.h: Defines symbol table class.
- keshe_final.h: Project header file.

## Running Guide
1. Open Visual Studio 2022.
2. Load the solution file `ProjectFiles/keshe_final.sln`.
3. Build and run the project.

## Function Examples

### Main Interface

![Main Interface](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/1.png)

### Syntax Analysis

![Syntax Analysis](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/2.png)

### Intermediate Code Generation and Optimization

![Intermediate Code Generation and Optimization](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/3.png)

### Target Code Generation

![Target Code Generation](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/4.png)

## Acknowledgements

Our implementation is based on [NEUEasyCompiler](https://github.com/Sswjm/NEUEasyCompiler). We thank the author for their contributions.

Creator: lau  
Contributors: lau, lyh, mzh, hxr, szy

## Contributions

Contributions to this project are welcome! Your efforts can help future students. 😊😊😊

This course design still has room for improvement, such as lack of support for strings, arrays, structures, and functions. If you wish to further develop this project, feel free to submit an issue or pull request. Contribution process:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.
