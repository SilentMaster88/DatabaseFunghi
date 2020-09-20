// Autore:  Lanzarotti Valentino
/*
  Descrizione:
  Pagina che contiene la dichiarazione delle funzioni della classse Fungo
*/
// Versione: 0.1
// 

// Inclusione file header
#include "fungo.h"
#include "functionsgestionale.h"
#include <cstring>
#include <fstream>


// Definizione delle funzioni della classe Fungo:

/*
Funzione che permette di settare l'ID
*/
void Fungo::SetId(int idf){  ID=idf; }

/*
Funzione che permette  di settare il nome comune
*/
void Fungo::SetNomeComune(string nom){ NomeComune=nom; }

/*
Funzione che permette di settare il nome latino 
*/
void Fungo::SetNomeLatino(string noml){ NomeLatino=noml;}

/*
Funzione che permette di settare il Regno
*/
void Fungo::SetRegno(string r){ Regno=r;}

/*
Funzione che permette di settare la Divisione
*/
void Fungo::SetDivisione(string d){ Divisione=d; }

/*
Funziome che permette di settare la Classe
*/
void Fungo::SetClasse(string cl){ Classe=cl;}

/*
Funzione che permette di settare l'ordine
*/
void Fungo::SetOrdine(string ord){ Ordine=ord;}

/*
Funzione che permette di settare la Famiglia
*/
void Fungo::SetFamiglia(string fam){ Famiglia=fam;}

/*
Funzione che permette di settare il Genere
*/
void Fungo::SetGenere(string gen) { Genere=gen;}

/*
Funzione che permette di settare la Specie
*/
void Fungo::SetSpecie(string spec) { Specie=spec;}

/*
Funzione che permette di settare l'Habitat
*/
void Fungo::SetHabitat(string hab){ Habitat=hab;}

/*
Funzione che permette di settare la Zona
*/
void Fungo::SetZona(string zon) { Zona=zon;}

/*
Funzione che restituisce l'ID
*/
int Fungo:: GetID() { return ID;}

/*
Funzione che restituisce il nome comune
*/
string Fungo::GetNomeComune(){ return NomeComune; }

/*
Funzione che restituisce il nome latino
*/
string Fungo::GetNomeLatino() { return NomeLatino; }

/*
Funzione che restituisce il Regno
*/
string Fungo::GetRegno() { return Regno;}

/*
Funzione che restituisce la Divisione
*/
string Fungo::GetDivisione() { return Divisione; }

/*
Funzione che restituisce la Classe
*/
string Fungo::GetClasse() { return Classe; }

/*
Funzione che restituisce l'Ordine
*/
string Fungo::GetOrdine() { return Ordine; }

/*
Funzione che restituisce la Famiglia
*/
string Fungo::GetFamiglia() { return Famiglia; }

/*
Funzione che restituisce il Genere
*/
string Fungo::GetGenere() { return Genere; }

/*
Funzione che restituisce la Specie
*/
string Fungo::GetSpecie() { return Specie; }

/*
Funzione che restituisce l'Habitat
*/
string Fungo::GetHabitat(){ return Habitat; }

/*
Funzione che restituisce la Zona
*/
string Fungo::GetZona() { return Zona; }


