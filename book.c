#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>
struct person
{
  char firstName[20];
  char lastName[20];
  char cel[13];
  char address[50];
  char email[30];
} v[200];

int nr=0;

char fn[250]="info.dat"; // emri i file-it.

void menu()
{

  printf("\t\t \xDB\xDB\xDB\xDB\xDB\xDB\xB2\xB2Libri i adresave\xB2\xB2\xDB\xDB\xDB\xDB\xDB\xDB");

  printf("\n\n 1 - Statistiks \t 2 - Register \t3 - Delete");
  printf("\n\t\t4 - Modify \t\t 5 - Search ");
  printf("\n  \t     s - Save \t    p - Show \td - Exit");
  printf("\n Choose : ");
}

void read()
{

 FILE *f;
 f=fopen(fn,"rb");
 if (f==NULL)
 {
   printf("\n \n   Gabim ne file");
   return;
 }
 system("cls");
 nr=0;

 while (fread(&v[nr],sizeof(struct person),1,f))
 {
   nr++;
 }

 fclose(f);
}

void save()
{
 FILE *f;
 f=fopen(fn,"wb");
 if (f==NULL)
 {
   printf("\n \n   Gabim ne file");
   return;
 }
int i;
 for( i=0;i<nr; i++)
 {
  fwrite(&v[i],sizeof(struct person),1,f);
 }

 system("cls");

 fclose(f);
}

void order()
{
printf("How do you want to order?");

 printf("\n\n 1 - By First Name");
printf("\n 2 - By LastName\n ");
int i,j;
 switch(getch())
  {

  	case '1':{
struct person vp;

	  for(i=0;i<nr-1;i++)
	  	{
	  		for( j=i+1;j<nr;j++)
	  		{
	  			if(strcmp(v[i].firstName,v[j].firstName)>0)
	  			{
			    	vp=v[i];
	  				v[i]=v[j];
	  				v[j]=vp;
		             	  }
	  	           }
	  		  }
	  	}
		break;

  	case '2':{

	  	 struct person vp;


	  	  for( i=0;i<nr-1;i++)
	  	{
	  		for( j=i+1;j<nr;j++)
	  		{
	  			if(strcmp(v[i].lastName,v[j].lastName)>0)
              {


	  				vp=v[i];
	  				v[i]=v[j];
	  				v[j]=vp;
	  		}
			  }
		  }
	  }

  	break;
  	default:{


	  system("cls");
	 printf("Error.Please enter 1 or 2\n\n\n");
	rradhit();
}
}


 printf("\n\n                 Lista e personave ");
 printf("\n ==========================================================");
 printf("\n   First Name     Last Name     Cel       Adress     Email");
 printf("\n-----------------------------------------------------------");
 for( i=0;i<nr; i++)
 {
  printf("\n%10s  %10s  %10s   %10s  %10s",v[i].firstName,v[i].lastName,v[i].cel,v[i].address,v[i].email);
 }
 printf("\n");
}

void add()
{
     printf("\n\n Add:");
     printf("\n First Name :");
     scanf("%s",v[nr].firstName);
     printf("Last Name :");
     scanf("%s",v[nr].lastName);
     printf("nr ne formatin 06X...:");
     scanf("%s",v[nr].tel);
     printf("Adresa(pa hapsira perdorni'_'):");
     scanf("%s",v[nr].address);
     printf("Email :");
     scanf("%s",v[nr].email);
     nr++;

 system("cls");


}

void delete()
{
    int i,j;
 char v_firstName[20];
 printf("\n\n Delete:");
 printf("\n First Name :");
 scanf("%s", v_firstName);
 for( i=0;i<nr; i++)
 {
  if (strcmp(v_firstName,v[i].firstName)==0)
  {
   for( j=i;j<nr-1; j++)
   {
     v[j]=v[j+1];
   }
   nr--;
   break;
  }
 }
}

void modify()
{
    int i;
 char v_firstName[20];
 printf("\n\n Modify");
 printf("\nFirst Name :");
 scanf("%s", v_firstName);
 for( i=0;i<nr; i++)
 {
  if (strcmp(v_firstName,v[i].firstName)==0)
  {
     printf("\nNew first name:");
     scanf("%s",v[i].firstName);
     printf("New last name:");
     scanf("%s",v[i].lastName);
     printf("Cel :");
     scanf("%s",v[i].cel);
     printf("Address :");
     scanf("%s",v[i].address);
     printf("Email :");
     scanf("%s",v[i].email);
     break;
  }
 }
 system("cls");
}

void search_firstName()
{
    int i;

 char v_firstName[20];
 printf("\n\n Searching by name");
 printf("\nFirst Name :");
 scanf("%s", v_firstName);
 for( i=0;i<nr; i++)
 {
  if (strcmp(v_firstName,v[i].firstName)==0)
  {
	  printf("\nFirst Name %s", v[i].firstName);
	  printf("\nLast Name  %s", v[i].lastName);
	  printf("\nCel  %s", v[i].tel);
	  printf("\nAddress  %s", v[i].address);
	  printf("\nEmail %s", v[i].email);
  }
 }
 printf("\n\n");
}

void search_lastName()
{
int i;
 char v_lastName[20];
 printf("\n\n Search by last name");
 printf("\nLast Name :");
 scanf("%s", v_lastName);
 for(i=0;i<nr; i++)
 {
  if (strcmp(v_lastName,v[i].lastName)==0)
  {
	  printf("\nFirst Name %s", v[i].firstName);
	  printf("\nLast Name  %s", v[i].lastName);
	  printf("\nCel  %s", v[i].tel);
	  printf("\nAddress  %s", v[i].address);
	  printf("\nEmail %s", v[i].email);
  }
 }
 printf("\n\n");
}

void search_cel()
{
int i;
 char v_cel[20];
 printf("\n\n Searching by cel");
 printf("\nCel :");
 scanf("%s",v_cel);
 for( i=0;i<nr; i++)
 {
  if (strcmp(v_cel,v[i].cel)==0)
  {
	  printf("\nFirst Name %s", v[i].firstName);
	  printf("\nLast Name  %s", v[i].lastName);
	  printf("\nCel  %s", v[i].tel);
	  printf("\nAddress  %s", v[i].address);
	  printf("\nEmail %s", v[i].email);
  }
 }
 printf("\n\n");
}


void search()
{
  printf("How do you want to search:");
  printf("\n\n 1 - First Name");
  printf("\n 2 - Last Name ");
  printf("\n 3 - Cel \n");

  switch(getch())
  {
  	case '1': search_firstName();
  	break;
  	case '2': search_lastName();
  	break;
  	case '3': search_cel();
  	break;
  	default:
  		system("cls");
  		printf("\nError.Please enter 1,2,3");
  		kerko();


  		printf("\n\n");
  }

}






void statistiks()
{
    int i;
    printf("\nPress 1 for the number of users:\n");
    printf("Press 2 for longest first name:\n");
    printf("Press 4 for longest last name:\n");
    printf("Press 5 for shortest first name:\n");
    printf("Press 6 for shortest last name:\n");

    switch(getch()){
    case '1':
        printf("Registered:     %d\n\n",nr);;
    break;
   case '2':{
       int i,plus=0,amc=0,eagle=0,vod=0;

for(i=0;i<nr;i++)
{
	if(v[i].tel[2]=='6')
	plus++;
    else if(v[i].tel[2]=='7')
     eagle++;
     else if (v[i].tel[2]=='8')
     amc++;
      else if (v[i].tel[2]=='9')
     vod++;
     }

printf("\nNr i personave me nr amc:     %d",amc);
printf("\nNr i personave me nr vod:     %d",vod);
printf("\nNr i personave me nr plus:    %d",plus);
printf("\nNr i personave me nr eagle:   %d\n",eagle);
   }
    break;
    case '3':
        {
            char max[20];

printf("Longest first names:\n");
strcpy(max,v[0].firstName);
for(i=0;i<nr;i++)
    {if(strlen(max)<strlen(v[i].firstName))
        strcpy(max,v[i].firstName);
    }

    for(i=0;i<nr;i++)
    {if(strlen(max)==strlen(v[i].firstName))
        printf("%s\n",v[i].firstName);
    }
        }
    break;
    case '4':
        {
            char max[20];

printf("Longest last names:\n");
strcpy(max,v[0].lastName);
for(i=0;i<nr;i++)
    {if(strlen(max)<strlen(v[i].lastName))
        strcpy(max,v[i].lastName);
    }

    for(i=0;i<nr;i++)
    {if(strlen(max)==strlen(v[i].lastName))
        printf("%s\n",v[i].lastName);
    }
        }
break;

   case '5':
        {
            char min[20];

printf("Shortest first names:\n");
strcpy(min,v[0].firstName);
for(i=0;i<nr;i++)
    {if(strlen(min)>strlen(v[i].firstName))
        strcpy(min,v[i].firstName);
    }

    for(i=0;i<nr;i++)
    {if(strlen(min)==strlen(v[i].firstName))
        printf("%s\n",v[i].firstName);
    }
        }
break;


    case '6':
        {
            char min[20];

printf("Shortest last names:\n");
strcpy(min,v[0].lastName);
for(i=0;i<nr;i++)
    {if(strlen(min)>strlen(v[i].lastName))
        strcpy(min,v[i].lastName);
    }

    for(i=0;i<nr;i++)
    {if(strlen(min)==strlen(v[i].lastName))
        printf("%s\n",v[i].lastName);
    }
        }
break;

default:
                system("cls");
                printf("\nError.\n");
                printf("\n\nPlease provide appropriate input\n");
                printf("\n\nPSending you back to main menu...\n");
                Sleep(3000);
				system("cls");

                menu();

}
}

int main()
{

 char k;
 read();


  do{
  menu();
  k=getch();
 switch(k)
{
    case '1':  statistiks();
    break;
   case '2':   add();
    break;
    case '3': delete();
    break;
    case '4': modify();
    break;
    case '5':  search();
    break;
    case 's': save();
    break;
    case 'p': order();
    break;
    case 'd' : exit(0);
    break;
    default:
                ssystem("cls");
				printf("\nError.\n");
				printf("\n\nPlease provide appropriate input\n");
				printf("\n\nPSending you back to main menu...\n");
				Sleep(3000);
				system("cls");
                    }
      }while(k!='d' && k!='D' && k!=27);


}
