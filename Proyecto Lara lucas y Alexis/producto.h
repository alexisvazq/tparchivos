#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

struct platos{
    int id;
    char nombre[50];
    float costopre, valorventa;
    int stock, tiemprepa, idresto, comiresto, idcat;
    bool estado;
};

const char *PATH_PLATOS = "datos/platos.dat";

/// Declaraciones
bool cargar_platos(platos *, int);
bool guardar_platos(platos, int);
platos leer_platos(int);
void listar_platos(platos);
void listar_todos_platos(platos);
int contar_platos(const char *);
int buscar_platos(int);


/// Funciones de archivo
platos leer_platos(int pos){
    platos reg;
    FILE *p;
    p = fopen(PATH_PLATOS, "rb");
    fseek(p, pos * sizeof(platos), SEEK_SET);
    fread(&reg, sizeof(platos), 1, p);
    fclose(p);
    return reg;
}

int contar_platos(const char *pathPlatos){
    int bytes;
    FILE *p;
    p = fopen(pathPlatos, "rb");
    if (p == NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(platos);
}

int buscar_platos(int codigoBuscado){
    platos reg;
    int pos = 0;
    FILE *p;
    p = fopen(PATH_PLATOS, "rb");
    if (p == NULL){
        return -2;
    }
    while(fread(&reg, sizeof(platos), 1, p) == 1){
        if (reg.id == codigoBuscado){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool guardar_platos(platos reg, int pos){
    bool estado;
    FILE *p;
    if (pos >= 0){
        p = fopen(PATH_PLATOS, "rb+");
        if (p == NULL){
            return false;
        }
        fseek(p, pos * sizeof(platos), SEEK_SET);
    }else{
        p = fopen(PATH_PLATOS, "ab");
        if (p == NULL){
            return false;
        }
    }
    estado = fwrite(&reg, sizeof(platos), 1, p);
    fclose(p);
    return estado;
}

/// Funciones de interfaz

bool cargar_platos(platos *p, int codigo = 0){

    if (codigo != 0){
        cout << codigo<<endl;
    }else{
        cout<<"Ingrese el ID unico del plato"<<endl;
        cout<<"ID: ";
        cin >> p->id;
        cin.ignore();
        cout<<endl;
        while(cin.fail() || buscar_platos(p->id) >= 0){

            if(cin.fail()){
                cout<<"El ID no contiene un formato valido (solo numeros). Intente con otro"<<endl;
                cin.clear();
                cin.ignore(256,'\n');
                cout<<endl;
                cout<<"ID: ";
                cin >> p->id;
                cin.ignore();
                cout<<endl;
            }else{
                cout<<"El ID ingresado ya existe. Intente con otro"<<endl;
                cout<<endl;
                cout<<"ID: ";
                cin >> p->id;
                cin.ignore();
                cout<<endl;
            }
        }
    }

    cout<<"Ingrese el nombre del plato"<<endl;
    cout<<"NOMBRE: ";
    cin.getline(p->nombre, 30);
    cout<<endl;
    while(p->nombre[0] == '\0'){
        cout<<"Este campo no puede quedar vacio, indique el nombre del plato"<<endl;
        cout<<endl;
        cout<<"NOMBRE: ";
        cin.getline(p->nombre, 30);
        cout<<endl;
    }

    cout<<"Ingrese el costo de preparacion del plato"<<endl;
    cout<<"COSTO DE PREPARACION: ";
    cin >> p->costopre;
    cin.ignore();
    cout<<endl;
    while(cin.fail() || p->costopre < 0){
        if(cin.fail()){
            cout<<"El costo de preparacion no contiene un formato valido (solo numeros). Intente con otro"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<endl;
            cout<<"COSTO DE PREPARACION: ";
            cin >> p->costopre;
            cin.ignore();
            cout<<endl;
        }else{
            cout<<"El coste de preparacion no puede ser negativo. Ingrese el coste de preparacion"<<endl;
            cout<<endl;
            cout<<"COSTO DE PREPARACION: ";
            cin >> p->costopre;
            cin.ignore();
            cout<<endl;
        }
    }

    cout<<"Ingrese el valor de venta del plato"<<endl;
    cout<<"VALOR DE VENTA: ";
    cin >> p->valorventa;
    cin.ignore();
    cout<<endl;
    while(cin.fail() || p->valorventa < p->costopre){
        if(cin.fail()){
            cout<<"El valor de venta no contiene un formato valido (solo numeros). Intente con otro"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<endl;
            cout<<"VALOR DE VENTA: ";
            cin >> p->valorventa;
            cin.ignore();
            cout<<endl;
        }else{
            cout<<"El valor de venta no puede ser menor al coste de preparacion. Ingrese el valor de venta"<<endl;
            cout<<endl;
            cout<<"VALOR DE VENTA: ";
            cin >> p->valorventa;
            cin.ignore();
            cout<<endl;
        }
    }

    cout<<"Ingrese los minutos a demorar en la preparacion del plato"<<endl;
    cout<<"TIEMPO DE PREPARACION: ";
    cin >> p->tiemprepa;
    cin.ignore();
    cout<<endl;
    while(cin.fail() || p->tiemprepa < 0){
        if(cin.fail()){
            cout<<"El tiempo de preparacion no contiene un formato valido (solo numeros). Intente con otro"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<endl;
            cout<<"TIEMPO DE PREPARACION: ";
            cin >> p->tiemprepa;
            cin.ignore();
            cout<<endl;
        }else{
            cout<<"El tiempo de demora debe ser positivo, por favor ingrese el tiempo de preparacion"<<endl;
            cout<<endl;
            cout<<"TIEMPO DE PREPARACION: ";
            cin >> p->tiemprepa;
            cin.ignore();
            cout<<endl;
        }
    }

    cout<<"Ingrese el ID del restaurante para el plato"<<endl;
    cout<<"ID DEL RESTAURANTE: ";
    cin >> p->idresto;
    cin.ignore();
    cout<<endl;
    while(cin.fail() || p->idresto < 0){
        if(cin.fail()){
            cout<<"El id del restaurante no contiene un formato valido (solo numeros). Intente con otro"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<endl;
            cout<<"ID DEL RESTAURANTE: ";
            cin >> p->idresto;
            cin.ignore();
            cout<<endl;
        }else{
            cout<<"El ID del restaurante debe ser positivo, por favor ingrese el ID del restaurante"<<endl;
            cout<<endl;
            cout<<"ID DEL RESTAURANTE: ";
            cin >> p->idresto;
            cin.ignore();
            cout<<endl;
        }
    }

    cout<<"Ingrese el porcentaje de comision del restaurante"<<endl;
    cout<<"COMISION RESTAURANTE: ";
    cin >> p->comiresto;
    cin.ignore();
    cout<<endl;
    while(cin.fail() || p->comiresto < 0 || p->comiresto > 100){
        if(cin.fail()){
            cout<<"La comision del restaurante no contiene un formato valido (solo numeros). Intente con otro"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<endl;
            cout<<"COMISION RESTAURANTE: ";
            cin >> p->comiresto;
            cin.ignore();
            cout<<endl;
        }else{
            cout<<"La comision del restaurante debe ser mayor a 0 y menor a 100. Intente nuevamente"<<endl;
            cout<<endl;
            cout<<"COMISION RESTAURANTE: ";
            cin >> p->comiresto;
            cin.ignore();
            cout<<endl;
        }
    }

    cout<<"Ingrese el ID de la categoria a la que pertenece el plato"<<endl;
    cout<<"ID CATEGORIA: ";
    cin >> p->idcat;
    cin.ignore();
    cout<<endl;
    while(cin.fail() || p->idcat < 0){
        if(cin.fail()){
            cout<<"El ID de la categoria no contiene un formato valido (solo numeros). Intente con otro"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<endl;
            cout<<"ID CATEGORIA: ";
            cin >> p->idcat;
            cin.ignore();
            cout<<endl;
        }else{
            cout<<"El ID de la categoria del plato debe ser positivo. Por favor intente nuevamente"<<endl;
            cout<<endl;
            cout<<"ID CATEGORIA: ";
            cin >> p->idcat;
            cin.ignore();
            cout<<endl;
        }
    }
    p->estado = true;
    return true;
}

void listar_platos(platos reg){
    int i;

    cout<<"El ID del plato es: "<< reg.id<<endl;

    cout<<"Nombre del plato: " << reg.nombre<<endl;

    cout<<"Costo de la preparacion: $" << reg.costopre<<endl;

    cout<<"Valor de la venta: $"  << reg.valorventa<<endl;

    cout<<"Tiempo de preparacion: " << reg.tiemprepa<<" min"<<endl;

    cout<<"ID del restaurante: " << reg.idresto<<endl;

    cout<<"Comision del restaurante: " << reg.comiresto<<"%"<<endl;

    cout<<"ID de la categoria del plato: " << reg.idcat<<endl;

    cout<<"Estado del plato: ";
    if( reg.estado ){
        cout<<"activo"<<endl;
    }else{
        cout<<"inactivo"<<endl;
    }
}

void listar_todos_platos(){
    platos reg;
    int i=0, cant;
    cant = contar_platos(PATH_PLATOS);

    for(i=0; i<cant; i++){
        reg = leer_platos(i);
        listar_platos(reg);
        cout<<endl<<"Presiona una tecla para avanzar de registro o finalizar."<<endl<<endl;
        anykey();
    }
}

void eliminar_plato(){
    int codigoBuscado, pos;
    platos reg;

    cout << "Ingrese el ID del plato a eliminar"<<endl;
    cout << "ID: ";

    cin >> codigoBuscado;
    if(cin.fail()){
        cout<<"El ID del plato no contiene un formato valido (solo numeros)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
    }else{
        pos = buscar_platos(codigoBuscado);
        if (pos >= 0){
            reg = leer_platos(pos);
            reg.estado = false;
            listar_platos(reg);

            if (guardar_platos(reg, pos) == true){
                cout<<"Producto eliminado correctamente"<<endl;
            }else{
                cout<<"No se pudo eliminar el producto"<<endl;
            }
        }else{
            cout<<"El plato a eliminar no existe."<<endl;
        }
    }
    anykey();
}


void editar_platos(){
    int codigoBuscado, pos;
    platos reg;

    cout << "Ingrese el ID del plato a modificar"<<endl;
    cout << "ID: ";

    cin >> codigoBuscado;
    if(cin.fail()){
        cout<<"El ID del plato no contiene un formato valido (solo numeros)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin.ignore();
    }else{
        pos = buscar_platos(codigoBuscado);
        if (pos >= 0){
            reg = leer_platos(pos);
            listar_platos(reg);

            cout<<endl;
            cout<<"Ingrese el nuevo costo de venta"<<endl;
            cout<<"VALOR DE VENTA: ";
            cin >> reg.valorventa;
            cin.ignore();
            cout<<endl;
            while(cin.fail() || reg.valorventa < reg.costopre){
                if(cin.fail()){
                    cout<<"El valor de venta no contiene un formato valido (solo numeros). Intente con otro"<<endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout<<endl;
                    cout<<"VALOR DE VENTA: ";
                    cin >> reg.valorventa;
                    cin.ignore();
                    cout<<endl;
                }else{
                    cout<<"El valor de venta no puede ser menor al coste de preparacion. Ingrese el valor de venta"<<endl;
                    cout<<endl;
                    cout<<"VALOR DE VENTA: ";
                    cin >> reg.valorventa;
                    cin.ignore();
                    cout<<endl;
                }
            }

            cout<<"Ingrese los nuevos minutos a demorar en la preparacion del plato"<<endl;
            cout<<"TIEMPO DE PREPARACION: ";
            cin >> reg.tiemprepa;
            cin.ignore();
            cout<<endl;
            while(cin.fail() || reg.tiemprepa < 0){
                if(cin.fail()){
                    cout<<"El tiempo de preparacion no contiene un formato valido (solo numeros). Intente con otro"<<endl;
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout<<endl;
                    cout<<"TIEMPO DE PREPARACION: ";
                    cin >> reg.tiemprepa;
                    cin.ignore();
                    cout<<endl;
                }else{
                    cout<<"El tiempo de demora debe ser positivo, por favor ingrese el tiempo de preparacion"<<endl;
                    cout<<endl;
                    cout<<"TIEMPO DE PREPARACION: ";
                    cin >> reg.tiemprepa;
                    cin.ignore();
                    cout<<endl;
                }
            }

            if (guardar_platos(reg, pos) == true){
                cout<<"Producto editado correctamente"<<endl;
            }else{
                cout<<"No se pudo editar el producto correctamente"<<endl;
            }
            anykey();
        }else{
            cout<<"El producto buscado no existe."<<endl;
        }
    }
}

void listar_platos_x_id(){
    int codigoBuscado, pos;
    platos reg;

    cout << "Ingrese el ID del plato a buscar"<<endl;
    cout << "ID: ";

    cin >> codigoBuscado;

    if(cin.fail()){
        cout<<"El ID del plato no contiene un formato valido (solo numeros)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin.ignore();
    }else{
        pos = buscar_platos(codigoBuscado);
        if (pos >= 0){
            reg = leer_platos(pos);
            listar_platos(reg);
            cin.ignore();
            anykey();
        }else{
            cout<<"El plato buscado no existe."<<endl;
            cin.ignore();
            anykey();
        }
    }
}

void listar_platos_x_idresto(){
    int codigoBuscado, pos;
    platos reg;

    cout << "Ingrese el ID del Restaurante a buscar"<<endl;
    cout << "ID Restaurante: ";

    cin >> codigoBuscado;
    cout <<endl;

    if(cin.fail()){
        cout<<"El ID del restaurante no contiene un formato valido (solo numeros)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin.ignore();
    }else{
        cout<<"Platos del restaurante con el ID "<<codigoBuscado<<":"<<endl;

        int i=0, cant;
        cant = contar_platos(PATH_PLATOS);
        for(i=0; i<cant; i++){

            reg = leer_platos(i);
            if (reg.idresto == codigoBuscado){
                cout<<reg.nombre<<endl;
            }
        }
        cin.ignore();

        anykey();
    }
}

void nuevo_platos(){
    platos reg;
    if (cargar_platos(&reg) == true){
        if (guardar_platos(reg, -1) == true){
            cout<<"El plato se guardo correctamente."<<endl;
            anykey();
        }else{
            cout<<"El plato no se pudo guardar correctamente"<<endl;
            anykey();
        }
    }else{
        cout<<"El plato no pudo ser cargado."<<endl;
        anykey();
    }

}

#endif // PRODUCTO_H_INCLUDED
