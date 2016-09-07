#include<iostream>
using namespace std;

class Weapon
{
public:
	virtual ~Weapon() {}
	virtual void useweapon() = 0;
};


class Knife : public Weapon
{
public:
	~Knife() {}
	void useweapon() { cout << "weapon knife " << endl; }
};

class Gun : public Weapon
{
public:
	~Gun() {}
	void useweapon() { cout << "weapon gun" << endl; }
};

class Character
{
public:
	Character(Weapon *p) : weapon(p) {}
	~Character()
	{
		delete weapon;
	}
	void excute()
	{
		weapon->useweapon();
	}
private:
	Weapon *weapon;	
};

