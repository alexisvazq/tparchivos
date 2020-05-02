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
int contar_platos();
int buscar_platos(int);


/// Funciones de archivo
platos leer_platos(int pos){
    platos reg;
    FILE *p;
    p = fopen(PATH_PLATOS, "rb");
    fseek(p, pos * sizeof(platos), SEEK_SET);
    fread(&reg, sizeof(platos), 1, p);
    return reg;
}

int contar_platos(){
    int bytes;
    FILE *p;
    p = fopen(PATH_PLATOS, "rb");
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
    }
    else{
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
  int i;
   if (codigo != 0){
    cout << codigo<<endl;
  }
  else{
    cout << "ID"<<endl;
        cin >> p->id;
            if (buscar_platos(p->id) >= 0){
                cout <<"Código de producto repetido"<<endl;
        return false;
    }
    cin.ignore();
  }
    cout << "NOMBRE"<<endl;
        cin.getline(p->nombre, 30);

    cout << "COSTO DE PREPARACION"<<endl;
        cin >> p->costopre;
            if (p->costopre < 0){
        return false;
  }
    cout << "VALOR DE VENTA"<<endl;
        cin >> p->valorventa;
            if (p->valorventa < p->costopre){
    return false;
  }
    cout << "TIEMPO DE PREPARACION"<<endl;
        cin >> p->tiemprepa;
            if (p->tiemprepa < 0){
    return false;
  }
    cout << "ID DEL RESTAURANTE"<<endl;
        cin >> p->idresto;
            if (p->idresto < 0){
    return false;
  }
    cout << "COMISION RESTAURANTE"<<endl;
        cin >> p->comiresto;
            if (0 < p->comiresto < 100 == FALSE )
        {
    return false;
  }
    cout << "ID CATEGORIA"<<endl;
        cin >> p->idcat;
            if (p->idcat < 0){
    return false;
  }

//   cout << "ESTADO"<<endl;
return true;
}

void listar_platos(platos reg){
    int i;


    cout<<"El ID del plato es: "<< reg.id<<endl;


    cout<<"Nombre del plato: " << reg.nombre<<endl;


    cout<<"Costo de la preparación: $" << reg.costopre<<endl;


    cout<<"Valor de la venta: $"  << reg.valorventa<<endl;


    cout<<"Tiempo de preparacion: " << reg.tiemprepa<<" min"<<endl;


    cout<<"ID del restaurante: " << reg.idresto<<endl;


    cout<<"Comisión del restaurante: " << reg.comiresto<<"%"<<endl;


    cout<<"ID de la categoria del plato: " << reg.idcat<<endl;


}

void listar_todos_platos(){
    platos reg;
    int i=0, cant;
    cant = contar_platos();

    for(i=0; i<cant; i++){
        reg = leer_platos(i);
        listar_platos(reg);
           cout<<endl<<"Presiona una tecla para avanzar de registro o finalizar."<<endl<<endl;
        anykey();
    }

}


void editar_platos(){
    int codigoBuscado, pos;
    platos reg;

    cout << "ID"<<endl;

    cin >> codigoBuscado;

    pos = buscar_platos(codigoBuscado);
    if (pos >= 0){
        reg = leer_platos(pos);
        listar_platos(reg);

        cout<<"Ingrese el nuevo costo de venta"<<endl;
        cin >> reg.valorventa;
        cin.ignore();
        cout<<"Ingrese el nuevo tiempo de preparación"<<endl;
        cin >> reg.tiemprepa;
        cin.ignore();

            if (guardar_platos(reg, pos) == true){
                cout<<"Producto editado correctamente"<<endl;
            }
            else{
                cout<<"No se pudo editar el producto correctamente"<<endl;
            }
        cin.ignore();
        anykey();
    }
    else{
        cout<<"El producto buscado no existe."<<endl;
    }

}

void listar_platos_x_id(){
    int codigoBuscado, pos;
    platos reg;

        cout << "ID del plato buscado"<<endl;

       cin >> codigoBuscado;

    pos = buscar_platos(codigoBuscado);
    if (pos >= 0){
        reg = leer_platos(pos);
        listar_platos(reg);
        cin.ignore();
        anykey();
    }
    else{
        cout<<"El plato buscado no existe."<<endl;
       cin.ignore();
        anykey();
    }

}

void listar_platos_x_idresto(){
    int codigoBuscado, pos;
    platos reg;

        cout << "ID del Restaurante"<<endl;

       cin >> codigoBuscado;

       cout<<"Platos del restaurante con el ID: "<<codigoBuscado<<endl;

        int i=0, cant;
        cant = contar_platos();
            for(i=0; i<cant; i++){

             reg = leer_platos(i);
 if (reg.idresto == codigoBuscado)
        {
         cout<<reg.nombre<<endl;
         }
                  }

//            return pos;

          cin.ignore();

        anykey();
     //   else{
   //     cout<<"El ID del restaurante no existe"<<endl;
  //  }

}

void nuevo_platos(){
    platos reg;
    if (cargar_platos(&reg) == true){
        if (guardar_platos(reg, -1) == true){
            cout<<"El plato se guardo correctamente."<<endl;
            anykey();
        }
        else{
            cout<<"El plato no se pudo guardar correctamente"<<endl;
            anykey();
        }
    }
    else{
        cout<<"El plato no pudo ser cargado."<<endl;
        anykey();

    }
    //otro cls
}

#endif // PRODUCTO_H_INCLUDED
