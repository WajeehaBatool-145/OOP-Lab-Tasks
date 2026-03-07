#include <iostream>
#include <string>
using namespace std;
struct student
{
	//data members
	string first_name;
	string last_name;
	int marks;
	//member function
	void DisplayStudentInfo()
	{
	cout<<"\nName:"<<first_name<<" "<<last_name<<endl;
	cout<<"Marks:"<<marks;
	}
};
int main()
{
	student s[3];
	student *sPtr=s;
	for(int i=0; i<3;i++)
	{
	cout<<"Enter 1st name: ";
	cin>>(sPtr+i)->first_name;
	cout<<"Enter last name: ";
	cin>>(sPtr+i)->last_name;
	cout<<"Enter marks: ";
	cin>>(sPtr+i)->marks;
    }
    cout<<"DETAILS"<<endl;
    for(int i=0;i<3;i++)
    {
    cout<<"\nStudent "<<i+1<<":";
	(sPtr+i)->DisplayStudentInfo();	
	}
	return 0;
}
