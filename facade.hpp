/**
*外观模式：当一个系统很复杂，系统提供给客户一个简单的对外接口，把里面的复杂结构
×都封装了起来。为子系统的一组接口提供哦你嗯一个一致的界面，外观模式定义了一个高层
×接口
*/
#include<iostream>
using namespace std;

class Scanner
{
public:
	void Scan() { cout << "scan" << endl; } 
};

class Parser
{
public:
	void Parse() { cout << "parse" << endl;}
};

class GenMidCode
{
public:
	void GenCode() { cout << "code" << endl; }
};

class Complier //高层接口
{
public:
	void run()
	{
		Scanner scan;
		Parser parse;
		GenMidCode gen;
		scan.Scan();	
		parse.Parse();
		gen.GenCode();
	}
};

