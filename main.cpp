// Autore:  Lanzarotti Valentino
/* 
   Descrizione: 
   Pagina che contiene la funzione  principale
*/
// Versione: 0.1
// 


// Inclusione dei file header:
#include <iostream>
#include <fstream>
#include "functionsgestionale.h"
#include "fungo.h"
 
using namespace std;
const int DIM=100;  // Dimensione massima del vettore fungo 


// Stringa che punta al file txt chiamato databasefunghi.txt
const string filegestionale="databasefunghi.txt";

// Funzione  Principale:<

int main(int argc, char** argv) 
{
 bool value;
 char scelta;
 char scelt,sceltar,metodo;
 string ricerca;
 int count=0;
 do 
 {
  Clearthescreen();	
  cout<< " MENU PRINCIPALE GESTIONALE PER LA CLASSIFICAZIONE DEI FUNGHI  "  << endl << endl
      << " 1) Inizializzazione del database del gestionale               "	<< endl << endl
      << " 2) Aggiungi un elemento al database                           "  << endl << endl
      << " 3) Modifica dati di un elemento registrato                    "  << endl << endl
      << " 4) Cancella elemento selezionato                              "  << endl << endl
      << " 5) Ricerca un elemento nel database                           "  << endl << endl
      << " 6) Statistiche del gestionale                                 "  << endl << endl
      << " 7) Elimina dati dal database del gestionale                   "  << endl << endl
      << " 8) Uscita dal programma                                       "  << endl << endl
      << " Selezionare l'opzione desiderata:                             ";
    cin>> scelta;
    switch(scelta)
    {
     case '1':
	 case 'I':
	 case 'i':
	 	      // Verifica del file
	 	     if(VerificaFile(filegestionale)==false) // se non trova il file
	 	      {
	 	       Alert("Il file databasefunghi.txt non esiste ");	
	 	       break;
			  }
			  //else if(VerificaFile(filegestionale)==true) // se   trova il file
	 	      else
			  {
	 	       Alert("Il file databasefunghi.txt   esiste ");
			   break;	
			  }
	 case '2':
	 case 'A':
	 case 'a':
	          Clearthescreen();
	          if(VerificaFile(filegestionale)==false) // se non trova il file
	 	      {
	 	       Alert("Il file databasefunghi.txt non esiste ");	
			  }
			  else if(VerificaFile(filegestionale)==true)
			  {
			   AggiungiDati(filegestionale);	
			  }
	          break;
	 case '3':
	 case 'M':
	 case 'm':
	          Clearthescreen();
	          if(VerificaFile(filegestionale)==false) // se non trova il file
	 	      {
	 	       Alert("Il file databasefunghi.txt non esiste ");	
			  }
			  else if(VerificaFile(filegestionale)==true)
			  {
			   int idm;
			   cout<< "Inserire l'id del record da modificare: ";
			   cin>>idm;	
			   ModificaDati(filegestionale,idm);	
			  }
	          break;
	 case '4':
	 case 'C':
	 case 'c':
	           Clearthescreen();
	          if(VerificaFile(filegestionale)==false) // se non trova il file
	 	      {
	 	       Alert("Il file databasefunghi.txt non esiste ");	
			  }
			  else if(VerificaFile(filegestionale)==true)
			  {
			   int idm;
			   cout<< "Inserire l'id del record da cancellare: ";
			   cin>>idm;	
			   CancellaDati(filegestionale,idm);	
			  }
	          break;
	 case '5':
	 case 'R':
	 case 'r':
	          Clearthescreen();
	          do
	          {
	           Clearthescreen();
			   cout<< " MENU RICERCA DEL GESTIONALE                   " << endl << endl
			       << " 1) Ricerca fungo per habitat                  " << endl << endl
				   << " 2) Ricerca fungo per zona                     " << endl << endl
				   << " 3) Ricerca fungo per famiglia                 " << endl << endl 
				   << " 4) Ricerca fungo per genere                   " << endl << endl
				   << " 5) Ricerca fungo per regno                    " << endl << endl
				   << " 6) Ricerca fungo per ordine                   " << endl << endl
				   << " 7) Ritorna al menup principale del gestionale " << endl << endl
				   << " Selezionare l'opzione desiderata: ";
				cin>>sceltar;
				switch(sceltar)
				{
				 case '1':
				 case 'H':
				 case 'h':
				          Clearthescreen();
				 	      cout<< " Ricerca fungo per Habitat " << endl << endl
				 	          << " Inserire l'habitat:       ";
				 	      cin>>ricerca;    
				 	      metodo='h';
				 	      RicercaDati(ricerca,metodo,filegestionale);
				          break;
				 case '2':
				 case 'Z':
				 case 'z':
				 	      Clearthescreen();
				 	      cout<< " Ricerca fungo per Zona " << endl << endl
				 	          << " Inserire la zona:       ";
				 	      cin>>ricerca; 
						  metodo='z';  
				 	      RicercaDati(ricerca,metodo,filegestionale);
				          break;
				 case '3':
				 case 'F':
				 case 'f':
				 	      cout<< " Ricerca fungo per Famiglia " << endl << endl
				 	          << " Inserire la faniglia:       ";
				 	      cin>>ricerca; 
						  metodo='f';  
				 	      RicercaDati(ricerca,metodo,filegestionale);
				          break;
				 case '4':
				 case 'G':
				 case 'g':
				 	      Clearthescreen();
				 	      cout<< " Ricerca fungo per Genere " << endl << endl
				 	          << " Inserire il genere:       ";
				 	      cin>>ricerca; 
						  metodo='g';  
				 	      RicercaDati(ricerca,metodo,filegestionale); 
				          break;
				 case '5':
				 case 'R':
				 case 'r':
				    	  Clearthescreen();
				 	      cout<< " Ricerca fungo per Regno " << endl << endl
				 	          << " Inserire il regno:       ";
				 	      cin>>ricerca; 
						  metodo='r';  
				 	      RicercaDati(ricerca,metodo,filegestionale);
				          break;
				 case '6':
				 case 'O':
				 case 'o':
				 	      Clearthescreen();
				 	      cout<< " Ricerca fungo per Ordine " << endl << endl
				 	          << " Inserire il regno:       ";
				 	      cin>>ricerca; 
						  metodo='r';  
				 	      RicercaDati(ricerca,metodo,filegestionale);
				          break;
				 case '7':
				 case 'U':
				 case 'u':
				  		  break;		  		  		  		  		  	
			    }
				break;    	
			  }
			  while(sceltar!='7'||sceltar!='U'||sceltar!='u');
	          break;
	 case '6':
	 case 'S':
	 case 's':
	          Clearthescreen();
	          do
	          {
	          	Clearthescreen();
	           cout<< " MENU STATISTICHE DEL GESTIONALE "  << endl << endl
			       << " 1) Totale  funghi per habitat    "  << endl << endl
				   << " 2) Totale  funghi per zona       "  << endl << endl
				   << " 3) Totale  funghi per famiglia   "  << endl << endl
				   << " 4) Totale  funghi per genere     "  << endl << endl
				   << " 5) Totale  funghi per regno      "  << endl << endl
				   << " 6) Ricerca fungo per ordine     "  << endl << endl
				   << " 7) Totale record salvati        "  << endl << endl
				   << " 8) Uscita dalle statistiche     "  << endl << endl
				   << " Selezionare l'opzione desiderata: ";
				cin>>scelt;
				switch(scelt)
				{
				 case '1':
				 case 'H':
				 case 'h':
				 	      Clearthescreen();
				 	      cout<< " Totale funghi per habitat " << endl << endl;
				 	      metodo='h';
				 	      TotaleDati(ricerca,metodo,filegestionale);
				 	      break;
				 case '2':
				 case 'Z':
				 case 'z':
				 	      Clearthescreen();
				 	      cout<< " Totale funghi per zona " << endl << endl;
				 	      metodo='z';
				 	      TotaleDati(ricerca,metodo,filegestionale);
				 	      break;
				 case '3':
				 case 'F':
				 case 'f':
				 	      Clearthescreen();
				 	      cout<< " Totale funghi per famiglia " << endl << endl;
				 	      metodo='f';
				 	      TotaleDati(ricerca,metodo,filegestionale);
				 	      break;
				 case '4':
				 case 'G':
				 case 'g':
				 	      Clearthescreen();
				 	      cout<< " Totale funghi per habitat " << endl << endl;
				 	      metodo='g';
				 	      TotaleDati(ricerca,metodo,filegestionale);
				 	      break;
				 case '5':
				 case 'R':
				 case 'r':
				 	      Clearthescreen();
				 	      cout<< " Totale funghi per regno " << endl << endl;
				 	      metodo='r';
				 	      TotaleDati(ricerca,metodo,filegestionale);
				 	      break;	  		 
				 case '6':
				 case 'O':
				 case 'o':
				 	      Clearthescreen();
				 	      cout<< " Totale funghi per ordine " << endl << endl;
				 	      metodo='o';
				 	      TotaleDati(ricerca,metodo,filegestionale);
				 	      break;
				 case '7':
				 case 'T':
				 case 't':
				 	      Clearthescreen();
				 	      count=GetId(filegestionale);
						  cout<< "Totale record salvati nel gestionale:   " << count << endl << endl;  
				          break;
			     case '8':
				 case 'U':
				 case 'u':
				          break; 
				 default: 
	                     cout<< "Opzione non disponibile o tasto errato!";
			             Delaycls();
			             Clearthescreen();		
			             break;		  		    	      
				} 
				break;   	
			  }
			  while(scelt!='8'||scelt!='U'||scelt!='u');
			  break;
	 case '7':
	 case 'E':
	 case 'e':
	 	      Clearthescreen(); 
	 	      EraseDatabase(filegestionale);
	 	      break;  
	          break;
	 case '8':
	 case 'U':
	 case 'u':
 	 	      exit(0);
	          break;
	 default: 
	         cout<< "Opzione non disponibile o tasto errato!";
			 Delaycls();
			 Clearthescreen();		
			 break;  			  		  		  		  		    	      
	}
      
 }
 while(scelta!='8'||scelta!='U'||scelta!='u');	
}


