#pragma once
#include "Recursos.h"

class MasterCard {

public:
	MasterCard() {};
	bool validar(string tipo, tarjeta x) {

		//Para cambiar color...
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		if (x.empresa == tipo) {
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); //verde
			cout << "Validando informacion... Autenticacion completada" << endl;
			cout << "Pago realizado con exito. Gracias por pagar con MasterCard!!" << endl << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //predeterminado
	
			return true;
		}
		else {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED); //verde
			cout << "Validando informacion... Error de autenticacion!!" << endl;
			cout << "La tarjeta ingresada no es MasterCard" << endl;
			cout << "Tipo de tarjeta ingresada: " << x.empresa << endl << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //predeterminado

			return false;

		}

	}
};

class Visa {

public:
	Visa() {};
	bool validar(string tipo, tarjeta x) {

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
		if (x.empresa == tipo) {
			
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "Validando informacion... Autenticacion completada" << endl;
			cout << "Pago realizado con exito. Gracias por pagar con VISA!!" << endl << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			return true;
		}
		else {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			cout << "Validando informacion... Error de autenticacion!!" << endl;
			cout << "La tarjeta ingresada no es VISA" << endl;
			cout << "Tipo de tarjeta ingresada: " <<x.empresa << endl << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			return false;
		}
		
	}
};

class AmericanExpress {

public:
	AmericanExpress() {};
	bool validar(string tipo, tarjeta x) {

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		if (x.empresa == tipo) {

			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "Validando informacion... Autenticacion completada" << endl;
			cout << "Pago realizado con exito. Gracias por pagar con AmericanExpress!!" << endl << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			return true;
		}
		else {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			cout << "Validando informacion... Error de autenticacion!!" << endl;
			cout << "La tarjeta ingresada no es AmericanExpress" << endl;
			cout << "Tipo de tarjeta ingresada: " << x.empresa << endl << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			return false;
		}

	}
};

class DinersClub {

public:
	DinersClub() {};
	bool validar(string tipo, tarjeta x) {

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		if (x.empresa == tipo) {

			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "Validando informacion... Autenticacion completada" << endl;
			cout << "Pago realizado con exito. Gracias por pagar con DinersClub!!" << endl << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			return true;
		}
		else {
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			cout << "Validando informacion... Error de autenticacion!!" << endl;
			cout << "La tarjeta ingresada no es DinersClub" << endl;
			cout << "Tipo de tarjeta ingresada: " << x.empresa << endl << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "Presione Enter para continuar...";

			return false;
		}

	}
};
