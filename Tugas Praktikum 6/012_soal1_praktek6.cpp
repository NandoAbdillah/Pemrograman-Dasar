#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Penghuni
{
    string nama_penghuni;
    string tanggal_tinggal;
};

bool periksaDuplikasi(int jumlahRecord, Penghuni data[], string nama)
{
    for (int i = 0; i < jumlahRecord; i++)
    {
        if (data[i].nama_penghuni == nama)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int jumlahRecord = 0;
    Penghuni data[100];

//bacs 
    ifstream dataFile("logbook.txt", ios::in);

    if (dataFile.is_open())
    {

        while (!dataFile.eof() && jumlahRecord < 100)
        {
            string nama;
            string tanggal;

            getline(dataFile, nama);
            getline(dataFile, tanggal);

            if (nama != "" && tanggal != "")
            {
                // struct 
                data[jumlahRecord].nama_penghuni = nama;
                data[jumlahRecord].tanggal_tinggal = tanggal;
                jumlahRecord++;
            }
        }
        dataFile.close();
    }

    int n;
    cout << "Masukkan jumlah penghuni yang akan ditambahkan: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {

        string nama;
        string tanggal;

        cout << "Nama Penghuni : ";
        getline(cin, nama);

        cout << "Tanggal Mulai Tinggal (DD-MM-YYYY) : ";
        getline(cin, tanggal);

        if (periksaDuplikasi(jumlahRecord, data, nama))
        {
            cout << nama << " sudah terdaftar pada Log Book masukkan penghuni lainnya " << endl;
            i--;
            continue;
        }
        else
        {

            data[jumlahRecord].nama_penghuni = nama;
            data[jumlahRecord].tanggal_tinggal = tanggal;

            jumlahRecord++;

            cout << nama << " Berhsil dicatat kedalam Log Book " << endl;
        }

        cout << endl;
    }

    ofstream dataOutFile("logbook.txt", ios::out);
    if (dataOutFile.is_open())
    {
        for (int i = 0; i < jumlahRecord; i++)
        {
            dataOutFile << data[i].nama_penghuni << endl;
            dataOutFile << data[i].tanggal_tinggal << endl;
        }
    }
    dataOutFile.close();

    return 0;
}