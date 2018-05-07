#include <iostream>
#include <string>

using namespace std;

class CPerson
{
public:
	CPerson(const string& name,const int age):name_(name), age_(age) 
	{
		cout << "I sozdal'" << endl;
	}
	CPerson(const CPerson& other):name_(other.name_),age_(other.age_)
	{
		if(this==&other)
		{
			cout << "Seriosly?" << endl;
		}
		cout << "Cntl+C\nCntrl+V" << endl;
		
	}
	string name() const // const - не меняет состояние объекта
	{
		return name_;
	}
	int age() const
	{
		return age_;
	}
	virtual void Hello() const
	{
		cout << "Hello from " << name_ << endl;
	}
	virtual ~CPerson()
	{
		cout << "I want to delete" << endl;
	}
	
protected:
	string name_;
	int age_;
};


class CStudent : public CPerson
{
public:
	CStudent(const string& name, int age, const string& university, int group):CPerson(name,age), university_(university), group_(group)
	{
		cout << "Student made" << endl;
	}
	CStudent(const CPerson& Person, const string& university, int group):CPerson(Person),university_(university), group_(group)
	{
		cout << "Student made" << endl;
	}
     void Hello() const override
	{
		cout << "Hello from " << name_<<" I'm from "<< university_ << endl;
	}
	~CStudent()
	{
		cout << "Student killed" << endl;
	}
private:
	
	string university_;
	int group_;

};
void SayHello(const CPerson& person)
{
	person.Hello();
}

class CEmployee :public CPerson
{
public:
	CEmployee(const string& name, int age, const string& company, unsigned int salary):CPerson(name,age),company_(company),salary_(salary)
	{
		
	}
	void Hello() const override
	{
		cout << "Hello from " << name_ << " I'm from " << company_ << endl;
	}
	~CEmployee()
	{
		cout << name_ << " fired!" << endl;
	}
	
private:
	string company_;
	unsigned int salary_;
};

/*int main()
{
	string name = "Sanechka";
	CPerson person(name, 18);
	cout << "Name: " << person.name() << "\nAge: " << person.age() << endl;
	person.Hello();
	SayHello(person);
	CStudent stud1(person, "ITMO", 3107);
	CStudent stud2(name, 18, "ITMO", 3107);
	stud1.Hello();
	SayHello(stud2);
	cout << stud1.name() << endl;
	CEmployee empl(name, 18, "Yandex", 100000);
	empl.Hello();
	SayHello(empl);
	/*CPerson * arr[] = { &stud1, &stud2,new CEmployee(name, 18, "Yandex", 100000) };
	for(int i=0;i<3;i++)
	{
		arr[i]->Hello();
	}
	delete[] arr;
	CPerson* pers= new CStudent(person, "ITMO", 3107);
	pers->Hello();
	delete pers;
	system("pause");
	return 0;
}*/