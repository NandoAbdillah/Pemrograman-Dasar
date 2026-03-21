#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Penghuni
{
    string nama_penghuni;
    string tanggal_tinggal;
    string tanggal_pergi;
};

int jumlahRecord = 0;
Penghuni penghuni[100];

ifstream dataFile("logbook2.txt", ios::in);

void readFile()
{

    if (dataFile.is_open())
    {

        while (!dataFile.eof() && jumlahRecord < 100)
        {
            string nama;
            string tanggalTinggal;
            string tanggalPergi;

            getline(dataFile, nama);
            getline(dataFile, tanggalTinggal);
            getline(dataFile, tanggalPergi);


            if (nama != "" && tanggalTinggal != "" && tanggalPergi != "")
            {
                
                penghuni[jumlahRecord].nama_penghuni = nama;
                penghuni[jumlahRecord].tanggal_tinggal = tanggalTinggal;
                penghuni[jumlahRecord].tanggal_pergi = tanggalPergi;

                jumlahRecord++;
            }
        }
        dataFile.close();
    }
}

bool periksaDuplikasi(int jumlahRecord, string nama)
{
    for (int i = 0; i < jumlahRecord; i++)
    {
        if (penghuni[i].nama_penghuni == nama)
        {
            return true;
        }
    }
    return false;
}

void saveData()
{
    ofstream dataOutFile("logbook2.txt", ios::out);
    if (dataOutFile.is_open())
    {
        for (int i = 0; i < jumlahRecord; i++)
        {
            dataOutFile << penghuni[i].nama_penghuni << endl;
            dataOutFile << penghuni[i].tanggal_tinggal << endl;
            dataOutFile << penghuni[i].tanggal_pergi << endl;
        }
    }
    dataOutFile.close();
}

void viewData()
{
    cout << "=====DATA PENGHUNI AGARTHA=====" << endl;
    cout << jumlahRecord;

    for (int i = 0; i < jumlahRecord; i++)
    {
        cout << "Nama Penghuni : " << penghuni[i].nama_penghuni << endl;
        cout << "Tanggal Mulai Tinggal : " << penghuni[i].tanggal_tinggal << endl;
        cout << "-------------------------------" << endl;
    }
}

void addData()
{
    string nama;
    string tanggalTinggal;
    string tanggalPergi;

    cout << "Nama Penghuni : ";
    getline(cin, nama);
    cout << "Tanggal Mulai Tinggal (DD-MM-YYYY) : ";
    getline(cin, tanggalTinggal);
    cout << "Tanggal Mulai Pergi (DD-MM-YYYY) : ";
    getline(cin, tanggalPergi);

    if (periksaDuplikasi(jumlahRecord, nama))
    {
        cout << nama << " sudah terdaftar pada Log Book masukkan penghuni lainnya " << endl;
    }
    else
    {
        penghuni[jumlahRecord].nama_penghuni = nama;
        penghuni[jumlahRecord].tanggal_tinggal = tanggalPergi;
        penghuni[jumlahRecord].tanggal_pergi = tanggalTinggal;

        jumlahRecord++;

        cout << nama << " Berhsil dicatat kedalam Log Book " << endl;

        saveData();
    }
}

void editData()
{
    string nama;
    cout << "Masukkan nama penghuni yang akan di edit: ";
    getline(cin, nama);

    bool ditemukan = false;

    for (int i = 0; i < jumlahRecord; i++)
    {
        if (penghuni[i].nama_penghuni == nama)
        {
            ditemukan = true;
            cout << "Data apa yang ingin di edit ?" << endl;
            cout << "1. Nama Penghuni" << endl;
            cout << "2. Tanggal Mulai Tinggal" << endl;
            cout << "3. Tanggal Pindah" << endl;

            int pilihan;
            cout << "Masukkan pilihan (1/2/3): ";
            cin >> pilihan;
            cin.ignore();

            switch (pilihan)
            {
            case 1:
            {
                string namaBaru;
                cout << "Masukkan Data Baru : ";
                getline(cin, namaBaru);
                penghuni[i].nama_penghuni = namaBaru;
            }
            break;

            case 2:
            {
                string tanggalMulaiBaru;
                cout << "Masukkan Data Baru : ";
                getline(cin, tanggalMulaiBaru);
                penghuni[i].tanggal_tinggal = tanggalMulaiBaru;
            }

            break;

            case 3:
            {
                string tanggalPindahBaru;
                cout << "Masukkan Data Baru : ";
                getline(cin, tanggalPindahBaru);
                penghuni[i].tanggal_pergi = tanggalPindahBaru;
            }
            break;

            default:
                break;
            }
        }

        saveData();
    }
    if (!ditemukan)
        cout << "Penghuni dengan nama " << nama << " tidak ditemukan." << endl;
}

void deleteData()
{

    string nama;
    cout << "Masukkan nama penghuni yang akan di hapus: ";
    getline(cin, nama);

    bool ditemukan = false;

    for (int i = 0; i < jumlahRecord; i++)
    {
        if (penghuni[i].nama_penghuni == nama)
        {
            ditemukan = true;
            cout << "Apa yakin data " << nama << " ingin dihapus ?" << endl;
            cout << "1. Iya" << endl;
            cout << "2. Batal" << endl;

            int pilihan;
            cout << "Masukkan pilihan (1/2): ";
            cin >> pilihan;
            cin.ignore();

            switch (pilihan)
            {
            case 1:
            {
                for (int data_i = i; data_i < jumlahRecord - 1; data_i++)
                {
                    penghuni[data_i] = penghuni[data_i + 1];
                }

                jumlahRecord--;
                
            }
            break;

            default:
                break;
            }
        }

        saveData();
    }
    if (!ditemukan)
        cout << "Penghuni dengan nama " << nama << " tidak ditemukan." << endl;
}

void recoverData()
{
    cout << "Fitur ini masih dalam pengembangan." << endl;
}

void mainMenu()
{

    int pilihMenu;
    cout << "========DATA PENGHUNI AGARTHA==========" << endl;
    cout << "MENU UTAMA" << endl;
    cout << "1. Tampilkan Semua Penghuni" << endl;
    cout << "2. Tambah Penghuni Baru" << endl;
    cout << "3. Edit Penghuni" << endl;
    cout << "4. Hapus Penghuni" << endl;
    cout << "5. Recoveri Penghuni " << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pilihMenu;
    cin.ignore();

    readFile();

    switch (pilihMenu)
    {
    case 1:
        viewData();
        break;

    case 2:
        addData();
        break;

    case 3:
        editData();
        break;

    case 4:
        deleteData();
        break;

    default:
        break;
    }
}

int main()
{

    readFile();
    mainMenu();
    return 0;
}