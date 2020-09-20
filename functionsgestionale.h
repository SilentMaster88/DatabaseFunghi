// Autore:  Lanzarotti Valentino
/*
  Descrizione:
  Pagina che contiene la dichiarazione delle funzioni
*/
// Versione: 0.1
// 

// Inclusione file header
#ifndef FUNCTIONSGESTIONALE_H
#define FUNCTIONSGESTIONALE_H

#include <cstdlib> // per le system
#include <ctime>
#include <cstring>
#include <iostream>
#include "fungo.h"

using namespace std;

// Dichiarazione delle funzioni
void Clearthescreen();
void Alert(string er);
void Delaycls();
bool VerificaFile(string file);
bool VerificaVuoto(string file);
void PrimoInserimento(string nf);
void AggiungiDati(string nfl);
void ModificaDati(string nfl,int idmod);
void CancellaDati(string nfl,int idmod);
void TotaleDati(string r,char m,string nfl);
void RicercaDati(string r,char m,string nfl);
void SalvaModifiche(string nfl,Fungo mods[],int dim);
int GetId(string nfile); 
void EraseDatabase(string nfile);

#endif
