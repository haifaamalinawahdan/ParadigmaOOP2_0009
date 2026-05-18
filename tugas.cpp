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

    virtual void tampilkanInfo() {
        cout << "Nama Nasabah : " << namaNasabah << endl;
        cout << "Saldo        : Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};

class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        cout << "Rekening Syariah bebas biaya admin." << endl;
    }
};

class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 berhasil dipotong." << endl;
    }
};

class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 berhasil dipotong." << endl;
        }
    }
};

int main() {

  
    RekeningBank* rekening1;
    RekeningBank* rekening2;
    RekeningBank* rekening3;

 
    RekeningSyariah syariah("Andi", 5000000);
    RekeningKonvensional konvensional("Budi", 3000000);
    RekeningPremium premium("Citra", 8000000);


    rekening1 = &syariah;
    rekening2 = &konvensional;
    rekening3 = &premium;

    cout << "===== REKENING SYARIAH =====" << endl;
    rekening1->tampilkanInfo();
    rekening1->potongAdmin();
    rekening1->tampilkanInfo();

    cout << "\n===== REKENING KONVENSIONAL =====" << endl;
    rekening2->tampilkanInfo();
    rekening2->potongAdmin();
    rekening2->tampilkanInfo();

    cout << "\n===== REKENING PREMIUM =====" << endl;
    rekening3->tampilkanInfo();
    rekening3->potongAdmin();
    rekening3->tampilkanInfo();

    return 0;



}