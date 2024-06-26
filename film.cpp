#include <iostream>
using namespace std;

// Deklarasi double linked list
struct DataFilm {
    string namaFilm;
    int durasi;
    int harga;
    DataFilm* kembali;
    DataFilm* lanjut;
};

DataFilm* kepala, * ekor, * saatIni, * nodeBaru, * hapus, * setelahNode;

// Membuat Double Linked List
void createDoubleLinkedList(string data[3]) {
    kepala = new DataFilm();
    kepala->namaFilm = data[0];
    kepala->durasi = stoi(data[1]);
    kepala->harga = stoi(data[2]);
    kepala->kembali = NULL;
    kepala->lanjut = NULL;
    ekor = kepala;
}

// Menghitung Double Linked List
int countDoubleLinkedList()
{
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        saatIni = kepala;
        int jumlah = 0;
        while (saatIni != NULL) {
            jumlah++;
            //step
            saatIni = saatIni->lanjut;
        }
        return jumlah;
    }
}

// Add First
void addFirst(string data[3]) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        nodeBaru = new DataFilm();
        nodeBaru->namaFilm = data[0];
        nodeBaru->durasi = stoi(data[1]);
        nodeBaru->harga = stoi(data[2]);
        nodeBaru->kembali = NULL;
        nodeBaru->lanjut = kepala;
        kepala->kembali = nodeBaru;
        kepala = nodeBaru;
    }
}

// Add Last
void addLast(string data[3]) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        nodeBaru = new DataFilm();
        nodeBaru->namaFilm = data[0];
        nodeBaru->durasi = stoi(data[1]);
        nodeBaru->harga = stoi(data[2]);
        nodeBaru->kembali = ekor;
        nodeBaru->lanjut = NULL;
        ekor->lanjut = nodeBaru;
        ekor = nodeBaru;
    }
}


// Remove First
void removeFirst()
{
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        hapus = kepala;
        kepala = kepala->lanjut;
        kepala->kembali = NULL;
        delete hapus;
    }
}

// Remove Last
void removeLast()
{
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        hapus = ekor;
        ekor = ekor->kembali;
        ekor->lanjut = NULL;
        delete hapus;
    }
}


void changeFirst(string data[3]) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    } else {
        kepala->namaFilm = data[0];
        kepala->durasi = stoi(data[1]);
        kepala->harga = stoi(data[2]);
    }
}

void changeLast(string data[3]) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    } else {
        ekor->namaFilm = data[0];
        ekor->durasi = stoi(data[1]);
        ekor->harga = stoi(data[2]);
    }
}


// Print Double Linked List
void printDoubleLinkedList()
{
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
        cout << "Isi Data : " << endl;
        saatIni = kepala;
        while (saatIni != NULL) {
            // print
            cout << "Nama Film : " << saatIni->namaFilm << endl;
            cout << "Durasi : " << saatIni->durasi << " menit" << endl;
            cout << "Harga : Rp. " << saatIni->harga << endl;
            cout << "\n";
            //step
            saatIni = saatIni->lanjut;
        }
    }
}

int main() {

    string newData[3] = { "Vina", "120", "50000" };
    createDoubleLinkedList(newData);

    printDoubleLinkedList();

    string data2[3] = { "Dilan 1945", "90", "35000" };
    addFirst(data2);

    printDoubleLinkedList();

    string data3[3] = { "Laskar Pelangi", "100", "45000" };
    addLast(data3);

    printDoubleLinkedList();

    string data5[3] = { "ayam dari timur", "112", "34000"};
    changeFirst(data5);

    printDoubleLinkedList();

    string data6[3] = { "laptop baru berujung lama", "130", "60000"};
    changeLast(data6);

    printDoubleLinkedList();

    removeFirst();
    printDoubleLinkedList();

    removeLast();
    printDoubleLinkedList();

    return 0;
}