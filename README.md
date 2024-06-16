# 东北大学编译原理课程设计

## 运行环境

- Visual Studio 2022

## 题目内容

### 项目简介

本项目是一个简单文法的编译器前端的设计与实现，包括以下功能：

- 定义一个简单的程序设计语言文法（包括变量说明语句、算术运算表达式、赋值语句；扩展包括逻辑运算表达式、If语句、While语句等）。
- 词法分析器的设计与实现。
- 语法分析器的设计与实现。
- 中间代码设计与生成器的实现。
- 基于Windows API实现的可视化界面。
- 基于多寄存器多内存的虚拟机模拟目标指令运行平台。

### 支持文法

```
PROGRAM  program id SUB_PROGRAM.
SUB_PROGRAM  VARIABLE COM_SENTENCE
VARIABLE  var ID_SEQUENCE ：TYPE ；
ID_SEQUENCE  id {，id}
TYPE  integer | real | char
COM_SENTENCE  begin SEN_SEQUENCE {; SEN_SEQUENCE} end
SEN_SEQUENCE EVA_SENTENCE|COND_SENTENCE|LOOP_SENTENCE|COM_SENTENCE

EVA_SENTENCE  id PUSH(id):= EXPRESSION ASSI(=)     //赋值语句文法
EXPRESSION  TERM{w1 TERM GEQ(w1)}
TERM  FACTOR{w2 FACTOR GEQ(w2)}
FACTOR  id PUSH(id) | cons PUSH(cons) | (EXPRESSION)
//EXPRESSION  EXPRESSION + TERM | TERM
//TERM  TERM *  FACTOR | FACTOR
//FACTOR  id | cons | ( EXPRESSION )

COND_SENTENCE  if LEXP then SEN_SEQUENCE [else SEN_SEQUENCE]   //条件语句
LOOP_SENTENCE  while LEXP do SEN_SEQUENCE                      //循环语句
LEXP  EXPRESSION LOP EXPRESSION
LOP   < |　> | <= | >= | ==
```

## 文件说明

- `datastructure.h`：定义数据结构。
- `lexanalyse.h`：定义词法分析类。
- `objectcode.h`：定义目标代码生成类。
- `parser.h`：定义语法分析类。
- `SYNBL.h`：定义符号表类。
- `lexanalyse.cpp`：词法分析器实现。
- `main.cpp`：主程序。
- `objectivecode.cpp`：目标代码生成实现。
- `parser.cpp`：语法分析实现。
- `synbl.cpp`：符号表实现。
- `VirtualMachine.cpp`：虚拟机实现
- `grammer.txt`：文法说明。
- `test1.txt`、`test2.txt`：测试文本。

## 功能示例

### 主界面

![主界面](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/1.png)

### 语法分析

![语法分析](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/2.png)

### 中间代码生成和代码优化

![中间代码生成和代码优化](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/3.png)

### 目标代码生成

![目标代码生成](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/4.png)

## 致谢

我们的实现以 [NEUEasyCompiler](https://github.com/Sswjm/NEUEasyCompiler) 作为起点。我们感谢其作者的贡献。

## 改进

该课设仍然存在一定改进之处，如不支持字符串、数组、结构体、函数。若您希望在此课设代码上进一步开发，请fork该代码并帮助我们完善。你的善举可以帮助更多学弟学妹们。😊😊😊
