#include <iostream>
#include <stdlib.h> 
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

typedef struct {
    string noKuitansi;
    string tanggal;
    string namaToko;
} Kuitansi;

char namafile[50];
Kuitansi kuin[20];

int loadData(string nf) {
    ifstream fileBaca(nf);
    int jumlahData = 0;
    if(fileBaca.is_open()){
        string baris;
        while (getline(fileBaca, baris) && jumlahData < 20) {
            if (baris.find("Data ke-") != string::npos) {
                getline(fileBaca, baris);
                kuin[jumlahData].noKuitansi = baris.substr(baris.find(":") + 2);
                getline(fileBaca, baris);
                kuin[jumlahData].tanggal = baris.substr(baris.find(":") + 2);
                getline(fileBaca, baris);
                kuin[jumlahData].namaToko = baris.substr(baris.find(":") + 2);
                jumlahData++;
            }
        }
        fileBaca.close();
    }
    return jumlahData;
}

void simpanUlang(string namaFile, int n){
    ofstream fileTulis(namaFile);
    if (fileTulis.is_open()){
        for (int i = 0; i < n; i++){
            fileTulis << "Data ke-" << i + 1 << endl;
            fileTulis << " No Kuitansi : " << kuin[i].noKuitansi << endl;
            fileTulis << " Tanggal    : " << kuin[i].tanggal << endl;
            fileTulis << " Nama Toko : " << kuin[i].namaToko << endl << endl;
        }
        fileTulis.close();
        cout << "Data berhasil disimpan ke " << namaFile << "!\n";
    } else {
        cout << "Gagal membuka atau membuat file!\n";

        }
    }


void shellSort(int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Kuitansi temp = kuin[i];
            int j;
            for (j = i; j >= gap && kuin[j - gap].noKuitansi > temp.noKuitansi; j -= gap) {
                kuin[j] = kuin[j - gap];
            }
            kuin[j] = temp;
        }
    }
}

void menu(){
    cout<<"\nMenu : \n";
    cout<< setfill('=')<<setw(40)<<"="<<endl;
    cout << setfill(' ');
    cout<<"1. Input  data \n"
        <<"2. Tampil data \n"
        <<"3. Searching \n"
        <<"4. Sorting \n"
        <<"5. Operasi file \n"
        <<"6. Exit \n";
    cout<< setfill('=')<<setw(40)<<"="<<endl;
    cout << setfill(' ');
    cout<<"Pilih : ";
}

void inputData(){
    int n;
    cout<<"\nDaftar File : \n";
    cout<<"==================================\n";
    int statusFolder = system("cmd /c dir /b *.txt 2>nul");
    if (statusFolder != 0){
        cout<<"Belum ada file yang tersimpan ! \n";
    }
    cout<<"==================================\n";

    cout<<"\nINPUT DATA\n"; 
    cout<<"==================================\n";
    cout<<"Jumlah data (max 10): "; 
    cin>>n; 
    cout<<"Disimpan di file : "; 
    cin>>namafile;
    
    ofstream fileTulis(namafile, ios::app);
    if(fileTulis.is_open()){
        for (int i = 0; i < n; i++){
            cout<<"Data ke-"<<i + 1<<endl;
            cout<<"No Kuitansi : ";
            getline(cin>>ws , kuin[i].noKuitansi);
            cout<<"Tanggal     : ";
            getline(cin>>ws , kuin[i].tanggal);
            cout<<"Nama Toko   : ";
            getline(cin>>ws , kuin[i].namaToko);
            fileTulis << "Data ke-" << i+1 << endl;
            fileTulis << "  No Kuitansi : " << kuin[i].noKuitansi << endl;
            fileTulis << "  Tanggal     : " << kuin[i].tanggal << endl;
            fileTulis << "  Nama Toko   : " << kuin[i].namaToko << endl << endl; 
        }
        fileTulis.close();
        cout << "\nData berhasil disimpan ke " << namafile << "!\n";
    } else {
        cout << "Gagal membuka atau membuat file!\n";
    }
}

void tampilData(){
    string namafileDiliat;
    cout<<"\nTAMPIL DATA: \n";
    cout<<"==================================\n";
    cout<<"Daftar File : \n"
        <<"==================================\n";
    int statusFolder = system("cmd /c dir /b *.txt 2>nul");
    if (statusFolder != 0){
        cout<<"Belum ada file yang tersimpan ! \n";
    }
    cout<<"==================================\n";

    cout<<endl;
    cout<<"Nama file yang akan ditampilkan : ";
    getline(cin>>ws, namafileDiliat);
    int jumlahData = loadData(namafileDiliat);

    if (jumlahData > 0){
        cout << "\n======================================================\n";
        cout << left << setw(18) << "NO KUITANSI" 
             << left << setw(15) << "TANGGAL" 
             << left << setw(2)  <<"NAMA TOKO" << endl;
        cout << "======================================================\n";
        
        for (int i = 0; i < jumlahData; i++) {
            cout << left << setw(18) << kuin[i].noKuitansi
                 << left << setw(15) << kuin[i].tanggal
                 << left << setw(2)  << kuin[i].namaToko << endl;
        }
        cout << "======================================================\n";
    }else{
        cout << "Gagal! File tidak ditemukan atau kosong.\n";
    }
}

void Searching(){
    string namafileDicari;
    int pilihDicari;
    cout<<"\nMENU SEARCHING: \n";
    cout<<"==================================\n"
        <<"1. SEQUENTIAL SEARCHING \n"
        <<"2. BINARY SEARCHING \n"
        <<"3. Kembali ke menu utama \n";
    cout<<"==================================\n"
        <<"Pilih : ";
    cin>>pilihDicari;
    if (pilihDicari == 3){
        return;
    }
    

    cout<<"Daftar File : \n"
        <<"==================================\n";
           system("cmd /c dir /b *.txt 2>nul");
    cout<<"==================================\n";

    cout<<"Data yang akan dicari dari file : ";
    getline(cin >> ws, namafileDicari);
    int n = loadData(namafileDicari);
    if (n == 0){
        cout << "File tidak ketemu!\n";
        return;
    }
    string target;
    switch (pilihDicari){
            case 1:{
            cout<<"\nSEQUENTIAL SEARCHING \n";
            cout<<"==================================\n";
            cout<<"Masukkan No Kuitansi: "; 
            getline(cin >> ws, target);
                {
                bool ketemu = false;
                int i = 0;
                while (i < n && !ketemu){
                    if (kuin[i].noKuitansi == target){
                        ketemu = true;
                    }else{
                        i++;
                    }
                }
                if (ketemu){
                    cout<<"Data ditemukan \n";
                    cout<<"==================================\n";
                        cout<<"No Kuitansi  : "<<kuin[i].noKuitansi<<endl;
                        cout<<"Tanggal      : "<<kuin[i].tanggal<<endl;
                        cout<<"Nama Toko    : "<<kuin[i].namaToko<<endl;
                    cout<<"==================================\n";
                }else{
                    cout<<"Data tidak ditemukan ! \n";
                }
            }

            break;
        }
            case 2:{
                cout << "\nBINARY SEARCHING \n";
                cout << "==================================\n";
                shellSort(n);
                cout<<"Masukkan No Kuitansi: "; 
                getline(cin >> ws, target);

                int awal = 0;
                int akhir = n - 1;
                int tengah;
                bool ketemu = false;

                while (awal <= akhir && !ketemu) {
                    tengah = (awal + akhir) / 2;
                    if (kuin[tengah].noKuitansi == target) {
                        ketemu = true;
                    } else if (kuin[tengah].noKuitansi < target) {
                        awal = tengah + 1;
                    } else {
                        akhir = tengah - 1;
                    }
                }
                if (ketemu) {
                    cout << "Data ditemukan \n";
                    cout << "==================================\n";
                    cout << "No Kuitansi : " << kuin[tengah].noKuitansi << endl;
                    cout << "Tanggal     : " << kuin[tengah].tanggal << endl;
                    cout << "Nama Toko   : " << kuin[tengah].namaToko << endl;
                    cout << "==================================\n";
                } else {
                    cout << "Data tidak ditemukan! \n";
                }
            break;
        }

            default:
                cout << "Pilihan tidak valid!\n";
            break;
    }

}

void operasiFile(){
    string namafileOperasi;
    int pilihUpdate;

    cout << "\nOPERASI FILE\n";
    cout << "==================================\n"
        << "1. Update Data (ubah isi data) \n"
        << "2. Ingin kembali ke menu utama ? (y/t) \n"
        << "==================================\n"
        << "Pilih (1-2) : ";
    cin >> pilihUpdate;

    if (pilihUpdate == 2) return;
    if (pilihUpdate != 1) {
        cout << "Pilihan yang anda masukkan tidak valid!\n";
        return;
    }

    cout << "\nDaftar File : \n"
        << "==================================\n";
    int statusFolder = system("cmd /c dir /b *.txt 2>nul");
    cout << "==================================\n";
    cout << "Nama file yang akan di update : ";
    getline(cin >> ws, namafileOperasi);

    int n = loadData(namafileOperasi);
    if (n == 0) {
        cout << "File yang anda cari tidak ditemukan atau kosong!\n";
        return;
    }

    //Tampilan data sebelum di update
    cout << "\nData sebelum di update :\n";
    cout << "==========================================================\n";
    cout << left << setw(5) << "NO"
        << left << setw(18) << "NO KUITANSI"
        << left << setw(15) << "TANGGAL"
        << left << setw(2) << "NAMA TOKO" << endl;
    cout << "===========================================================\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << i + 1
            << left << setw(18) << kuin[i].noKuitansi
            << left << setw(15) << kuin[i].tanggal
            << left << setw(2) << kuin[i].namaToko << endl;
    }
    cout << "===========================================================\n";

    string targetUpdate;
    cout << "\nMasukkan No Kuitansi yang ingin di update : ";
    getline(cin >> ws, targetUpdate);

    int indexDitemukan = -1;
    for (int i = 0; i < n; i++) {
        if (kuin[i].noKuitansi == targetUpdate) {
            indexDitemukan = i;
            break;

        }
    }

    if (indexDitemukan == -1) {
        cout << "Data dengan No Kuitansi \" " << targetUpdate << " \" tidak ditemukan!\n";
        return;
    }

    cout << "\nData yang akan di update : \n";
    cout << "==========================================================\n";
    cout << "No Kuitansi : " << kuin[indexDitemukan].noKuitansi << endl;
    cout << "Tanggal    : " << kuin[indexDitemukan].tanggal << endl;
    cout << "Nama Toko : " << kuin[indexDitemukan].namaToko << endl;
    cout << "==========================================================\n";

    int pilihanfield;
    cout << "\npilih field yang ingin di update : \n"
        << "==================================\n"
        << "1. No Kuitansi \n"
        << "2. Tanggal\n"
        << "3. Nama Toko\n"
        << "4. Ubah semua field\n"
        << "==================================\n"
        << "pilih (1-4) : ";
    cin >> pilihanfield;

    switch (pilihanfield) {
        case 1:{
            string baru;
            cout << "Masukkan No Kuitansi baru : ";
            getline(cin >> ws, baru);
            kuin[indexDitemukan].noKuitansi = baru;
            break;
        }
        case 2:{
            string baru;
            cout << "Masukkan tanggal baru : ";
            getline(cin >> ws, baru);
            kuin[indexDitemukan].tanggal = baru;
            break;
        }
        case 3: {
            string baru;
            cout << "Masukkan nama toko baru :";
            getline(cin >> ws, baru);
            kuin[indexDitemukan].namaToko = baru;
            break;
        }
        case 4: {
            cout << "Masukkan no kuitansi baru : ";
            getline(cin >> ws, kuin[indexDitemukan].noKuitansi);
            cout << "Masukkan tanggal baru :";
            getline(cin >> ws, kuin[indexDitemukan].tanggal);
            cout << "Masukkan nama toko baru :";
            getline(cin >> ws, kuin[indexDitemukan].namaToko);
            break;
        }
        default:
            cout << "Pilihan yang anda masukkan tidak valid!\n";
            return;

        }

        simpanUlang(namafileOperasi, n);

        cout << "\nData berhadil di Update!\n";
        cout << "==========================================================\n";
        cout << "No Kuintansi : " << kuin[indexDitemukan].noKuitansi << endl;
        cout << "Tanggal    : " << kuin[indexDitemukan].tanggal << endl;
        cout << "Nama Toko : " << kuin[indexDitemukan].namaToko << endl;
        cout << "==========================================================\n";

    }


int main() {
    int pilih;
    char ulang;
    
do {
        menu();
        cin >> pilih;
        
        switch (pilih){
            case 1:
                inputData();
            break;
            
            case 2:
                tampilData();
            break;

            case 3:
                Searching();
            break;
            case 4:
                //sortingData; //Miawwww
            break;
            case 5:
                operasiFile(); 
                break;
            case 6:
                cout << "Keluar dari program...\n"
                     << "Terimakasih ! \n";
                return 0; 
            break;

            default:
                cout << "Pilihan tidak valid!\n";
            break;
        }
        
cout << "\nKembali ke menu utama? (y/t) : ";
cin >> ulang;
} while (ulang == 'y' || ulang == 'Y');

    return 0;
}
