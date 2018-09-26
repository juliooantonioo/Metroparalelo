#include <cstdlib>
#include "funciones.h"
#include <fstream>
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void mostrarmatriz(int combis[][13]){
    for (int i=0;i<13;i++){
        for (int j=0;j<13;j++){
            cout<<combis[i][j]<<' ';
        }
        cout<<endl;
    }
}

bool coincide(string lineatexto,string codigo){
    if (lineatexto.find(codigo+" ")==0){
        return true;
    }
    else{
        return false;
    }
    
}

void iniciofinlineas(string codigo1,string codigo2, string redmetro[][30], estacion& inicial, estacion& fin){
    int cont=0;
    ifstream fichero;
    inicial.linea2=99;
    fin.linea2=99;
    fichero.open("linea1.txt");
    while (!fichero.eof()){
        getline(fichero,redmetro[0][cont]);
        if (coincide(redmetro[0][cont],codigo1)==true){
            inicial.linea1=1;
            inicial.i1=cont;
        }
        if (coincide(redmetro[0][cont],codigo2)==true){
            fin.linea1=1;
            fin.i1=cont;
        }
        cont=cont+1;
    }
    cont=0;
    fichero.close();
    fichero.open("linea2.txt");
    while (!fichero.eof()){
        getline(fichero,redmetro[1][cont]);
        if (coincide(redmetro[1][cont],codigo1)==true){
            inicial.linea1=2;
            inicial.i1=cont;
        }
        if (coincide(redmetro[1][cont],codigo2)==true){
            fin.linea1=2;
            fin.i1=cont;
        }
        cont=cont+1;
    }
    cont=0;
    fichero.close();
    fichero.open("linea4.txt");
    while (!fichero.eof()){
        getline(fichero,redmetro[2][cont]);
        if (coincide(redmetro[2][cont],codigo1)==true){
            inicial.linea1=4;
            inicial.i1=cont;
        }
        if (coincide(redmetro[2][cont],codigo2)==true){
            fin.linea1=4;
            fin.i1=cont;
        }
        cont=cont+1;
    }
    cont=0;
    fichero.close();
    fichero.open("linea4a.txt");
    while (!fichero.eof()){
        getline(fichero,redmetro[3][cont]);
        if (coincide(redmetro[3][cont],codigo1)==true){
            inicial.linea1=44;
            inicial.i1=cont;
        }
        if (coincide(redmetro[3][cont],codigo2)==true){
            fin.linea1=44;
            fin.i1=cont;
        }
        cont=cont+1;
    }
    cont=0;
    fichero.close();
    fichero.open("linea5.txt");
    while (!fichero.eof()){
        getline(fichero,redmetro[4][cont]);
        if (coincide(redmetro[4][cont],codigo1)==true){
            inicial.linea1=5;
            inicial.i1=cont;
        }
        if (coincide(redmetro[4][cont],codigo2)==true){
            fin.linea1=5;
            fin.i1=cont;
        }
        cont=cont+1;
    }
    cont=0;
    fichero.close();
    fichero.open("linea6.txt");
    while (!fichero.eof()){
        getline(fichero,redmetro[5][cont]);
        if (coincide(redmetro[5][cont],codigo1)==true){
            inicial.linea1=6;
            inicial.i1=cont;
        }
        if (coincide(redmetro[5][cont],codigo2)==true){
            fin.linea1=6;
            fin.i1=cont;
        }
        cont=cont+1;
    }
    cont=0;
    fichero.close();
}


void infocombis(estacion estaciones[]){
    estaciones[1].i1=0,estaciones[1].linea1=1,estaciones[1].i2=8,estaciones[1].linea2=5; 
    estaciones[2].i1=13,estaciones[2].linea1=2,estaciones[2].i2=14,estaciones[2].linea2=5;
    estaciones[3].i1=10,estaciones[3].linea1=1,estaciones[3].i2=12,estaciones[3].linea2=2;  
    estaciones[4].i1=15,estaciones[4].linea1=1,estaciones[4].i2=17,estaciones[4].linea2=5; 
    estaciones[5].i1=19,estaciones[5].linea1=1,estaciones[5].i2=9,estaciones[5].linea2=6; 
    estaciones[6].i1=20,estaciones[6].linea1=1,estaciones[6].i2=0,estaciones[6].linea2=4; 
    estaciones[7].i1=21,estaciones[7].linea1=5,estaciones[7].i2=5,estaciones[7].linea2=6;
    estaciones[8].i1=8,estaciones[8].linea1=2,estaciones[8].i2=3,estaciones[8].linea2=6; 
    estaciones[9].i1=0,estaciones[9].linea1=2,estaciones[9].i2=5,estaciones[9].linea2=44;
    estaciones[10].i1=12,estaciones[10].linea1=4,estaciones[10].i2=0,estaciones[10].linea2=44; 
    estaciones[11].i1=13,estaciones[11].linea1=4,estaciones[11].i2=29,estaciones[11].linea2=5;
}

void inicioentrenodos(estacion listacombinaciones[],estacion &origen,int &izq,int &der)
{
    int cont,validador=1;
    origen.i1=-1;
    origen.i2=-1;
    cont=listacombinaciones[0].i1;
    while (cont>=0 and validador==1){
        for (int i=1;i<12;i++){
            if (cont==listacombinaciones[i].i1 and listacombinaciones[0].linea1==listacombinaciones[i].linea1){
                origen.i1=listacombinaciones[i].i1;
                origen.linea1=listacombinaciones[i].linea1;
                validador=0;
                izq=i;
            }
            if (cont==listacombinaciones[i].i2 and listacombinaciones[0].linea1==listacombinaciones[i].linea2){
                origen.i1=listacombinaciones[i].i2;
                origen.linea1=listacombinaciones[i].linea2;
                validador=0;
                izq=i;
            }
        }
        cont=cont-1;
    }
    validador=1;
    cont=listacombinaciones[0].i1;
    while (cont<30 and validador==1){
        for (int j=1;j<12;j++){
            if (cont==listacombinaciones[j].i1 and listacombinaciones[0].linea1==listacombinaciones[j].linea1){
                origen.i2=listacombinaciones[j].i1;
                origen.linea2=listacombinaciones[j].linea1;
                validador=0;
                der=j;
            }
            if (cont==listacombinaciones[j].i2 and listacombinaciones[0].linea1==listacombinaciones[j].linea2){
                origen.i2=listacombinaciones[j].i2;
                origen.linea2=listacombinaciones[j].linea2;
                validador=0;
                der=j;
            }
        }
        cont=cont+1;
    }
}

void finentrenodos(estacion listacombinaciones[],estacion &destino, int &izq,int &der){
    int cont,validador=1;
    destino.i1=-1;
    destino.i2=-1;
    cont=listacombinaciones[12].i1;
    while (cont>=0 and validador==1){
        for (int i=0;i<12;i++){
            if (cont==listacombinaciones[i].i1 and listacombinaciones[12].linea1==listacombinaciones[i].linea1){
                destino.i1=listacombinaciones[i].i1;
                destino.linea1=listacombinaciones[i].linea1;
                validador=0;
                izq=i;
            }
            if (cont==listacombinaciones[i].i2 and listacombinaciones[12].linea1==listacombinaciones[i].linea2){
                destino.i1=listacombinaciones[i].i2;
                destino.linea1=listacombinaciones[i].linea2;
                validador=0;
                izq=i;
            }
        }
        cont=cont-1;
    }
    validador=1;
    cont=listacombinaciones[12].i1;
    while (cont<30 and validador==1){
        for (int j=0;j<12;j++){
            if (cont==listacombinaciones[j].i1 and listacombinaciones[12].linea1==listacombinaciones[j].linea1){
                destino.i2=listacombinaciones[j].i1;
                destino.linea2=listacombinaciones[j].linea1;
                validador=0;
                der=j;
            }
            if (cont==listacombinaciones[j].i2 and listacombinaciones[12].linea1==listacombinaciones[j].linea2){
                destino.i2=listacombinaciones[j].i2;
                destino.linea2=listacombinaciones[j].linea2;
                validador=0;
                der=j;
            }
        }
        cont=cont+1;
    }
}

void agregarnodoinicio(int combinaciones[][13], estacion indicesnodos,int izq,int der,estacion actual){
    if (izq!=-1){
        combinaciones[0][izq]=abs(indicesnodos.i1-actual.i1);
        combinaciones[izq][0]=abs(indicesnodos.i1-actual.i1);
    }
    if (der!=-1){
        combinaciones[0][der]=abs(indicesnodos.i2-actual.i1);
        combinaciones[der][0]=abs(indicesnodos.i2-actual.i1);
    }
    if (der!=-1 and izq!=-1){
        combinaciones[izq][der]=-1;
        combinaciones[der][izq]=-1;
    }
}

void agregarnodofin(int combinaciones[][13], estacion indicesnodos,int izq,int der,estacion actual){
    if (izq!=-1){
        combinaciones[12][izq]=abs(indicesnodos.i1-actual.i1);
        combinaciones[izq][12]=abs(indicesnodos.i1-actual.i1);
    }
    if (der!=-1){
        combinaciones[12][der]=abs(indicesnodos.i2-actual.i1);
        combinaciones[der][12]=abs(indicesnodos.i2-actual.i1);
    }
    if (der!=-1 and izq!=-1){
        combinaciones[izq][der]=-1;
        combinaciones[der][izq]=-1;
    }
}

void iniciarmatrizcaminos(caminoacumulado matriz[][13]){
    for(int i=0;i<13;i++){
        for (int j=0;j<13;j++){
            matriz[i][j].acumulado=-1;
            matriz[i][j].estado=3;
        }
    }
}

bool recorrido(int nodosrecorridos[], int nodo){
    for (int i=0;i<12;i++){
        if (nodosrecorridos[i]==nodo){
            return true;
        }
    }
    return false;
}

void desplegarmatrizrecorrido(caminoacumulado matriz[][13]){
    for (int i=0;i<13;i++){
        for (int j=0;j<13;j++){
            cout<<matriz[i][j].acumulado<< " ";
        }
        cout<<endl;
    }
}

void filtrarcaminos(caminoacumulado matriz[][13], int lista[]){
    int minimo=999;
    for(int i=0;i<13;i++){
        for (int j=0;j<13;j++){
            if (matriz[j][i].acumulado<minimo and matriz[j][i].acumulado!=-1){
                lista[i]=j;
                minimo=matriz[j][i].acumulado;
            }
        }
        minimo=999;
    }
}

void desplegarlista(int lista[]){
    for (int i=0; i<13;i++){
        cout<<lista[i]<<endl;
    }
}

void caminomascorto(int combinaciones[][13],int caminosdef[]){
    caminoacumulado matrizcaminos[13][13];
    int iactual=0,jactual=0;
    int nodosrecorridos[13]={14,14,14,14,14,14,14,14,14,14,14,14,14},cont=0,nodoactual=0,minimo=99,acumuladoactual=0;
    iniciarmatrizcaminos(matrizcaminos);
    for(int i=0;i<13;i++){
        nodosrecorridos[i]=nodoactual;
        for (int j=0;j<13;j++){
            if (combinaciones[nodoactual][j]!=-1 and matrizcaminos[nodoactual][j].estado!=2){
                if (matrizcaminos[nodoactual][j].acumulado<=(acumuladoactual+combinaciones[nodoactual][j])){
                    matrizcaminos[nodoactual][j].acumulado=(acumuladoactual+combinaciones[nodoactual][j]);
                    matrizcaminos[nodoactual][j].estado=1;
                }
            }
        }
        while (cont<=i){
            for (int k=0;k<13;k++){
                if (matrizcaminos[nodosrecorridos[cont]][k].acumulado<minimo and !recorrido(nodosrecorridos,k) and matrizcaminos[nodosrecorridos[cont]][k].estado==1){
                    nodoactual=k;
                    acumuladoactual=matrizcaminos[nodosrecorridos[cont]][k].acumulado;
                    iactual=nodosrecorridos[cont];
                    jactual=k;
                    minimo=matrizcaminos[nodosrecorridos[cont]][k].acumulado;
                }
            }
            cont=cont+1;
        }
        cont=0;
        matrizcaminos[iactual][jactual].estado=2;
        minimo=99;        
    }
    filtrarcaminos(matrizcaminos,caminosdef);    
}

void estacionesentre(int codigolinea,string combinaciones[][30],int i1,int i2){
    if (i1>i2){
        for (int i=i1;i>i2;i--){
            imprimirestacion(combinaciones[codigolinea][i]);
        }
    }
    if (i1<i2){
        for (int i=i1;i<i2;i++){
            imprimirestacion(combinaciones[codigolinea][i]);
        }
    }
}

int lineacomun(int i1,int i2,estacion infocombis[],int &codigoi,int &codigof){
    int comun=99;
    int codigolinea=0;
    if (infocombis[i1].linea1==infocombis[i2].linea1){
        comun=infocombis[i1].linea1;
        codigoi=infocombis[i1].i1;
        codigof=infocombis[i2].i1;
    }
    if (infocombis[i1].linea1==infocombis[i2].linea2){
        comun=infocombis[i1].linea1;
        codigoi=infocombis[i1].i1;
        codigof=infocombis[i2].i2;
    }
    if (infocombis[i1].linea2==infocombis[i2].linea1){
        comun=infocombis[i1].linea2;
        codigoi=infocombis[i1].i2;
        codigof=infocombis[i2].i1;
    }
    if (infocombis[i1].linea2==infocombis[i2].linea2){
        comun=infocombis[i1].linea2;
        codigoi=infocombis[i1].i2;
        codigof=infocombis[i2].i2;
    }
    if (codigoi!=codigof){
        if(comun==1){
            codigolinea=0;
        }
        if(comun==2){
            codigolinea=1;
        }
        if(comun==4){
            codigolinea=2;
        }
        if(comun==44){
            codigolinea=3;
        }
        if(comun==5){
            codigolinea=4;
        }
        if(comun==6){
            codigolinea=5;
        }
    }
    return codigolinea;
}

void obtenerruta(int lista[], estacion infocombis[],string combinaciones[][30]){
    int indice=12,indicesgte=lista[12],codigolinea,codigoi=0,codigof=0;
    while (indicesgte!=0){
        indicesgte=lista[indice];
        codigolinea=lineacomun(indice,indicesgte,infocombis,codigoi,codigof);
        estacionesentre(codigolinea,combinaciones,codigoi,codigof);
        if (indicesgte==0){
            imprimirestacion(combinaciones[codigolinea][codigof]);
            cout<<"Fin Recorrido"<<endl;
        }
        indice=indicesgte;
    }
}

void imprimirestacion(string nombre){
    int val=0,largo=99;
    largo=nombre.length();
    for (int i=0;i<largo;i++){
        if (val!=0){
            cout<<nombre[i];
        }
        if (nombre[i]==' '){
            val=1;
        }
    }
    cout<<" * ";
}