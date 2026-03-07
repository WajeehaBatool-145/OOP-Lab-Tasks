#include <iostream>
using namespace std;
struct student
{
	//data members
	string first_name;
	string last_name;
	int roll_no;
	int marks;
	//member function
	student displayStudentInfo()
	{
		cout<<"Name: "<<first_name<<" "<<last_name<<endl;
		cout<<"Marks: "<<marks;
	}
};
int main()
{
	student s1;
	
	s1.first_name="Wajeeha";
	s1.last_name="Batool";
	s1.marks=39;
	s1.displayStudentInfo();
	
	
	
	
	return 0;
}
