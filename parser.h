#pragma once
#ifndef _PARSER_H_
#define _PARSER_H_

#include"SYNBL.h"

class Parser:public synbl {  //�﷨���﷨�Ƶ���������࣬��Ҫʹ�õݹ��½��ӳ���
public:
	~Parser() {}
	Parser(string file_string);
	void check();
	bool mainControl();   //�ݹ��½��﷨�������س���
	string checkGrammar();
	string printQuaternion();  
	string printRecording();
	vector<QuaternionNode> getQuaternion();  //���ؽ������Ԫʽ����

private:
	int i;
	bool tag;

	int offset;
	int len;
	char cat;
	char type;

	vector<QuaternionNode> Quaternion;  //��Ԫʽ�����洢�������Ԫʽ����
	queue<string> id;  //���ڴ洢��ʶ������д���ű�
	stack<Objective> sem;  //����ջ���ݴ�������������ֵ
	vector<TempVariable> tempvar;  //temporary variable ��ʱ������

	void PROGRAM();
	void SUB_PROGRAM();
	void VARIABLE();
	void COM_SENTENCE();
	void ID_SEQUENCE();
	void TYPE();
	void SEN_SEQUENCE();
	void EVA_SENTENCE();
	void COND_SENTENCE();
	void LOOP_SENTENCE();
	void EXPRESSION();
	void TERM();
	void FACTOR();
	void LEXP();
	void ELSE();
	void LOP();




	void action_1();  //program() ����program��Ԫʽ
	void action_2();  //end()  ����end��Ԫʽ
	void action_3();  //a1  ��������
	void action_4();  //a2  ��������
	void action_5();  //a3  ��������
	void action_6();  //a4  ��������
	void action_7();  //a5  ��������
	void action_8();  //a6  ��������
	void action_9();  //Push(id)  ����ǰ��ʶ��ѹ������ջ
	void action_10();  //ASSI(=)  ��ֵ�����Ԫʽ���ɺ���
	void action_11(string w);  //GEQ(w)  ���ʽ���������ϵ����Ԫʽ���ɺ���
	void action_12();  //IF(if)  ������俪ʼ��Ԫʽ���ɺ���
	void action_13();  //EL(el)  else�����Ԫʽ���ɺ���
	void action_14();  //IE(ie)  ������������Ԫʽ���ɺ���
	void action_15();  //WH()  ѭ����俪ʼ��Ԫʽ���ɺ���
	void action_16();  //Do(do)  do�����Ԫʽ���ɺ���
	void action_17();  //WE(we)  ѭ����������Ԫʽ���ɺ���
	void action_18(string t_name);//������ʱ���������ű�
};


#endif