#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

typedef struct tab *pointTab;
typedef struct tab
{
   char  info[50];
}tab;

//rmspace to remoove spaces in case
void rmSpace(char *s)
{
	int  i,k=0;
 
	 for(i=0;s[i];i++)
    {
            s[i]=s[i+k];
    
            
            if(s[i]==' ')
            {
                k++;
                i--;
            }
            
        }
}


int putInTable( char *s,pointTab table)
{

    char inter[50];
    bool cond;
    int i=0,j,t=0;
    while (s[i]!='\0')
    {  
        cond=false;
        if (s[i]=='(' || s[i]==')' ||  s[i]=='/' || s[i]=='*' || s[i]=='%' )
        {
            table[t].info[0]=s[i];
            table[t].info[1]='\0';
            t++;
            cond=true;
        }
        if(s[i]=='+' || s[i]=='-')
        {
             if (s[i-1]!='+' && s[i-1]!='-' && s[i-1]!= '*' && s[i-1]!='/' &&  s[i-1]!= '(' && s[i]!='%')
            {
                 table[t].info[0]=s[i];
                 table[t].info[1]='\0';
            printf("yes\n");
   
            }
            else 
            {
                j=i;
                while (s[i]!='\0' && isdigit(s[i])!=0)
                {
                    i++;
                }
            
                int m=0;
                for ( j; j <= i; j++)
                {
                     table[t].info[m]=s[j];
                     m++;
                }
                table[t].info[m]='\0';
   

                }
                    cond=true;
                    t++;     
        }

        if (isdigit(s[i])!=0 && cond==false)
        {
                j=i;
            while (s[i]!='\0' && isdigit(s[i])!=0)
            {
                i++;
            }
            int m=0;
            for ( j; j < i; j++)
            {
                 table[t].info[m]=s[j];
                 m++;
            }
                table[t].info[m]='\0';
                cond=true;
                t++;
                i--;
            }
        i++;
    }

  return t;
}


int main(){
    
    tab table[512];
    int tailleTab;
    char string[512]="(32+-435)";
    
    tailleTab =putInTable(string,table);
   for (int i = 0; i <tailleTab ; i++)
   {
     printf("%s\n",table[i].info);
   }


    return 0;
}
