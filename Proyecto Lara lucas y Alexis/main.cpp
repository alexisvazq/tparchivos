#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "rlutil.h"
using namespace rlutil;
//#include "inc/funciones.h"
#include "producto.h"

int main(){
    int opt;
    while(true){
        system("cls");
        cout<<"-------MENU PRINCIPAL--------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"     1)  PLATOS"<<endl;
        cout<<"     2)  CLIENTES"<<endl,
        cout<<"     3)  PEDIDOS"<<endl;
        cout<<"     4)  REPORTES"<<endl;
        cout<<"     5)  CONFIGURACION"<<endl;
        cout<<"     0)  SALIR"<<endl;
        cout<<"---SELECCIONE UNA OPCION----"<<endl;
        cin>>opt;
        system("cls");

        switch(opt){
            case 1:
                //nuevo_platos();
                int opt2;
                while(true){
                    system("cls");
                    cout<<"-------MENU PLATOS-----------"<<endl;
                    cout<<"-----------------------------"<<endl;
                    cout<<"     1) NUEVO PLATO"<<endl;
                    cout<<"     2) MODIFICAR PLATO"<<endl,
                    cout<<"     3) LISTAR PLATO POR ID"<<endl;
                    cout<<"     4) PLATOS POR RESTAURANTE"<<endl;
                    cout<<"     5) LISTAR TODOS LOS PLATOS"<<endl;
                    cout<<"     6) ELIMINAR PLATO"<<endl;
                    cout<<"     0) SALIR"<<endl;
                    cout<<"---SELECCIONE UNA OPCION----"<<endl;
                    cin>>opt2;
                    system("cls");

                    switch(opt2){
                        case 1:
                            nuevo_platos();
                        break;
                        case 2:
                            editar_platos();
                        break;
                        case 3:
                            listar_platos_x_id();
                        break;
                        case 4:
                            listar_platos_x_idresto();
                        break;
                        case 5:
                            listar_todos_platos();
                        break;
                        case 6:
                            eliminar_plato();
                        break;
                        case 0:
                            return 0;
                        break;
                    }
                }
            case 2:
                //editar_platos();
            break;
            case 3:
                //listar_platos_x_id();
            break;
            case 4:
                //listar_platos();
            break;
            case 0:
                return 0;
            break;
        }
    }
    return 0;
}
