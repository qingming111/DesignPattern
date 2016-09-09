/**
*观察者模式:定义对象件的一种一对多的依赖关系，当一个对象的状态发生改变时，所有
×的依赖于它的对象得到通知并被自动更新。当一个对象发生了变化，关注它的对象就会
×通知。
*/

#include<iostream>
#include<list>

using namespace std;

class Observer
{
public:
	virtual ~Observer() {}
	virtual void getstate() = 0;
	virtual void Update(int) = 0;
};

class Subject
{
public:
	virtual void Attach(Observer *) = 0;
	virtual void Detach(Observer *) = 0;
	virtual int get_state() = 0;
	virtual void Notify() = 0;
};

class ConcreteObserver : public Observer
{
public:
	ConcreteObserver(Subject *pSubject) : m_psubject(pSubject) {}
	void Update(int value)
	{
		cout << "new state" << value << endl;
	}
	void getstate()
	{
		cout << m_psubject->get_state()	<< endl;
	}
private:
	Subject *m_psubject;
};

class ConcreteSubject : public Subject
{
public:	
	int get_state() { return state; }
	void set_state(int s) { state = s; }
	void Attach(Observer *pObserver)
	{
		m_ObserverList.push_back(pObserver);	
	}
	void Detach(Observer *pObserver)
	{
		m_ObserverList.remove(pObserver);
	}
	void Notify()
	{
		list<Observer *>::iterator it = m_ObserverList.begin();
		for(; it != m_ObserverList.end(); ++it)
		{
			(*it)->Update(state);
		}		
	}
	
private:
	list<Observer *> m_ObserverList;
	int state;
};

