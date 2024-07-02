#include"../HeaderFiles/lexanalyse.h"


int LexAnalyser::IfLetter(char ch)                       //�ж���ĸ
{
	if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
		return 1;
	else
		return 0;
}

int LexAnalyser::IfDigit(char ch)                       //�ж�����
{
	if (ch >= '0' && ch <= '9')
		return 1;
	else
		return 0;
}
string LexAnalyser::Convert(double Num)	//floatתstring
{
	ostringstream oss;
	oss << Num;
	string str(oss.str());
	return str;
}
string LexAnalyser::Convert2(ll Num)	//llתstring
{
	ostringstream oss;
	oss << Num;
	string str(oss.str());
	return str;
}
//����ʶ��� ll����CT double����RT
void LexAnalyser::constant(string s)
{
	double ans = 0;//���s 
	bool t = 0;//�������� ����0 ʵ��1 
	ll e = 1;//ָ���ķ��� + 1  - -1
	ll f = 1;//�����ķ��� 
	ll p = 0, m = 0;//p��ָ��λ  m��С��λ�� 
	int i;

	for (i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			ans = ans * 10 + (s[i] - '0');
		else if (s[i] == '.')
		{
			t = 1;
			break;
		}
		else if (s[i] == 'e')
		{
			break;
		}
		else if (s[i] == '-')
			f = -1;
	}
	for (i = i; i < s.size(); i++)
	{
		if (t == 0)
			break;
		if (s[i] >= '0' && s[i] <= '9')
		{
			ans = ans * 10 + (s[i] - '0');
			m++;
		}
		else if (s[i] == 'e')
		{
			break;
		}
	}
	for (i = i; i < s.size(); i++)
	{
		if (t == 0)
			t = 1;
		if (s[i] == '-')
			e = -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			p = p * 10 + (s[i] - '0');
		}
	}
	TokenNode token;
	if (t == 1)
	{
		ans = f * ans * pow(10, (e * p - m));//
		string temp = Convert(ans);
		vector<string>::iterator i;
		i = RT.begin();
		int num = 0, bo = 0;
		while (i != RT.end())
		{
			num++;
			if (*i == temp)
			{
				bo = 1;
				break;
			}
			i++;
		}
		if (bo == 1)
		{
			token.name = "RT";
			token.location = num;
			Token.push_back(token);
		}
		else
		{
			token.name = "RT";
			token.location = num + 1;
			RT.push_back(temp);
			Token.push_back(token);
		}
	}
	if (t == 0)
	{
		ans = ans * f;
		string temp = Convert2((ll)ans);
		vector<string>::iterator i;
		i = CT.begin();
		int num = 0, bo = 0;
		while (i != CT.end())
		{
			num++;
			if (*i == temp)
			{
				bo = 1;
				break;
			}
			i++;
		}
		if (bo == 1)
		{
			token.name = "CT";
			token.location = num;
			Token.push_back(token);
		}
		else
		{
			token.name = "CT";
			token.location = num + 1;
			CT.push_back(temp);
			Token.push_back(token);
		}
	}
}

int LexAnalyser::reserve(char* strt)      //��ؼ���
{
	string str = strt;
	vector<string>::iterator i;
	i = KT.begin();
	int num = 0;
	while (i != KT.end())
	{
		num++;
		if (*i == str)
			return num;
		i++;
	}
	return 0;
}

int LexAnalyser::reserve2(char* strt)      //����
{
	string str = strt;
	vector<string>::iterator i;
	i = PT.begin();
	int num = 0;
	while (i != PT.end())
	{
		num++;
		if (*i == str)
			return num;
		i++;
	}
	return 0;
}
int LexAnalyser::InsertIT(char* strt)   //��ʶ��
{
	string str = strt;
	vector<string>::iterator i;
	i = IT.begin();
	int num = 0;
	string s = strt;
	while (i != IT.end())
	{
		num++;
		if (*i == s)
			return num;
		i++;
	}
	IT.push_back(s);
	return num + 1;
}
int LexAnalyser::InsertcT(char* strt)
{
	string str = strt;
	vector<string>::iterator i;
	i = cT.begin();
	int num = 0;
	string s = strt;
	while (i != cT.end())
	{
		num++;
		if (*i == s)
			return num;
		i++;
	}
	cT.push_back(s);
	return num + 1;
}
int LexAnalyser::InsertST(char* strt)
{
	string str = strt;
	vector<string>::iterator i;
	i = ST.begin();
	int num = 0;
	string s = strt;
	while (i != ST.end())
	{
		num++;
		if (*i == s)
			return num;
		i++;
	}
	ST.push_back(s);
	return num + 1;
}

string LexAnalyser::Print_Token()
{
	ostringstream oss;
	vector<TokenNode>::iterator i;
	i = Token.begin();
	TokenNode t;

	while (i != Token.end()) {
		t = *i;
		oss << t.name << " " << t.location;

		// If it's not the last element, print a comma
		if (i + 1 != Token.end()) {
			oss << ", ";
		}

		i++;
	}
	oss << endl; // Print a newline at the end of the output

	return oss.str();
}


string LexAnalyser::ShowTable()
{
	ostringstream oss;

	oss << "Identifiers (IT):" << endl;
	for (const auto& id : IT) {
		oss << id << endl;
	}
	oss << endl;

	oss << "Constant Integers (CT):" << endl;
	for (const auto& constInt : CT) {
		oss << constInt << endl;
	}
	oss << endl;

	oss << "Real Numbers (RT):" << endl;
	for (const auto& realNum : RT) {
		oss << realNum << endl;
	}
	oss << endl;

	oss << "Characters (cT):" << endl;
	for (const auto& ch : cT) {
		oss << ch << endl;
	}
	oss << endl;

	oss << "Strings (ST):" << endl;
	for (const auto& str : ST) {
		oss << str << endl;
	}
	oss << endl;

	// vall_print(); // If this function needs to be included, capture its output similarly

	return oss.str();

}

void LexAnalyser::lexical(string line)
{

	int i_line;            //line�е�i���ַ� 
	char ch, strt[50];
	int value, i_str;            //��ǰ�����еĵ�i���ַ� 
	TokenNode token;
	i_line = 0;
	ch = line[i_line++];
	while (ch)
	{
		i_str = 0;
		while (ch == ' ' || ch == '\n')
			ch = line[i_line++];

		if (IfLetter(ch))				//��ĸ��ͷ�� 
		{
			while (IfLetter(ch) || IfDigit(ch))   //������ĸ������ 
			{
				strt[i_str++] = ch;       //ƴ�ӵ�strt��
				ch = line[i_line++];
			}
			strt[i_str] = '\0';
			value = reserve(strt);     //��ؼ��ֱ�

			if (value)				//���ǹؼ��־��Ǳ�ʶ�� 
			{
				token.name = "KT";
				token.location = value;
				Token.push_back(token);
			}
			else
			{
				value = InsertIT(strt);
				token.name = "IT";
				token.location = value;
				Token.push_back(token);
			}
		}

		else if (IfDigit(ch))           //������ͷ��
		{
			int e_n = 0, d_n = 0;
			while (IfDigit(ch) || ch == 'e' || ch == '.')//add error pending   -needing
			{
				if (ch == 'e')
				{
					if (e_n == 0)
						e_n = 1;
					else
					{
						cout << "�ʷ�����error��CT/RT" << endl;
						exit(0);
					}
				}
				if (ch == '.')
				{
					if (d_n == 0)
						d_n = 1;
					else
					{
						cout << "�ʷ�����error��CT/RT" << endl;
						exit(0);
					}
				}
				strt[i_str++] = ch;
				ch = line[i_line++];
			}
			constant((string)strt);
		}
		else if (ch == 34 || ch == 39)      //34="   39='
		{
			if (ch == 39)//�� 
			{

				ch = line[i_line++];
				strt[0] = ch;
				ch = line[i_line++];
				ch = line[i_line++];
				strt[1] = '\0';
				value = InsertcT(strt);
				token.name = "cT";
				token.location = value;
				Token.push_back(token);
			}
			else
			{
				ch = line[i_line++];
				while (IfLetter(ch))
				{
					strt[i_str++] = ch;       //ƴ�ӵ�strt��
					ch = line[i_line++];
				}
				ch = line[i_line++];
				strt[i_str] = '\0';
				value = InsertST(strt);
				token.name = "ST";
				token.location = value;
				Token.push_back(token);
			}
		}
		else
		{
			strt[i_str++] = ch;
			if (ch == ':')
			{
				ch = line[i_line];
				if (ch == '=')
				{
					strt[i_str++] = ch;
					i_line++;
				}
			}
			if (ch == '>')
			{
				ch = line[i_line];
				if (ch == '=')
				{
					strt[i_str++] = ch;
					i_line++;
				}
			}
			if (ch == '<')
			{
				ch = line[i_line];
				if (ch == '=')
				{
					strt[i_str++] = ch;
					i_line++;
				}
			}
			strt[i_str] = '\0';
			value = reserve2(strt);
			if (value)
			{
				token.name = "PT";
				token.location = value;
				Token.push_back(token);
			}
			else
			{
				cout << "�ʷ�����error��PT" << endl;
				exit(0);
			}
			ch = line[i_line++];
		}
	}
}


void LexAnalyser::lexAnalyse(string file_string) {
	//ifstream input_file(file_name);
	//string file_string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
	lexical(file_string);
}


void LexAnalyser::vall_print() {
	cout << "Activation Record:" << endl;
	stack<string> T;
	for (size_t i = 1; i < IT.size(); ++i) {
		T.push(IT[i]);
	}
	while (!T.empty()) {
		cout << T.top() << endl;
		T.pop();
	}
}