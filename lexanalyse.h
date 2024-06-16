#pragma once
#ifndef _LEXANALYSE_H_
#define _LEXANALYSE_H_

#include"datastructure.h"


class LexAnalyser {
public:
	void lexAnalyse(string file_name);
	string Print_Token();
	string ShowTable();
	vector<TokenNode> Token;  //�洢Token���У��Ա���к�������
	vector<string> KT = { "program","var","integer","real","char","begin","end","if","then","else","while","do" };//�ؼ��ʱ�
	vector<string> PT = { ",",":",";",":=","*","/","+","-",".","(",")" ,"<",">","<=",">=","=="};//�����
	vector<string> IT;//��ʶ����
	vector<string> CT;//��������
	vector<string> RT;//ʵ����С����
	vector<string> cT;//�ַ���
	vector<string> ST;//�ַ�����
private:
	int IfLetter(char ch);
	int IfDigit(char ch);
	string Convert(double Num);
	string Convert2(ll Num);
	void constant(string s);
	int reserve(char* strt);
	int reserve2(char* strt);
	int InsertIT(char* strt);
	int InsertcT(char* strt);
	int InsertST(char* strt);
	void lexical(string line);
	void vall_print();
};



#endif
