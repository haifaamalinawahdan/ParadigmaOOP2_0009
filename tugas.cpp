#include <iostream>
#include <string>
using namespace std;

class RekeningBank {
protected:
    string namaNasabah;
    double saldo;
public:
    RekeningBank(string nama, double saldoAwal) {
        namaNasabah = nama;
        saldo = saldoAwal;
    }
    
    virtual void potongAdmin() = 0;


};