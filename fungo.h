// Autore:  Lanzarotti Valentino
/*
  Descrizione:
  Pagina che contiene la dichiarazione e definizione della classe Fungo
*/
// Versione: 0.1
// 

// Inclusione file header
#ifndef FUNGO_H
#define FUNGO_H
#include <cstring>
#include <iostream>

using namespace std;

// Definizione della classe Fungo:
class Fungo
{
 private:
 int ID; // ID del record
 string NomeComune; // Nome comune del fungo
 string NomeLatino; // Nome latino del fungo
 string Regno; // Il regno naturale del fungo 
 string Divisione; //  La divisione della classificazione del fungo
 string Classe; //   La classe del fungo
 string Ordine; // L'ordine del fungo
 string Famiglia; //  La famiglia del fungo
 string Genere; // Il genere del fungo
 string Specie; // La specie del fungo
 string Habitat; // L'habitat del fungo
 string Zona; // La zona del fungo
 public:
 // Metodi Setter 
 void SetId(int idf);
 void SetNomeComune(string nom);
 void SetNomeLatino(string noml);
 void SetRegno(string r);
 void SetDivisione(string d);
 void SetClasse(string cl);
 void SetOrdine(string ord);
 void SetFamiglia(string fam);
 void SetGenere(string gen);
 void SetSpecie(string spec);
 void SetHabitat(string hab);
 void SetZona(string zon);
 // Metodi Getter
 int GetID();
 string GetNomeComune();
 string GetNomeLatino();
 string GetRegno();
 string GetDivisione();
 string GetClasse();
 string GetOrdine();
 string GetFamiglia();
 string GetGenere();
 string GetSpecie();
 string GetHabitat();
 string GetZona();
};

#endif
