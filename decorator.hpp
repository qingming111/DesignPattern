#include<iostream>
using namespace std;

//装饰模式：动态的给对象添加一些职责

class Product
{
public:
	Product() {}
	virtual ~Product() {}
	virtual void operation() = 0;
};

class ProductA : public Product
{
public:
	ProductA() {}	
	~ProductA() {}
	void operation() { cout << "producta " << endl;}
};

class ProductB : public Product
{
public:
	ProductB() {}
	~ProductB() {}
	void operation() { cout << "productb" << endl; }
};

class Decorator : public Product
{
public:
	Decorator(Product* p) : product(p){}
	~Decorator() { }
	virtual void operation() 
	{
		product->operation();			
	}
private:
	Product *product;
};

class DecoratorA : public Decorator
{
public:
	DecoratorA(Product *p) : Decorator(p) {}
	void operation()
	{
		Decorator::operation();
		Addoperation();
	}
	void Addoperation()
	{ cout << "add " << endl;}
};

