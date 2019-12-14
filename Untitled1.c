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

void funU()								//načítanie do upr. pola
{
	int i=0,f=0;
	char povText[1000], uprText[1000];
	char ch;
	FILE*sifra;
	sifra =fopen("sifra.txt","r");
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
    fclose(sifra);
	return;        
}

void funS()							//výpis upr. pola
{
	int i=0,f=0;
	char povText[1000], uprText[1000];
	char ch;
	FILE*sifra;
	sifra =fopen("sifra.txt","r");
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
		
	while (uprText[f]!='\0')
          {
            printf("%c",uprText[f]);
            f++;
          }
    printf("\n"); 
	fclose(sifra);   
	return;
}

void funD()										// zistenie dlzky slov v poli
{
	FILE*sifra;
	char povText[1000];
	char ch;
	int i=0, k,pocet=0;
	sifra =fopen("sifra.txt","r");
	scanf("%d",&k);
    while (fscanf(sifra,"%c",&ch)!=EOF && i!=1000 )
    {
      povText[i]=ch;
      i++;
    }
    fclose(sifra);    
    
	i=0;	  	
	if (k>=1 && k<=100)
	{
		
		while (povText[i]!='\0')
		{
			
			if (povText[i]==' ' && pocet==3)
			{
				
				i=i-3;
				printf("%c%c%c",povText[i],povText[i+1],povText[i+2]);
				pocet=0;
				i=i+3;
				printf("\n");
			} 
			
			else if (povText[i]==' ')
				{
					pocet=0;
					i++;			
				}
			 	else 
			 	{
			 		i++;
			 		pocet++;
				}
			/*{
				i++;
				pocet++;
			
			}*/
			
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

/*void funH()					//nieco, co som spravil z histogramu
{
	int i=0,f=0;
	int pismena=26;
	char povText[1000], uprText[1000];
	int a,b,c,d,e,F,g,h,I,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
	char ch;
	FILE*sifra;
	sifra =fopen("sifra.txt","r");
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
        
    f=0;
    while(uprText[f]!='\0')
    {
    	switch 
    	{
    		case 'a': a++; break;
    		case 'b': b++; break;
    		case 'c': c++; break;
    		case 'd': d++; break;
    		case 'e': e++; break;
    		case 'F': F++; break;
			case 'g': g++; break;
			case 'h': h++; break;
			case 'I': I++; break;
			case 'j': j++; break;
			case 'k': k++; break;
			case 'l': l++; break;
			case 'm': m++; break;
			case 'n': n++; break;
			case 'o': o++; break;
			case 'p': p++; break;
			case 'q': q++; break;
			case 'r': r++; break;
			case 's': s++; break;
			case 't': t++; break;
			case 'u': u++; break;
			case 'v': v++; break;
			case 'W': w++; break;
			case 'x': x++; break;
			case 'y': y++; break;
			case 'z': z++; break;
		}
    f++;
	for (i=0;i<pismena)
	{
		
	}
	printf("ABCDEFGHIJKLMNAOPQRSTUVWXYZ\n");
	if 
	
}*/

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

void funP()
{
	FILE*sifra;
	char povText[1000];
	char ch;
	int i=0,z,k;
	sifra =fopen("sifra.txt","r");
	scanf("%d%d",&z,&k);
    while (fscanf(sifra,"%c",&ch)!=EOF && i!=1000 )
    {
      povText[i]=ch;
      i++;
    }
    fclose(sifra);  
	i=0;  
    while (povText[i]!='\0')
    {
    	if (i>=z-1 && i<=k-1)
    	{
    		if (povText[i]==' ')
    		{
    			printf("+");
			}
    		else if (printf("%c",povText[i]));
		}
		i++;
	}
    

    
}

void funZ()
{
	int i=0,f=0,g=0;
	char povText[1000], uprText[1000];
	char ch,r[10];
	scanf("%s",&r);
	int podmienky=0,parny=0;
	FILE*sifra;
	sifra =fopen("sifra.txt","r");
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
    fclose(sifra);
	printf("\n");
	g=parny;
	g=0;
	while (r[g]!='\0')
	{
		if (r[g]>='A' && r[g]<='Z') 
		{
			g++;
		}
		else
		{
			printf("Retazec nie je mozne vlozit\n");
			return;
		}
		
    }
    if (parny+f%2==0) podmienky++;
	if (parny+f<1000) podmienky++;   
	if (podmienky!=2) 
	{
		printf("Retazec nie je mozne vlozit\n");	
	}
	else (printf("Retazec sa vlozil\n"));
	f=0;
	g=0;
	while(uprText[f]!='\0');
	{
		printf("got this far");
		printf("%c",uprText[f]);
		if (f==f/2)
		{
			while(r[g]!='\0');
			{
				printf("%c",r[g]);
				g++;
			}
			
		}
		f++;
	}
	printf("\n");
	
    return;
}

int main()									//hlavna funckia

{
  char ch;
  char povText[1000],uprText[1000];
  int pole,i,f;  
  int test=0;
  do
  { 
  scanf("%c",&ch);
  
  switch (ch)								//Switch case vo while, aby sa priíkazy mohli opakovať do kola, do kial sa nestlaci k. 
  {
    case 'n': test=1; funN(); break;      

    case 'v': {
    	if (test==1)
		{
			funV();
		}
		else (printf("Sprava nie je nacitana\n"));
	}break;

    case 'u': {	
       if (test==1) 
       {
        funU(); test=2;
       }     
      else (printf("Sprava nie je nacitana\n"));
    }break;

    case 's' :
    {
      if (test==2)
	  {
      	funS();
	  }
	  else (printf("Sprava nie je nacitana\n"));
    }break;
    
    case 'd': {
    	if (test==2 || test==1)
    	{
    		funD();
		}
		else (printf("Sprava nie je nacitana\n"));
	}break;
	
	/*case 'h':{
		 if (test==2)
		 {
		 	funH();
		 }
		 else (printf("Nie je k dispozicii upravena sprava.\n"));
		
	}break;*/
	
	case 'c':{
		if (test==2)
		{
			funC();
		}

	}break;
	
	case 'p':{
		if (test==1)
		{
			funP();
		}
		else (printf("Sprava nie je nacitana\n"));
		
	}break;
	
	case 'z':{
		if (test==2)
		{
			funZ();
		}
		else (printf("Nie je k dispozicii upravena sprava.\n"));
		
	}break;
    
    }

  }
  while(ch!='k'); 
  return 0;
}

//Program som robil v DevC++ a tam mi všetko išlo, len turing mi to nechce zobrať. 
