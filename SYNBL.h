#pragma once
#ifndef _SYNBL_H_
#define _SYNBL_H_

#include"lexanalyse.h"
class synbl :public LexAnalyser//符号表
{
public:

	struct symbol {
		string name;		//name
		char type;		//类型
		char cat;	//属性
		int offset;
	};
	vector<symbol>sym;
	int sym_search(string str);
	void init_symbol();
	void enter(string id, char type, char cat, int offset);
	void enter_temp_var(TempVariable tempVar, char type, char cat, int offset);
	string synbl_print();
	char isin_sym(string str);
};


#endif
