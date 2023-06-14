#include <iostream>
#include <string>//untuk merepresentasikan teks dan data teks dalam bahasa pemrograman. 
#include <vector>//merepresentasikan kumpulan data yang terorganisir dalam satu dimensi.

using namespace std;//mengakses semua elemen yang terkait dengan namespace "std" (Standar) tanpa harus menyebutkan namespace tersebut secara eksplisit setiap kali menggunakan elemen-elemen dari std.

class Penerbit {
public:
    Penerbit(const string& namaPenerbit) : namaPenerbit(namaPenerbit) {}

    string getNamaPenerbit() const { //mengembalikan sebuah nilai bertipe string atau untuk mengambil nilai dari suatu variabel 
        return namaPenerbit;
    }

private://untuk mengatur aksesibilitas anggota (member) dari sebuah kelas. Ketika anggota kelas dinyatakan sebagai "private", artinya mereka hanya dapat diakses oleh anggota lain dari kelas tersebut, dan tidak dapat diakses dari luar kelas.
    string namaPenerbit;
};

class Pengarang {
public:
    Pengarang(const string& namaPengarang, Penerbit* penerbit) : namaPengarang(namaPengarang), penerbit(penerbit) {}

    string getNamaPengarang() const {
        return namaPengarang;
    }

    Penerbit* getPenerbit() const {
        return penerbit;
    }

private:
    string namaPengarang;
    Penerbit* penerbit;
};

class Buku {
public://ksesibilitas suatu anggota (member) dari suatu kelas atau struktur. Ketika suatu anggota dideklarasikan sebagai "public" dalam C++, berarti anggota tersebut dapat diakses dari luar kelas atau struktur tersebut.
    Buku(const string& judulBuku, Pengarang* pengarang) : judulBuku(judulBuku), pengarang(pengarang) {}

    string getJudulBuku() const {
        return judulBuku;
    }

    Pengarang* getPengarang() const {
        return pengarang;
    }

private:
    string judulBuku;
    Pengarang* pengarang;
};

int main() {
    // Membuat objek Penerbit
    Penerbit gamaPress("Gama Press");
    Penerbit intanPariwara("Intan Pariwara");

    // Membuat objek Pengarang
    Pengarang joko("Joko", &gamaPress);
    Pengarang lia("Lia", &gamaPress);
    Pengarang giga("Giga", &gamaPress);
    Pengarang asroni("Asroni", &intanPariwara);

    // Membuat objek Buku
    Buku fisika("Fisika", &joko);
    Buku algoritma("Algoritma", &joko);
    Buku basisData("Basisdata", &lia);
    Buku dasarPemrograman("Dasar Pemrograman", &asroni);
    Buku matematika("Matematika", &giga);
    Buku multimedia1("Multimedia 1", &giga);

    // Menyimpan objek Pengarang dan Penerbit dalam vektor
    vector<Penerbit*> daftarPenerbit = { &gamaPress, &intanPariwara };
    vector<Pengarang*> daftarPengarang = { &joko, &lia, &giga, &asroni };

    // Menampilkan daftar pengarang pada penerbit "Gama Press"
    cout << "Daftar pengarang pada penerbit \"Gama Press\":" << endl;
    for (Pengarang* pengarang : daftarPengarang) {
        if (pengarang->getPenerbit()->getNamaPenerbit() == "Gama Press") {
            cout << pengarang->getNamaPengarang() << endl;
        }
    }

    // Menampilkan daftar pengarang pada penerbit "Intan Pariwara"
    cout << "Daftar pengarang pada penerjemah" >>
