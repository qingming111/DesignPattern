#include<string>
#include<iostream>
using namespace std;

class Product
{
public:
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

class Factory
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
