/*______________________________________________________________

	NAME  :- AMRUTHA S KUMAR
	DATE OF SUBMISSION  :- 25-JAN-2019
	TITLE :-  DATABASE OF EMPLOYEE       
__________________________________________________________________*/

#include<stdio.h>
#include<stdlib.h>
struct employee
{
	char name[50];
	char gender[50];
	char profile[50];
	int id;
	struct employee *next;
	struct employee *prev;
};
typedef struct employee node;
node*first=NULL;
node*last=NULL;

void create_3()//ENTERING DATA OF THREE EMPLOYEE
{

	int i=3;


	while(i!=0)
	{
		node*new=(node*)malloc(sizeof(node));

		if(first==NULL)
		{
			printf("Enter the name of Employee:\t\t");
			scanf("%s",new->name);
			printf("Enter the Gender:\t\t\t");
			scanf("%s",new->gender);
			printf("Enter Profile:\t\t\t\t");
			scanf("%s",new->profile);
			printf("Enter ID:\t\t\t\t");
			scanf("%d",&new->id);
			printf("\n");
		
			new->next=NULL;
			new->prev=NULL;
			first=new;
			last=new;

			i--;
		}
		else
		{
			printf("Enter the name of Employee:\t\t");
                	scanf("%s",new->name);
             		printf("Enter the Gender:\t\t\t");
                	scanf("%s",new->gender);
                	printf("Enter Profile:\t\t\t\t");
                	scanf("%s",new->profile);
                	printf("Enter ID:\t\t\t\t");
                	scanf("%d",&new->id);
                	printf("\n");
        	 	             	
		
			if(new->id < first->id)//SORTING WHILE ENTERING
			{	
				new->prev=NULL;
				new->next=first;
				first->prev=new;
				first=new;
          			i--;
			}
			else if(new->id>last->id)
			{
				last->next=new;
				new->next=NULL;
				new->prev=last;
				last=new;
				i--;
			}
			else
			{
				node*temp=first;
				while(temp->id < new->id && temp->id < last->id)
				{
					temp=temp->next;
				}
				if(temp->id == new->id)
				{
					printf("id exist\n");
					return;
				}
				else
				{
					temp->prev->next=new;
					new->prev=temp->prev;
					new->next=temp;
					temp->prev=new;
					i--;
				}	
			}	
		}	
	}
}
void create_1()//ENTERING DATA OF ONE EMPLOYEE
{
	node *temp3=first;
	node *temp1=last;
	node *temp2;
	node*new=(node*)malloc(sizeof(node));
	printf("Enter the name of Employee:\t\t");
        scanf("%s",new->name);
        printf("Enter the Gender:\t\t\t");
        scanf("%s",new->gender);    
        printf("Enter Profile:\t\t\t\t");
        scanf("%s",new->profile);
        printf("Enter ID:\t\t\t\t");
        scanf("%d",&new->id);
        printf("\n");

                
	while(temp3!=NULL)
	{
		if(new->id==temp3->id)
		{
			printf("\nID Already Exist\n");
			
			return;
		}
		else
		temp3=temp3->next;
	}

		
	node*temp=first;
	if(temp->id > new->id)
	{
		new->next=first;
		new->prev=NULL;
		first->prev=new;
		first=new;
		
	}	
		
	else if(temp1->id < new->id)
	{
		new->next=NULL;
		new->prev=last;
		last->next=new;
		last=new;

	}
	else
	{
		while(new->id > temp->id)
		{
			temp2=temp;
			temp=temp->next;
		}

			new->next=temp;
			new->prev=temp2;
			temp->prev=new;
			temp2->next=new;
	}
}



void display()//DISPLAYING ALL DETAILS
{
	printf("\t\t\t\t\t\t\tEMPLOYEE DETAILS\n");

	node*temp3=first;
	while(temp3!=NULL)
	{

		printf("\n");
		printf("\t\t\t\t\t\t\t\tID:-%d\n",temp3->id);
		printf("\t\t\t\t\t\t\t\tNAME:-%s\n",temp3->name);
		printf("\t\t\t\t\t\t\t\tGENDER:-%s\n",temp3->gender);
		printf("\t\t\t\t\t\t\t\tPROFILE:-%s\n",temp3->profile);
		printf("\n");
		temp3=temp3->next;
		
	}
}

void display_1()//SINGLE DATA WILL DISPLAY
{
	node*temp=first;
	int key,count=0;
	node*temp3=first;
	printf("\nEnter the ID no:");
	scanf("%d",&key);

	while(temp3!=NULL)
	{
		if(key==temp3->id)
		{
			count++;
		}
	temp3=temp3->next;
	}
	
	if(count==0)
	{
		printf("ID is Not Exist\n");
		return;
	}
	else
	{
		while(key!=temp->id)
		{
			temp=temp->next;
		}
			printf("\n");
			printf("\t\t\t\t\t\t\t\tid:%d\n",temp->id);
			printf("\t\t\t\t\t\t\t\tname:%s\n",temp->name);
			printf("\t\t\t\t\t\t\t\tgender:%s\n",temp->gender);
			printf("\t\t\t\t\t\t\t\tprofile:%s\n",temp->profile);
	}
}

void remove_1()//REMOVE DATA FROM DATABASE
{
	int count=0;
	node*temp=first;
	node*temp1=last;
	node*temp3=first;
	node*temp2;int key;
	printf("\nEnter the id  to be removed:");
	scanf("%d",&key);

	while(temp3!=NULL)
	{
		if(key==temp3->id)
		{
			count++;
		}
	temp3=temp3->next;
	}

	if(count==0)
	{
		printf("ID is Not Exist\n");
		return;
	}

	else
	{
		if(key==temp->id)
		{
			first=first->next;
			first->prev=NULL;
			free(temp);

		}
		else if(key==temp1->id)
		{
			temp2=last->prev;
			last=temp2;
			temp2->next=NULL;
			free(temp1);

		}	
		else
		{
			while(key!=temp->id)
			{
				temp2=temp;
				temp=temp->next;
			}
	temp2->next=temp->next;
	free(temp);
	printf("Remove entered ID\n");
	
		}
	}	
}


void store_text()//TEXT FILE MODE
{
	FILE *fp=fopen("filet","w+");
	node*temp=first;
	while(temp!=NULL)
	{
		
		fprintf(fp," \t\t\t\tid=%d\t name=%s\t gender=%s\t profile=%s\n\n",temp->id,temp->name,temp->gender,temp->profile);
		
		temp=temp->next;
	}
	printf("TEXT MODE\n");
	fclose(fp);
}


void store_binary()//BINARY FILE MODE
{
	int num;
	char ch;
	FILE *fp1,*fp2;
	fp1=fopen("filet","r");
	if(!fp1)
	{
		printf("Unable to open\n");
	}	
	fp2=fopen("binary","wb");
	if(!fp2)
	{
		printf("Unable to open\n");
	}
	while(!feof(fp1))//feof() indicates EOF happened on the previous IO operation.
	{
		fread(&ch,sizeof(char),1,fp1);
		num = ch;
		fwrite(&num,sizeof(int),1,fp2);
	}
	printf("BINARY MODE\n");
	fclose(fp1);
	fclose(fp2);
}

int main()
{
	while(1)
	{

		printf("\n\t\tMENU");
		printf("\n\t----------------------");
		printf("\n");
		printf("\n 1.Create the details of three Employee");
		printf("\n 2.Create the details of one more Employee");
		printf("\n 3.Remove the details of a Employee");
		printf("\n 4.Display the details of all Employee");
		printf("\n 5.Display the details of  Employee");
		printf("\n 6.Store the details to a Text file");
		printf("\n 7.Store the details to a Binary file");
		printf("\n 8.Exit");
		enum number { one=1,two,three,four,five,six,seven,eight };

                enum  number ch;

		printf("\n Enter your choice:");
		scanf("%x",&ch);
		printf("\n");
		
		switch(ch)
		{
			case one:create_3();
				break;
	
			case two:create_1();
        			break;

			case three:remove_1();
			        break;

			case four:display();
        			break;

			case five:display_1();
       		 		break;
	
			case six:store_text();
			        break;

			case seven:store_binary();
				break;

			case eight:exit(1);
				break;

			default:printf("\ninvalid");
				break;
		}
	}
}





















