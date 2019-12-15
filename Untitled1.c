// projekt.c -- Jakub Gašparín, 23.11.2019 15:35

#include <stdio.h>
int funN(char *p)		//načítanie do pov. pola
{
	FILE*sifra;
	int i=0;
	char c;
	if	((sifra = fopen("sifra.txt","r"))!=NULL)
	{
		while ((c=fgetc(sifra))!=EOF)
		{
			p[i]=c;
			i++;
		}
	}
	else (printf("Subor sa nenasiel"));
	fclose(sifra);
	return i;
}

void funV(char *p, int N)	//Vypis pola
{
	int i=0;
	do
	{
		printf("%c",p[i]);
		i++;
	}
	while (i<N);
	printf("\n");
	return;
}

int funU(char *p,char *u,int N)		//načítanie do upr. pola
{ 
    	int i=0,f=0;	
	while (i<N)
        {
         if (p[i]>='a' && p[i]<='z')
            {
              u[f]=p[i];
              u[f]=u[f]-32;
              f++;
            }
            else if(p[i]>='A' && p[i]<='Z')
            {
              u[f]=p[i];
              f++;
            }
          
            i++;
        }
    
	return f;        
}

void funS(char *u,int V)	//výpis upr. pola
{	int f=0;
	do
	{
		printf("%c",u[f]);
		f++;
	}
	while (f<V);
	printf("\n");
	return;	
}
void funD(char *p,int N)	// zistenie dlzky slov v poli
{  
	int i=0,,pocet=0,k;
	scanf("%d",&k);
	if (k>=1 && k<=100)
	{	
		while (i<N)
		{			
			if (p[i]==' ' && pocet==3)
			{
				
				i=i-3;
				printf("%c%c%c",p[i],p[i+1],p[i+2]);
				pocet=0;
				i=i+3;
				printf("\n");
			} 
			
			else if (p[i]==' ')
				{
					pocet=0;
					i++;			
				}
			 	else 
			 	{
			 		i++;
			 		pocet++;
				}			
		}
	}
	else 
	{
		printf("Zla dlzka slova.");
		return;
	}
	printf("\n");
	return;
}

void funC(char *u, int V)			// Cesarova sifra. 
{	
    int f=0;
    scanf("%d",&n);
    while(f<V)
    {
    	if(u[f]>='a' && u[f]<='z')
		{
			u[f]=u[f]-n;			
			if(u[f]>'a')
			{
			 	u[f] = u[f]-'a'+'z'-1;
			}			
		}
		else if(u[f] >= 'A' && u[f]<='Z')
		{
			u[f]=u[f]+n;			
			if(u[f]>'A')
			{
				u[f] = u[f]-'A'+'Z'-1;
			}			
		}
		printf("%c",u[f]);
		f++;
	}
    printf("\n"); 
    return;
}

int main()				//hlavna funckia
{
  char ch;
  char povText[1000]={0},uprText[1000]={0};
  int N,V; 
  int pole,i,f;
	
  do
  { 
  scanf("%c",&ch);
  
  switch (ch)	//Switch case vo while, aby sa priíkazy mohli opakovať do kola, do kial sa nestlaci k. 
  {
    case 'n': N=funN(povText); break;  
    case 'v': funV(povText,N); break;
    case 'u': V=funU(povText,uprText,N); break;
    case 's': funS(uprText,V); break;    
    case 'd': funD(povText,N); break;    
    case 'c': funC(uprText,V); break;
   }

  }
  while(ch!='k'); 
  return 0;
}
