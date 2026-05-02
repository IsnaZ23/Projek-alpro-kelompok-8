//Kelompok 8 : 123250011, 123250013, 123250028
#include <iostream>
#include <string>
using namespace std;
int n, i;
bool y = true;

typedef struct{
    int NoKuitansi;
    string Tanggal;
    string NamaToko;
}Kuitansi;
Kuitansi dataKuitansi[100];

// Konfirmasi - Ino
void konfirmasi() {
    char konfirmasi;
    cout << "Apakah anda ingin mengulang ? (y/t) : ";
    cin >> konfirmasi;
    if (konfirmasi == 'Y' || konfirmasi == 'y') {
        system("cls");
    } else {
        cout << "Terima kasih telah menggunakan program ini!\n";
        y = false;
    }
}
// Batas Akhir - Ino

// Input Data + Lihat Data - Isnan
void inputData(){
    system("cls");
    cout<<"INPUT DATA \n "
        <<"================================= \n";
    cout<<"Jumlah data (Maksimal 10) : ";
    cin>>n;

    while (n > 10 || n < 1){
        cout<<"Maaf, kapasitas data hanya 10 ! \n"
            <<"Masukan Jumlah data ulang : ";
        cin>>n;
    }
    
    for ( i = 0; i < n; i++){
        cout<<"Data ke-"<<i+1<<endl;
        cout<<"No Kuitansi \t: ";
        cin>>dataKuitansi[i].NoKuitansi;
        cout<<"Tanggal \t: ";
        cin>>dataKuitansi[i].Tanggal;
        cout<<"Nama Toko \t: ";
        cin.ignore();
        getline(cin,dataKuitansi[i].NamaToko);
    }
    cout<<"===================================== \n";
    konfirmasi();
}

void lihatData(){
cout<<"TAMPIL DATA  \n "
    <<"=================================================== \n";
cout<<"NO. Kuitansi\tTanggal\t\tNama Toko \n"
    <<"==================================================== \n";
if (n == 0){
    cout<<"Data tidak ada !";
}

else{
    for ( i = 0; i < n; i++){
        cout<<dataKuitansi[i].NoKuitansi<<"\t\t"<<dataKuitansi[i].Tanggal<<"\t\t"<<dataKuitansi[i].NamaToko<<endl;
    }
}
cout<<"==================================================== \n";
}
// Batas Akhir - Isnan

// Sorting Data - Ino
// Bubble
void bubbleSort(int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dataKuitansi[j].NoKuitansi > dataKuitansi[j + 1].NoKuitansi) {
                swap(dataKuitansi[j], dataKuitansi[j + 1]);
            }
        }
    }
}

// Selection
void selectionSort(int n) {

    for (int i = 0; i < n - 1; i++) {
        int indexMin = i;
        for (int j = i + 1; j < n; j++) {
            if (dataKuitansi[indexMin].NoKuitansi > dataKuitansi[j].NoKuitansi) {
                indexMin = j;
            }
        }
        swap(dataKuitansi[i], dataKuitansi[indexMin]);
    }
}

// Insert
void insertionSort(int n) {

    for (int i = 1; i < n; i++) {
        Kuitansi kunci = dataKuitansi[i];
        int j = i - 1;
        while (j >= 0 && dataKuitansi[j].NoKuitansi > kunci.NoKuitansi) {
            dataKuitansi[j + 1] = dataKuitansi[j];
            j--;
        }
        dataKuitansi[j + 1] = kunci;
    }
}

// Merge
Kuitansi tempData[100];

void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    
    while (i <= mid && j <= high) {
        if (dataKuitansi[i].NoKuitansi <= dataKuitansi[j].NoKuitansi) {
            tempData[k] = dataKuitansi[i];
            i++;
        } else {
            tempData[k] = dataKuitansi[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid) { tempData[k] = dataKuitansi[i]; i++; k++; }
    while (j <= high) { tempData[k] = dataKuitansi[j]; j++; k++; }
    
    for (k = low; k <= high; k++) {
        dataKuitansi[k] = tempData[k];
    }
}

void mergeSort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid);      // Belah kiri
        mergeSort(mid + 1, high);  // Belah kanan
        merge(low, mid, high);     // Gabungin
    }
}

// Quick
void quickSort(int low, int high) {
    if (low < high) {
        Kuitansi pivot = dataKuitansi[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (dataKuitansi[j].NoKuitansi <= pivot.NoKuitansi) {
                i++;
                swap(dataKuitansi[i], dataKuitansi[j]);
            }
        }
        swap(dataKuitansi[i + 1], dataKuitansi[high]);
        
        int p = i + 1;
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

// Shell
void shellSort(int n) {

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Kuitansi temp = dataKuitansi[i];
            int j;
            for (j = i; j >= gap && dataKuitansi[j - gap].NoKuitansi > temp.NoKuitansi; j -= gap) {
                dataKuitansi[j] = dataKuitansi[j - gap];
            }
            dataKuitansi[j] = temp;
        }
    }
}

void sortingData() {
    if (n == 0) {
        cout << "Data kosong! Silakan input data terlebih dahulu.\n";
        return;
    }

    int alg;
    system("cls");
    cout << "PILIH ALGORITMA SORTING \n"
         << "================================= \n"
         << "1. Bubble Sort\n"
         << "2. Selection Sort\n"
         << "3. Insertion Sort\n"
         << "4. Merge Sort\n"
         << "5. Quick Sort\n"
         << "6. Shell Sort\n"
         << "7. Kembali Ke Menu\n"
         << "================================= \n"
         << "Pilih : ";
    cin >> alg;

    if (alg == 7) {
        return;
    }

    if (alg < 1 || alg > 6) {
        cout << "Pilihan algoritma tidak ada!\n";
        konfirmasi();
        return;
    }

    cout << "\nData sebelum diurutkan:\n";
    lihatData();

    if (alg == 1) bubbleSort(n);
    else if (alg == 2) selectionSort(n);
    else if (alg == 3) insertionSort(n);
    else if (alg == 4) mergeSort(0, n - 1);
    else if (alg == 5) quickSort(0, n - 1);
    else if (alg == 6) shellSort(n);

    cout << "\nData berhasil diurutkan!\n";
    lihatData();
    konfirmasi();
}
// Batas Akhir - Ino

// Cari Data - Reni
void cariDataSequensial(){
    int cari;
    bool found = false;
    int i = 0;

    if (n == 0){
        cout << "Data kosong! Silakan input data terlebih dahulu.\n";
        return;
    }

    cout << "SEQUENSIAL SEARCH \n"
        <<"================================= \n";
    cout << "NoKuitansi yang anda cari (int) : ";
    cin >> cari;
    
    while (!found && i < n)
    {
        if (cari == dataKuitansi[i].NoKuitansi)
        {
           cout << "\nData anda sudah ditemukan ! \n";
           cout << "No Kuitansi \t: " << dataKuitansi[i].NoKuitansi << endl;
           cout << "Tanggal \t: " << dataKuitansi[i].Tanggal << endl;
           cout << "Nama Toko \t: " << dataKuitansi[i].NamaToko << endl << endl;
           found = true;
        }
        else i++;
    
    }
    if (i == n)
    {
        cout << "NoKuitansi yang anda cari: " << cari << endl;
        cout << cari << " tidak ditemukan ! \n\n";
    }

}

void cariDataBinary(){
    int cari;
    bool found = false;
    int i, j, k;
    j = n - 1;
    i = 0;

    cout << "BINARY SEARCH \n"
        <<"================================= \n";
    cout << "NoKuitansi yang anda cari (int) : ";
    cin >> cari;

    bubbleSort(n);
    while ((!found) && (i <= j)){
        k = (i + j) / 2;
        if (cari == dataKuitansi[k].NoKuitansi){
           cout << "\nData anda sudah ditemukan ! \n";
           cout << "No Kuitansi \t: " << dataKuitansi[k].NoKuitansi << endl;
           cout << "Tanggal \t: " << dataKuitansi[k].Tanggal << endl;
           cout << "Nama Toko \t: " << dataKuitansi[k].NamaToko << endl << endl;
           found = true;
        }
        else 
        {
            if (cari < dataKuitansi[i].NoKuitansi)
            j = k - 1;
            else i = k + 1;
        }

    }
    if (!found)
    {
        cout << "NoKuitansi yang anda cari: " << cari << endl;
        cout << cari << " tidak ditemukan ! \n\n";
    }
}

void cariData() {
    int pilihSearching;
    cout<< " MENU SEARCHING : \n ";
    cout<< "================================= \n ";
    cout<< " 1. SEQUENSIAL SEARCH \n " 
        << " 2. BINARY SEARCH \n "
        << " 3. Kembali ke menu utama \n "
        <<"================================= \n ";  
    cout << "Pilih : ";
    cin >> pilihSearching;
    switch (pilihSearching){
        case 1:
        cariDataSequensial();
        break;

        case 2:
        cariDataBinary();
        break;

        case 3:
        break;

        default:
        cout << "maaf pilihan yang anda pilih tidak tersedia ! ";
        break;
    }
    konfirmasi();
}
// Batas Akhir - Reni

int main() {
    int pilih;

    while (y) {
        cout<<"MENU : \n"
        <<"================================= \n";
        cout<<"1. Input Data \n"
        <<"2. Tampil Data \n"
        <<"3. Searching \n" //sequential, binary
        <<"4. Sorting \n" //bubble, selection, insertion, merge, quick, shell
        <<"5. Exit \n"
        <<"================================= \n";
        cout<<"Pilih : ";
        cin>>pilih;
    
        switch (pilih){
        case 1:
        inputData();
        break;
    
        case 2:
        lihatData();
        konfirmasi();
        break;
    
        case 3:
        cariData();
        break;

        case 4:
        sortingData();
        break;

        case 5:
        y = false;
        cout << "Terima kasih telah menggunakan program ini!\n";
        break;

        default:
        cout<<"Maaf, pilihan yang anda pilih tidak tersedia!\n";
        konfirmasi();
        break;
        }
    }
}
