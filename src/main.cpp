#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

/* INISIALISAI VARIABEL */
char Op[] = {'*','+','/','-'}; int inputCount; string stringNum; string NumString[4]; double Num[4]; double ArrNum[24][4]; string txt; ifstream file; string str; string txtOut; ofstream fileOutput;

double OpFunc (char op, double a, double b) { 
/* Fungsi empat operator aritmatika aritmatika */
  if (op == '+') return (double)a+b;
  else if (op == '-') return (double)a-b;
  else if (op == '/') { if (b != 0) return (double)a/b;}
  else if (op == '*') return (double)a*b;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); // Mempercepat IO
  bool valid = false;
  int no = 0; int n = 0; int solusiCounter = 0; int Hasil = 24; double EPS = 0.0000000001; bool IsExist; string pilihanMode; string pilihanSave; int printError=0;
  str = "";

  /* ASCII ART sebagai kode start program */
  cout << "\033[1;31m"
  << R"(
        222222222222222        444444444  
      2:::::::::::::::22     4::::::::4  
      2::::::222222:::::2   4:::::::::4  
      2222222     2:::::2  4::::44::::4  
                  2:::::2 4::::4 4::::4  
                  2:::::24::::4  4::::4  
              2222::::24::::4   4::::4  
          22222::::::224::::444444::::444
        22::::::::222  4::::::::::::::::4
      2:::::22222     4444444444:::::444
      2:::::2                    4::::4  
      2:::::2                    4::::4  
      2:::::2       222222       4::::4  
      2::::::2222222:::::2     44::::::44
      2::::::::::::::::::2     4::::::::4
      22222222222222222222     4444444444
  )";
  cout << "\033[0m";
  cout << "\033[1;32m"
              << "G    A   M    E    S    O    L    V    E    R\n"
              << "\033[0m"
              << endl;

  /* Kode untuk memilih jenis masukan */
  while(!valid){
    cout << "================================================" << endl;
    cout<<"Masukkan pilihan masukan:"<<endl;
    cout<<"1. Masukan via CLI"<<endl;
    cout<<"2. Masukan via file (*.txt)"<<endl;
    cout<<"3. Masukan random dari sistem"<<endl;
    valid=true;
    cin >> pilihanMode;
    cin.ignore();
    if(pilihanMode != "1" && pilihanMode != "2" && pilihanMode != "3"){
    valid = false;
    if(printError == 0){
        cout << "Input tidak valid. Silahkan coba kembali."<<endl;
        printError++;
    }
    }
    printError=0;
  }
  valid=false;
  cout << "================================================" << endl;
  switch(pilihanMode[0]){
    case '1':
    while(!valid){
        valid = true;
        inputCount = 0;
        printError=0;
        cout<<"Silahkan masukkan nilai yang akan diproses: "<<endl;
        getline(cin, stringNum);
        stringstream ssin(stringNum);
        while(ssin.good()){
            string temp;
            ssin >> temp;
            if (inputCount > 3) {
                valid = false;
                cout << "Input tidak valid. Silahkan masukkan 4 karakter saja!"<<endl;
                cout << "================================================" << endl;
                break;
            }
            NumString[inputCount] = temp;
            inputCount++;
        }
        if(valid){
            for(int i = 0 ; i < 4 ; i ++){
                if(NumString[i] == "2" || NumString[i] == "3" || NumString[i] == "4" || NumString[i] == "5" || NumString[i] == "6" || NumString[i] == "7" || NumString[i] == "8" || NumString[i] == "9" || NumString[i] == "A" || NumString[i] == "J" || NumString[i] == "Q" || NumString[i] == "K" || NumString[i] == "10"){
                    switch(NumString[i][0]){
                    case 'A':
                        Num[i] = 1;
                        break;
                    case 'J':
                        Num[i] = 11;
                        break;
                    case 'Q':
                        Num[i] = 12;
                        break;
                    case 'K':
                        Num[i] = 13;
                        break;
                    default:
                        if(NumString[i] == "10"){
                        Num[i] = 10;
                        }else{
                        Num[i] = double(NumString[i][0]) - 48;
                        }
                        break;
                    }
                } else{
                    valid = false;
                    if(printError == 0){
                        cout << "Input tidak valid. Silahkan masukkan karakter yang valid (A, 2-10, J, Q, K)!"<<endl;
                        cout << "================================================" << endl;
                        printError++;
                    }
                    for(int j = 0 ; j < i+1 ; j ++){
                    NumString[j] = "";
                    Num[j] = 0;
                    }
                }
            }
        }
      }
      cout << "================================================" << endl;
      printError=0;
      break;
    case '2':
      while(!valid){
        valid = true;
        inputCount = 0;
        printError = 0;
        cout<<"Silahkan masukkan nama file yang akan diproses: "<<endl;
        cin >> txt;
        file.open("../test/input/" + txt + ".txt");
        if(file.is_open()){
            while(getline(file, stringNum)){
                stringstream ssin(stringNum);
                while(ssin.good()){
                    string temp;
                    ssin >> temp;
                    if (inputCount > 3) {
                        valid = false;
                        cout << "Input tidak valid. Silahkan masukkan 4 karakter saja!"<<endl;
                        cout << "================================================" << endl;
                        break;
                    }
                    NumString[inputCount] = temp;
                    inputCount++;
                }
            }
        }
        else{
            valid = false;
            cout << "File tidak ditemukan. Silahkan coba kembali."<<endl;
            cout << "================================================" << endl;
        }
        if(valid){
            for(int i = 0 ; i < 4 ; i++){
                if(NumString[i] == "2" || NumString[i] == "3" || NumString[i] == "4" || NumString[i] == "5" || NumString[i] == "6" || NumString[i] == "7" || NumString[i] == "8" || NumString[i] == "9" || NumString[i] == "A" || NumString[i] == "J" || NumString[i] == "Q" || NumString[i] == "K" || NumString[i] == "10"){
                    switch(NumString[i][0]){
                    case 'A':
                        Num[i] = 1;
                        break;
                    case 'J':
                        Num[i] = 11;
                        break;
                    case 'Q':
                        Num[i] = 12;
                        break;
                    case 'K':
                        Num[i] = 13;
                        break;
                    default:
                        if(NumString[i] == "10"){
                        Num[i] = 10;
                        }else{
                        Num[i] = double(NumString[i][0]) - 48;
                        }
                        break;
                    }
                }
                else{
                    valid = false;
                    if(printError == 0){
                        cout << "Input tidak valid. Silahkan masukkan nama file yang berisi karakter valid (A, 2-10, J, Q, K)!"<<endl;
                        cout << "================================================" << endl;
                        printError++;
                    }
                    for(int j = 0; j < i+1; j ++){
                        NumString[j]="";
                        Num[j]=0;
                    }
                }
            }
        }
        file.close();
      }
      cout << "================================================" << endl;
      printError=0;
      break;
    case '3':
      srand(time(0));
      for(int i = 0; i < 4 ; i++){
        int x = rand() % 13 + 1;
        Num[i] = x;
        switch(x){
          case 1:
            NumString[i] = 'A';
            break;
          case 11:
            NumString[i] = 'J';
            break;
          case 12:
            NumString[i] = 'Q';
            break;
          case 13:
            NumString[i] = 'K';
            break;
          default:
            string conv = to_string(Num[i]);
            NumString[i] = conv[0];
            break;
        }
      }
      cout << "Bilangan hasil random dari sistem: " << endl;
      cout << NumString[0] << " " << NumString[1] << " " << NumString[2] << " " << NumString[3] << endl;
  }

  /* Kode untuk mengecek solusi yang ada */
  for (int a = 0 ; a < 4 ; a++){
    for(int b = 0 ; b <4 ; b++) {
      if (b != a){
        for (int c = 0 ; c < 4 ; c++) {
          if ((c != a) && (c != b)) {
            for (int d = 0 ; d < 4 ; d++) {
              if ((d !=a ) && (d != b) && ( d!= c)){
                ArrNum[n][0] = Num[a]; ArrNum[n][1] = Num[b];
                ArrNum[n][2] = Num[c]; ArrNum[n][3] = Num[d]; IsExist = false;
                for (int f = 0 ; f < n ; f++) {
                  for (int g = 0 ; g < 4 ; g++) {
                    if (g < 3) {
                      if (ArrNum[f][g] != ArrNum[n][g]) break;
                    } else {
                      if (ArrNum[f][g] == ArrNum[n][g]) IsExist = true;
                    }
                  }
                  if (IsExist == true) break;
                }

                if (IsExist == false ) {
                  n++;
                  for (int i = 0 ; i < 4 ; i++) { // Operator pertama
                    for (int j = 0 ; j < 4 ; j++) { // Operator kedua
                      for (int k = 0; k < 4 ; k++) { // Operator ketiga
                      /* Fungsi untuk mengatasi semua kemungkinan bracket (5 kemungkinan) */
                        if (fabs(OpFunc(Op[k], (OpFunc(Op[j], (OpFunc(Op[i],Num[a], Num[b])), Num[c])), Num[d]) -Hasil) <= EPS) { // ((n0 op0 n1) op1 n2) op2 d3
                          solusiCounter++; 
                        }
                        if (fabs(OpFunc(Op[k], (OpFunc( Op[i], Num[a], (OpFunc(Op[j],Num[b], Num[c])) ) ) , Num[d])- Hasil) <= EPS) { // (n0 op0 (n1 op1 n2)) op2 d3
                          solusiCounter++; 
                        }
                        if (fabs(OpFunc(Op[j],OpFunc(Op[i], Num[a], Num[b]), OpFunc(Op[k], Num[c], Num[d])) - Hasil ) <= EPS) { // (n0 op0 n1) op1 (n2 op2 n3)
                          solusiCounter++; 
                        }
                        if (fabs(OpFunc(Op[i],Num[a],OpFunc(Op[k],OpFunc(Op[j],Num[b],Num[c]), Num[d])) - Hasil) <= EPS) { // n0 op0 ((n1 op1 n2) op2 n3)
                          solusiCounter++; 
                        }
                        if (fabs(OpFunc(Op[i],Num[a],OpFunc(Op[j],Num[b],OpFunc(Op[k], Num[c],Num[d]))) - Hasil) <= EPS) { // n0 op0 (n1 op1 (n2 op2 n3))
                          solusiCounter++; 
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if(solusiCounter == 0){
    cout << "Tidak ada solusi" << endl;
    str += "Tidak ada solusi\n";
  } else {
    cout << "Terdapat " << solusiCounter << " solusi" <<endl;
    str += "Terdapat ";
    str += to_string(solusiCounter);
    str += " solusi\n";
  }

  clock_t Mulai = clock(); //Waktu Dimulai
  n=0;
  for (int a = 0 ; a < 4 ; a++){
    for(int b = 0 ; b <4 ; b++) {
      if (b != a){
        for (int c = 0 ; c < 4 ; c++) {
          if ((c != a) && (c != b)) {
            for (int d = 0 ; d < 4 ; d++) {
              if ((d !=a ) && (d != b) && ( d!= c)){
                ArrNum[n][0] = Num[a]; ArrNum[n][1] = Num[b];
                ArrNum[n][2] = Num[c]; ArrNum[n][3] = Num[d]; IsExist = false;
                for (int f = 0 ; f < n ; f++) {
                  for (int g = 0 ; g < 4 ; g++) {
                    if (g < 3) {
                      if (ArrNum[f][g] != ArrNum[n][g]) break;
                    } else {
                      if (ArrNum[f][g] == ArrNum[n][g]) IsExist = true;
                    }
                  }
                  if (IsExist == true) break;
                }

                if (IsExist == false ) {
                  n++;
                  for (int i = 0 ; i < 4 ; i++) { // Operator pertama
                    for (int j = 0 ; j < 4 ; j++) { // Operator kedua
                      for (int k = 0; k < 4 ; k++) { // Operator ketiga
                      /* Fungsi untuk mengatasi semua kemungkinan bracket (5 kemungkinan) */
                        if (fabs(OpFunc(Op[k], (OpFunc(Op[j], (OpFunc(Op[i],Num[a], Num[b])), Num[c])), Num[d]) -Hasil) <= EPS) { // ((n0 op0 n1) op1 n2) op2 d3
                          no++; cout<< "\033[1;36m"; cout << no << " "<< "((" << Num[a] << Op[i] <<  Num[b] << ")" << Op[j]  << Num[c] << ")" << Op[k] << Num[d] << endl; cout << "\033[0m";
                          str += to_string(no); str += " "; str += "(("; str += to_string(int(Num[a])); str += Op[i]; str += to_string(int(Num[b])); str += ")"; str += Op[j]; str += to_string(int(Num[c])); str += ")"; str += Op[k]; str += to_string(int(Num[d])); str += "\n";
                        }
                        if (fabs(OpFunc(Op[k], (OpFunc( Op[i], Num[a], (OpFunc(Op[j],Num[b], Num[c])) ) ) , Num[d])- Hasil) <= EPS) { // (n0 op0 (n1 op1 n2)) op2 d3
                          no++; cout << "\033[1;33m"; cout << no << " "<< "(" << Num[a] << Op[i] << "("  << Num[b]  << Op[j]  << Num[c] << "))" << Op[k] << Num[d] << endl; cout << "\033[0m";
                          str += to_string(no); str += " "; str += "("; str += to_string(int(Num[a])); str += Op[i]; str += "("; str += to_string(int(Num[b])); str += Op[j]; str += to_string(int(Num[c])); str += "))"; str += Op[k]; str += to_string(int(Num[d])); str += "\n";
                        }
                        if (fabs(OpFunc(Op[j],OpFunc(Op[i], Num[a], Num[b]), OpFunc(Op[k], Num[c], Num[d])) - Hasil ) <= EPS) { // (n0 op0 n1) op1 (n2 op2 n3)
                          no++; cout << "\033[1;32m"; cout << no << " "<< "(" << Num[a] << Op[i] << Num[b] << ")" << Op[j] << "(" << Num[c] << Op[k] << Num[d] << ")" << endl; cout << "\033[0m";
                          str += to_string(no); str += " "; str += "("; str += to_string(int(Num[a])); str += Op[i]; str += to_string(int(Num[b])); str += ")"; str += Op[j]; str += "("; str += to_string(int(Num[c])); str += Op[k]; str += to_string(int(Num[d])); str += ")"; str += "\n";
                        }
                        if (fabs(OpFunc(Op[i],Num[a],OpFunc(Op[k],OpFunc(Op[j],Num[b],Num[c]), Num[d])) - Hasil) <= EPS) { // n0 op0 ((n1 op1 n2) op2 n3)
                          no++; cout << "\033[1;34m"; cout << no <<" " << Num[a] << Op[i] << "(("  << Num[b]  << Op[j]  << Num[c] << ")" << Op[k] << Num[d] << ")" << endl; cout << "\033[0m";
                          str += to_string(no); str += " "; str += to_string(int(Num[a])); str += Op[i]; str += "(("; str += to_string(int(Num[b])); str += Op[j]; str += to_string(int(Num[c])); str += ")"; str += Op[k]; str += to_string(int(Num[d])); str += ")"; str += "\n";
                        }
                        if (fabs(OpFunc(Op[i],Num[a],OpFunc(Op[j],Num[b],OpFunc(Op[k], Num[c],Num[d]))) - Hasil) <= EPS) { // n0 op0 (n1 op1 (n2 op2 n3))
                          no++; cout << "\033[1;35m"; cout << no << " " << Num[a] << Op[i] << "("  << Num[b] << Op[j] << "(" <<  Num[c] << Op[k] << Num[d] << "))" << endl; cout << "\033[0m";
                          str += to_string(no); str += " "; str += to_string(int(Num[a])); str += Op[i]; str += "("; str += to_string(int(Num[b])); str += Op[j]; str += "("; str += to_string(int(Num[c])); str += Op[k]; str += to_string(int(Num[d])); str += "))"; str += "\n";
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  /* Kode untuk menghitung waktu eksekusi */
  cout << "\033[0m";
  cout << "Waktu Eksekusi\t: " << (double)(clock() - Mulai)/CLOCKS_PER_SEC << "s\n";
  str += "Waktu Eksekusi\t: ";
  str += to_string(double(clock()-Mulai)/CLOCKS_PER_SEC);
  str += "s";
  str += "\n";

  /* Kode untuk menampilkan kartu masukan */
  str += "Kartu Masukan\t: ";
  for(int i = 0 ; i < 4 ; i++){
    str += NumString[i];
    str += " ";
  }
  str += "\n";

  /* Kode untuk menyimpan hasil */
  valid = false;
  while(!valid){
    cout << "================================================" << endl;
    cout << "Apakah hasil ingin disimpan? (y/n): " << endl;
    cin >> pilihanSave;
    valid = true;
    if(pilihanSave != "y" && pilihanSave != "n"){
      valid = false;
      if(printError==0){
        cout << "Input tidak valid. Silahkan coba kembali." << endl;
        printError++;
      }
    }
    printError = 0;
  }
  cout << "================================================" << endl;
  switch(pilihanSave[0]){
    case 'y':
      cout << "Masukkan nama file untuk keluaran:" << endl;
      cin >> txtOut;
      cout << "================================================" << endl;
      fileOutput.open("../test/output/" + txtOut +".txt",std::ios::out);
      if(fileOutput.is_open()){
        fileOutput << str << endl;
        cout << "File output berhasil disimpan" << endl;
        cout << "================================================" << endl;
      }
      else{
        cout << "Gagal untuk melakukan proses penyimpanan" << endl;
        cout << "================================================" << endl;
      }
      break;
    case 'n':
      cout << "File tidak disimpan" << endl;
      cout << "================================================" << endl;
      break;
  }

  /* Kode untuk menutup program */
  cout << "\033[1;32m";
  cout << " T    H    A    N    K    Y    O    U    !    !"<<endl;
  cout << "  For using our app to solve your 24-Game :))  "<<endl;
  cout << "\033[0m";
  return 0;
}
