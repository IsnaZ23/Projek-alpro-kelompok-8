//Kelompok 8 : 123250011, 123250013, 123250028
#include <iostream>
#include <string>
using namespace std;
int n, i;

typedef struct{
    int NoKuitansi;
    string Tanggal;
    string NamaToko;
}Kuitansi;
Kuitansi dataKuitansi[100];

// Isnan
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

// Ino
// Fungsi pembantu untuk membandingkan data berdasarkan kriteria
bool compare(Kuitansi a, Kuitansi b, int kriteria) {
    if (kriteria == 1) return a.NoKuitansi > b.NoKuitansi; // Urutkan No Kuitansi
    if (kriteria == 2) return a.Tanggal > b.Tanggal;       // Urutkan Tanggal
    if (kriteria == 3) return a.NamaToko > b.NamaToko;     // Urutkan Nama Toko
    return false;
}

// Bubble
void bubbleSort(int n, int kriteria) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(dataKuitansi[j], dataKuitansi[j + 1], kriteria)) {
                // Tukar data
                Kuitansi temp = dataKuitansi[j];
                dataKuitansi[j] = dataKuitansi[j + 1];
                dataKuitansi[j + 1] = temp;
            }
        }
    }
}

// Selection
void selectionSort(int n, int kriteria) {
    for (int i = 0; i < n - 1; i++) {
        int indexMin = i;
        for (int j = i + 1; j < n; j++) {
            if (compare(dataKuitansi[indexMin], dataKuitansi[j], kriteria)) {
                indexMin = j;
            }
        }
        // Tukar data terkecil ke posisi i
        Kuitansi temp = dataKuitansi[i];
        dataKuitansi[i] = dataKuitansi[indexMin];
        dataKuitansi[indexMin] = temp;
    }
}

// Insert
void insertionSort(int n, int kriteria) {
    for (int i = 1; i < n; i++) {
        Kuitansi kunci = dataKuitansi[i];
        int j = i - 1;
        // Geser data yang lebih besar ke kanan
        while (j >= 0 && compare(dataKuitansi[j], kunci, kriteria)) {
            dataKuitansi[j + 1] = dataKuitansi[j];
            j--;
        }
        dataKuitansi[j + 1] = kunci;
    }
}

// Merge
Kuitansi tempData[100]; // Array bantuan sementara

void merge(int low, int mid, int high, int kriteria) {
    int i = low, j = mid + 1, k = low;
    
    // Bandingkan dan masukkan ke array bantuan
    while (i <= mid && j <= high) {
        if (!compare(dataKuitansi[i], dataKuitansi[j], kriteria)) {
            tempData[k] = dataKuitansi[i];
            i++;
        } else {
            tempData[k] = dataKuitansi[j];
            j++;
        }
        k++;
    }
    
    // Masukkan sisa data jika ada
    while (i <= mid) { tempData[k] = dataKuitansi[i]; i++; k++; }
    while (j <= high) { tempData[k] = dataKuitansi[j]; j++; k++; }
    
    // Salin kembali ke array utama
    for (k = low; k <= high; k++) {
        dataKuitansi[k] = tempData[k];
    }
}

void mergeSort(int low, int high, int kriteria) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(low, mid, kriteria);      // Belah kiri
        mergeSort(mid + 1, high, kriteria);  // Belah kanan
        merge(low, mid, high, kriteria);     // Gabungkan
    }
}

// Quick
void quickSort(int low, int high, int kriteria) {
    if (low < high) {
        Kuitansi pivot = dataKuitansi[high]; // Ambil pivot dari elemen terakhir
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (!compare(dataKuitansi[j], pivot, kriteria)) {
                i++;
                Kuitansi temp = dataKuitansi[i];
                dataKuitansi[i] = dataKuitansi[j];
                dataKuitansi[j] = temp;
            }
        }
        // Tukar pivot ke posisi yang benar
        Kuitansi temp = dataKuitansi[i + 1];
        dataKuitansi[i + 1] = dataKuitansi[high];
        dataKuitansi[high] = temp;
        
        int p = i + 1;
        quickSort(low, p - 1, kriteria);  // Urutkan kiri pivot
        quickSort(p + 1, high, kriteria); // Urutkan kanan pivot
    }
}

// Shell
void shellSort(int n, int kriteria) {
    // Kurangi jarak (gap) secara bertahap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Kuitansi temp = dataKuitansi[i];
            int j;
            for (j = i; j >= gap && compare(dataKuitansi[j - gap], temp, kriteria); j -= gap) {
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

    int alg, kriteria;
    system("cls");
    cout << "PILIH ALGORITMA SORTING \n"
         << "================================= \n"
         << "1. Bubble Sort\n"
         << "2. Selection Sort\n"
         << "3. Insertion Sort\n"
         << "4. Merge Sort\n"
         << "5. Quick Sort\n"
         << "6. Shell Sort\n"
         << "================================= \n"
         << "Pilih : ";
    cin >> alg;

    system("cls");
    cout << "URUTKAN BERDASARKAN \n"
         << "================================= \n"
         << "1. No. Kuitansi\n"
         << "2. Tanggal\n"
         << "3. Nama Toko\n"
         << "================================= \n"
         << "Pilih : ";
    cin >> kriteria;

    cout << "\nData sebelum diurutkan:\n";
    lihatData();

    if (alg == 1) bubbleSort(n, kriteria);
    else if (alg == 2) selectionSort(n, kriteria);
    else if (alg == 3) insertionSort(n, kriteria);
    else if (alg == 4) mergeSort(0, n - 1, kriteria);
    else if (alg == 5) quickSort(0, n - 1, kriteria);
    else if (alg == 6) shellSort(n, kriteria);
    else {
        cout << "Pilihan algoritma tidak ada!\n";
        return;
    }
    cout << "\nData berhasil diurutkan!\n";
    lihatData();
}

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
    cout << "NoKuitansi yang anda cari : ";
    cin >> cari;
    
    // n = sizeof(dataKuitansi) / sizeof(dataKuitansi[0]);
    while (!found && i < n)
    {
        if (cari == dataKuitansi[i].NoKuitansi)
        {
           cout << "Data anda sudah ditemukan ! \n";
           cout << "No Kuitansi \t: " << dataKuitansi[i].NoKuitansi << endl;
           cout << "Tanggal \t: " << dataKuitansi[i].Tanggal << endl;
           cout << "Nama Toko \t: " << dataKuitansi[i].NamaToko << endl;
           found = true;
        }
        else i++;
    
    }
    if (i == n)
    {
        cout << "NoKuitansi yang anda cari: " << cari << endl;
        cout << cari << " tidak ditemukan ! \n";
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
    cout << "NoKuitansi yang anda cari : ";
    cin >> cari;

    bubbleSort(n, 1);
    while ((!found) && (i <= j)){
        k = (i + j) / 2;
        if (cari == dataKuitansi[k].NoKuitansi){
            cout << "Data anda sudah ditemukan ! \n";
           cout << "No Kuitansi \t: " << dataKuitansi[k].NoKuitansi << endl;
           cout << "Tanggal \t: " << dataKuitansi[k].Tanggal << endl;
           cout << "Nama Toko \t: " << dataKuitansi[k].NamaToko << endl;
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
        cout << cari << " tidak ditemukan ! \n";
    }
}

int main() {
    int pilih;
    char y;
    int pilihSearching;
    bool kembaliMenuUtama = true;

    do{
    cout<<"MENU : \n"
        <<"================================= \n";
    cout<<"1. Input Data \n"
        <<"2. Tampil Data \n"
        <<"3. Searching \n" //sequential, binary
        <<"4. Sorting \n"
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
    break;
    
    case 3:
        cout<< " MENU SEARCHING : \n ";
        cout<< "================================= \n ";
        cout<< " 1. SEQUENSIAL SEARCH \n " 
            << " 2. BINARY SEARCH \n "
            << " 3. kembali ke menu utama \n "
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
            cout << "maaf pilihan yang anda pilih tidak tersedia ! ";}
            break;

    case 4:
    sortingData();
    break;

    case 5:
    kembaliMenuUtama = false;
    break;

    default:
    cout<<"Maaf tidak ada pilihan yang sesuai anda pilih !";
    break;
    }

    if (kembaliMenuUtama == true)  {
        cout<<"Apakah anda ingin mengulang ? (y/t) : ";
        cin>>y;

        if(y != 'y' && y != 'Y') {
            cout << "Terima kasih !";
            kembaliMenuUtama = false;
        }
    }

    } while (kembaliMenuUtama == true);
    cout << "Terima kasih !";
    
}