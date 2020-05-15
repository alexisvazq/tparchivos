#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

struct pedidos{
    int id;
    int idcliente, idplato,cant;
    float preciouni, valoacion;
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
    p = fopen(PATH_pedidos, "rb");
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
    p = fopen(PATH_pedidos, "rb");
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
        p = fopen(PATH_pedidos, "rb+");
        if (p == NULL){
            return false;
        }
        fseek(p, pos * sizeof(pedidos), SEEK_SET);
    }else{
        p = fopen(PATH_pedidos, "ab");
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
            cout<<"ID DEL pedido(PUESTO AUTOMATICAMENTE): "<<p->id<<endl;

    }
    cout<<"Ingrese el nombre del pedido"<<endl;
    cout<<"NOMBRES: ";
    cin.ignore();
    cin.getline(p->nombre, 50);

    cout<<endl;
    while(p->nombre[0] == '\0'){
        cout<<"Este campo no puede quedar vacio, indique el nombre del pedido"<<endl;
        cout<<endl;
        cout<<"NOMBRE: ";
        cin.getline(p->nombre, 30);
        cout<<endl;
    }

cout<<"Ingrese el/los apellido/s del pedido"<<endl;
    cout<<"APELLIDOS: ";
    cin.getline(p->apellidos, 50);
    cout<<endl;
    while(p->apellidos[0] == '\0'){
        cout<<"Este campo no puede quedar vacio, indique el apellido del pedido"<<endl;
        cout<<endl;
        cout<<"APELLIDOS: ";
        cin.getline(p->apellidos, 50);
        cout<<endl;
    }

cout <<"Ingrese el mail del pedido"<<endl;
    cout<<"MAIL: ";
        cin.getline(p->mail, 50);
        while((p->mail[0] == '\0') || (mail_valido(p->mail) == false)) {
            cout<<"El mail ingresado no es valido, ingrese nuevamente el mail"<<endl;
            cout<<"MAIL: ";
             cin.getline(p->mail,50);
            }

cout<<"Ingrese domicilio del pedido"<<endl;
        cout<<"DOMICILIO: ";
    cin.getline(p->domicilio, 100);
    cout<<endl;
    while(p->domicilio[0] == '\0'){
        cout<<"Este campo no puede quedar vacio, indique el domicilio del pedido"<<endl;
        cout<<endl;
        cout<<"DOMICILIO: ";
        cin.getline(p->domicilio, 100);
        cout<<endl;
    }

    cout<<"Ingrese el codigo postal del pedido"<<endl;
    cout<<"CODIGO POSTAL: ";
    cin >> p->cp;
    cin.ignore();
    cout<<endl;
    while(cin.fail() || p->cp < 1000 || p->cp > 9999){
        if(cin.fail()){
            cout<<"El codigo postal del pedido no contiene un formato valido (solo numeros). Intente con otro"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<endl;
            cout<<"CODIGO POSTAL: ";
            cin >> p->cp;
            cin.ignore();
            cout<<endl;
        }else{
            cout<<"El codigo postal del pedido debe ser mayor a 1000 y menor a 9999. Intente nuevamente"<<endl;
            cout<<endl;
            cout<<"CODIGO POSTAL: ";
            cin >> p->cp;
            cin.ignore();
            cout<<endl;
        }
    }

    cout<<"Ingrese la fecha de nacimiento del pedido"<<endl;
    cout<<"FECHA DE NACIMIENTO: "<<endl;
    cout<<"DIA :"<<endl;
    cin >> p->fecha_nacimiento.dia;
    cout<<"EL DIA Q PUSIMOOS ES: "<<p->fecha_nacimiento.dia<<endl;
    cout<<"MES :"<<endl;
    cin >> p->fecha_nacimiento.mes;
     cout<<"EL DIA Q PUSIMOOS ES: "<<p->fecha_nacimiento.mes<<endl;
    cout<<"AÑO :"<<endl;
    cin >> p->fecha_nacimiento.anio;
     cout<<"EL DIA Q PUSIMOOS ES: "<<p->fecha_nacimiento.anio<<endl;
         cin.ignore();


    while(fecha_valida(p->fecha_nacimiento) == false) {
        cout<<"FECHA DE NACIMIENTO INCORRECTA, VUELVA A INTENTARLO: "<<endl;
        cout<<"FECHA DE NACIMIENTO: ";
        cout<<"DIA :"<<endl;
        cin >> p->fecha_nacimiento.dia;
        cout<<"MES :"<<endl;
        cin >> p->fecha_nacimiento.mes;
        cout<<"AÑO :"<<endl;
        cin >> p->fecha_nacimiento.anio;
            cin.ignore();
            cout<<endl;

        }


    p->estado = true;

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
            listar_pedidos(reg);

            cout<<endl;
            cout<<"Ingrese el nuevo domicilio del pedido"<<endl;
            cout<<"DOMICILIO: ";
            cin >> reg.domicilio;
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

    cout<<"Nombre completo del pedido: " <<reg.nombre<<" "<<reg.apellidos<<endl;

    cout<<"Mail del pedido: " << reg.mail<<endl;

    cout<<"Domicilio: "  <<reg.domicilio<<endl;

    cout<<"Codigo Postal: " << reg.cp<<endl;

    cout<<"Fecha de nacimiento: "<<reg.fecha_nacimiento.dia<<'/'<<reg.fecha_nacimiento.mes<<'/'<<reg.fecha_nacimiento.anio<<endl;


    cout<<"Estado del pedido: ";
    if( reg.estado ){
        cout<<"activo"<<endl;
    }else{
        cout<<"inactivo"<<endl;
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
