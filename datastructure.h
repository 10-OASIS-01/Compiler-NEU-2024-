#pragma once
#ifndef _DATASTRUCTURE_H_
#define _DATASTRUCTURE_H_

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<fstream>
#include<stack>
#include<algorithm>
#include<sstream>
#include<queue>
#include <cstring>
#include <stdio.h>
#include<stdlib.h>
#include<set>
#include<cstdio>
#include<utility>
#include<map>

using namespace std;
typedef long long ll;

typedef struct TempVariable {
	string name;
	char type;
	char cat;
	int offset;

}TempVariable;

typedef struct TokenNode {
	string name;
	int location{};
}TokenNode;

typedef struct Objective {
	string name;
	string type;  //1 ����ʱ����  2 ��ʱ����  3 ����  
	inline Objective(string Name = "", string Type = "")
	{
		name = Name;
		type = Type;
	}
}Objective;
typedef struct QuaternionNode {  //��Ԫʽ��������
	int block;  //����������  init 0
	int type;  //����  init 0

	string op;//���
	Objective objective1;//����1
	Objective objective2;//����2
	Objective result;//���
	inline QuaternionNode(int Block, int Type, string Op, Objective Obj1, Objective Obj2, Objective Result)
	{
		block = Block;
		type = Type;
		op = Op;
		objective1 = Obj1;
		objective2 = Obj2;
		result = Result;
	}
}QuaternionNode;



#endif