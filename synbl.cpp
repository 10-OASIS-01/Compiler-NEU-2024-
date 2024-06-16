#include"SYNBL.h"
using namespace std;

int synbl::sym_search(string str)//���ұ���
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

char synbl::isin_sym(string str)//����type
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

void synbl::init_symbol()//���ű��ʼ��
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

void synbl::enter(string id, char type, char cat, int offset)//�������
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


	int location = sym_search(tempVar.name); // ������ʱ�����Ƿ��Ѵ���

	vector<symbol>::iterator it = sym.begin();
	// �����ʱ�����Ѵ��ڣ����������Ϣ�����������������µ���ʱ����
	if (location)
	{

		(it + location - 1)->type = tempVar.type;  // ��������
		(it + location - 1)->cat = tempVar.cat;  // �������
		// Ҳ���Ը����������ԣ���ƫ������
	}
	else
	{
		symbol sy;
		sy.name = tempVar.name;
		sy.type = tempVar.type; // ��ʱ��������
		sy.cat = tempVar.cat; // ��ʱ�������
		// ��ʼ����������
		sy.offset = tempVar.offset; // ƫ������ʼ��Ϊ-1���ɸ�����Ҫ�޸�
		sym.push_back(sy); // ����ʱ����������ű�
	}
}

string synbl::synbl_print() { //���ű����
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
