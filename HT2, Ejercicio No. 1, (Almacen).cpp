/* Se dispone de un archivo STOCK correspondiente a la existencia de art�culos de un almac�n y se desea se�alar aquellos cuyos art�culos
cuyo nivel est� por debajo del m�nimo y que visualicen un mensaje "Hacer pedido". Cada art�culo contiene un registro con los siguientes
campos: N�mero de c�digo del art�culo, nivel m�nimo, nivel actual, proveedor, precio.
El programa debe contener un men� que se especifiquen las siguientes opciones:
1) Agregar productos (Grabar datos a un archivo)
2) Leer archivo y mostrar en pantalla que productos tienen el m�nimo
 if (nivel actual <= nivel m�nimo)
 	cout<<"Nivel M�nimo");*/ 
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
void lectura();
void escritura();
void menu();
void ingreso_de_datos();
struct eproducto{
	int codigo, nivel;
	float precio;
	char proveedor[30],nombre[30];
	
};

int main(){
	fflush(stdin);
	menu();
	system("pause");
	return 0;
}
void ingreso_de_datos(){
	fflush(stdin);
	int n,i;
	string _producto;
	cout<<"Cuantos productos se ingresar�n?"<<endl;
	cin>>n;
	eproducto producto[n]; 
		for (i=0;i<n;i++){
			cout<<"Ingresar nombre del producto: "<<endl;
			cin>>producto[i].nombre[30];
			cout<<"Ingresar c�digo del producto: "<<endl;
			cin>>producto[i].codigo;
			cout<<"Ingresar la cantidad de existencias del producto: "<<endl;
			cin>>producto[i].nivel;
			cout<<"Ingresar el precio del producto: "<<endl;
			cin>>producto[i].precio;
			cout<<"Ingresar el nombre del proveedor: "<<endl;
			cin>>producto[i].proveedor;
		}	
}	
void escritura(){
	ofstream archivo;
	string producto;
	
	archivo.open("stock.txt",ios::out);
	if (archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	ingreso_de_datos();
	
	archivo.close();
}
void lectura(){
	ifstream archivo;
	string texto;
	archivo.open("stock.txt",ios::in);
	if (archivo.fail()){
		cout<<"No se pudo abrir el archivo porque a�n no se ha creado. "<<endl;
		exit(1);
	}
	while(!archivo.eof()){
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close(); 
}
	
void menu(){
	int opcion(1);
	cout<<"Men� principal"<<endl;
	cout<<"1) Agregar productos"<<endl;
	cout<<"2) Mostrar productos bajo el m�nimo"<<endl;
	cin>>opcion;
	if(opcion==1){
		system("CLS");
		cout<<"Opci�n 1";
		escritura();
	}
	else if (opcion==2){
		system("CLS");
		cout<<"Opci�n 2";
		lectura();
	}

}
