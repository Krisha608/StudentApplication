#include<stdio.h>
#include<conio.h>
#define SIZE 2
struct Student{
	int sid;
	char name[30];
	float fees,maths,comp,eng,total,per;
	char grade;
	int flag;
	
}s[SIZE];
void scanStudentDetails();
void displayStudentDetails();
void calculateMarksheet(int i);
int search(int id);
void update(int id);
void displayparticular(int index);
void del(int id);
void main(){
	int choice,id,index=-1;
	while(1){
		clrscr();
		printf("\n1--> create student");
		printf("\n2--> display student");
		printf("\n3--> search");
		printf("\n4--> update");
		printf("\n5--> delete");
		printf("\n6--> exit");
		printf("enter the choice");
		scanf("%d",&choice);
		switch(choice){
			case 1:	scanStudentDetails();
					break;
			case 2:	displayStudentDetails();
					break;
			case 3:	printf("\n Enter the id you want to search");
					scanf("%d",&id);
					index=search(id);
					if(index>=0){
						displayparticular(index);
					}
					else{
						printf("\n the record not found");
					}
					getch();
					break;
			case 4:	printf("\n Enter the id you want to update");
					scanf("%d",&id);
					update(id);
					break;
			case 5:	printf("\n Enter the id you want to delete");
					scanf("%d",&id);
					del(id);
					displayStudentDetails();
					getch();
					break;
			case 6:	exit(0);
			default:printf("invalid case");
			
		}
		getch();
	}
}
void scanStudentDetails(){
	FILE *fp;
	float temp,i;
	fp=fopen("student.txt","w");
	for(i=0;i<SIZE;i++){
		printf("\n Enter the sid");
		scanf("%d%s",&s[i].sid,s[i].name);
		printf("\n enter the fees");
		scanf("%f",&temp);
		s[i].fees=temp;
		printf("\n enter the com,eng,maths");
		scanf("%f",&temp);
		s[i].comp=temp;
		scanf("%f",&temp);
		s[i].eng=temp;
		scanf("%f",&temp);
		s[i].maths=temp;
		calculateMarksheet(i);
		s[i].flag=1;
	}
	fclose(fp);
}
void calculateMarksheet(int i){
	s[i].total=s[i].maths+s[i].eng+s[i].comp;
	s[i].per=s[i].total/3;
	if(s[i].per>=90){
		s[i].grade='A';
	}
	else{
		s[i].grade='B';
	}
}
void displayStudentDetails(){
	FILE *fp;
	int i;
	fp=fopen("student.txt","r");
	printf("\nsid\tname\tfees\tcomp\teng\tmaths\ttotal\tper\tgrade\n");
	for(i=0;i<SIZE;i++){
		if(s[i].flag==1){
			printf("\n%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%c",s[i].sid,s[i].name,s[i].fees,s[i].comp,s[i].eng,s[i].maths,s[i].total,s[i].per,s[i].grade);
		}
	}
	fclose(fp);
}
int search(int id){
	int i;
	int found=-1;
	for(i=0;i<SIZE;i++){
		if(s[i].sid==id){
			found=i;
			return found;
		}
	}
	return found;
}
void displayparticular(int index){
	clrscr();
	if(s[index].flag==1){
		printf("\nsid\tname\tfees\tcomp\teng\tmaths\ttotal\tper\tgrade\n");
		printf("\n%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%c",s[index].sid,s[index].name,s[index].fees,s[index].comp,s[index].eng,s[index].maths,s[index].total,s[index].per,s[index].grade);
	}
}
void update(int id){
	int index=-1,choice,choice1;
	float temp;
	index=search(id);
	if(index>=0){
		printf("\n1--->update name");
		printf("\n2--->update marks");
		printf("\n3--->update fees");
		printf("\nEnter the choice");
		scanf("%d",&choice);
		switch(choice){
			case 1:	displayparticular(index);
					printf("\n please enter the new name");
					scanf("%s",&s[index].name);
					printf("\n the record has been updated");
					displayparticular(index);
					getch();
					break;
			case 2:	printf("\n1--->update eng marks");
					printf("\n2--->update maths marks");
					printf("\n3--->update comp marks");
					printf("\n4--->update all sub marks");
					printf("\nEnter the choice");
					scanf("%d",&choice1);
					switch(choice1){
						case 1:	clrscr();
								displayparticular(index);
								printf("\nEnter the new eng marks");
								scanf("%f",&temp);
								s[index].eng=temp;
								printf("\n The update marks are:");
								calculateMarksheet(index);
								displayparticular(index);
								getch();
								break;
						case 2:	clrscr();
								displayparticular(index);
								printf("\nEnter the new maths marks");
								scanf("%f",&temp);
								s[index].maths=temp;
								printf("\n The update marks are:");
								calculateMarksheet(index);
								displayparticular(index);
								getch();
								break;	
						case 3:	clrscr();
								displayparticular(index);
								printf("\nEnter the new comp marks");
								scanf("%f",&temp);
								s[index].comp=temp;
								printf("\n The update marks are:");
								calculateMarksheet(index);
								displayparticular(index);
								getch();
								break;
						case 4:	clrscr();
								displayparticular(index);
								printf("\nEnter the new eng marks");
								scanf("%f",&temp);
								s[index].eng=temp;
								printf("\nEnter the new maths marks");
								scanf("%f",&temp);
								s[index].maths=temp;
								printf("\nEnter the new comp marks");
								scanf("%f",&temp);
								s[index].comp=temp;
								calculateMarksheet(index);
								printf("\n The update marks are:");
								displayparticular(index);
								getch();
								break;
					}
					break;
			case 3:	clrscr();
					displayparticular(index);
					printf("\n please enter the new fees");
					scanf("%f",&temp);
					s[index].fees=temp;
					printf("\n the record has been updated");
					displayparticular(index);
					getch();
					break;
		}
		
	}
	else{
		printf("the record to be updated not found");
	}
}
void del(int id){
	int index=-1;
	index=search(id);
	if(index>=0){
		s[index].flag=-1;
	}
	else{
		printf("the record to be deleted not found");
	}
}