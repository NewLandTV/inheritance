#include <iostream>
#include <cstring>

class Person
{
private:
	char* name;
	int age;
	
public:
	Person(const char* _name, int _age) : age(_age)
	{
		name = new char[strlen(_name) + 1];
		
		strcpy(name, _name);
		
		std::cout << "Person()" << std::endl;
	}
	
	void PrintName()
	{
		std::cout << name << std::endl;
	}
	
	void PrintAge()
	{
		std::cout << age << std::endl;
	}
	
	void PrintAll()
	{
		PrintName();
		PrintAge();
		
		std::cout << std::endl;
	}
	
	void SetName(const char* newName)
	{
		name = new char[strlen(newName) + 1];
		
		strcpy(name, newName);
		
		std::cout << "Changed Name." << std::endl;
	}
	
	void IncrementAge()
	{
		age++;
		
		std::cout << "Incremented Age." << std::endl;
	}
	
	~Person()
	{
		delete []name;
		
		std::cout << "~Person()" << std::endl;
	}
};

class Student : public Person
{
private:
	int studentNum;
	int grade;
	int ban;	// 반
	
public:
	Student(const char* _name, int _age, int _studentNum, int _grade, int _ban) : Person(_name, _age), studentNum(_studentNum), grade(_grade), ban(_ban)
	{
		std::cout << "Student()" << std::endl;
	}
	
	void PrintStudentNum()
	{
		std::cout << studentNum << std::endl;
	}
	
	void PrintGrade()
	{
		std::cout << grade << std::endl;
	}
	
	void PrintBan()
	{
		std::cout << ban << std::endl;
	}
	
	void PrintStudentAll()
	{
		PrintAll();
		PrintStudentNum();
		PrintGrade();
		PrintBan();
		
		std::cout << std::endl;
	}
};

void PrintPtrPerson(Person* p)
{
	p->PrintAge();
	p->PrintName();
	p->PrintAll();
	p->SetName(">");
	p->IncrementAge();
	p->PrintAll();
}

int main()
{
	Person p1("장경혁", 14);
	Student s1("Kim", 9, 1, 2, 3);
	
	Person* ptrP1 = new Person("릐도르", 26);	
	
	PrintPtrPerson(ptrP1);
	
	p1.PrintAge();
	p1.PrintName();
	p1.IncrementAge();
	p1.PrintAll();
	
	s1.PrintAge();
	s1.PrintName();
	s1.SetName("Hello");
	s1.PrintAll();
	s1.SetName("Kim@@");
	s1.PrintStudentAll();
	s1.PrintBan();
	s1.PrintGrade();
	s1.PrintStudentNum();
	
	delete ptrP1;
	
	std::cout << "End of Main Function" << std::endl;
	
	return 0;
}
