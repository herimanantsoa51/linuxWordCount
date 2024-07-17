#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000

FILE* Open(char *str);
int CountLine(FILE* file);
int CountChar(FILE* file);
int CountWord(FILE* file);
int CountMaxLine(FILE* file);
void Display(int opt);
int* AllocationM(int n);
int Tabmax(int*A,int n);
void Sdisplay(char* str,int a,int b,int c);
void Tdisplay(int a);

int main (int argc, char* argv[])
{   

    
    FILE* file=NULL;
    int c=0,i=0,l=0,w=0,tl=0,tw=0,tc=0,n=0,j=0;
    n=strlen(argv[1]);
    
    if (argc >= 3 && argv[1][0]=='-')
    {   
        for (i=2;i<argc;i++)
        {
            for (j=1;j<n;j++)
            {
                    {   
                        
                        file=Open(argv[i]);
                        Display(argv[1][j]);
                        switch (argv[1][j])
                        {
                        case 'l':
                            Tdisplay(CountLine(file));
                            break;
                        case 'm':
                            Tdisplay(CountChar(file));
                            break;
                        case 'w':
                            Tdisplay(CountWord(file));
                            break;
                        case 'L':
                            Tdisplay(CountMaxLine(file));
                            break;
                        default:
                            break;
                        }
                        
                        fclose(file);
                    }
            }
            printf("%s\n",argv[i]);
        }
    }
    
    else
    {
        for (i=1;i<argc;i++)
        {   
            file=Open(argv[i]);
            l=CountLine(file);
            w=CountWord(file);
            c=CountChar(file);
            tl +=l;
            tw +=w;
            tc +=c;
            Sdisplay(argv[i],l,w,c);
            fclose(file);
        }
        if (argc>1)
            Sdisplay("total",tl,tw,tc);
    }
    

    return 0;

}

FILE* Open(char *str)
{
    FILE* file=fopen(str,"r");
    if(file==NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        exit (EXIT_FAILURE);
    }
    return(file);
}

int CountLine(FILE* file)
{   
    char str[max];
    int count=0;
    while (fgets(str,max,file)!=NULL)
        count++;
    rewind(file);
    return (count);  
    
}
int CountChar(FILE* file)
{   
    int c=0;
    int m;
    do 
    {   
        
        m=fgetc(file);
        if(m!='\n')
            c++;

    }while (m!=EOF);
    rewind(file);
    
    return(c);
    
}

int CountWord(FILE* file)
{
    int c=0;
    char m[max];
    while (!feof(file))
    {
        fscanf(file,"%s",m);
            c++;
    }
    
    rewind(file);
    return(c-1);

}
int CountMaxLine(FILE* file)
{
    int c=0,l=0,i=0;
    int m;
    int *A=NULL;
    l=CountLine(file);
    A=AllocationM(l);
    do 
    {   
        
        m=fgetc(file);
        if(m =='\n')
        {
            A[i]=c-1;
            i++;
            c=0;
            
        }
        else
            c++;

    }while (m!=EOF);

    rewind(file);
    return(Tabmax(A,l));
    
}
void Display(int opt)
{
    switch (opt)
    {
    case 'l':
        printf("N_line:\t");
        break;
    case 'm':
        printf("N_character:\t");
        break;
    case'w':
        printf("N_words:\t");
        break;
    case'L':
        printf("N_max_line_length:\t");
        break;
    default:
        printf("Option disabled\n");
        exit(1);
        break;
    }
}
int* AllocationM(int n)
{
    int *A=NULL;
    A=(int*)malloc(n*sizeof(int));
    if (A==NULL)
    {
        printf("Erreur d'Allocation memoire\n");
        exit (1);
    }
    return(A);

}

int Tabmax(int*A,int n)
{   
    int i=0,maxi=A[0];
    for(i;i<n;i++)
    {
        if(maxi<A[i])
        {
            maxi =A[i];
        }
    }
    return(maxi);
}
void Sdisplay(char* str,int a,int b,int c)
{
    printf("%d\t%d\t%d\t%s\n",a,b,c,str);
}
void Tdisplay(int a)
{
    printf("%d\t",a);
}

