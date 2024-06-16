#pragma once
#include "datastructure.h"

struct ACT_INF //四元式的活跃信息
{
	string num1;
	string num2;
	string ans;
	ACT_INF(string a = "", string b = "", string c = "")
	{
		num1 = a; num2 = b; ans = c;
	}
};

struct ACT_SYNBL
{
	string name;
	string act_inf;
	ACT_SYNBL(string a = "", string b = "")
	{
		name = a; act_inf = b;
	}
};

class objective
{
public:
	vector<QuaternionNode> qua;
	vector<QuaternionNode> Block[20];
	vector<QuaternionNode> qua_new;

	set<string>Tmp_var; //临时变量
	set<string>var; //非临时变量
	vector<ACT_INF>Act_inf;
	vector<string>objcode;
	stack<string>SEM; //保存待返填地址
	vector<vector<ACT_SYNBL>>Act_synbl;

	vector<ACT_INF>Act_inf_Obj[20];
	vector<string>objcode_Obj[20];
	stack<string>SEM_Obj[20]; //保存待返填地址
	vector<vector<ACT_SYNBL>>Act_synbl_Obj[20];

	void process_blocks();

    //void example();
    //void example2();
    int to_int(string str);
    bool is_inActsynbl(Objective token, vector<ACT_SYNBL>act_synbl);
    void Active_Information(vector<QuaternionNode>qua, int iofB);
	string Objective_Code(vector<QuaternionNode>qua, vector<ACT_INF>Act_inf);
    //void run();

	void mergeActInf();
	void mergeActSynbl();
	void mergeBlocks();



	// Function to print ACT_INF vector
	string printActInf();
	// Function to print ACT_SYNBL 2D vector
	string printActSynbl();
	string printQua();
	string printBlock();
	void printQua_new();
	void assignBlockToQuaNew();
	void printActInfo();


    void init(vector<QuaternionNode> quat);     //初始化四元式结构体数组
    void addition(int n, string A, string typ);   //把标记A添加到节点n上，顺便删除无用标记
    int getnode(string B);   //获取标记为B的节点的id
    void makeleaf(string B, string typ);   //构造叶子节点
    void delnode(int n);     //删除id为n的节点
    int findnode(string opl, string B, string C);   //在DAG中查找有无符合A=B op C的节点
    int makenode(string opl, string B, string C);  //构造中间节点
    string coutvalue(string opl, string B, string C);   //计算两个数运算的值
	void makequa(int block, ostringstream& oss);  //生成block块中优化后的四元式
    void deletedag();  //对dag清零
	string optimizequa(int block_num);    //优化四元式
    int divide();             //划分基本块

};



