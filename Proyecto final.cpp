#include<iostream>
using namespace std;

const int filas=4 , columnas=5;
const int coordenadaFilas=-1, coordenadaColumnas=-1;
const int tamVec=(filas*columnas);
int disponibilidad[filas][columnas];
int NumContainer[filas][columnas];
int PesContainer[filas][columnas];
int NumPuertos, PesoContainer, CantContainers=0;       
char TipArt[filas][columnas];
char tipArt;
string cantPuert;
string Marca[filas][columnas];
string MarcaArt[tamVec];
string cantidadPuertos[tamVec];
string NombPuertos[filas][columnas];                                   
void mostrarDisponibles(int disponibilidad[filas][columnas]);
void pedircoordenadas(int coordenadaFilas, int coordenadaColumnas);
void Puertos(string cantidadPuertos[], int);
void PosPuertos(string NombPuertos[filas][columnas]);
void PesoCont(int PesContainer[filas][columnas]);
void Empresa(string Marca[filas][columnas]);
void Articulo(char TipArt[filas][columnas]);

int main(){                                                                                                                             // CODIGO PRINCIPAL

        cout<<"\t\tSHIP LOGISTICs \n";
        Puertos(cantidadPuertos,tamVec);
        PosPuertos(NombPuertos), PesoCont(PesContainer), Empresa(Marca), Articulo(TipArt);
        main();

        for(int i=0;i<filas;i++){
                for(int j=0;j<columnas;j++){
                        disponibilidad[i][j] = 0;
                        }
        }               
}
void mostrarDisponibles(int disponibilidad[filas][columnas]){                   // MOSTRAR MATRIZ DISPONIBILIDAD

        cout<<"\n\t DISPONIBILIDAD DE PUERTOS\n\n";
        cout<<"\t";
        for (int i=0;i<columnas;i++){
            cout<<"( "<<i+1<<" )"<<"\t";
        }       
                cout<<"\n \n";

    for (int i=0;i<filas;i++){
            cout<<"( "<<i+1<<" )"<<"\t";
        for (int j=0;j<columnas;j++){               
            cout<<" "<<disponibilidad [i][j]<<" "<<"\t";
        }
        cout<<"\n \n";
    }
}

void pedircoordenadas(int coordenadaFilas, int coordenadaColumnas){             // INGRESAR NOMBRE DE PUERTO A COORDENADA INDICADA POR USUARIO

        cout<<"\n";

        if(NumPuertos<(tamVec) || NumPuertos>=1){

        do{
        for(int i=0;i<CantContainers;i++){
        cout<<"Cual es el peso del container? "<<endl;
        cin>>PesoContainer;     
        cout<<"Que empresa provee los articulos del container? "<<endl;
        cin>>MarcaArt[i];
        cout<<"Que tipo de articulo contiene el container? "<<"\n [a] Alimentos\n [b] Dispositivos electronicos\n [c] Ropa y demas textiles\n";
        cout<<" RESPUESTA: ";
        cin>>tipArt;
        cout<<"En que posicion desea ingresar el container? "<<endl;   
        cout<<"[Fila]: ";
        cin>>coordenadaFilas;
        cout<<"[Columna]: ";
        cin>>coordenadaColumnas;

        if(coordenadaFilas<0 || coordenadaFilas>filas || coordenadaColumnas<0 || coordenadaColumnas>columnas){
                                                cout<<"\t\t\t\t LA POSICION INGRESADA ES INVALIDA \n \t\t\t\tporfavor ingrese una posicion valida \n";
                                        }else{
                                                NombPuertos[coordenadaFilas-1][coordenadaColumnas-1]=cantPuert;
                                                disponibilidad[coordenadaFilas-1][coordenadaColumnas-1]=1;
                                                PesContainer[coordenadaFilas-1][coordenadaColumnas-1]=PesoContainer;
                                                Marca[coordenadaFilas-1][coordenadaColumnas-1]=MarcaArt[i];
                                                TipArt[coordenadaFilas-1][coordenadaColumnas-1]=tipArt;
                                        }
                                }
                        }while(coordenadaFilas<0 || coordenadaFilas>filas || coordenadaColumnas<0 || coordenadaColumnas>columnas);     
                }
 }

void Puertos(string cantidadPuertos[], int tamVec){                                             // PEDIR EL NUMERO Y NOMBRES DE PUERTOS

        do{
                cout<<"Por favor ingresar el numero de puertos: ";
                cin>>NumPuertos;

                if(NumPuertos>tamVec || NumPuertos<=0){
                        cout<<"\n\t\t\t\t VALOR INCORRECTO \n"<<"\t\t\t por favor ingrese un valor valido\n"<<endl;
                }
        }while(NumPuertos>(tamVec) || NumPuertos<=0);

        for(int i=0;i<NumPuertos;i++){
                cout<<"por favor ingrese el nombre del puerto "<<i+1<<": ";
                cin>>cantidadPuertos[i];
                cantPuert=cantidadPuertos[i];

                do{
                        cout<<"Por favor ingrese el numero de containers que va a ingresar en ese puerto: ";
                        cin>>CantContainers;

                        if(CantContainers<=0 || CantContainers>tamVec){
                                cout<<"\n\t\t\t\t VALOR INCORRECTO \n"<<"\t\t\t por favor ingrese un valor valido\n"<<endl;
                                }       
                        }while(CantContainers<=0 || CantContainers>tamVec);

                        mostrarDisponibles(disponibilidad);
                        pedircoordenadas(coordenadaFilas,coordenadaColumnas);
                }
        }       


void PosPuertos(string NombPuertos[filas][columnas]){                                   // MOSTRAR MATRIZ DE PUERTOS

                        cout<<"\n\t\t PUERTOS \n\n";
        cout<<"\t";
        for (int i=0;i<columnas;i++){
            cout<<"( "<<i+1<<" )"<<"\t\t";
        }       
                cout<<"\n \n";

    for (int i=0;i<filas;i++){
            cout<<"( "<<i+1<<" )"<<"\t";
        for (int j=0;j<columnas;j++){               
            cout<<" "<<NombPuertos [i][j]<<" "<<"\t\t";
        }
        cout<<"\n \n";
                }
        }

void PesoCont(int PesContainer[filas][columnas]){                                               // MOSTRAR MATRIZ DE PESOS CONTAINERS

        cout<<"\n\t PESO CONTAINERS \n\n";
        cout<<"\t";
        for (int i=0;i<columnas;i++){
            cout<<"( "<<i+1<<" )"<<"\t\t";
        }       
                cout<<"\n \n";

    for (int i=0;i<filas;i++){
            cout<<"( "<<i+1<<" )"<<"\t";
        for (int j=0;j<columnas;j++){               
            cout<<" "<<PesContainer [i][j]<<" "<<"\t\t";
        }
        cout<<"\n \n";
    }
}

void Empresa(string Marca[filas][columnas]){                                                    // MOSTRAR MATRIZ DE MARCA O EMPRESAS

        cout<<"\n\t EMPRESA \n\n";
        cout<<"\t";
        for (int i=0;i<columnas;i++){
            cout<<"( "<<i+1<<" )"<<"\t\t";
        }       
                cout<<"\n \n";

    for (int i=0;i<filas;i++){
            cout<<"( "<<i+1<<" )"<<"\t";
        for (int j=0;j<columnas;j++){               
            cout<<" "<<Marca[i][j]<<" "<<"\t\t";
        }
        cout<<"\n \n";
    }
}

void Articulo(char TipArt[filas][columnas]){                                                    // MOSTRAR MATRIZ DE TIPO DE ARTICULO

        cout<<"\n\t TIPO DE ARTICULO \n\n";
        cout<<"\t";
        for (int i=0;i<columnas;i++){
            cout<<"( "<<i+1<<" )"<<"\t";
        }       
                cout<<"\n \n";

    for (int i=0;i<filas;i++){
            cout<<"( "<<i+1<<" )"<<"\t";
        for (int j=0;j<columnas;j++){               
            cout<<" "<<TipArt[i][j]<<" "<<"\t";
        }
        cout<<"\n \n";
    }
}
