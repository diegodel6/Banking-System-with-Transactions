#include <iostream>
#include <string>

using namespace std;

class Cuenta {
private:
    string numero_cuenta;
    string titular_cuenta;
    double saldo;

public:
    Cuenta(string num_cuenta, string titular, double saldo_inicial) {
        numero_cuenta = num_cuenta;
        titular_cuenta = titular;
        saldo = saldo_inicial;
    }

    void depositar(double monto) {
        saldo += monto;
        cout << "Deposito de $" << monto << " realizado con exito." << endl;
    }

    bool retirar(double monto) {
        if (monto > saldo) {
            cout << "Fondos insuficientes para retirar $" << monto << "." << endl;
            return false;
        }
        saldo -= monto;
        cout << "Retiro de $" << monto << " realizado con exito." << endl;
        return true;
    }

    double obtener_saldo() {
        return saldo;
    }

    void mostrar_info_cuenta() {
        cout << "Numero de cuenta: " << numero_cuenta << endl;
        cout << "Titular de la cuenta: " << titular_cuenta << endl;
        cout << "Saldo actual: $" << saldo << endl;
    }

    string obtener_numero_cuenta() {
        return numero_cuenta;
    }
};

class Transaccion {
private:
    Cuenta* cuenta_emisor;
    Cuenta* cuenta_receptor;
    double monto;

public:
    Transaccion(Cuenta* emisor, Cuenta* receptor, double monto) {
        cuenta_emisor = emisor;
        cuenta_receptor = receptor;
        this->monto = monto;
    }

    void procesar_transaccion() {
        cout << "Procesando transaccion de $" << monto << "..." << endl;
        if (cuenta_emisor->retirar(monto)) {
            cuenta_receptor->depositar(monto);
            cout << "Transaccion completada con exito!" << endl;
        } else {
            cout << "Transaccion fallida debido a fondos insuficientes." << endl;
        }
    }

    void mostrar_info_transaccion() {
        cout << "Informacion de la transaccion:" << endl;
        cout << "  Cuenta emisora: " << cuenta_emisor->obtener_numero_cuenta() << endl;
        cout << "  Cuenta receptora: " << cuenta_receptor->obtener_numero_cuenta() << endl;
        cout << "  Monto: $" << monto << endl;
    }
};

int main() {
    Cuenta cuenta1("123456", "Diego Delgado", 500.0);
    Cuenta cuenta2("654321", "Juan Perez", 300.0);

    cout << "Informacion inicial de las cuentas:" << endl;
    cuenta1.mostrar_info_cuenta();
    cout << endl;
    cuenta2.mostrar_info_cuenta();
    cout << "====================================" << endl;

    Transaccion transaccion1(&cuenta1, &cuenta2, 150.0);
    transaccion1.mostrar_info_transaccion();
    transaccion1.procesar_transaccion();
    cout << "====================================" << endl;

    cout << "Informacion de las cuentas despues de la transaccion:" << endl;
    cuenta1.mostrar_info_cuenta();
    cout << endl;
    cuenta2.mostrar_info_cuenta();

    return 0;
}