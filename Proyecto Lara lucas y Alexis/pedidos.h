#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

struct pedidos{
    int id;
    int idcliente, idplato,cant;
    float preciouni, valoracion;
    fecha fecha_pedido;
    int estado;
};

const char *PATH_PEDIDOS = "datos/pedidos.dat";

/// Declaraciones
bool mail_valido (pedidos *, int);
bool fecha_valida ();
bool cargar_pedidos(pedidos *, int);
bool guardar_pedidos(pedidos, int);
pedidos leer_pedidos(int);
void listar_pedidos(pedidos);
void listar_todos_pedidos(pedidos);
int contar_pedidos();
int buscar_pedidos(int);
void listar_pedidos_x_id();
void eliminar_pedido();


///



pedidos leer_pedidos(int pos){
    pedidos reg;
    FILE *p;
    p = fopen(PATH_PEDIDOS, "rb");
    fseek(p, pos * sizeof(pedidos), SEEK_SET);
    fread(&reg, sizeof(pedidos), 1, p);
    fclose(p);
    return reg;
}

int contar_pedidos(){
    int bytes;
    FILE *p;
    p = fopen(PATH_PEDIDOS, "rb");
    if (p == NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(pedidos);
}

int buscar_pedidos(int codigoBuscado){
    pedidos reg;
    int pos = 0;
    FILE *p;
    p = fopen(PATH_PEDIDOS, "rb");
    if (p == NULL){
        return -2;
    }
    while(fread(&reg, sizeof(pedidos), 1, p) == 1){
        if (reg.id == codigoBuscado){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool guardar_pedidos(pedidos reg, int pos){
    bool estado;
    FILE *p;
    if (pos >= 0){
        p = fopen(PATH_PEDIDOS, "rb+");
        if (p == NULL){
            return false;
        }
        fseek(p, pos * sizeof(pedidos), SEEK_SET);
    }else{
        p = fopen(PATH_PEDIDOS, "ab");
        if (p == NULL){
            return false;
        }
    }
    estado = fwrite(&reg, sizeof(pedidos), 1, p);
    fclose(p);
    return estado;
}

//
bool cargar_pedidos(pedidos *p, int codigo = 0){

    if (codigo != 0){
        cout << codigo<<endl;
    }else{
            p-> id = contar_pedidos() + 1;
            cout<<"ID DEL PEDIDO(PUESTO AUTOMATICAMENTE): "<<p->id<<endl;

    }

    cout<<"Ingrese el ID del cliente"<<endl;
    cout<<"ID DEL CLIENTE: ";
    cin >> p->idcliente;
  if (buscar_clientes(p->idcliente)== -1){
   return false;
  }
    cin.ignore();
        cout<<endl;

    cout<<"Ingrese el ID del plato"<<endl;
    cout<<"ID DEL PLATO: ";
    cin >> p->idplato;
  if (buscar_platos(p->idplato)== -1){
   return false;
  }
    cin.ignore();
        cout<<endl;

   cout<<"Ingrese la cantidad de platos"<<endl;
    cout<<"CANTIDAD: ";
    cin >> p->cant;
    cin.ignore();
    cout<<endl;
    while(cin.fail() || p->cant < 1){
        if(cin.fail()){
            cout<<"La cantidad de platos no contiene un formato valido (solo numeros). Intente con otro"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<endl;
            cout<<"CANTIDAD: ";
            cin >> p->cant;
            cin.ignore();
            cout<<endl;
        }else{
            cout<<"La cantidad de platos no puede ser negativo ni 0. Ingrese la cantidad de platos"<<endl;
            cout<<endl;
            cout<<"CANTIDAD: ";
            cin >> p->cant;
            cin.ignore();
            cout<<endl;
        }
    }
int pos;
platos reg;
     pos = buscar_platos(p->idplato);
        if (pos >= 0){
            reg = leer_platos(pos);
           p->preciouni=reg.valorventa;
        }
 time_t t;
 t=time(NULL);
 struct tm *f;
 f = localtime(&t);
 p->fecha_pedido.anio = f->tm_year+1900;
 p->fecha_pedido.mes = f->tm_mon+1;
 p->fecha_pedido.dia = f->tm_mday;

   cout<<"Ingrese una valoracion"<<endl;
    cout<<"VALORACION: ";
    cin >> p->valoracion;
    cin.ignore();
    cout<<endl;
    while(cin.fail() || p->valoracion < 0 || p->valoracion > 10){
        if(cin.fail()){
            cout<<"La valoracion no contiene un formato valido (solo numeros). Intente con otro"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<endl;
            cout<<"Valoracion: ";
            cin >> p->valoracion;
            cin.ignore();
            cout<<endl;
        }else{
            cout<<"La valoracion debe ser 0 a 10. Intente nuevamente"<<endl;
            cout<<endl;
            cout<<"Valoracion: ";
            cin >> p->valoracion;
            cin.ignore();
            cout<<endl;
        }
    }

    p->estado = 1;

    return true;
}


void listar_todos_pedidos(){
    pedidos reg;
    int i=0, cant;
    cant = contar_pedidos();

    for(i=0; i<cant; i++){
        reg = leer_pedidos(i);

        listar_pedidos(reg);
        cout<<endl<<"Presiona una tecla para avanzar de registro o finalizar."<<endl<<endl;
        anykey();
    }
}

void eliminar_pedido(){
    int codigoBuscado, pos;
    pedidos reg;

    cout << "Ingrese el ID del pedido a eliminar"<<endl;
    cout << "ID: ";

    cin >> codigoBuscado;
    if(cin.fail()){
        cout<<"El ID del pedido no contiene un formato valido (solo numeros)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
    }else{
        pos = buscar_pedidos(codigoBuscado);
        if (pos >= 0){
            reg = leer_pedidos(pos);
            reg.estado = false;
            listar_pedidos(reg);

            if (guardar_pedidos(reg, pos) == true){
                cout<<"Producto eliminado correctamente"<<endl;
            }else{
                cout<<"No se pudo eliminar el producto"<<endl;
            }
        }else{
            cout<<"El pedido a eliminar no existe."<<endl;
        }
    }
    anykey();
}


void editar_pedidos(){
    int codigoBuscado, pos;
    pedidos reg;

    cout << "Ingrese el ID del pedido a modificar"<<endl;
    cout << "ID: ";

    cin >> codigoBuscado;
    if(cin.fail()){
        cout<<"El ID del pedido no contiene un formato valido (solo numeros)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin.ignore();
    }
    else{
        pos = buscar_pedidos(codigoBuscado);
        if (pos >= 0){
            reg = leer_pedidos(pos);
            cout<<endl;
            cout<<"Ingrese el nuevo estado del pedido"<<endl;
            cout<<"ESTADO: ";
            cin >> reg.estado;
            if(reg.estado!=1 && reg.estado!=2 && reg.estado!=3 )
            {
                cout<<"El estado ingresado es incorrecto"<<endl;
                anykey();

            }
            cin.ignore();
            cout<<endl;


            if (guardar_pedidos(reg, pos) == true){
                cout<<"pedido editado correctamente"<<endl;
            }
            else{
                cout<<"No se pudo editar el pedido correctamente"<<endl;
            }
            anykey();
        }else{
            cout<<"El pedido buscado no existe."<<endl;
                  anykey();
        }
    }
}



void listar_pedidos_x_id(){
    int codigoBuscado, pos;
    pedidos reg;

    cout << "Ingrese el ID del pedido a buscar"<<endl;
    cout << "ID: ";

    cin >> codigoBuscado;

    if(cin.fail()){
        cout<<"El ID del pedido no contiene un formato valido (solo numeros)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin.ignore();
    }else{
        pos = buscar_pedidos(codigoBuscado);
        if (pos >= 0){
            reg = leer_pedidos(pos);
            listar_pedidos(reg);
            cin.ignore();
            anykey();
        }else{
            cout<<"El pedido buscado no existe."<<endl;
            cin.ignore();
            anykey();
        }
    }
}


void listar_pedidos(pedidos reg){
    int i;

    cout<<"El ID del pedido es: "<< reg.id<<endl;

    cout<<"El ID del cliente es: " <<reg.idcliente<<endl;

    cout<<"ID del plato: " << reg.idplato<<endl;

    cout<<"Cantidad: "  <<reg.cant<<endl;

    cout<<"Precio unitario: " << reg.preciouni<<endl;

    cout<<"Fecha del pedido: "<<reg.fecha_pedido.dia<<'/'<<reg.fecha_pedido.mes<<'/'<<reg.fecha_pedido.anio<<endl;

   cout<<"Valoracion: "<<reg.valoracion<<endl;

    cout<<"Estado del pedido: ";

    switch (reg.estado){
    case 3:
        cout<<"Pedido Cancelado"<<endl;
    break;
    case 1:
        cout<<"Pedido En Curso"<<endl;
    break;
    case 2:
        cout<<"Pedido Completado"<<endl;
    break;
    }

 }

void nuevo_pedidos(){
    pedidos reg;
    if (cargar_pedidos(&reg) == true){
                    if (guardar_pedidos(reg, -1) == true){
            cout<<"El pedido se guardo correctamente."<<endl;
            anykey();
        }else{
            cout<<"El pedido no se pudo guardar correctamente"<<endl;
            anykey();
        }
    }else{
        cout<<"El pedido no pudo ser cargado."<<endl;
        anykey();
    }
    }



#endif // PEDIDOS_H_INCLUDED
