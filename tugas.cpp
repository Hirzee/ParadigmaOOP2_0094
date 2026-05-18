#include <iostream>
#include <vector>
using namespace std;

// Abstract Base Class
class RekeningBank {
protected:
    string namaNasabah;
    double saldo;

public:
    RekeningBank(string nama, double saldoAwal) {
        namaNasabah = nama;
        saldo = saldoAwal;
    }

    // Pure Virtual Function
    virtual void potongAdmin() = 0;

    // Menampilkan informasi rekening
    void tampilkanInfo() {
        cout << "Nama Nasabah : " << namaNasabah << endl;
        cout << "Saldo        : Rp " << saldo << endl;
        cout << "-----------------------------" << endl;
    }

    virtual ~RekeningBank() {}
};

// Class Rekening Syariah
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        cout << "Rekening Syariah -> Tidak ada potongan admin." << endl;
    }
};

// Class Rekening Konvensional
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Rekening Konvensional -> Potongan admin Rp 15.000" << endl;
    }
};

// Class Rekening Premium
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Rekening Premium -> Bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "Rekening Premium -> Potongan admin Rp 50.000" << endl;
        }
    }
};

int main() {

    vector<RekeningBank*> daftarRekening;

    // Membuat objek rekening
    daftarRekening.push_back(new RekeningSyariah("Andi", 5000000));
    daftarRekening.push_back(new RekeningKonvensional("Budi", 3000000));
    daftarRekening.push_back(new RekeningPremium("Citra", 15000000));
    daftarRekening.push_back(new RekeningPremium("Dina", 7000000));

    cout << "=== PROSES AKHIR BULAN BANK GIBRAN JAYA ===" << endl;
    cout << endl;

    // Proses potong admin
    for (RekeningBank* rekening : daftarRekening) {
        rekening->potongAdmin();
        rekening->tampilkanInfo();
    }

    // Hapus memori
    for (RekeningBank* rekening : daftarRekening) {
        delete rekening;
    }

    return 0;
}