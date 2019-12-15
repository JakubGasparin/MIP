// projekt.c -- Jakub Gašparín, 23.11.2019 15:35

#include <stdio.h>
int funN(char *p)									//načítanie do pov. pola
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

void funV(char *p, int N)						//Vypis pola
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

int funU(char *p,char *u,int N)								//načítanie do upr. pola
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

void funS(char *u,int V)							//výpis upr. pola
{	int f=0;
	do
	{
		printf("%c",u[f]);
		f++;
	}
	while (f<V);
	printf("\n");
	return;	

void funD(char *p,int N)										// zistenie dlzky slov v poli
{  
	int i=0,k;
	scanf("%d",&k)
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



void funC()									// Cesarova sifra. 
{
	int i=0,f=0,n;
	char povText[1000], uprText[1000];
	char ch;
	FILE*sifra;
	sifra =fopen("sifra.txt","r");
	scanf("%d",&n);
    while (fscanf(sifra,"%c",&ch)!=EOF && i!=1000 )
    {
      povText[i]=ch;
      i++;
    }
    fclose(sifra);  
    i=0;	
	while (povText[i]!='\0')
        {
         if (povText[i]>='a' && povText[i]<='z')
            {
              uprText[f]=povText[i];
              uprText[f]=uprText[f]-32;
              f++;
            }
            else if(povText[i]>='A' && povText[i]<='Z')
            {
              uprText[f]=povText[i];
              f++;
            }
          
            i++;
        }   
        
    i=0;
    f=0;
    while(uprText[f]!='\0')
    {
    	if(uprText[f]>='a' && uprText[f]<='z')
		{
			uprText[f]=uprText[f]-n;
			
			if(uprText[f]>'a')
			{
				uprText[f] = uprText[f]-'a'+'z'-1;
			}			
		}
		else if(uprText[f] >= 'A' && uprText[f]<='Z')
		{
			uprText[f]=uprText[f]+n;			
			if(uprText[f]>'A')
			{
				uprText[f] =uprText[f]-'A'+'Z'-1;
			}		
			
		}
		printf("%c",uprText[f]);
		f++;
	}
    printf("\n"); 
    fclose(sifra);
    return;
}

int main()									//hlavna funckia

{
  char ch;
  char povText[1000],uprText[1000];
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
   }

  }
  while(ch!='k'); 
  return 0;
}

//Program som robil v DevC++ a tam mi všetko išlo, len turing mi to nechce zobrať. 
