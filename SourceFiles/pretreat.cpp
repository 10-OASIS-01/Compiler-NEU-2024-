/*�﷨����Ԥ������������������LL(1)�����ʽ��first����follow��������first����follow����дLL(1)������*/
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<stack>
#include<set>
#include<algorithm>

using namespace std;

struct Production {
	string left;
	string right;
};
class PreTreat {
protected:
	vector<Production> productions;   //����ʽ����
	vector<string> terminal;          //�ս������
	vector<string> nonterminal;       //���ս������
	set<string> first;
	set<string> follow;

	void grammarRead();
public:
	~PreTreat(){}
	PreTreat();
};