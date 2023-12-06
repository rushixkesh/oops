#include<iostream>

#include<stdlib.h>

using namespace std;


struct node{

char ssn[25],name[25],dept[10],designation[25], phone[10]; int sal;

struct node *llink;

struct node *rlink;

};

typedef struct node* NODE;


NODE first = NULL;

int count=0;


NODE create(){

NODE enode;

enode = (NODE)malloc(sizeof(struct node));

if(enode== NULL){

cout<<"\nRunning out of memory\n";

exit(0);

}

cout<<"\nEnter the ssn,Name,Department,Designation,Salary,PhoneNo of the employee:\n";

cin>>enode->ssn>>enode->name >>enode->dept>>enode->designation >>enode->sal

>>enode->phone;

enode->llink=NULL;

enode->rlink=NULL;

count++;

return enode;
}


NODE insertfront(){

NODE temp;

temp = create();

if(first == NULL){

return temp;

}

temp->rlink = first;

first->llink = temp;

return temp;

}


void display(){

NODE cur;

int nodeno=1;

cur = first;

if(cur == NULL)

cout<<"\n No Contents to display in DLL";

while(cur!=NULL){

cout<<"\nENode:" <<nodeno<<"||SSN:" <<cur->ssn<<"|Name:" <<cur->name <<"|Department:" <<cur->dept<<"|Designation:" <<cur->designation <<"|Salary:" <<cur->sal<<"|Phone no:" <<cur->phone; cur = cur->rlink;

nodeno++;

}

cout<< "\nNo of employee nodes is " <<count;

}
NODE deletefront(){

NODE temp;

if(first == NULL){

cout<<"\nDoubly Linked List is empty";

return NULL;

}

if(first->rlink== NULL){

cout<<"\nThe employee node with the ssn:" <<first->ssn<<"is deleted";

free(first);

count--;

return NULL;

}

temp = first;

first = first->rlink;

temp->rlink = NULL;

first->llink = NULL;

cout<<"\nThe employee node with the ssn:" <<temp->ssn<<"is deleted";

free(temp);

count--;

return first;

}	
NODE insertend(){	
NODE cur, temp;	
temp = create();	
if(first == NULL){	
return temp;	
}	
cur= first;	
while(cur->rlink!=NULL){	
cur = cur->rlink;	
}

cur->rlink = temp;

temp->llink = cur;

return first;

}	
NODE deleteend(){	
NODE prev,cur;	
if(first == NULL){	
cout<<"\nDoubly Linked List is empty";	
return NULL;	
}	
if(first->rlink == NULL){	
cout<< "\nThe employee node with the ssn:" <<first->ssn<<" is deleted";	
free(first);	
count--;	
return NULL;	
}	
prev=NULL;	
cur=first;	
while(cur->rlink!=NULL){	
prev=cur;	
cur = cur->rlink;	
}	
cur->llink = NULL;	
cout<<"\nThe employee node with the ssn:" <<cur->ssn<<"is deleted";	
free(cur);	
prev->rlink = NULL;	
count--;	
return first;	
}	

int main(){

int ch,i,n;

while(1){

cout<<"\n\n~~~Menu~~~";

cout<<"\n1:Create DLL of Employee Nodes";

cout<<"\n2:DisplayStatus";

cout<<"\n3:InsertAtEnd";

cout<<"\n4:DeleteAtEnd";

cout<<"\n5:InsertAtFront";

cout<<"\n6:DeleteAtFront";

cout<<"\n7:Exit \n";

cout<< "\nPlease enter your choice: ";

cin>>ch;


switch(ch){

case 1 :

cout<<"\nEnter the no of Employees:	";

cin>>n;

for(i=1;i<=n;i++)

first = insertend();

break;

case 2:

display();

break;

case 3:

first = insertend();	
break;	
case 4:	
first = deleteend();	
break;

case 5:

first = insertfront();

break;

case 6:

first = deletefront();

break;

case 7:

exit(0);

default:

cout<<"\nPlease Enter the valid choice";

}

}

}	
