#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void copia_seguridad(pizzeria *regplatos,clientes *regclientes,Pedidos *regpedidos)
{
  FILE *pplatos,*pcoplatos,*pclientes,*pcoclientes,*ppedidos,*pcopedidos;

  pplatos = fopen(PATH_ARCHIVO,"rb");
  if(pplatos == NULL){
        system("cls");
      cout << " NO SE PUDO ABRIR EL ARCHIVOS PLATOS " << endl;
      getch();
    return;
  }
  pclientes = fopen(PATH_CLIENTES,"rb");
  if(pclientes == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO CLIENTES " << endl;
    getch();
    return;
  }
  ppedidos = fopen(PATH_PEDIDOS,"rb");
  if(ppedidos == NULL){
    system("cls");
    cout << "NO SE PUDO ABRIR EL ARCHIVO PEDIDOS  " << endl;
    getch();
    return;
  }
  pcoplatos = fopen("platos.bkp","ab");
  if(pcoplatos == NULL){
        system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA PLATOS " << endl;
    getch();
    return;
  }
  pcoclientes = fopen("clientes.bkp","ab");
  if(pcoclientes == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA CLIENTES " << endl;
    getch();
    return;
  }
  pcopedidos = fopen("pedidos.bkp","ab");
  if(pcoclientes == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA PEDIDOS " << endl;
    getch();
    return;
  }
  while(fread(&regplatos,sizeof(pizzeria),1,pplatos) == 1){
    fwrite(&regplatos,sizeof(pizzeria),1,pcoplatos);
  }
  while(fread(&regclientes,sizeof(clientes),1,pclientes) == 1){
    fwrite(&regclientes,sizeof(clientes),1,pcoclientes);
  }
  while(fread(&regpedidos,sizeof(Pedidos),1,ppedidos) == 1){
    fwrite(&regpedidos,sizeof(Pedidos),1,pcopedidos);
  }
  fclose(pclientes);
  fclose(pcoclientes);
  fclose(ppedidos);
  fclose(pcopedidos);
  fclose(pplatos);
  fclose(pcoplatos);
  system("cls");
  cout << " Datos copiados ..." << endl;
  getch();
}


void restaurar_copia_de_seguridad(pizzeria *regplatos,clientes *regclientes,Pedidos *regpedidos)
{
    FILE *pplatos,*pcoplatos,*pclientes,*pcoclientes,*ppedidos,*pcopedidos;
    pcoplatos= fopen("platos.bkp","rb");
    if(pcoplatos == NULL){
        system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA PLATOS " << endl;
    getch();
    return;
  }
  pcoclientes = fopen("clientes.bkp","rb");
  if(pcoclientes == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA CLIENTES " << endl;
    getch();
    return;
  }
  pcopedidos = fopen("pedidos.bkp","rb");
  if(pcoclientes == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO COPIA CLIENTES " << endl;
    getch();
    return;
  }
  pplatos = fopen(PATH_ARCHIVO,"wb");
  if(pplatos == NULL){
      system("cls");
      cout << " NO SE PUDO ABRIR EL ARCHIVOS PLATOS " << endl;
      getch();
      return;
  }
  pclientes = fopen(PATH_CLIENTES,"wb");
  if(pclientes == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO CLIENTES " << endl;
    getch();
    return;
  }
  ppedidos = fopen(PATH_PEDIDOS,"wb");
  if(ppedidos == NULL){
    system("cls");
    cout << " NO SE PUDO ABRIR EL ARCHIVO PEDIDOS " << endl;
    getch();
    return;
  }
  while(fread(&regplatos,sizeof(pizzeria),1,pcoplatos) == 1){
    fwrite(&regplatos,sizeof(pizzeria),1,pplatos);
  }
  while(fread(&regclientes,sizeof(clientes),1,pcoclientes) == 1){
    fwrite(&regplatos,sizeof(clientes),1,pclientes);
  }
  while(fread(&regpedidos,sizeof(Pedidos),1,pcopedidos) == 1){
    fwrite(&regpedidos,sizeof(Pedidos),1,ppedidos);
  }
 fclose(pclientes);
  fclose(pcoclientes);
  fclose(ppedidos);
  fclose(pcopedidos);
  fclose(pplatos);
  fclose(pcoplatos);
  system("cls");
  cout << " Datos restaurados correctamente " << endl;
  getch();
}

#endif // CONFIGURACION_H_INCLUDED
