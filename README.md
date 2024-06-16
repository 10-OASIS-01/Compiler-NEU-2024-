# 东北大学编译原理课程设计

运行环境：vs2022

题目内容：
一个简单文法的编译器前端的设计与实现
定义一个简单程序设计语言文法（包括变量说明语句、算术运算表达式、赋值语句；扩展包括逻辑运算表达式、If语句、While语句等）；
扫描器设计实现；
语法分析器设计实现；
中间代码设计；
中间代码生成器设计实现。 
补充实现内容：
基于Windows API实现的可视化界面，
基于多寄存器多内存的虚拟机模拟目标指令运行平台


支持文法：
\\\
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
\\\

功能示例：

主界面：
![GitHub Logo](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/1.png)

语法分析：
![GitHub Logo](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/2.png)

中间代码生成和代码优化：
![GitHub Logo](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/3.png)

目标代码生成：
![GitHub Logo](https://github.com/10-OASIS-01/Compiler-NEU-2024-/blob/main/fig/4.png)






