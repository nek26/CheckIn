// CHECK IN CODE by Cinthya J, Anoushka G, Nidusha K
//preprocessing directives
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NODE struct node
int classes; // inputed by teacher
int length;
void insert();
void HELP();
void read_file();
void save_file();
struct node //creating linked list  with the structure
{
	char name[20];
	int mood;
	NODE *next;
};
NODE*head=NULL; //global variables to define head and tail nodes
NODE*tail=NULL;

int main(int argc, char *argv[ ])
{
        int input;
        char inputname[20]; // declaring variables
	
	if (argc==1) 
        {
                printf("The Name of the file is missing! \n");
                return 1;
        }
	
//	read_file(argv[1]);//calling read file function
        printf("Enter your name : ");
        scanf("%s",inputname);
        printf("Hi %s ! \n \n", inputname);

        	printf("Checking in.... \n Press 1 to check in \n \n");
        	scanf("%d",&input);        
        
	read_file(argv[1]);	
	switch(input)
	{
		case 1:
		insert(inputname);
		save_file(argv[1]);
		exit(1);
		break;
			
		default:
		printf("Invalid input \n");
		break;	
	}
	


return 0;
}

void insert(char * str)
{
	int read_input;
	printf("Your attendance has been recorded! \n \n");
	printf("How are you feeling today? \n 1 -- Pretty good \n 2 -- I'm hanging in there \n 3 -- I've been better \n 4 -- HELP \n \n");
	scanf("%d",&read_input);
	NODE *temp;
 	//creating the node and inserting
	(temp=(NODE*) malloc(sizeof (NODE)));
	if (head==NULL) //checking if list is empty then adding a new reservation
	{
		strcpy(temp->name,str);
               	temp->mood=read_input;
		head=temp;
                tail=temp;
	}
               
 	else //inputting new reservation to the end of the list

       	{
			strcpy(temp->name,str);
			temp->mood=read_input;
			temp->next=NULL; //changing the tail 
			tail->next=temp;
			tail=temp;
     
	}

	if (read_input==4)
	{
		HELP(str);
	}
	
	else
	
	{
		printf("Thanks for checking in! \n \n");
	}

return;
}

void HELP(char * strname)
{
	int help_input;
	printf("Thanks for checking in! \n \n");
	printf("%s , what is causing you trouble? \n", strname);
	printf("1-- My family \n2-- My identity \n3-- My thoughts \n4-- My habits \n5-- Time management/procastination \n6--Academics \n");
	scanf("%d",&help_input);
	switch(help_input)
	{
		case 1:
		printf (" https://www.thehotline.org/ \n");
		break;
		
		case 2:
		printf ("https://itgetsbetter.org/ \n https://www.thetrevorproject.org/#sm.000olojrb152wdhptzg2roqo4v2qu \n");
		break;
		
		case 3:
                printf ("https://suicidepreventionlifeline.org/  \n https://adaa.org/ \n");
                break;

		case 4:
                printf ("https://www.nationaleatingdisorders.org/  \n https://www.addictioncenter.com/community-resources/  \n");
                break;
	
		case 5:
                printf ("https://www.mindtools.com/pages/main/newMN_HTE.htm  \n");
                break;
		
		case 6:
                printf ("You are always welcome to come to my office hours on MWF from 2:15pm to 4:15pm \n");
		printf ("Or you can schedule an appointment by emailing me at professor@univetsity.edu \n");
                break;
	}
return;
}


void read_file(char * filename) //function to read file 
{	
//	int length;
	FILE *fp;
	fp=fopen(filename,"r"); //open the file
        if (fp==NULL) // if the file does not exist.
	{
		return;
	}
	char inputname1[20];
	char moodname1[20];
//	fseek(fp,47,SEEK_SET); // putting pointer after header
	
//	while(fscanf(fp,"%s %s",inputname1,moodname1)==2) //reading name and size from file
//	{
//	insert(inputname1); //inserting to linked list
//	}

	fscanf(fp,"%s %s",inputname1,moodname1);
	fseek(fp,0,SEEK_END);
	fclose(fp); //closing the file
}

void save_file(char * filename) //function to write the linked list into the file
{
	FILE *fp;
	fp=fopen(filename,"a");
	char moodname[40]; 
	NODE *p;
       	if (fp==NULL) // if the file does not exist.
        {
                return;
        }
	// printing header
//	fprintf(fp,"Name\t\tmood\n");
//	fprintf(fp,"_________________________________ \n");
        p=head;
        while(p!=NULL) //traversing linked list
        {	
		if (p->mood==1)
		{
			strcpy(moodname,"Pretty good");
		}
		
		else if (p->mood==2)
                {
			strcpy(moodname,"I'm hanging in there");
                        
                }

		else if (p->mood==3)
                {
                        strcpy(moodname,"I've been better");
	
                }
	
		else 
                {
                        strcpy(moodname,"HELP");
                }
                fprintf(fp, "%s \t %s \n",p->name,moodname);
                p=p->next;
        }
	if (p==NULL)
	{
		return;
	}

	fclose(fp);
	return;

	
}

              
              
                
                
                
                        
                   
                        
                        
                        
                      
                
			
		
			
			

                          


        
      
        	

