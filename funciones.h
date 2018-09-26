#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <cstdlib>
#include "funciones.h"
#include <fstream>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

void mostrarmatriz(int [][13]);

struct estacion{
    int linea1;
    int i1;
    int linea2;
    int i2;
};

struct caminoacumulado{
    int acumulado;
    int estado;
};
void iniciofinlineas(string ,string , string[][30], estacion& , estacion&);

bool mismaestacion(string, string);

void infocombis(estacion[]);

void inicioentrenodos(estacion[],estacion&,int&,int&);

void finentrenodos(estacion[],estacion&,int&,int&);

void agregarnodoinicio(int [][13], estacion ,int,int,estacion);

void agregarnodofin(int [][13], estacion ,int,int,estacion);

void iniciarmatrizcaminos(caminoacumulado[][13]);

void caminomascorto(int [][13],int[]);

bool recorrido(int[],int);

void desplegarmatrizrecorrido(caminoacumulado [][13]);

void filtrarcaminos(caminoacumulado[][13], int[]);

void desplegarlista(int[]);

void estacionesentre(int,string [][30],int,int);

int lineacomun(int,int,estacion[],int&,int&);

void obtenerruta(int[], estacion[],string [][30]);

void imprimirestacion(string);

#endif /* FUNCIONES_H */
