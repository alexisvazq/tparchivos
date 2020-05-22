#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "rlutil.h"
using namespace rlutil;
#include "producto.h"
#include "clientes.h"
#include "pedidos.h"
//#include "configuracion.h"

int main(){

    int opt;
    while(true){
        system("cls");
        cout<<"-------MENU PRINCIPAL--------"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"     1)  PLATOS"<<endl;
        cout<<"     2)  CLIENTES"<<endl;
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
                while(opt2!=0){
                    system("cls");
                    cout<<"-------MENU PLATOS-----------"<<endl;
                    cout<<"-----------------------------"<<endl;
                    cout<<"     1) NUEVO PLATO"<<endl;
                    cout<<"     2) MODIFICAR PLATO"<<endl;
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
                          //  return 0;
                        break;
                    }

                };
                break;
            case 2:
                     int opt3;
                while(opt3!=0){
                    system("cls");
                    cout<<"-------MENU CLIENTES-----------"<<endl;
                    cout<<"-------------------------------"<<endl;
                    cout<<"     1) NUEVO CLIENTE"<<endl;
                    cout<<"     2) MODIFICAR CLIENTE"<<endl;
                    cout<<"     3) LISTAR CLIENTE POR ID"<<endl;
                    cout<<"     4) LISTAR TODOS LOS CLIENTES"<<endl;
                    cout<<"     5) ELIMINAR CLIENTE"<<endl;
                    cout<<"     0) VOLVER AL MENU PRINCIPAL"<<endl;
                    cout<<"-----SELECCIONE UNA OPCION-----"<<endl;
                    cin>>opt3;
                    system("cls");

                    switch(opt3){
                        case 1:
                            nuevo_clientes();
                        break;
                        case 2:
                            editar_clientes();
                        break;
                        case 3:
                            listar_clientes_x_id();
                        break;
                        case 4:
                            listar_todos_clientes();
                        break;
                        case 5:
                            eliminar_cliente();
                        break;

                        case 0:
                     //       return 0;
                            break;
                    }
                     };
                break;


            case 3:

                  int opt4;
                while(opt4!=0){
                    system("cls");
                    cout<<"-------MENU PEDIDOS-----------"<<endl;
                    cout<<"-------------------------------"<<endl;
                    cout<<"     1) NUEVO PEDIDO"<<endl;
                    cout<<"     2) MODIFICAR PEDIDO"<<endl;
                    cout<<"     3) LISTAR PEDIDO POR ID"<<endl;
                    cout<<"     4) LISTAR TODOS LOS PEDIDOS"<<endl;
                    cout<<"     0) VOLVER AL MENU PRINCIPAL"<<endl;
                    cout<<"-----SELECCIONE UNA OPCION-----"<<endl;
                    cin>>opt4;
                    system("cls");

                    switch(opt4){
                        case 1:
                            nuevo_pedidos();
                        break;
                        case 2:
                            editar_pedidos();
                        break;
                        case 3:
                            listar_pedidos_x_id();
                        break;
                        case 4:
                            listar_todos_pedidos();
                        break;
                        case 0:
                       //     return 0 ;
                            break;
                    }
                     };




            break;
            case 4:

            break;
            case 5:

                       int opt5;
                while(opt5!=0){
                    system("cls");
                    cout<<"-------MENU CONFIGURACION-----------"<<endl;
                    cout<<"------------------------------------"<<endl;
                    cout<<"     1) REALIZAR COPIA DE SEGURIDAD"<<endl;
                    cout<<"     2) RESTAURAR COPIA DE SEGURIDAD"<<endl;
                    cout<<"     0) VOLVER AL MENU PRINCIPAL"<<endl;
                    cout<<"-----SELECCIONE UNA OPCION-----"<<endl;
                    cin>>opt5;
                    system("cls");

                    switch(opt5){
                        case 1:
                 //           copia_seguridad();
                        break;
                        case 2:
                   //         restaurar_seguridad();
                        break;
                        case 0:
                      //      return 0 ;
                            break;
                    }
                     };


            break;
            case 0:
                return 0;
            break;
            }

    }
    return 0;

}

