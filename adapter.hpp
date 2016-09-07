#include <iostream>
using namespace std;

class Target
{
public:
	Target() { }
	virtual ~Target() {}
	virtual void request() { cout << "hello, this is target" << endl; }
};

class Adaptee
{
public:
	Adaptee() {}
	~Adaptee() { }
	void special() { cout << "this is adater" << endl; }
}; 

class Adapter : public Target, private Adaptee
{
public:	
	void request() { 
		special();
	}
};


class Adapter1 : public Target
{
public: 
	Adapter1() : adptee(new Adaptee()) {}
	Adapter1(Adaptee *p) : adptee(p) {}
	~Adapter1() {
		if(adptee != NULL)
		{
			delete adptee;
		}
	}
	void request()
	{ adptee->special(); }
private:
	Adaptee *adptee;
};

