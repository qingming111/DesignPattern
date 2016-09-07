#include<iostream>
using namespace std;


//桥接模式：抽象部分和实现分离 如手机品牌多种多样而手机的应用也是成千上万，此时就有了手机应用商店的概念，手机应用商店就相当一个桥梁的作用，把手机应用和手机品牌联系在了一起

class OS
{
public:
	OS() {}
	virtual ~OS() { }
	virtual void OSimp() = 0;
};

class Linux : public OS
{
public:
	Linux() {}
	~Linux() {}
	void OSimp() { cout << "linus" << endl;}	
};

class Mac : public OS
{
public:
	Mac() {}
	~Mac() {}
	void OSimp() { cout << "mac" << endl; }
};

class Computer
{
public:
	
	virtual void installos(OS *os) = 0;


};

class Apple : public Computer
{
public:
	void installos(OS* os) { os->OSimp(); }
};

class Dell : public Computer
{
public: 
	void installos(OS* os) { os->OSimp(); }
};

