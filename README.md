#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class Fruit
{
public:
	virtual void sayName()
	{
		cout << "Fruit" << endl;
	}
};
class FruitFactory
{
public:
	virtual Fruit *getBanana()
	{
		cout << "FruitFactory:getBanana " << endl;
		return NULL;
	}
	virtual Fruit *getApple()
	{
		cout << "FruitFactory:getApple " << endl;
		return NULL;
	}
};
class NorthApple:public Fruit
{
public:
	virtual void sayName()
	{
		cout << "NorthApple" << endl;
	}
};
class NorthBanana :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "NorthBanana" << endl;
	}
};
class SouthApple :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "SouthApple" << endl;
	}
};
class SouthBanana :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "SouthBanana" << endl;
	}
};
class NorthFactory :public FruitFactory
{
public:
	virtual Fruit *getBanana()
	{
		return new NorthBanana;
	}
	virtual Fruit *getApple()
	{
		return new NorthApple;
	}
};
int main(void)
{	
	
	cout<<"hello word!"<<endl;
	return 0;
}
