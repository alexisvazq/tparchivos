#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void copia_seguridad(platos *regplatos,clientes *regclientes,pedidos *regpedidos)
{
  FILE *pplatos,*pcoplatos,*pclientes,*pcoclientes,*ppedidos,*pcopedidos;

  pplatos = fopen(PATH_PLATOS,"rb");
  if(pplatos == NULL){
        system("cls");
      cout << "EL ARCHIVO PLATOS NO PUDO SER ABIERTO " << endl;
      anykey();
    return;
  }
  pclientes = fopen(PATH_CLIENTES,"rb");
  if(pclientes == NULL){
    system("cls");
    cout << "  EL ARCHIVO CLIENTES NO SE PUDO ABRIR " << endl;
    anykey();
    return;
  }
  ppedidos = fopen(PATH_PEDIDOS,"rb");
  if(ppedidos == NULL){
    system("cls");
    cout << " EL ARCHIVO PEDIDOS NO SE PUDO ABRIR " << endl;
    anykey();
    return;
  }
  pcoplatos = fopen("platos.bkp","ab");
  if(pcoplatos == NULL){
        system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA PLATOS " << endl;
    anykey();
    return;
  }
  pcoclientes = fopen("clientes.bkp","ab");
  if(pcoclientes == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA CLIENTES " << endl;
    anykey();
    return;
  }
  pcopedidos = fopen("pedidos.bkp","ab");
  if(pcoclientes == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA PEDIDOS " << endl;
    anykey();
    return;
  }
  while(fread(&regplatos,sizeof(platos),1,pplatos) == 1){
    fwrite(&regplatos,sizeof(platos),1,pcoplatos);
  }
  while(fread(&regclientes,sizeof(clientes),1,pclientes) == 1){
    fwrite(&regclientes,sizeof(clientes),1,pcoclientes);
  }
  while(fread(&regpedidos,sizeof(pedidos),1,ppedidos) == 1){
    fwrite(&regpedidos,sizeof(pedidos),1,pcopedidos);
  }
  fclose(pclientes);
  fclose(pcoclientes);
  fclose(ppedidos);
  fclose(pcopedidos);
  fclose(pplatos);
  fclose(pcoplatos);
  system("cls");
  cout << "--------COPIA DE SEGURIDAD REALIZADA--------" << endl;
  anykey();
}


void restaurar_seguridad(platos *regplatos,clientes *regclientes,pedidos *regpedidos)
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
}

#endif // CONFIGURACION_H_INCLUDED
