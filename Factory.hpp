#include<string>
#include<iostream>
using namespace std;




class Product
{
public:
	virtual ~Product() = 0;
	virtual void use() = 0;
};

class ProductA : public Product
{
public:
	void use() { cout << "producta" << endl; }

};

class ProductB : public Product
{
public:
	void use() { cout << "productb" << endl; }

};

class simpleFactory
{
public:
	Product* createProduct(const string &s)
	{
		if(s == "A")
			return new ProductA();
		else if(s == "B")
			return new ProductB();
		else
			return NULL;
	}
};

//工厂方法模式,如果增加新产品，就需要修改简单工厂模式的工厂类，违反了开放封闭原则


class Factory
{
public:
	virtual ~Factory() = 0;
	virtual Product* createProduct() = 0;

};

class FactoryA : public Factory
{
public:
	Product* createProduct()
	{
		return new ProductA();
	}

};

class FactoryB : public Factory
{
public:
	Product* createProduct()
	{
		return new ProductB();
	}

};

//抽象工厂模式



class AbstractFactory
{
public:
	virtual Product1* createProduct() = 0;
	virtual Product2* createProduct() = 0;

};



