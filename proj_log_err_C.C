#include<stdio.h>
#include<time.h>

typedef struct         // Strucure qui permet de stocher  date et le temps
{
	int a;
	int m;
    int j;
	int h;	
	int min;	
	int s;  		
}datetime;



datetime liredatetime( ) // fonction permet de lire la  date  et le temps au clavier saisie par un utilisateur
{
	datetime D_T;

	
	printf("\n\nla date  (sous forme  an/m/j) : ");
	scanf("%d/%d/%d",&(D_T.a),&(D_T.m),&(D_T.j));
	getchar();
	printf("l'heur de debut (sous forme h:min:s) : ");
	scanf("%d:%d:%d",&(D_T.h),&(D_T.min),&(D_T.s));
	getchar();
	
	return D_T ;
}


int ComparerDatetime( datetime DatTim1 , datetime DatTim2 )
  /* fonction permet de Comparer deux  dates avec le temps :
     return 1 si datetime1 > datetime2 
     return -1 si datetime1 < datetime2
     return 0 si datetime1 = datetime2
  */
{
	if( DatTim1.a > DatTim2.a) return 1 ;
	else if( DatTim1.a < DatTim2.a ) return -1;
	else if( DatTim1.m > DatTim2.m ) return 1;
	else if (DatTim1.m < DatTim2.m) return -1;
	else if(DatTim1.j> DatTim2.j) return 1;
	else if(DatTim1.j < DatTim2.j) return -1 ;
	else if(DatTim1.h> DatTim2.h) return 1;
	else if(DatTim1.h < DatTim2.h) return -1 ;
	else if(DatTim1.min> DatTim2.min) return 1;
	else if(DatTim1.min < DatTim2.min) return -1 ;
	else if(DatTim1.s> DatTim2.s) return 1;
	else if(DatTim1.s < DatTim2.s) return -1 ;
	return 0 ;
	
}


void AfficherErreur( ){ // Permet d'afficher tout les erreurs commises entre deux dates saisies par l'utilisateur 
	
     datetime debut , fin ;

     printf("\nSaisir La date et l'heur de debut :");
     debut = liredatetime();
    
     printf("\nSaisir la date et l'heur de fin ");
      fin = liredatetime();
      
    
    if( ComparerDatetime( fin , debut ) >= 0 )
	{	   
    	int NumErr;
    	char mess[40];
    	datetime LirLign;
        FILE * f;	
	f= fopen("FichierLog.txt","r");

	if(f){
      		while( fscanf(f,"Date : %d/%d/%d temps : %d/%d/%d NumErreur : %d %s [^\n]",&LirLign.a,&LirLign.m,&LirLign.j,&LirLign.h,&LirLign.min,&LirLign.s,&NumErr,mess) != EOF )
{
	if( ComparerDatetime( LirLign , debut ) >= 0 && ComparerDatetime( fin , LirLign ) >= 0 )
{
      				printf("\n La date : %d/%d/%d Temps : %d:%d:%d NumeroErreur : %d Message : %s",LirLign.a,LirLign.m,LirLign.j,LirLign.h,LirLign.min,LirLign.s,NumErr,mess);
				}
			
      				
			}
      		
		}
		else
		{
			printf("\nEchec d'ouverture ");
		}
		fclose(f);	      
	
	}	
	else
	{
		printf("\nErreur : la date de debut est superieur a la date de fin ");
	}     
	
 }


	

	

int main()
{ 
	AfficherErreur( );
	
	return 0 ;	 
}
