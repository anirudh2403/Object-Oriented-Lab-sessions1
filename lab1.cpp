#include<iostream>

using namespace std;
int n = 0; // keeps track of how many students are there in the database
int index,sub; // global variables that the functions are sharing


int SetStudRec();
int GetIndStudRec(int index);
int GetAllStudRec();
int GetAvgMarks(int sub);
int findst(int roll); // given the roll number iot returns the index of the student structure




// structure that holds the template in which the data of the students is stored
struct stdrec{
    char firstname[20];
    char lastname[20];
    int rollno;
    int grade[5];


    } student[50]; // Defining the limit of the the number of students of which the data can be stired

int main()
{
    int choice; // the choice of the switch case
    int out = 1; // flag variable to exit the loop
while(out){
    cout<<"PRESS 1:  To Set the details of a student  \n" ;
    cout<<"PRESS 2:  To get the details of an individual student  \n" ;
    cout<<"PRESS 3:  get the details of all the students  \n" ;
    cout<<"PRESS 4:  get the average marks of a given subject  \n";
    cout<<"PRESS -1 : to exit";
    cout<<"\n";
    cin >> choice;

    switch(choice)
    {
        case 1 : SetStudRec();

                 break;
        case 2  :
                cout<<"Enter student rollno. UG2013";
                cin>>index;

                GetIndStudRec(findst(index));
                break;

        case 3  : GetAllStudRec();
                break;
        case 4  :
                    cout<<"Enter subject you want the avg marks of ";
                    cin>> sub;
                    GetAvgMarks(sub);

                break;
        case -1:

                out = 0;
    }
}
}
// asks the student for all the things that need to be stored
int SetStudRec() {

    int i;

    cout<< "ENTER THE DETAILS OF STUDENT"<< n+1<<"\n";

    cout<<"Enter First Name ";
    cin >> student[n].firstname ;
    cout<<"\n";

     cout<<"Enter Last Name ";
    cin >> student[n].lastname ;
    cout<<"\n";

     cout<<"Enter roll number UG2013";
    cin >> student[n].rollno ;

    if( student[n].rollno < 10000 || student[n].rollno > 14999){
        cout<<"incorrect roolno, input again \n";
         cout<<"Enter roll number UG2013";
    cin >> student[n].rollno ;
    }
    if(findst(student[n].rollno) != -1) // findst() returns -1 if the roll no is not already in the database
    {
        cout<<"Roll number already exists in database, Enter again";
        cout<<"Enter roll number UG2013";
        cin >> student[n].rollno ;
    }
    cout << "\n";

    //storing the grades for individual subjects
    for (i=0;i<5;i++){
        cout<<"Enter grades of subject "<<i+1<<"  ";
        cin >> student[n].grade[i] ;
        cout<<"\n";

    }
    n+=1;

    }

//gets the index returned from findst()
int GetIndStudRec(int index){
    int i;
        if(index == -1)
         {   cout<<"Incorrect rollno\n";
            return -1;}

    cout<< student[index].firstname <<" "<<student[index].lastname<<" \n";
    cout<< "UG2013"<<student[index].rollno  <<" \n";
    for(i=0;i<5;i++){
        cout<<"Grade of subject"<<i<<"is"<<student[index].grade[i]<<"\n";
    }

cout<<"\n\n";


}
// runs the GetIndStudRec() function for all the students

int GetAllStudRec(){

    int i;

    for (i=0;i<n;i++){
        GetIndStudRec(i);
    }

}
// returns avg marks for the subject chosen by the student
int GetAvgMarks(int sub)
{
    int i,temp;
    for (i=0;i<n;i++)
    {
        temp += student[i].grade[sub];

    }
    temp = temp/5;
    cout<<"The Average for subject "<<sub<<" is "<<temp<<"\n\n";





}
//finds the rollno in the database and returns the index of the corresponding student

int findst(int roll)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(student[i].rollno == roll)
            return i;
    }

    return -1;

}


