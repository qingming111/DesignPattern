/**
*命令模式：将请求封装成一个对象，从而使你可用不同的请求对客户进行参数化;对请求
×排队货记录请求日志，以及支持可撤销的操作。在OOP中，一切都是对象，将请求封装成
×对象，符合OOP的设计思想将客户的单个请求封装成对象以后，我们可以对这个请求存储
×更多的信息，让请求有更多的能力;命令模式同样能够把请求发送者和接收者解藕，使得
×命令发送者不用关心将以何种方式被处理。
*/

#include<iostream>
#include<vector>
using namespace std;

class Cook  //reciver
{
public:
	void chicken() { cout << "师傅做烤鸡肉"<< endl;}
	void mutton() { cout << "烤羊肉" << endl; }	
};

class Command
{
public:
	Command(Cook *com) : reciver(com) {}
	virtual void execute() = 0; 
protected:
	Cook *reciver;
};

class Makechicken : public Command
{
public:
	Makechicken(Cook *com) : Command(com) {}
	void execute()
	{
		reciver->chicken();	
	}	
};

class Makemutton : public Command
{
public:
	Makemutton(Cook *com) : Command(com) {}
	void execute()
	{
		reciver->mutton();
	}
	
};

class Waiter 
{
public:
	void SetCom(Command *com)
	{
		ComList.push_back(com);	
	}
	void Notify()
	{
		for(int i = 0; i < ComList.size(); ++i)
			ComList[i]->execute();
	}
private:
	vector<Command *> ComList;
};


