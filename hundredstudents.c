#include<stdio.h>
#include<string.h>
void addStudent();
void deleteStudent();
void listOfStudent();
void editStudent();
void displayListOfStudent();
void searchStudent();
int rollNumber[100];
char name[100][22];
int numberOfRecordsAdded;

int main()
{
int ch;
numberOfRecordsAdded=0;

while(1)
{
printf("1. Add  Student\n");
printf("2. Edit student\n");
printf("3. delete student\n");
printf("4. Search student\n");
printf("5. Display list of students\n");
printf("6. Exit\n");
scanf("%d",&ch);
fflush(stdin);

if(ch<1||ch>6)
{
printf("Invalid Input\n");
}
else
{
if(ch==1)
{
if(numberOfRecordsAdded==100)
{
printf("only 100 students can be added you cannot add more\n");
}
else
{
addStudent();
}
}
if(ch>=2&&ch<=5)
{
if(numberOfRecordsAdded==0)
{
printf("you have not yet added any student\n");
}
else
{
if(ch==2)editStudent();
if(ch==3)deleteStudent();
if(ch==4)searchStudent();
if(ch==5)displayListOfStudent();
}
}
if(ch==6)break;
}
}
return 0;
}

void addStudent()
{
int k,e;

printf("Add Modole\n");
printf("Entre roll number");
scanf("%d",&k);
fflush(stdin);

if(k<=0)
{
printf("Invalid Roll Number\n");
return;
}

e=0;

while(e<numberOfRecordsAdded)
{
if(rollNumber[e]==k)
{
printf("that roll num is alloted to %s",name[e]);
return;
}
e++;
}
rollNumber[numberOfRecordsAdded]=k;

printf("Enter Name:");

fgets(name[numberOfRecordsAdded],22,stdin);
fflush(stdin);
name[numberOfRecordsAdded][strlen(name[numberOfRecordsAdded])-1]='\0';

numberOfRecordsAdded++;
printf("Student Added\n");
}

void displayListOfStudent()
{
int f;

for(f=0;f<numberOfRecordsAdded;f++)
{
printf("Roll Number: %d,Name:%s\n",rollNumber[f],name[f]);
}
}

void searchStudent()
{
int found,k,e;
printf("enter roll number");
scanf("%d",&k);
if(k<=0)
{
printf("invalid roll number");
}
e=0;
found=0;
while(e<=numberOfRecordsAdded)
{
if(rollNumber[e]==k)
{
found++;
break;
}
e++;
}

if(found==0)
{
printf("Invalid Rollnumber");
}
else
{
printf("name : %s\n",name[e]);
}
}
void editStudent()
{
int found,k,e;
int m;
printf("enter roll number");
scanf("%d",&k);
if(k<=0)
{
printf("invalid roll number");
}
e=0;
found=0;
while(e<=numberOfRecordsAdded)
{
if(rollNumber[e]==k)
{
found++;
break;
}
e++;
}

if(found==0)
{
printf("Invalid Rollnumber\n");
return;
}
else
{
printf("Name %s\n",name[e]);
}

printf("Edit Name(1/0)\n");
scanf("%d",&m);


if(m==0)
{
printf("Record Not Edited\n");
return;
}
else
{
printf("Enter New Name\n");
fgets(name[e],22,stdin);
fflush(stdin);
name[e][strlen(name[e])-1]='\0';

printf("Record Updated\n");

}



}

void deleteStudent()
{}


