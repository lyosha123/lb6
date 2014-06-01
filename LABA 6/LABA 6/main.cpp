#include <iostream>
#include <vector>
#include <list>

using namespace std;

//class A

class Class_A
{
public:
	Class_A(void);
	virtual     ~Class_A(void);
	/// Pure virtual method
	virtual void             Show(void) = 0;
};
Class_A::Class_A(void)
{
}


Class_A::~Class_A(void)
{
}

//Class B

class Class_B :
	public Class_A
{
public:
	Class_B(void);
	~Class_B(void);
	/// Print Class name
	void            Show(void);
};
Class_B::Class_B(void)
{
}


Class_B::~Class_B(void)
{
}


void Class_B::Show(void)
{
	cout << "Class B" << endl;
}

//Class C

class Class_C :
	public Class_A
{
public:
	Class_C(void);
	~Class_C(void);
	/// Print Class name
	void           Show(void);
};

Class_C::Class_C(void)
{
}


Class_C::~Class_C(void)
{
}


void Class_C::Show(void)
{
	cout << "Class C" << endl;
}

//Class D

class Class_D :
	public Class_A
{
public:
	Class_D(void);
	~Class_D(void);
	/// Print Class name
	void             Show(void);
};

Class_D::Class_D(void)
{
}


Class_D::~Class_D(void)
{
}


void Class_D::Show(void)
{
	cout << "Class D" << endl;
}

//Class Factory

class Factory
{
public:
	Factory(void);
	~Factory(void);
	/// Create pointer to class B, C or D
	/// @param ID of created object's class
	/// ID = 1 => Class B
	/// ID = 3 => Class C
	/// ID = 3 => Class D
	Class_A*         Create(int ID);
};

Factory::Factory(void)
{
}


Factory::~Factory(void)
{
}


Class_A*   Factory::Create(int ID)
{
	switch (ID)
	{
	case  1:
		return new Class_B;
	case  2:
		return new Class_C;
	case  3:
		return new Class_D;
	default:
		return nullptr;
	}
}


//----------------------------------------------

int main()
{
	list<Class_A*> List;
	int repeat = 0;
	Class_A* elemet = nullptr;
	Factory fact;

	cout << "Enter 1 to create Class B object" << endl;
	cout << "Enter 2 to create Class C object" << endl;
	cout << "Enter 3 to create Class D object" << endl;
	cout << "Enter 0 to print list" << endl;

	do
	{
		cin >> repeat;
		elemet = fact.Create(repeat);
		if (elemet)
			List.push_back(elemet);
	} while (repeat != 0);


	while (!List.empty())
	{
		elemet = List.front();
		elemet->Show();
		delete elemet;
		List.pop_front();
		elemet = nullptr;
	}


	system("pause");
	return 0;
}