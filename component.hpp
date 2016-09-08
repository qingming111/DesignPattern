/*
*组合模式：将对象组合成树形结构来表现“整体/部分”层次结构。组合能让客户
×以一致的方式处理对象以及对象组合
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Company
{
public:
	Company(string name) : ID(name) {}
	virtual ~Company() {}
	virtual void add(Company *com) {}
	virtual void show(int depth) {} 

protected:
	string ID;
};

class ConcreteCompany : public Company
{
public:
	ConcreteCompany(string name) : Company(name) {}
	~ConcreteCompany() {}
	void add(Company *com) { ComLists.push_back(com); }
	void show(int depth)
	{
		for(int i = 0; i < depth; ++i)
			cout << "-";
		cout << ID << endl;
		vector<Company *>::iterator it = ComLists.begin();
		for(; it != ComLists.end(); ++it)
			(*it)->show(depth + 2);
	}
private:
	vector<Company *> ComLists;
};


class Finace : public Company
{
public:
	Finace(string name) : Company(name) {}
	~Finace() {}
	void show(int depth)
	{
		for(int i = 0; i < depth; ++i)
			cout << "-";
		cout << ID << endl;
	}
};


