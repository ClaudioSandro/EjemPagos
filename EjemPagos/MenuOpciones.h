#pragma once
#include "Recursos.h"

class MenuOpciones {

public:

	int mostrarMenu(string tipo) {

		if (tipo == "Cliente") {
			int op;
			cout << "BIENVENIDO A LA APP SAPORE D'ITALIA" << endl << endl;
			cout << "1. Crear Orden" << endl;
			cout << "2. Ver mis ordenes pendientes" << endl;
			cout << "3. Sistema de pagos" << endl;
			cout << "4. Salir" << endl << endl;
			cout << "Opcion: "; cin >> op;

			return op;
		}
		if (tipo == "Trabajador") {
			
		}
	}

};