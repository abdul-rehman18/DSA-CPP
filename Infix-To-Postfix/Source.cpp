#include"myStack.h"

int main()
{
    myStack<char> s1(100);
    cout<<"*****************************Default Value Test Cases*****************************"<<endl;
    s1.post("((12 + 13) * (20 - 30)) / (811 + 99)");
    cout<<endl;
    s1.post("(a + (b * c) ) + d");
    cout<<endl;
    cout<<"=================================================="<<endl;
    char arr[100];
    cout<<"*****************************User Defined Value Test Case*****************************"<<endl;
    cout<<"Enter Expression to evaluate with round brackets : "<<endl;
	cin.getline(arr,100);
    cout<<endl;
    s1.post(arr);
    cout<<endl;
    
    //s1.display();
    return 0;
}