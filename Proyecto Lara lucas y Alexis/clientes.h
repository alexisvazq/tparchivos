#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

struct fecha{
  int dia, mes, anio;
};
struct clientes{
    int id;
    char apellidos[50], nombre[50], mail[50], domicilio[100];
    float costopre, valorventa;
    int cp;
    fecha fecha_nacimiento;
    bool estado;
};
int dias_mes[12]={31,28,31,30,31,30,31,31,30,31,30,31};

const char *PATH_CLIENTES = "datos/clientes.dat";

/// Declaraciones
bool mail_valido (clientes *, int);
bool fecha_valida ();
bool cargar_clientes(clientes *, int);
bool guardar_clientes(clientes, int);
clientes leer_clientes(int);
void listar_clientes(clientes);
void listar_todos_clientes(clientes);
int contar_clientes();
int buscar_clientes(int);
void listar_clientes_x_id();
void eliminar_cliente();

/// Funciones de archivo

clientes leer_clientes(int pos){
    clientes reg;
    FILE *p;
    p = fopen(PATH_CLIENTES, "rb");
    fseek(p, pos * sizeof(clientes), SEEK_SET);
    fread(&reg, sizeof(clientes), 1, p);
    fclose(p);
    return reg;
}

int contar_clientes(){
    int bytes;
    FILE *p;
    p = fopen(PATH_CLIENTES, "rb");
    if (p == NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(clientes);
}

int buscar_clientes(int codigoBuscado){
    clientes reg;
    int pos = 0;
    FILE *p;
    p = fopen(PATH_CLIENTES, "rb");
    if (p == NULL){
        return -2;
    }
    while(fread(&reg, sizeof(clientes), 1, p) == 1){
        if (reg.id == codigoBuscado){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool guardar_clientes(clientes reg, int pos){
    bool estado;
    FILE *p;
    if (pos >= 0){
        p = fopen(PATH_CLIENTES, "rb+");
        if (p == NULL){
            return false;
        }
        fseek(p, pos * sizeof(clientes), SEEK_SET);
    }else{
        p = fopen(PATH_CLIENTES, "ab");
        if (p == NULL){
            return false;
        }
    }
    estado = fwrite(&reg, sizeof(clientes), 1, p);
    fclose(p);
    return estado;
}

/// Funciones de interfaz

bool mail_valido(const char *mail) {
    int tam = strlen(mail);
    bool puntoTrasArroba = false;

    //No puede comenzar ni terminar con arroba o punto
    if (mail[0] == '@' || mail [0] == '.' || mail[tam-1] == '@' || mail[tam-1] == '.') {
        return false ;
        cout<<"1"<<endl;
        anykey();
    }

    char * posPrimerArroba = strchr(mail,'@');
    char * posUltimoArroba = strrchr(mail,'@');
    // Debe contener un arroba
    if(posPrimerArroba == NULL) {
        return false;
        cout<<"2"<<endl;
        anykey();
    }
    // No puede contener mas de un arroba
    if(posPrimerArroba != posUltimoArroba){
        return false;
        cout<<"3"<<endl;
        anykey();
    }

            bool puntoSeguido = false;
        bool charTrasArroba = false;

    for (int i = 0; i < tam; i++){


        // Me fijo si es alfanumerico o punto o guion
        if( !isalnum(mail[i]) && mail[i] != '.' && mail[i] != '-' && mail[i] != '@' ){
            return false;

        }
        // Debe contener al menos un punto luego del arroba
        if( mail[i] == '@' ){
            charTrasArroba = true;

        }
        if( charTrasArroba && mail[i] == '.' ){
            puntoTrasArroba = true;

        }
        // No puede contener dos puntos seguidos
        if( mail[i] == '.' ){
            if( puntoSeguido ){
                return false;

            }else{
                puntoSeguido = true;

            }
        }else{
            puntoSeguido = false;

        }
    }

    if(!puntoTrasArroba){
        return false;

    }

    return true;
}

// bool mail_valido(const char *mail) {
//     char charRegEx = "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+";
//     return regex_match(mail, charRegEx);
// }


bool fecha_valida(fecha fecha_nacimiento){

   if((fecha_nacimiento.anio % 4 == 0 && fecha_nacimiento.anio % 100 != 0) || fecha_nacimiento.anio % 400 == 0){
        dias_mes[1] = dias_mes[1] + 1;
   }
    if(fecha_nacimiento.mes < 1 || fecha_nacimiento.mes > 12){
        return false;
    }
    int m = fecha_nacimiento.mes-1;
    if(fecha_nacimiento.dia < 1 || fecha_nacimiento.dia > dias_mes[m]){
        return false;
    }
    if(1900>fecha_nacimiento.anio||fecha_nacimiento.anio>2020){
        return false;
    }
    return true;
}


bool cargar_clientes(clientes *p, int codigo = 0){

    if (codigo != 0){
        cout << codigo<<endl;
    }else{
            p-> id = contar_clientes() + 1;
            cout<<"ID DEL CLIENTE(PUESTO AUTOMATICAMENTE): "<<p->id<<endl;

    }
    cout<<"Ingrese el nombre del cliente"<<endl;
    cout<<"NOMBRES: ";
    cin.ignore();
    cin.getline(p->nombre, 50);

    cout<<endl;
    while(p->nombre[0] == '\0'){
        cout<<"Este campo no puede quedar vacio, indique el nombre del cliente"<<endl;
        cout<<endl;
        cout<<"NOMBRE: ";
        cin.getline(p->nombre, 30);
        cout<<endl;
    }

cout<<"Ingrese el/los apellido/s del cliente"<<endl;
    cout<<"APELLIDOS: ";
    cin.getline(p->apellidos, 50);
    cout<<endl;
    while(p->apellidos[0] == '\0'){
        cout<<"Este campo no puede quedar vacio, indique el apellido del cliente"<<endl;
        cout<<endl;
        cout<<"APELLIDOS: ";
        cin.getline(p->apellidos, 50);
        cout<<endl;
    }

cout <<"Ingrese el mail del cliente"<<endl;
    cout<<"MAIL: ";
        cin.getline(p->mail, 50);
        while((p->mail[0] == '\0') || (mail_valido(p->mail) == false)) {
            cout<<"El mail ingresado no es valido, ingrese nuevamente el mail"<<endl;
            cout<<"MAIL: ";
             cin.getline(p->mail,50);
            }

cout<<"Ingrese domicilio del cliente"<<endl;
        cout<<"DOMICILIO: ";
    cin.getline(p->domicilio, 100);
    cout<<endl;
    while(p->domicilio[0] == '\0'){
        cout<<"Este campo no puede quedar vacio, indique el domicilio del cliente"<<endl;
        cout<<endl;
        cout<<"DOMICILIO: ";
        cin.getline(p->domicilio, 100);
        cout<<endl;
    }

    cout<<"Ingrese el codigo postal del cliente"<<endl;
    cout<<"CODIGO POSTAL: ";
    cin >> p->cp;
    cin.ignore();
    cout<<endl;
    while(cin.fail() || p->cp < 1000 || p->cp > 9999){
        if(cin.fail()){
            cout<<"El codigo postal del cliente no contiene un formato valido (solo numeros). Intente con otro"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<endl;
            cout<<"CODIGO POSTAL: ";
            cin >> p->cp;
            cin.ignore();
            cout<<endl;
        }else{
            cout<<"El codigo postal del cliente debe ser mayor a 1000 y menor a 9999. Intente nuevamente"<<endl;
            cout<<endl;
            cout<<"CODIGO POSTAL: ";
            cin >> p->cp;
            cin.ignore();
            cout<<endl;
        }
    }

    cout<<"Ingrese la fecha de nacimiento del cliente"<<endl;
    cout<<"FECHA DE NACIMIENTO: "<<endl;
    cout<<"DIA :"<<endl;
    cin >> p->fecha_nacimiento.dia;
    cout<<"EL DIA Q PUSIMOOS ES: "<<p->fecha_nacimiento.dia<<endl;
    cout<<"MES :"<<endl;
    cin >> p->fecha_nacimiento.mes;
     cout<<"EL DIA Q PUSIMOOS ES: "<<p->fecha_nacimiento.mes<<endl;
    cout<<"ANIO :"<<endl;
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
        cout<<"ANIO :"<<endl;
        cin >> p->fecha_nacimiento.anio;
            cin.ignore();
            cout<<endl;

        }


    p->estado = true;

    return true;
}

void listar_clientes(clientes reg){
    int i;

    cout<<"El ID del cliente es: "<< reg.id<<endl;

    cout<<"Nombre completo del cliente: " <<reg.nombre<<" "<<reg.apellidos<<endl;

    cout<<"Mail del cliente: " << reg.mail<<endl;

    cout<<"Domicilio: "  <<reg.domicilio<<endl;

    cout<<"Codigo Postal: " << reg.cp<<endl;

    cout<<"Fecha de nacimiento: "<<reg.fecha_nacimiento.dia<<'/'<<reg.fecha_nacimiento.mes<<'/'<<reg.fecha_nacimiento.anio<<endl;


    cout<<"Estado del cliente: ";
    if( reg.estado ){
        cout<<"activo"<<endl;
    }else{
        cout<<"inactivo"<<endl;
    }
}

void listar_todos_clientes(){
    clientes reg;
    int i=0, cant;
    cant = contar_clientes();

    for(i=0; i<cant; i++){
        reg = leer_clientes(i);
        listar_clientes(reg);
        cout<<endl<<"Presiona una tecla para avanzar de registro o finalizar."<<endl<<endl;
        anykey();
    }
}

void eliminar_cliente(){
    int codigoBuscado, pos;
    clientes reg;

    cout << "Ingrese el ID del cliente a eliminar"<<endl;
    cout << "ID: ";

    cin >> codigoBuscado;
    if(cin.fail()){
        cout<<"El ID del cliente no contiene un formato valido (solo numeros)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
    }else{
        pos = buscar_clientes(codigoBuscado);
        if (pos >= 0){
            reg = leer_clientes(pos);
            reg.estado = false;
            listar_clientes(reg);

            if (guardar_clientes(reg, pos) == true){
                cout<<"Producto eliminado correctamente"<<endl;
            }else{
                cout<<"No se pudo eliminar el producto"<<endl;
            }
        }else{
            cout<<"El cliente a eliminar no existe."<<endl;
        }
    }
    anykey();
}


void editar_clientes(){
    int codigoBuscado, pos;
    clientes reg;

    cout << "Ingrese el ID del cliente a modificar"<<endl;
    cout << "ID: ";

    cin >> codigoBuscado;
    if(cin.fail()){
        cout<<"El ID del cliente no contiene un formato valido (solo numeros)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin.ignore();
    }
    else{
        pos = buscar_clientes(codigoBuscado);
        if (pos >= 0){
            reg = leer_clientes(pos);
            listar_clientes(reg);

            cout<<endl;
            cout<<"Ingrese el nuevo domicilio del cliente"<<endl;
            cout<<"DOMICILIO: ";
            cin >> reg.domicilio;
            cin.ignore();
            cout<<endl;


            if (guardar_clientes(reg, pos) == true){
                cout<<"Cliente editado correctamente"<<endl;
            }
            else{
                cout<<"No se pudo editar el Cliente correctamente"<<endl;
            }
            anykey();
        }else{
            cout<<"El Cliente buscado no existe."<<endl;
        }
    }
}


void listar_clientes_x_id(){
    int codigoBuscado, pos;
    clientes reg;

    cout << "Ingrese el ID del cliente a buscar"<<endl;
    cout << "ID: ";

    cin >> codigoBuscado;

    if(cin.fail()){
        cout<<"El ID del cliente no contiene un formato valido (solo numeros)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin.ignore();
    }else{
        pos = buscar_clientes(codigoBuscado);
        if (pos >= 0){
            reg = leer_clientes(pos);
            listar_clientes(reg);
            cin.ignore();
            anykey();
        }else{
            cout<<"El cliente buscado no existe."<<endl;
            cin.ignore();
            anykey();
        }
    }
}


void nuevo_clientes(){
    clientes reg;
    if (cargar_clientes(&reg) == true){
                    if (guardar_clientes(reg, -1) == true){
            cout<<"El cliente se guardo correctamente."<<endl;
            anykey();
        }else{
            cout<<"El cliente no se pudo guardar correctamente"<<endl;
            anykey();
        }
    }else{
        cout<<"El cliente no pudo ser cargado."<<endl;
        anykey();
    }

}


#endif // CLIENTES_H_INCLUDED
