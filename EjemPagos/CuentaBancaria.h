#pragma once
#include "Recursos.h"
#include "MetodoPagos.h"
#include "Usuario.h"


class CuentaBancaria {
private:
	bool pagoRealizado = false;
public:
	void setPagoCompletado(bool _pagoRealizado) { pagoRealizado = _pagoRealizado; }
	bool getPagoRealizado() { return pagoRealizado; }

	tarjeta guardarTarjeta(tarjeta aux, tarjeta metodo);
	int opcionProceder();
	tarjeta nuevaTarjeta();
	int opcionPago(tarjeta metodo);
	tarjeta ingresarDatos(string tipo, tarjeta metodo);
	void mostrarTarjeta(tarjeta metodo);

	tarjeta pagar(string tipo, tarjeta metodo);
};

void CuentaBancaria::mostrarTarjeta(tarjeta metodo) {

	cout << "Tipo: " << metodo.empresa << endl;
	cout << "Numero de Tarjeta: " << metodo.numero << endl;
	cout << "Titular: " << metodo.titular << endl;
	cout << "Codigo: " << metodo.codigo << endl;
	cout << endl;

}

tarjeta CuentaBancaria::nuevaTarjeta() {
	tarjeta aux;
	int op_metodo;

	cout << "INGRESAR TARJETA " << endl << endl;
	cout << "Seleccione la empresa de su tarjeta: " << endl << endl;

	cout << "1.Visa" << endl;
	cout << "2.MasterCard" << endl;
	cout << "3.AmericanExpress" << endl;
	cout << "4.DinersClub" << endl << endl;

	cout << "Opcion: "; cin >> op_metodo; cout << endl;
	switch (op_metodo)
	{
	case 1: aux.empresa = "Visa"; break;
	case 2: aux.empresa = "MasterCard"; break;
	case 3: aux.empresa = "AmericanExpress"; break;
	case 4: aux.empresa = "DinersClub"; break;
	}
	system("cls");

	cout << "INGRESAR TARJETA " << endl << endl;
	cout << "Tipo: " << aux.empresa << endl;
	cout << "Numero de Tarjeta: "; cin >> aux.numero;
	cout << "Titular: "; cin >> aux.titular;
	cout << "Codigo: "; cin >> aux.codigo;
	cout << endl;

	return aux;
}

tarjeta CuentaBancaria::guardarTarjeta(tarjeta aux, tarjeta metodo) {
	//Proceso de guardar tarjeta en cuenta 
	int op_guardar;

	cout << "Desea guardar la tarjeta? Si(1) No(2): "; cin >> op_guardar;

	if (op_guardar == 1) {

		cout << "Se guardaron los datos correctamente!! Presione Enter para continuar..." << endl << endl;

		//Pausar el programa hasta que se presione enter
		cin.ignore(); cin.get();
		system("cls");

		return aux; // Si desea guardar la tarjeta devuelve los datos de la tarjeta ingresada
	}
	else {
		cout << "No se guardaron datos de la tarjeta... Presione Enter para continuar..." << endl << endl;

		//Pausar el programa hasta que se presione enter
		cin.ignore(); cin.get();
		system("cls");

		return metodo; //Caso contrario devuelve la predeterminada
	}
}
int CuentaBancaria::opcionProceder() {
	int op_proceder;
	cout << "Desea proceder con la tarjeta ingresada?" << endl << endl;
	cout << "1.Si" << endl;
	cout << "2.Volver a ingresar" << endl;
	cout << "3.Salir" << endl << endl;

	cout << "Opcion: "; cin >> op_proceder; cout << endl;
	return op_proceder;
}

tarjeta CuentaBancaria::ingresarDatos(string tipo, tarjeta metodo) {
	tarjeta aux;
	MetodoPagos pago;
	tarjeta guardada;
	
	int op_proceder;

	//Obtener datos de nueva tarjeta en aux

	aux = nuevaTarjeta();

	do {
		op_proceder = opcionProceder();
		if (op_proceder == 3) { system("cls"); break; } //SALIR
		if (op_proceder == 2) { system("cls"); aux = nuevaTarjeta(); } //Volver a ingresar
	} while (op_proceder != 1);
		
	if (op_proceder == 1) {
		if (pago.validar(tipo, aux)) setPagoCompletado(true); //Si la validacion devuelve true entonces marca que el pago se realizo
		guardada = guardarTarjeta(aux, metodo); //Pregunta si quiere guardar
		return guardada;
	}
	else {
		return metodo;
	}
		  			
};

int CuentaBancaria::opcionPago(tarjeta metodo) {
	int op;
	cout << "Desea usar la tarjeta guardada en su cuenta? Si(1) No(2)"; cin >> op; cout << endl;
	if (op == 1 && metodo.empresa == " ") { //Si no hay tarjeta guardada
		cout << "No existe tarjeta guardada... Redireccionado a ingreso de tarjeta..." << endl;

		//Pausar el programa hasta que se presione enter
		cout << "Presione Enter para continuar...";
		cin.ignore(); cin.get();
		system("cls");

		return 2; // Devuelve como si quisiera usar la guardada
	}
	else if (op == 2) { //Si no quiere usar tarjeta guardada
		system("cls");
		return 2;
	}else
		system("cls");
		return 1; // Si quiere usar tarjeta guardada
	
}

tarjeta CuentaBancaria::pagar(string tipo, tarjeta metodo) {
	
	tarjeta aux;

	int op = opcionPago(metodo); //Seleccion tarjeta guardada?

	if (op == 2) { //Si no se desea usar tarjeta guardada o no existe tarjeta guardada
		aux = ingresarDatos(tipo, metodo); //Obtener datos de nueva tarjeta
		return aux;
	}
	else { //Si se deseas usar tarjeta guardada
		MetodoPagos pago;
		mostrarTarjeta(metodo);
		if (pago.validar(tipo, metodo)) setPagoCompletado(true);

		//Pausar el programa hasta que se presione enter
		cout << "Presione Enter para continuar...";
		cin.ignore(); cin.get();
		system("cls");

		return metodo;
		
	}
	
	
}