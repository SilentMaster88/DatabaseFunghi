// Autore:  Lanzarotti Valentino
/*
  Descrizione:
  Pagina che contiene la definizione delle funzioni
*/
// Versione: 0.1
//  

// Inclusione file header
#include "functionsgestionale.h"
#include "fungo.h"
#include <fstream>
#include <iostream>
#include <cctype>

// Sviluppo delle funzioni:

/*
 Funzione che richiama il clearscreen 
*/
void Clearthescreen() {system("cls");}

/*
Funzione che presa una stringa stampa un messaggio
*/
void Alert(string er)
{
 cout<<  er << "\n";
}

/*
Funzione che richiama la pausa
*/
void Delaycls()
{
 system( "pause" );	
}

/*
Funzione che verifica la presenza del file gestionale
*/
bool VerificaFile(string file)
{
 bool esiste=false;
 fstream filegest;
 filegest.open(file.c_str(), ios::in ); // sola lettura
 if( filegest.is_open() ){esiste=true;} 
 filegest.close(); 
 return esiste; 
}

/*
Funzione che verifica se il file è vuoto
*/
bool VerificaVuoto(string file)
{
 fstream in(file.c_str(),ios::in);
 in.seekp(0, ios::end);
 int spot = in.tellg();
 if( spot == 0)
 {
   return true;
 }	
 else
 {
  return false;	
 }	
}

/*
Funzione che permette di fare i primi inserimenti nel file ttxt
*/ 
void PrimoInserimento(string nf)
{
 // Richiesta dei dati del fungo
 int id=1;	
 char sceltaop;
 int IDap;
 string NomCom,NomLat;
 string Regn,Div;
 string Clas,Ord;
 string Fam,Gen;
 string Spec,Habit;
 string Zon; 
 fstream out;
 out.open(nf.c_str(),ios::app );
  do
  {
   cout<< "Inserire i dati richiesti per poter creare i primi inserimenti " << endl << endl;
   cout<< "ID del record:    " << id << endl;
   cout<< "Inserire il nome comune del fungo:  ";
   cin>>NomCom;
   cout<< endl
       << "Inserire il nome latino del fungo:  ";
   cin>>NomLat;
   cout<< endl
	   << "Inserire il regno del fungo:   ";
   cin>>Regn;
   cout<< endl
       << "Inserire la divisione del fungo: ";
   cin>>Div;
   cout<< endl
       << "Inserire la classe del fungo:   ";
   cin>>Clas;
   cout<< endl
       << "Inserire l ordine del fungo:    ";
   cin>>Ord;
   cout<< endl
       << "Inserire la famiglia del fungo: ";
   cin>>Fam;
   cout<< endl
       << "Inserire il genere del fungo: ";
   cin>>Gen;
   cout<< "Inserire la specie del fungo: ";
   cin>>Spec;
   cout<< endl
       << "Inserire habitat del fungo: ";
   cin>>Habit;
   cout<< endl
       << "Inserire la zona del fungo: ";
   cin>>Zon;
   cout<< endl;
   if(out.fail()==false)
   {
    out<< id      << endl
       << NomCom  << endl
       << NomLat  << endl
       << Regn    << endl
       << Div     << endl
       << Clas    << endl
       << Ord     << endl
       << Fam     << endl
       << Gen     << endl
       << Spec    << endl
       << Habit   << endl
       << Zon     << endl << endl;
  
  Alert("Scrittura su file eseguita correttamente");
 }	
 else
 {
  Alert("Scrittura su file non eseguita");	 
 }
   cout<< endl
       << "Inserire un altro fungo nel database? s/n";
   cin>>sceltaop;    
   id++;								    
  }
  while(sceltaop!='n');
   out.close();   
 // uscita dalla funzione	
}

/*
Funzione che permette di inserire i dati
*/
void InserimentoDati(string nfl)
{
 Alert("Il file esiste e verranno aggiunti altri dati");
 // Richiesta dei dati del fungo
 //int id=1;	
  int id=1+(GetId(nfl));
 char sceltaop;
int IDap;
 string NomCom,NomLat;
 string Regn,Div;
 string Clas,Ord;
 string Fam,Gen;
 string Spec,Habit;
 string Zon; 
  fstream out;
  out.open(nfl.c_str(),ios::app );
  do
  {
   cout<< "Inserire i dati richiesti per poter creare i primi inserimenti " << endl << endl;
   cout<< "ID del record:    " << id << endl;
   cout<< "Inserire il nome comune del fungo:  ";
   cin>>NomCom;
   cout<< endl
       << "Inserire il nome latino del fungo:  ";
   cin>>NomLat;
   cout<< endl
	   << "Inserire il regno del fungo:   ";
   cin>>Regn;
   cout<< endl
       << "Inserire la divisione del fungo: ";
   cin>>Div;
   cout<< endl
       << "Inserire la classe del fungo:   ";
   cin>>Clas;
   cout<< endl
       << "Inserire l ordine del fungo:    ";
   cin>>Ord;
   cout<< endl
       << "Inserire la famiglia del fungo: ";
   cin>>Fam;
   cout<< endl
       << "Inserire il genere del fungo: ";
   cin>>Gen;
   cout<< "Inserire la specie del fungo: ";
   cin>>Spec;
   cout<< endl
       << "Inserire habitat del fungo: ";
   cin>>Habit;
   cout<< endl
       << "Inserire la zona del fungo: ";
   cin>>Zon;
   cout<< endl;
   if(out.fail()==false)
   {
    out<< id     << endl
       << NomCom << endl
       << NomLat << endl
       << Regn   << endl
       << Div    << endl
       << Clas   << endl
       << Ord    << endl
       << Fam    << endl
       << Gen    << endl
       << Spec   << endl
       << Habit  << endl
       << Zon    << endl << endl;
  
  Alert("Scrittura su file eseguita correttamente");
 }	
 else
 {
  Alert("Scrittura su file non eseguita");	 
 }
   cout<< endl
       << "Inserire un altro fungo nel database? s/n";
   cin>>sceltaop;    
   id++;								    
  }
  while(sceltaop!='n');
   out.close();   
}

/*
Funzione che restituisce il totale dei record presenti
*/
int GetId(string nfile)
{
 int idcount=0;	
 fstream in;
 in.open(nfile.c_str(), ios::in);
  
 if(in)
 {
  char IDval;
  while(!in.eof())
  {
   in>> IDval;
   if(isdigit(IDval))
   {
    idcount++;
   }
  }   
 }
 in.close();
 cout<< "Nel file sono presenti:  " << idcount << "record" << endl;
   return idcount;
}

/*
Funzione che permette di aggiungere i dati in append
*/
void AggiungiDati(string nfl)
{
 int id=1+(GetId(nfl));
 char sceltaop;
int IDap;
 string NomCom,NomLat;
 string Regn,Div;
 string Clas,Ord;
 string Fam,Gen;
 string Spec,Habit;
 string Zon; 
  fstream out;
  out.open(nfl.c_str(),ios::app );
  do
  {
   cout<< "Inserire i dati richiesti per poter creare i primi inserimenti " << endl << endl;
   cout<< "ID del record:    " << id << endl;
   cout<< "Inserire il nome comune del fungo:  ";
   cin>>NomCom;
   cout<< endl
       << "Inserire il nome latino del fungo:  ";
   cin>>NomLat;
   cout<< endl
	   << "Inserire il regno del fungo:   ";
   cin>>Regn;
   cout<< endl
       << "Inserire la divisione del fungo: ";
   cin>>Div;
   cout<< endl
       << "Inserire la classe del fungo:   ";
   cin>>Clas;
   cout<< endl
       << "Inserire l ordine del fungo:    ";
   cin>>Ord;
   cout<< endl
       << "Inserire la famiglia del fungo: ";
   cin>>Fam;
   cout<< endl
       << "Inserire il genere del fungo: ";
   cin>>Gen;
   cout<< "Inserire la specie del fungo: ";
   cin>>Spec;
   cout<< endl
       << "Inserire habitat del fungo: ";
   cin>>Habit;
   cout<< endl
       << "Inserire la zona del fungo: ";
   cin>>Zon;
   cout<< endl;
   if(out.fail()==false)
   {
    out<< id      << endl
       << NomCom  << endl
       << NomLat  << endl
       << Regn    << endl
       << Div     << endl
       << Clas    << endl
       << Ord     << endl
       << Fam     << endl
       << Gen     << endl
       << Spec    << endl
       << Habit   << endl
       << Zon     << endl << endl;
  
  Alert("Scrittura su file eseguita correttamente");
 }	
 else
 {
  Alert("Scrittura su file non eseguita");	 
 }
   cout<< endl
       << "Inserire un altro fungo nel database? s/n";
   cin>>sceltaop;    
   id++;								    
  }
  while(sceltaop!='n');
   out.close();   
  			
}

/*
Funzione che permette di modificare i dati di un record
*/
void ModificaDati(string nfl,int idmod)
{
 // Caricamento dati nel vettore di oggetti fungo
 int dimensione=GetId(nfl);
  string modifica;
 // Ricerca dell'id da cancellare
 Fungo mod[dimensione];
 char Sceltamod,confop;
 do
 {
  cout<< "MENU MODIFICA DATI FUNGO CON  ID   " << idmod << endl << endl
      << "0) Modifica Nome Comune            " << endl
	  << "1) Modifica Nome Latino            " << endl
	  << "2) Modifica Regno                  " << endl
	  << "3) Modifica Divisione              " << endl
	  << "4) Modifica Classe                 " << endl
	  << "5) Modifica Ordine                 " << endl
	  << "6) Modifica Famiglia               " << endl
	  << "7) Modifica Genere                 " << endl
	  << "8) Modifica Specie                 " << endl
	  << "9) Modifica Habitat                " << endl
	  << "U) Uscita dal menu modifica        " << endl
	  << "SCegliere l'opzione desiderata:    ";
  cin>>Sceltamod;
  switch(Sceltamod)
  {
   case '0':
   case 'N':
   case 'n':
            Clearthescreen();
            cout<< "Inserire il nuovo nome comune:  ";
            cin>>modifica;
            cout<< endl
                << "Continuare con l'operazione? y/n " << endl;
            cin>>confop;
			if(confop=='y')        
			{
			 mod[idmod].SetNomeComune(modifica);	
			 // Salva modifiche su file
			 SalvaModifiche(nfl,mod,dimensione);
			} 
			else
			{
			 cout<< "Modifica non salvata" << endl;	
			}       
            break;
   case '1':
   case 'L':
   case 'l':
   	        Clearthescreen();
            cout<< "Inserire il nuovo nome latino:  ";
            cin>>modifica;
            cout<< endl
                << "Continuare con l'operazione? y/n " << endl;
            cin>>confop;
			if(confop=='y')        
			{
			 mod[idmod].SetNomeLatino(modifica);	
			 // Salva modifiche su file
			 SalvaModifiche(nfl,mod,dimensione);
			} 
			else
			{
			 cout<< "Modifica non salvata" << endl;	
			}       
            break;
   case '2':
   case 'R':
   case 'r':
   	        Clearthescreen();
            cout<< "Inserire il nuovo regno:  ";
            cin>>modifica;
            cout<< endl
                << "Continuare con l'operazione? y/n " << endl;
            cin>>confop;
			if(confop=='y')        
			{
			 mod[idmod].SetRegno(modifica);	
			 // Salva modifiche su file
			 SalvaModifiche(nfl,mod,dimensione);
			} 
			else
			{
			 cout<< "Modifica non salvata" << endl;	
			}       
            break;
   case '3':
   case 'D':
   case 'd':
   	        Clearthescreen();
            cout<< "Inserire la nuova divisione:  ";
            cin>>modifica;
            cout<< endl
                << "Continuare con l'operazione? y/n " << endl;
            cin>>confop;
			if(confop=='y')        
			{
			 mod[idmod].SetDivisione(modifica);	
			 // Salva modifiche su file
			 SalvaModifiche(nfl,mod,dimensione);
			} 
			else
			{
			 cout<< "Modifica non salvata" << endl;	
			}       
            break;
   case '4':
   case 'C':
   case 'c':
   	        Clearthescreen();
            cout<< "Inserire la nuova classe:  ";
            cin>>modifica;
            cout<< endl
                << "Continuare con l'operazione? y/n " << endl;
            cin>>confop;
			if(confop=='y')        
			{
			 mod[idmod].SetClasse(modifica);
			 // Salva modifiche su file
			 SalvaModifiche(nfl,mod,dimensione);	
			} 
			else
			{
			 cout<< "Modifica non salvata" << endl;	
			}       
            break;
   case '5':
   case 'O':
   case 'o':
   	        Clearthescreen();
            cout<< "Inserire il nuovo ordine:  ";
            cin>>modifica;
            cout<< endl
                << "Continuare con l'operazione? y/n " << endl;
            cin>>confop;
			if(confop=='y')        
			{
			 mod[idmod].SetOrdine(modifica);
			 // Salva modifiche su file
			 SalvaModifiche(nfl,mod,dimensione);	
			} 
			else
			{
			 cout<< "Modifica non salvata" << endl;	
			}       
            break;
   case '6':
   case 'F':
   case 'f':
   	        Clearthescreen();
            cout<< "Inserire  la nuova famiglia:  ";
            cin>>modifica;
            cout<< endl
                << "Continuare con l'operazione? y/n " << endl;
            cin>>confop;
			if(confop=='y')        
			{
			 mod[idmod].SetFamiglia(modifica);
			 // Salva modifiche su file
			 SalvaModifiche(nfl,mod,dimensione);	
			} 
			else
			{
			 cout<< "Modifica non salvata" << endl;	
			}       
            break;
   case '7':
   case 'G':
   case 'g':
   	        Clearthescreen();
            cout<< "Inserire il nuovo genere:  ";
            cin>>modifica;
            cout<< endl
                << "Continuare con l'operazione? y/n " << endl;
            cin>>confop;
			if(confop=='y')        
			{
			 mod[idmod].SetGenere(modifica);
			 // Salva modifiche su file
			 SalvaModifiche(nfl,mod,dimensione);	
			} 
			else
			{
			 cout<< "Modifica non salvata" << endl;	
			}       
            break;
   case '8':
   case 'S':
   case 's':
   	        Clearthescreen();
            cout<< "Inserire la nuova specie:  ";
            cin>>modifica;
            cout<< endl
                << "Continuare con l'operazione? y/n " << endl;
            cin>>confop;
			if(confop=='y')        
			{
			 mod[idmod].SetSpecie(modifica);
			 // Salva modifiche su file
			 SalvaModifiche(nfl,mod,dimensione);	
			} 
			else
			{
			 cout<< "Modifica non salvata" << endl;	
			}       
            break;
   case '9':
   case 'H':
   case 'h':
   	        Clearthescreen();
            cout<< "Inserire il nuovo habitat:  ";
            cin>>modifica;
            cout<< endl
                << "Continuare con l'operazione? y/n " << endl;
            cin>>confop;
			if(confop=='y')        
			{
			 mod[idmod].SetHabitat(modifica);	
			 // Salva modifiche su file
			 SalvaModifiche(nfl,mod,dimensione);
			} 
			else
			{
			 cout<< "Modifica non salvata" << endl;	
			}       
            break;
   case 'U':
   case 'u':
            break;break;         
           																															
  }	  	
  
 }
 while(Sceltamod!='U'||Sceltamod!='u');
}

/*
Funzione che permette di salvare le modifiche apportate
*/
void SalvaModifiche(string nfl,Fungo mods[],int dim)
{
 int k=0;	
 fstream out;
 out.open(nfl.c_str(), ios::out);
 while(k<dim)
 {
  out<<mods[k].GetID()  << endl
     <<mods[k].GetNomeComune() << endl
     <<mods[k].GetNomeLatino() << endl
     <<mods[k].GetRegno()  << endl
     <<mods[k].GetDivisione() << endl
     <<mods[k].GetClasse() << endl
     <<mods[k].GetOrdine() << endl
     <<mods[k].GetFamiglia() << endl
     <<mods[k].GetGenere() << endl
     <<mods[k].GetSpecie() << endl
     <<mods[k].GetHabitat() << endl
     <<mods[k].GetZona() << endl << endl;
   k++;
 }
 cout<< "Salvataggio dati eseguito...." << endl;	
}

/*
Funzione che permette di cancellare un record
*/
void CancellaDati(string nfl,int idmod)
{
 // Caricamento dati nel vettore di oggetti fungo
 int dimensione=GetId(nfl);
 string NomeComune,NomeLatino,Regno,Divisione,Classe,Ordine,Famiglia,Genere,Specie,Habitat,Zona;
 fstream out;
 int ID;
 char risp;
 cout<< "File salvati nel database su file txt:   "  << dimensione << endl;
 Fungo A[dimensione];
 int k=0,i=0;
 fstream in;
 in.open(nfl.c_str(), ios::in);
 while(k<dimensione)
 {
  in>>ID
    >>NomeComune
    >>NomeLatino
    >>Regno
    >>Divisione
    >>Classe
    >>Ordine
    >>Famiglia
    >>Genere
    >>Specie
    >>Habitat
    >>Zona;
  A[k].SetId(ID);
  A[k].SetNomeComune(NomeComune);
  A[k].SetNomeLatino(NomeLatino);
  A[k].SetRegno(Regno);
  A[k].SetDivisione(Divisione);
  A[k].SetClasse(Classe);
  A[k].SetOrdine(Ordine);
  A[k].SetFamiglia(Famiglia);
  A[k].SetGenere(Genere);
  A[k].SetSpecie(Specie);
  A[k].SetHabitat(Habitat);
  A[k].SetZona(Zona);
  k++;
 }
 cout<< "Caricamento dati eseguito...." << endl;
 // Ricerca dell'id da cancellare
 do
 {
  cout<<"Quale record vuoi eliminare? " ;
  cin>>ID;
 }
 while (ID<=0 || ID >dimensione);
 ID--;
 
 // Conferma operazione
 cout<<"Sicuro di confermare l'operazione'? (s/n): ";
 cin>>risp;
 if (risp=='S' || risp=='s' ) //  l'utente conferma la cancellazione del record
 {
  for (i=0; i<dimensione; i++)
  {
   A[ID+i]=A[ID+i+1];
  }
  cout<<" Record eliminato...";
  dimensione--; //decremento variabile  
  in.open(nfl.c_str(), ios::in);
  while(k<dimensione)
  {
   in<<A[k].GetID() << endl
     <<A[k].GetNomeComune() << endl
     <<A[k].GetNomeLatino() << endl
     <<A[k].GetRegno() << endl
     <<A[k].GetDivisione() << endl
     <<A[k].GetClasse() << endl
     <<A[k].GetOrdine() << endl
     <<A[k].GetFamiglia() << endl
     <<A[k].GetGenere() << endl
     <<A[k].GetSpecie() << endl
     <<A[k].GetHabitat() << endl
     <<A[k].GetZona() << endl << endl; 
  k++;
 }
 }
 else
 {
  cout<< "Salvataggio non riuscito " << endl;	
 }
}


/*
Funzione che mostra i dati salvati per varie ricerche
*/
void RicercaDati(string r,char m,string nfl)
{
 int dimensione=GetId(nfl);
 int ID;
 string NomeComune,NomeLatino;
 string Regno,Divisione;
 string Classe,Ordine;
 string Famiglia,Genere;
 string Specie,Habitat;
 string Zona;	
 cout<< "Dimensione:   "  << dimensione << endl;
 Fungo A[dimensione];
 int k=0,i=0;
 fstream in;
 in.open(nfl.c_str(), ios::in);
 while(k<dimensione)
 {
  in>>ID
    >>NomeComune
    >>NomeLatino
    >>Regno
    >>Divisione
    >>Classe
    >>Ordine
    >>Famiglia
    >>Genere
    >>Specie
    >>Habitat
    >>Zona;
  A[k].SetId(ID);
  A[k].SetNomeComune(NomeComune);
  A[k].SetNomeLatino(NomeLatino);
  A[k].SetRegno(Regno);
  A[k].SetDivisione(Divisione);
  A[k].SetClasse(Classe);
  A[k].SetOrdine(Ordine);
  A[k].SetFamiglia(Famiglia);
  A[k].SetGenere(Genere);
  A[k].SetSpecie(Specie);
  A[k].SetHabitat(Habitat);
  A[k].SetZona(Zona);
  k++;
 }
 cout<< "Caricamento dati eseguito...." << endl;
 cout<< "Inizio ricerca " << endl; 
 switch(m)
 {
  case 'h':
  	       while(i<dimensione)
           { 
  	        if(A[i].GetHabitat()==r)
            {
            	cout<< "Risultato ricerca per habitat:          "<< endl << endl;
             cout<< "ID:            " << A[i].GetID()         << endl
                 << "Nome Comune:   " << A[i].GetNomeComune() << endl 
	             << "Nome Latino:   " << A[i].GetNomeLatino() << endl
	             << "Regno:         " << A[i].GetRegno()      << endl
	             << "Divisione:     " << A[i].GetDivisione()  << endl
	             << "Classe:        " << A[i].GetClasse()     << endl
	             << "Ordine:        " << A[i].GetOrdine()     << endl
	             << "Famiglia:      " << A[i].GetFamiglia()   << endl
	             << "Genere:        " << A[i].GetGenere()     << endl
	             << "Specie:        " << A[i].GetSpecie()     << endl
	             << "Habitat:       " << A[i].GetHabitat()    << endl
	             << "Zona:          " << A[i].GetZona()       << endl
	             << endl;
	        }
		    else if(A[i].GetHabitat()!=r)
		    {
		      cout<< "Ricerca dati per habitat negativa" << endl;  	
		    }
		    i++;
		   }
	       Delaycls();
  	       break;
  case 'z':
  	       while(i<dimensione)
           { 
  	        if(A[i].GetHabitat()==r)
            {
            	cout<< "Risultato ricerca per zona:          "<< endl << endl;
             cout<< "ID:            " << A[i].GetID()         << endl
                 << "Nome Comune:   " << A[i].GetNomeComune() << endl 
	             << "Nome Latino:   " << A[i].GetNomeLatino() << endl
	             << "Regno:         " << A[i].GetRegno()      << endl
	             << "Divisione:     " << A[i].GetDivisione()  << endl
	             << "Classe:        " << A[i].GetClasse()     << endl
	             << "Ordine:        " << A[i].GetOrdine()     << endl
	             << "Famiglia:      " << A[i].GetFamiglia()   << endl
	             << "Genere:        " << A[i].GetGenere()     << endl
	             << "Specie:        " << A[i].GetSpecie()     << endl
	             << "Habitat:       " << A[i].GetHabitat()    << endl
	             << "Zona:          " << A[i].GetZona()       << endl
	             << endl;
	        }
		    else if(A[i].GetHabitat()!=r)
		    {
		     cout<< "Ricerca dati per zona negativa" << endl; 
		    }
		    i++;
		   }
	       Delaycls();
  	       break;
  case 'f':
  	        while(i<dimensione)
           { 
  	        if(A[i].GetHabitat()==r)
            {
            	cout<< "Risultato ricerca per famiglia:          "<< endl << endl;
             cout<< "ID:            " << A[i].GetID()         << endl
                 << "Nome Comune:   " << A[i].GetNomeComune() << endl 
	             << "Nome Latino:   " << A[i].GetNomeLatino() << endl
	             << "Regno:         " << A[i].GetRegno()      << endl
	             << "Divisione:     " << A[i].GetDivisione()  << endl
	             << "Classe:        " << A[i].GetClasse()     << endl
	             << "Ordine:        " << A[i].GetOrdine()     << endl
	             << "Famiglia:      " << A[i].GetFamiglia()   << endl
	             << "Genere:        " << A[i].GetGenere()     << endl
	             << "Specie:        " << A[i].GetSpecie()     << endl
	             << "Habitat:       " << A[i].GetHabitat()    << endl
	             << "Zona:          " << A[i].GetZona()       << endl
	             << endl;
	        }
		    else if(A[i].GetHabitat()!=r)
		    {
		     cout<< "Ricerca dati per famiglia negativa" << endl; 	
		    }
		    i++;
		   }
	       Delaycls();
  	       break;        
  case 'g':
           while(i<dimensione)
           { 
  	        if(A[i].GetHabitat()==r)
            {
            	cout<< "Risultato ricerca per genere:          "<< endl << endl;
             cout<< "ID:            " << A[i].GetID()         << endl
                 << "Nome Comune:   " << A[i].GetNomeComune() << endl 
	             << "Nome Latino:   " << A[i].GetNomeLatino() << endl
	             << "Regno:         " << A[i].GetRegno()      << endl
	             << "Divisione:     " << A[i].GetDivisione()  << endl
	             << "Classe:        " << A[i].GetClasse()     << endl
	             << "Ordine:        " << A[i].GetOrdine()     << endl
	             << "Famiglia:      " << A[i].GetFamiglia()   << endl
	             << "Genere:        " << A[i].GetGenere()     << endl
	             << "Specie:        " << A[i].GetSpecie()     << endl
	             << "Habitat:       " << A[i].GetHabitat()    << endl
	             << "Zona:          " << A[i].GetZona()       << endl
	             << endl;
	        }
		    else if(A[i].GetHabitat()!=r)
		    {
		      cout<< "Ricerca dati per genere negativa" << endl;  	
		    }
		    i++;
		   }
	       Delaycls();
  	       break;
  case 'r':
           while(i<dimensione)
           { 
  	        if(A[i].GetHabitat()==r)
            {
            	cout<< "Risultato ricerca per regno:          "<< endl << endl;
             cout<< "ID:            " << A[i].GetID()         << endl
                 << "Nome Comune:   " << A[i].GetNomeComune() << endl 
	             << "Nome Latino:   " << A[i].GetNomeLatino() << endl
	             << "Regno:         " << A[i].GetRegno()      << endl
	             << "Divisione:     " << A[i].GetDivisione()  << endl
	             << "Classe:        " << A[i].GetClasse()     << endl
	             << "Ordine:        " << A[i].GetOrdine()     << endl
	             << "Famiglia:      " << A[i].GetFamiglia()   << endl
	             << "Genere:        " << A[i].GetGenere()     << endl
	             << "Specie:        " << A[i].GetSpecie()     << endl
	             << "Habitat:       " << A[i].GetHabitat()    << endl
	             << "Zona:          " << A[i].GetZona()       << endl
	             << endl;
	        }
		    else if(A[i].GetHabitat()!=r)
		    {
		      cout<< "Ricerca dati per  regnonegativa" << endl; 	
		    }
		    i++;
		   }
	       Delaycls();
  	       break;
  case 'o':
           while(i<dimensione)
           { 
  	        if(A[i].GetHabitat()==r)
            {
            	cout<< "Risultato ricerca per ordine:          "<< endl << endl;
             cout<< "ID:            " << A[i].GetID()         << endl
                 << "Nome Comune:   " << A[i].GetNomeComune() << endl 
	             << "Nome Latino:   " << A[i].GetNomeLatino() << endl
	             << "Regno:         " << A[i].GetRegno()      << endl
	             << "Divisione:     " << A[i].GetDivisione()  << endl
	             << "Classe:        " << A[i].GetClasse()     << endl
	             << "Ordine:        " << A[i].GetOrdine()     << endl
	             << "Famiglia:      " << A[i].GetFamiglia()   << endl
	             << "Genere:        " << A[i].GetGenere()     << endl
	             << "Specie:        " << A[i].GetSpecie()     << endl
	             << "Habitat:       " << A[i].GetHabitat()    << endl
	             << "Zona:          " << A[i].GetZona()       << endl
	             << endl;
	        }
		    else if(A[i].GetHabitat()!=r)
		    {
		     cout<< "Dato con habitat non trovato" << endl; 	
		    }
		    i++;
		   }
	       Delaycls();
  	       break;
  } 
}

/*
Funzione che calcola il totale dei dati salvati per varie ricerche
*/
void TotaleDati(string r,char m,string nfl)
{
 int dimensione=GetId(nfl);
 int ID;
 string NomeComune,NomeLatino;
 string Regno,Divisione;
 string Classe,Ordine;
 string Famiglia,Genere;
 string Specie,Habitat;
 string Zona;	
 cout<< "Dimensione:   "  << dimensione << endl;
 Fungo A[dimensione];
 int k=0,i=0;
 fstream in;
 in.open(nfl.c_str(), ios::in);
 while(k<dimensione)
 {
  in>>ID
    >>NomeComune
    >>NomeLatino
    >>Regno
    >>Divisione
    >>Classe
    >>Ordine
    >>Famiglia
    >>Genere
    >>Specie
    >>Habitat
    >>Zona;
  A[k].SetId(ID);
  A[k].SetNomeComune(NomeComune);
  A[k].SetNomeLatino(NomeLatino);
  A[k].SetRegno(Regno);
  A[k].SetDivisione(Divisione);
  A[k].SetClasse(Classe);
  A[k].SetOrdine(Ordine);
  A[k].SetFamiglia(Famiglia);
  A[k].SetGenere(Genere);
  A[k].SetSpecie(Specie);
  A[k].SetHabitat(Habitat);
  A[k].SetZona(Zona);
  k++;
 }
 cout<< "Caricamento dati eseguito...." << endl;
 cout<< "Inizio ricerca " << endl; 	
 switch(m)
 {
  case 'h':
  	       while(i<dimensione)
           { 
  	        if((A[i].GetHabitat().empty()==false))
            {
             i++;	
            }
		    else  
		    {
		     cout<< "Totale per habitat non riuscito " << endl; 	
		    }
		   }
		   cout<< "Totale record salvati per habitat: " << i << endl;
	       Delaycls();
  	       break;
  case 'z':
  	        while(i<dimensione)
           { 
  	        if((A[i].GetZona().empty()==false))
            {
             i++;	
            }
		    else  
		    {
		     cout<< "Totale per zona non riuscito " << endl; 	
		    }
		   }
		   cout<< "Totale record salvati per zona: " << i << endl;
	       Delaycls();
  	       break;
  case 'f':
  	       while(i<dimensione)
           { 
  	        if((A[i].GetFamiglia().empty()==false))
            {
             i++;	
            }
		    else  
		    {
		     cout<< "Totale per famiglia non riuscito " << endl; 	
		    }
		   }
		   cout<< "Totale record salvati per famiglia: " << i << endl;
	       Delaycls();
  	       break;       
  case 'g':
           while(i<dimensione)
           { 
  	        if((A[i].GetGenere().empty()==false))
            {
             i++;	
            }
		    else  
		    {
		     cout<< "Totale per genere non riuscito " << endl; 	
		    }
		   }
		   cout<< "Totale record salvati per genere: " << i << endl;
	       Delaycls();
  	        break;
  case 'r':
           while(i<dimensione)
           { 
  	        if((A[i].GetRegno().empty()==false))
            {
             i++;	
            }
		    else  
		    {
		     cout<< "Totale per regno non riuscito " << endl; 	
		    }
		   }
		   cout<< "Totale record salvati per regno: " << i << endl;
	       Delaycls();
  	        break;
  case 'o':
           while(i<dimensione)
           { 
  	        if((A[i].GetOrdine().empty()==false))
            {
             i++;	
            }
		    else  
		    {
		     cout<< "Totale per ordine non riuscito " << endl; 	
		    }
		   }
		   cout<< "Totale record salvati per ordine: " << i << endl;
	       Delaycls();
  	        break;
  	       break;
  } 
	
}

/*
Funzione che permette di cancellare il database presente su file
*/
void EraseDatabase(string nfile)
{
 fstream erase;
 erase.open(nfile.c_str(),ios::out | ios::trunc );
 if (!erase.is_open() || erase.fail())
 {
   erase.close();
   cout<< "Errore : Cancellazione  !";
 }
 erase.close();	
 cout<< "Database cancellato dal file";
}
