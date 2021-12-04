#include<stdio.h>
#include<stdlib.h>
typedef struct patient
{
	int id;
	int wardno;
	char firstname[100];
	char lastname[100];
	char gender[50];
	int age;
	char bg[20];
	char city[50];
	long int mobile;
	char email[50];
	char problem[50];
	char doctor[50];
}patient;
patient* Patient;
int count=0;
int size;
void add();
void display();
void search();
void edit();
void destroy();
void main()
{
	int choice;
	printf("\nEnter total number of patients you want to add in record system :");
	scanf("%d",&size);
	Patient=(patient*) malloc(sizeof(patient)*size);
    do
	{
		printf("\n1.Add patients record\n2.List patients record\n3.Search patients record\n4.Edit patients record\n5.Delete patients record\n6.Exit");
		printf("\nEnter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				add();
				break;
			case 2:
				display();
				break;
			case 3:
				search();
				break;
			case 4:
				edit();
				break;
			case 5:
				destroy();
				break;
			case 6:
				exit(0);
			default :
				printf("Invalid Choice");
				break;
			
		}
	}while(1);
}
void add()
{
        printf("Enter Id, Ward number,first Name,last Name,gender,age,blood group,city,mobile number,email,problem,prescribed doctor of patient :");
		scanf("%d%d%s%s%s%d%s%s%ld%s%s%s",&Patient[count].id,&Patient[count].wardno,&Patient[count].firstname,&Patient[count].lastname,&Patient[count].gender,&Patient[count].age,&Patient[count].bg,&Patient[count].city,&Patient[count].mobile,&Patient[count].email,&Patient[count].problem,&Patient[count].doctor);
		count++;
}
void display()
{
	int i;
	printf("Entered information is :\n");
	for(i=0;i<count;i++)
	{
		printf("Id = %d",Patient[i].id);
		printf("\t Ward No = %d",Patient[i].wardno);
		printf("\t First Name = %s",&Patient[i].firstname);
		printf("\t Last Name = %s",&Patient[i].lastname);
		printf("\t Gender = %s",&Patient[i].gender);
		printf("\t Age = %d",Patient[i].age);
		printf("\t Blood Group = %s",&Patient[i].bg);
		printf("\t City = %s",&Patient[i].city);
		printf("\t Mobile Number = %ld",Patient[i].mobile);
		printf("\t Email Id = %s",&Patient[i].email);
		printf("\t Problem = %s",&Patient[i].problem);
		printf("\t Doctor = %s\n",&Patient[i].doctor);
		printf("-------------------------------------------------\n");
	}
	
}
void search()
{
	int i,found=0;
	char find1[20];
	char find2[20];
	printf("Enter first name of patient you want to search :");
	scanf("%s",&find1);
	printf("Enter last name of patient you want to search :");
	scanf("%s",&find2);
	for(i=0;i<count;i++)
	{
		if(strcmp(find1,Patient[i].firstname)==0 && strcmp(find2,Patient[i].lastname)==0)
		{
			found=1;
			printf("\nThe patient you searched exists in Hospital,Here are details of the patient\n");
			printf("Id = %d",Patient[i].id);
		    printf("\t Ward No = %d",Patient[i].wardno);
		    printf("\t First Name = %s",&Patient[i].firstname);
		    printf("\t Last Name = %s",&Patient[i].lastname);
		    printf("\t Gender = %s",&Patient[i].gender);
		    printf("\t Age = %d",Patient[i].age);
		    printf("\t Blood Group = %s",&Patient[i].bg);
		    printf("\t City = %s",&Patient[i].city);
		    printf("\t Mobile Number = %ld",Patient[i].mobile);
		    printf("\t Email Id = %s",&Patient[i].email);
		    printf("\t Problem = %s",&Patient[i].problem);
		    printf("\t Doctor = %s\n",&Patient[i].doctor);
		    printf("-------------------------------------------------\n");
		}
	}
	if(found==0)
	{
		printf("Sorry,The patient you searched not exists in Hospital");
	}
}
void edit()
{
	int id,i;
	printf("Enter a Id of the patient you want to modify:");
	scanf("%d",&id);
	for(i=0;i<count;i++)
	{
		if(id==Patient[i].id)
		{
			printf("Enter new Id, Ward number,first Name,last Name,gender,age,blood group,city,mobile number,email,problem,prescribed doctor of patient :");
		    scanf("%d%d%s%s%s%d%s%s%ld%s%s%s",&Patient[i].id,&Patient[i].wardno,&Patient[i].firstname,&Patient[i].lastname,&Patient[i].gender,&Patient[i].age,&Patient[i].bg,&Patient[i].city,&Patient[i].mobile,&Patient[i].email,&Patient[i].problem,&Patient[i].doctor);
		}
	}
}
void destroy()
{
	int id,i,j,found=0;
	printf("Enter a patient id of the patient record you want to delete:");
	scanf("%d",&id);
	for(i=0;i<count;i++)
	{
		if(Patient[i].id==id)
		{
			found=1;
			for(j=i;j<count-1;j++)
			{
				Patient = Patient+1;
			}
			count--;
			printf("Record deleted successfully!!!");
		}
	}
	if(found==0)
	{
		printf("Record not found");
	}
	
}
