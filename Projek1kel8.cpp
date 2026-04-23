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

int main() {
    int pilih;
    char y;

    do{
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
    break;
    
    case 3:
    cout << "Maaf pilihan anda tidak ada !";
    break;


    default:
    cout<<"Maaf tidak ada pilihan yang sesuai anda pilih !";
    break;
    }

    cout<<"Apakah anda ingin mengulang ? (y/t) : ";
    cin>>y;
    } while (y == 'Y' || y == 'y');
    


}