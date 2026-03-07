#include <iostream>

using namespace std; 
struct student
{
	string first_name;
	string last_name;
	int marks;
	//member function
	void DisplayStudentInfo()
	{
		cout<<"Name:"<<first_name<<" "<<last_name<<endl;
		cout<<"Marks:"<<marks;
	}
};
int main()
{
	student s[3];
	for(int i=0;i<3;i++)
	{
		//Entering data 
		cout<<"Enter first name of student: ";
		cin>>s[i].first_name;
		cout<<"Enter last name of student: ";
		cin>>s[i].last_name;
		cout<<"Enter Marks:";
		cin>>s[i].marks;
	}
	cout<<"Students data";
	for(int i=0;i<3;i++)
	{
		cout<<"\n";
		cout<<"Student "<<i+1<<":"<<endl;
		s[i].DisplayStudentInfo();
		
	}
	return 0;
}
