#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

bool doBackupPlatos();
bool doBackupClientes();
bool doBackupPedidos();

void copia_seguridad(){
  bool isBackupPlatos = doBackupPlatos();
  bool isBackupClientes = doBackupClientes();
  bool isBackupPedidos = doBackupPedidos();

	if( isBackupPlatos && isBackupClientes && isBackupPedidos ){
		cout<<"Backup exitoso!"<<endl;
	}else{
		cout<<"No se pudo crear el backup"<<endl;
	}
}

bool doBackupPlatos(){

	bool isBackupDone;
  int cantPlatos = contar_platos();

  platos *platosB = (platos *) malloc(cantPlatos*sizeof(platos));
  if(platosB==NULL){
    cout<<"Error de asignación de memoria"<<endl;
    return false;
  }
	
  FILE *p;

	p = fopen("datos/platos.dat", "rb");
	int platosLeidos = fread(&platosB[0], sizeof(platos), cantPlatos, p);
	fclose(p);

	p = fopen("datos/platos.bkp", "wb");
	int platosEscritos = isBackupDone = fwrite(&platosB[0], sizeof(platos), cantPlatos, p);
	fclose(p);

	free(platosB);

	return isBackupDone;
}

bool doBackupClientes(){

	bool isBackupDone;
  int cantClientes = contar_clientes();

  clientes *clientesB = (clientes *) malloc(cantClientes*sizeof(clientes));
  if(clientesB==NULL){
    cout<<"Error de asignación de memoria"<<endl;
    return false;
  }
	
  FILE *p;

	p = fopen("datos/clientes.dat", "rb");
	int clientesLeidos = fread(&clientesB[0], sizeof(clientes), cantClientes, p);
	fclose(p);

	p = fopen("datos/clientes.bkp", "wb");
	int clientesEscritos = isBackupDone = fwrite(&clientesB[0], sizeof(clientes), cantClientes, p);
	fclose(p);

	free(clientesB);

	return isBackupDone;
}

bool doBackupPedidos(){

	bool isBackupDone;
  int cantPedidos = contar_pedidos();

  pedidos *pedidosB = (pedidos *) malloc(cantPedidos*sizeof(pedidos));
  if(pedidosB==NULL){
    cout<<"Error de asignación de memoria"<<endl;
    return false;
  }
	
  FILE *p;

	p = fopen("datos/pedidos.dat", "rb");
	int pedidosLeidos = fread(&pedidosB[0], sizeof(pedidos), cantPedidos, p);
	fclose(p);

	p = fopen("datos/pedidos.bkp", "wb");
	int pedidosEscritos = isBackupDone = fwrite(&pedidosB[0], sizeof(pedidos), cantPedidos, p);
	fclose(p);

	free(pedidosB);

	return isBackupDone;
}

/*void restaurar_seguridad(platos *regplatos,clientes *regclientes,pedidos *regpedidos)
{
    FILE *pplatos,*pcoplatos,*pclientes,*pcoclientes,*ppedidos,*pcopedidos;
    pcoplatos= fopen("platos.bkp","rb");
    if(pcoplatos == NULL){
        system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA PLATOS " << endl;
    anykey();
    return;
  }
  pcoclientes = fopen("clientes.bkp","rb");
  if(pcoclientes == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA CLIENTES " << endl;
    anykey();
    return;
  }
  pcopedidos = fopen("pedidos.bkp","rb");
  if(pcoclientes == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA CLIENTES " << endl;
    anykey();
    return;
  }
  pplatos = fopen(PATH_PLATOS,"wb");
  if(pplatos == NULL){
      system("cls");
      cout << " NO SE PUDO ABRIR EL ARCHIVOS PLATOS " << endl;
      anykey();
      return;
  }
  pclientes = fopen(PATH_CLIENTES,"wb");
  if(pclientes == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO CLIENTES " << endl;
    anykey();
    return;
  }
  ppedidos = fopen(PATH_PEDIDOS,"wb");
  if(ppedidos == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO PEDIDOS " << endl;
    anykey();
    return;
  }
  while(fread(&regplatos,sizeof(platos),1,pcoplatos) == 1){
    fwrite(&regplatos,sizeof(platos),1,pplatos);
  }
  while(fread(&regclientes,sizeof(clientes),1,pcoclientes) == 1){
    fwrite(&regplatos,sizeof(clientes),1,pclientes);
  }
  while(fread(&regpedidos,sizeof(pedidos),1,pcopedidos) == 1){
    fwrite(&regpedidos,sizeof(pedidos),1,ppedidos);
  }
 fclose(pclientes);
  fclose(pcoclientes);
  fclose(ppedidos);
  fclose(pcopedidos);
  fclose(pplatos);
  fclose(pcoplatos);
  system("cls");
  cout << "--------COPIA DE SEGURIDAD RESTAURADA-------- " << endl;
  anykey();
}*/

#endif // CONFIGURACION_H_INCLUDED
