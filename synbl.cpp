#include"SYNBL.h"
using namespace std;

int synbl::sym_search(string str)//查找变量
{
	int num = 1;
	vector<symbol>::iterator it;
	it = sym.begin();
	while (it != sym.end())
	{
		if (it->name == str)
		{
			return num;
		}
		num++;
		it++;
	}
	return 0;
}

char synbl::isin_sym(string str)//返回type
{
	int num = 1;
	vector<symbol>::iterator it;
	it = sym.begin();
	while (it != sym.end())
	{
		if (it->name == str)
		{
			return it->type;
		}
		num++;
		it++;
	}

	return 'i';
}

void synbl::init_symbol()//符号表初始化
{
	vector<TokenNode>::iterator it;
	vector<string>::iterator i;
	int num;
	it = Token.begin();
	while (it != Token.end())
	{
		if (it->name == "IT")
		{
			i = IT.begin();
			i += ((it->location) - 1);
			string str = *i;
			num = sym_search(str);
			if (num == 0)
			{
				symbol sy;
				sy.name = str;
				sy.type = '&';
				sy.cat = '&';
				sy.offset = -1;
				sym.push_back(sy);
			}
		}
		it++;
	}

}

void synbl::enter(string id, char type, char cat, int offset)//插入变量
{
	int location = sym_search(id);
	vector<symbol>::iterator it;
	it = sym.begin();
	if (location)
	{
		(it + location - 1)->type = type;
		(it + location - 1)->cat = cat;
		(it + location - 1)->offset = offset;
	}
}

void synbl::enter_temp_var(TempVariable tempVar, char type, char cat, int offset)
{


	int location = sym_search(tempVar.name); // 查找临时变量是否已存在

	vector<symbol>::iterator it = sym.begin();
	// 如果临时变量已存在，则更新其信息，如果不存在则插入新的临时变量
	if (location)
	{

		(it + location - 1)->type = tempVar.type;  // 更新类型
		(it + location - 1)->cat = tempVar.cat;  // 更新类别
		// 也可以更新其他属性，如偏移量等
	}
	else
	{
		symbol sy;
		sy.name = tempVar.name;
		sy.type = tempVar.type; // 临时变量类型
		sy.cat = tempVar.cat; // 临时变量类别
		// 初始化其他属性
		sy.offset = tempVar.offset; // 偏移量初始化为-1，可根据需要修改
		sym.push_back(sy); // 将临时变量插入符号表
	}
}

string synbl::synbl_print() { //符号表输出
	ostringstream oss;
	oss << "name\t" << "type\t" << "cat\t" << "offset" << endl;
	vector<symbol>::iterator it = sym.begin();
	while (it != sym.end()) {
		oss << it->name << "\t";
		if (it->type == '&')
			oss << "--\t";
		else
			oss << it->type << "\t";
		if (it->cat == '&')
			oss << "--  \t";
		else
			oss << it->cat << "\t";
		if (it->offset == -1)
			oss << "--" << endl;
		else
			oss << it->offset << endl;
		it++;
	}
	return oss.str();
}
