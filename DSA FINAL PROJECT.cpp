#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
fstream myfile,myfile1;
string s[100];
struct books
{
 //parts of a node.
 string name,authur;
 int id;
 books *link;

};
struct books *start=NULL;
struct books *temp,*cur;

struct person
{
 
 string name1,namebook;
 int id1;
 person *next1;
 
};
struct person *start1=NULL;
struct person *tail1;
struct person *temp1;

 creat_file (string n,string a,int i)
 {
  //create 1st node...
   if(start==NULL)
   {
    start=new books;
    start->link=NULL;
    start->name=n;
    start->authur=a;
    start->id=i;
    myfile.open ("books library.txt",ios::out | ios::app);
	myfile<<"Name_:"<<start->name<<"|Authur:"<<start->authur<<"_|ID:_"<<start->id<<endl;
	myfile.close();
   }
   //to create new node..
   else
   {
    cur=start;
    while(cur->link!=NULL)
    {
     cur=cur->link;
    }
    temp=new books;
    temp->name=n;
	temp->authur=a;
    temp->id=i;
    temp->link=NULL;
    cur->link=temp;
   myfile.open ("books library.txt",ios::out | ios::app);
	myfile<<"Name_:"<<temp->name<<"|Authur:"<<temp->authur<<"_|_ID:_"<<temp->id<<endl;
	myfile.close();
   }
 
    }
 
    //print data of the linklist.
    void print_now()
    {
     cur=start;
     int c;
     if(start==NULL)
     {
     	cout<<"no books added now.\n";
     	
	 }
	 else
	 {
	 	while(cur!=NULL)
	 	{
	 		cout<<cur->name<<" *** "<<cur->authur<<" *** "<<cur->id<<endl;
	 		cur=cur->link;
		 }
	 }
 }

  void search(string n)
 {
 	struct books *q=start;
 	if(start==NULL){
 		cout<<"no books in the library.\n";
 		
	 }
	 else
	 {
	 	while(q->name!=n && q->link!=NULL)
	 	{
	 		q=q->link;
		 }
	 }
	 if(q->name==n)
	 {
	 	cout<<"book is present in the library.\n";
	 	
	 }
	 else{
	 	cout<<"book not found.\n";
	 }
}

 void print()
 {
 	//this function reads the data from file
 	myfile.open("books library.txt",ios::in);
 	int i=0;
 	while(!(myfile.eof()))
 	{
 		myfile>>s[i];
 		cout<<s[i]<<endl;
 		i++;
	 }
	 myfile.close();
 }
 void issuebook(string n1,int i1,string name1)
 {

	   if(start1==NULL)
   {
   start1=new person;
    start1->next1=NULL;
    start1->name1=name1;
    start1->namebook=n1;
    start1->id1=i1;
   myfile1.open ("records.txt",ios::out | ios::app);
	myfile1<<"Name_:"<<start1->name1<<"|book name :"<<start1->namebook<<"_|Id:_"<<start1->id1<<endl;
myfile1.close();
   }
   //to create new node..
   else
   {
    tail1=start1;
    while(tail1->next1!=NULL)
    {
     tail1=tail1->next1;
    }
      temp1=new person;
    temp1->name1=name1;
	temp1->namebook=n1;
    temp1->id1=i1;
     temp1->next1=NULL;
    tail1->next1=temp1;
   myfile1.open ("records.txt",ios::out | ios::app);
	myfile1<<"Name_:"<<temp1->name1<<"|book name :"<<temp1->namebook<<"_|Id:_"<<temp1->id1<<endl;
myfile1.close();
   }
 	
 }

int main()
{
 int nooffiles,i,p,ch,k,j,opt,y,Y,idd;
 string n,an,t,n1,name1;
 int i1;
 char filename [] = "C:\\Users\\ali\\OneDrive\\Desktop\\records.txt"; 
 int result;
 cout<<"\n\t===================================================================\n\n";
 cout<<"\t\t\t LIBRARY MANAGEMENT SYSTEM\n";
 cout<<"\n\t===================================================================\n\n";
 cout<<"\n\t===================================================================\n\n";
 cout<<"\n\t1- CAN ENTER NEW BOOK\n";
 cout<<"\n\t2- CAN SEARCH FOR THE  BOOKS \n";
 cout<<"\n\t3- WHEN A BOOK IS BROUGHT,,, YOU CAN DELETE IT FROM YOUR LIBRARY\n";
 cout<<"\n\t4- CAN SEE ALL THE LIST ANY TIME\n";
 cout<<"\n\t5- YOU CAN SEARCH ANY BOOK ONLINE\n";
  cout<<"\n\t5-keep persons record and delete record file\n";
 cout<<"\n\t===================================================================\n\n";
 cout<<"\n\t========================SAVE BOOKS===============================\n"<<endl;
 cout<<"press 1 if you want to perform any operation\n";
 cin>>opt;
if(opt==1)
 
{
		system("CLS");
 do
 {
 cout<<"\n\nWhat You want to do with your Books now"<<endl;
 cout<<"\n1-Save new Book\n";
 cout<<"2-Delete any book"<<endl;
 cout<<"3-Search "<<endl;
 cout<<"4-See All list"<<endl;
cout<<"5-Read online books "<<endl;
cout<<"6-issue a book "<<endl;
cout<<"7-delete record file of people who issued the book "<<endl;
cout<<"8-Exit\n"<<endl;
 
 cin>>ch;
 	system("CLS");
 switch(ch)
 {
  case 1:
   cout<<"\n\t============================ADD NEW BOOK============================\n\n";
   cout<<"Enter Book Data to insert in your library"<<endl;
 
  cout<<"Enter Name \n";
  cin>>n;
  cout<<"Enter Authur name \n";
  cin>>an;
 // cout<<"Enter Type \n";
//  cin>>t;
cout<<"Enter Book id \n";
  cin>>idd;
  creat_file(n,an,idd);

   cout<<"Book "<<n<<" has been Saved in your Library "<<endl;
   break;
  case 2:
   cout<<"\n\t=========================DELETE Book============================\n\n";
 
 	myfile.open("books library.txt",ios::in);
 	  k=0;
 	int del;
 	while(myfile.good())
 	{
 		myfile>>s[k];
 		cout<<k+1<<"-"<<s[k]<<endl;
 		k++;
	 }
	 myfile.close();
	 cout<<"Which Book data you want to delete ..? ";
	 cin>>del;
	 s[del-1]="";
 
	 cout<<"\nBook record has been deleted "<<endl;
	 myfile.open("books library.txt",ios::out);
	 for(  j=0;j<=k;j++)
	 myfile<<s[j]<<endl;
	 myfile<<endl;
	 myfile.close();
     break;
   case 3:
   	cout<<"\n\t===============SEARCH BOOK=====================\n\n";
   	cout<<"Enter NAME of Book to search it from Library\t";
   	cin>>n;
   	search(n);
   	break;
	case 4:
	cout<<"\n\t=====================PRINTING ALL LIST============================\n\n";
   	print();
   	break;
   	case 5:
   	cout<<"\n\t=====================SEARCH BOOK ONLINE============================\n\n";
   system("cmd/c start https://books.google.com/");
   		break;
   	case 6:
   	cout<<"\n\t=====================ISSUE A BOOK============================\n\n";
   		 int k;
 		myfile.open("books library.txt",ios::in);
 	  k=0;
 
 	while(myfile.good())
 	{
 		myfile>>s[k];
 		cout<<s[k]<<endl;
 		k++;
	 }
   		 cout<<"enter book name that you want to issue.\n";
	 cin>>n1;
	 cout<<"enter your CNIC.\n ";
	 cin>>i1;
	 cout<<"enter your name.\n";
	 cin>>name1;
	   issuebook(n1,i1,name1)	;
	   break;
	case 7:
	 	cout<<"\n\t=====================DELETE FILE============================\n\n";
	
  // deletes the file if it exists
   result = remove(filename);

  // check if file has been deleted successfully
  if (result != 0) {
    // print error message
    cout << "File deletion failed";
  }
  else {
    cout << "File deleted successfully";
  }
	
  break;
	   
  case 8:
   cout<<"\n\t====================LIST OF Books added Now======================\n\n";
   print_now();
   break;
  default:
   cout<<"\t----------Invalid----------"<<endl;
 }
}
 while(ch>0 && ch<8);
 cout<<"\nTHANK YOU"<<endl;
 getch();
 }
 else
 {
 	cout<<"invalid";
 }
}
