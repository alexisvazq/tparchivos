#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

// const char *PATH_PEDIDOS = "datos/pedidos.dat";
const char *PATH_PEDIDOSBKP = "datos/pedidos.bkp";
// const char *PATH_PLATOS = "datos/platos.dat";
const char *PATH_PLATOSBKP = "datos/platos.bkp";
// const char *PATH_CLIENTES = "datos/clientes.dat";
const char *PATH_CLIENTESBKP = "datos/clientes.bkp";

bool doBackupPlatos();
bool doBackupClientes();
bool doBackupPedidos();

bool doRestorePlatos();
bool doRestoreClientes();
bool doRestorePedidos();

void copia_seguridad(){
  bool isBackupPlatos = doBackupPlatos();
  bool isBackupClientes = doBackupClientes();
  bool isBackupPedidos = doBackupPedidos();

	if( isBackupPlatos && isBackupClientes && isBackupPedidos ){
		cout<<"El backup fue exitoso!"<<endl;
	}else{
		cout<<"No se pudo crear el backup"<<endl;
	}
  anykey();
}

void restaurar_copia(){
  bool isRestorePlatos = doRestorePlatos();
  bool isRestoreClientes = doRestoreClientes();
  bool isRestorePedidos = doRestorePedidos();

	if( isRestorePlatos && isRestoreClientes && isRestorePedidos ){
		cout<<"El backup se ha restaurado exitosamente!"<<endl;
	}else{
		cout<<"No se pudo restaurar el backup"<<endl;
	}
  anykey();
}

bool doBackupPlatos(){

	bool isBackupDone;
  int cantPlatos = contar_platos(PATH_PLATOS);

  platos *platosB = (platos *) malloc(cantPlatos*sizeof(platos));
  if(platosB==NULL){
    cout<<"Error de asignación de memoria"<<endl;
    return false;
  }
	
  FILE *p;

	p = fopen(PATH_PLATOS, "rb");
	int platosLeidos = fread(&platosB[0], sizeof(platos), cantPlatos, p);
	fclose(p);

	p = fopen(PATH_PLATOSBKP, "wb");
	int platosEscritos = isBackupDone = fwrite(&platosB[0], sizeof(platos), cantPlatos, p);
	fclose(p);

	free(platosB);

	return isBackupDone;
}

bool doBackupClientes(){

	bool isBackupDone;
  int cantClientes = contar_clientes(PATH_CLIENTES);

  clientes *clientesB = (clientes *) malloc(cantClientes*sizeof(clientes));
  if(clientesB==NULL){
    cout<<"Error de asignación de memoria"<<endl;
    return false;
  }
	
  FILE *p;

	p = fopen(PATH_CLIENTES, "rb");
	int clientesLeidos = fread(&clientesB[0], sizeof(clientes), cantClientes, p);
	fclose(p);

	p = fopen(PATH_CLIENTESBKP, "wb");
	int clientesEscritos = isBackupDone = fwrite(&clientesB[0], sizeof(clientes), cantClientes, p);
	fclose(p);

	free(clientesB);

	return isBackupDone;
}

bool doBackupPedidos(){

	bool isBackupDone;
  int cantPedidos = contar_pedidos(PATH_PEDIDOS);

  pedidos *pedidosB = (pedidos *) malloc(cantPedidos*sizeof(pedidos));
  if(pedidosB==NULL){
    cout<<"Error de asignación de memoria"<<endl;
    return false;
  }
	
  FILE *p;

	p = fopen(PATH_PEDIDOS, "rb");
	int pedidosLeidos = fread(&pedidosB[0], sizeof(pedidos), cantPedidos, p);
	fclose(p);

	p = fopen(PATH_PEDIDOSBKP, "wb");
	int pedidosEscritos = isBackupDone = fwrite(&pedidosB[0], sizeof(pedidos), cantPedidos, p);
	fclose(p);

	free(pedidosB);

	return isBackupDone;
}

bool doRestorePlatos(){

	bool isRestoreDone;
  int cantPlatos = contar_platos(PATH_PLATOSBKP);

  platos *platosB = (platos *) malloc(cantPlatos*sizeof(platos));
  if(platosB==NULL){
    cout<<"Error de asignación de memoria"<<endl;
    return false;
  }
	
  FILE *p;

	p = fopen(PATH_PLATOSBKP, "rb");
	int platosLeidos = fread(&platosB[0], sizeof(platos), cantPlatos, p);
  cout<<"PLATOS LEIDOS: "<<platosLeidos<<endl;
	fclose(p);

	p = fopen(PATH_PLATOS, "wb");
	int platosEscritos = isRestoreDone = fwrite(&platosB[0], sizeof(platos), cantPlatos, p);
  cout<<"PLATOS ESCRITOS: "<<platosEscritos<<endl;
	fclose(p);

	free(platosB);

	return isRestoreDone;
}

bool doRestoreClientes(){

	bool isRestoreDone;
  int cantClientes = contar_clientes(PATH_CLIENTESBKP);

  clientes *clientesB = (clientes *) malloc(cantClientes*sizeof(clientes));
  if(clientesB==NULL){
    cout<<"Error de asignación de memoria"<<endl;
    return false;
  }
	
  FILE *p;

	p = fopen(PATH_CLIENTESBKP, "rb");
	int clientesLeidos = fread(&clientesB[0], sizeof(clientes), cantClientes, p);
	fclose(p);

	p = fopen(PATH_CLIENTES, "wb");
	int clientesEscritos = isRestoreDone = fwrite(&clientesB[0], sizeof(clientes), cantClientes, p);
	fclose(p);

	free(clientesB);

	return isRestoreDone;
}

bool doRestorePedidos(){

	bool isRestoreDone;
  int cantPedidos = contar_pedidos(PATH_PEDIDOSBKP);

  pedidos *pedidosB = (pedidos *) malloc(cantPedidos*sizeof(pedidos));
  if(pedidosB==NULL){
    cout<<"Error de asignación de memoria"<<endl;
    return false;
  }
	
  FILE *p;

	p = fopen(PATH_PEDIDOSBKP, "rb");
	int pedidosLeidos = fread(&pedidosB[0], sizeof(pedidos), cantPedidos, p);
	fclose(p);

	p = fopen(PATH_PEDIDOS, "wb");
	int pedidosEscritos = isRestoreDone = fwrite(&pedidosB[0], sizeof(pedidos), cantPedidos, p);
	fclose(p);

	free(pedidosB);

	return isRestoreDone;
}

#endif // CONFIGURACION_H_INCLUDED
