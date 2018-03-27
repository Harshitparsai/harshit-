#include<stdio.h>
#include<string.h>
struct cricket
{
	char t_name[20];
	char ot_name[20];
	char g_name[20];
    char score[20];
    float over;
    float RR;
}c;
void menu();
void write();
void add_record();
void delete_record();
void search();
void update();
int main()
{
     menu();
	 return 0;	
}
void menu()
{   int n;
    printf("\nPress the number what you want to do:\n 1. write record\t2. add record\t3. delete record\n4. search a record\t5. update a record\t 6. Exit");
    scanf("%d",&n);
	switch(n)
	{
		case 1:write();
		       menu();
		       break;
		case 2:add_record();
		       menu();
		       break;
		case 3:delete_record();
		       menu();
		       break;
		case 4: search();
		        menu();
		        break;
		case 5: update();
		        menu();
		        break;
		default:printf("\nInvalid input");
	}
}
void write()
{
    FILE *f;
    char ch;
	f=fopen("F:\\cricet.txt","w");
	if(f==NULL)
	{
	    printf("\n file does not open");	
	}	
	else
	{
		 printf(" \n do u wannna to write records then press y");
		fflush(stdin);
		 scanf("%c",&ch);
		 while(ch=='y'||ch=='Y')//user choice to give input or not
		 {
		 
             //f=	fopen("F:\\cricet.txt","a") ;
		    printf("\nfile  open");
	    	printf("\ndata is being written " );
	    	printf("\nEnter team name ");
			fflush(stdin);   //we r taking thevalues of student
        	gets(c.t_name);
     	    printf("\nEnter the score ");
            gets(c.score);
            fflush(stdin);
            printf("\nEnter the over played ");
            scanf("%f",&c.over);
            printf("\nEnter the Run rate ");
            scanf("%f",&c.RR);
            fflush(stdin);
            printf("\nEnter the opposition ");
            gets(c.ot_name);
            printf("\nEnter the Ground name");
            gets(c.g_name);
	    	printf("\ndata is written\n  do u want to write more info" );
	         //fclose will close the file from the ram
	        fprintf(f,"%s %s %f %f %s %s ",c.t_name,c.score,c.over,c.RR,c.ot_name,c.g_name);
	    	fflush(stdin);
		   scanf("%ch",&ch);
		   //fclose(f);
	   }
	}
	
}
void add_record()
{
	FILE *f;
    char ch;
	f=fopen("F:\\cricet.txt","a");
	if(f==NULL)
	{
	    printf("\n file does not open");	
	}	
	else
	{
		 printf(" \n do u wannna to write records then press y");
		fflush(stdin);
		 scanf("%c",&ch);
		 while(ch=='y'||ch=='Y')//user choice to give input or not
		 {
		 
             f=	fopen("F:\\cricet.txt","a") ;
		    printf("\nfile  open");
	    	printf("\ndata is being written " );
	    	printf("\nEnter team name ");
			fflush(stdin);   //we r taking thevalues of student
        	gets(c.t_name);
     	    printf("\nEnter the score ");
            gets(c.score);
            fflush(stdin);
            printf("\nEnter the over played ");
            scanf("%f",&c.over);
            printf("\nEnter the Run rate ");
            scanf("%f",&c.RR);
            fflush(stdin);
            printf("\nEnter the opposition ");
            gets(c.ot_name);
            printf("\nEnter the Ground name");
            gets(c.g_name);
	    	printf("\ndata is written\n  do u want to write more info" );
	         //fclose will close the file from the ram
	        fprintf(f,"%s %s %f %f %s %s ",c.t_name,c.score,c.over,c.RR,c.ot_name,c.g_name);
	    	fflush(stdin);
		   scanf("%ch",&ch);
		   fclose(f);
	   }
	}
	
}
void delete_record()
{ 
  FILE *f,*f1;
  f= fopen("F:\\cricet.txt","r");
  f1=fopen("F:\\cricet1.txt","a");
  char  name[20];
  printf("Enter the name of the team of which record have to be deleted\n");
  scanf("%s",&name);
  while(fscanf(f,"%s %s %f %f %s %s ",c.t_name,c.score,&c.over,&c.RR,c.ot_name,c.g_name)!= EOF)
  {   if(strcmp(name,c.t_name)!=0)
       {
	       fprintf(f1,"%s %s %f %f %s %s ",c.t_name,c.score,c.over,c.RR,c.ot_name,c.g_name);
	   }
  }
  fclose(f);
  fclose(f1);
  remove("cricket.txt");
  rename("cricet1.txt","cricet.txt");
	
}
void search()
{
	int n;
	float overs;
   char team1[20],team2[20],ground[20];
	FILE *f;      //f is a pointer variable of type file
	
    f=	fopen("F:\\cricet.txt","r") ;         //fopen is open a file function it will return the address and it is stored in f variable in reading  mode in
                                        
	if(f==NULL)                          // FILE nt open then f will be NULL
	{
		printf("\nfile does not open");
	 } 
	else                                    //if it is open then
	{   printf("\n through which one u want to search\n 1. team name\t2. opposition team name\t3. Overs \t4. ground name "); 
	    scanf("%d",&n);
	    fflush(stdin);
	    switch(n)
		{ case 1: printf("\nEnter the team to be displayed");
	              gets(team1);
	          	while(fscanf(f,"%s %s %f %f %s %s ",c.t_name,c.score,&c.over,&c.RR,c.ot_name,c.g_name)!= EOF)  //fread reds the data
	         	{   if(strcmp(c.t_name,team1)==0)
		            printf("%s %s %f %f %s %s ",c.t_name,c.score,c.over,c.RR,c.ot_name,c.g_name);
	            }
	            break;
	      case 2:printf("\nEnter the opposition team name to be displayed");
	              gets(team2);
	         	while(fscanf(f,"%s %s %f %f %s %s ",c.t_name,c.score,&c.over,&c.RR,c.ot_name,c.g_name)!= EOF)  //fread reds the data
	         	{   if(strcmp(c.ot_name,team2)==0)
		            printf("%s %s %f %f %s %s ",c.t_name,c.score,c.over,c.RR,c.ot_name,c.g_name);
	            }
	            break;
	      case 3:printf("\nEnter Overs to be displayed");
	             scanf("%f",&overs);
	             while(fscanf(f,"%s %s %f %f %s %s ",c.t_name,c.score,&c.over,&c.RR,c.ot_name,c.g_name)!= EOF) //fread reds the data
	         	{   if(c.over==overs)
		            printf("%s %s %f %f %s %s ",c.t_name,c.score,c.over,c.RR,c.ot_name,c.g_name);
	            }
	            break;
	      case 4:printf("\nEnter the ground  name to be displayed");
	              gets(ground);
	         	while(fscanf(f,"%s %s %f %f %s %s ",c.t_name,c.score,&c.over,&c.RR,c.ot_name,c.g_name)!= EOF) //fread reds the data
	         	{   if(strcmp(c.g_name,team2)==0)
		            printf("%s %s %f %f %s %s ",c.t_name,c.score,c.over,c.RR,c.ot_name,c.g_name);
	            }
	            break;
	             
	     default:printf("invalid");
		}
		
	}
}
void update()
{
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

