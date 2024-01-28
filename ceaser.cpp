#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <thread>
using namespace std;

string input; 

int string_size(string input) {
    int i = 0;
    while(input[i] != '\0') {
        ++i;
    }
    return i-1; 
}

void encrypt(string& input_, int n) {
    int i = 0;
    while(input_[i] != '\0') {
        int j = input_[i]-32;
        j = (j + n) % 94; 
        input_[i] = j+32; 
        ++i;
    }
    cout<<"\n"; 

}

void decrypt(string& input_, int n) {
    int i = 0;
    while(input_[i] != '\0') { 
        int j = input_[i]-32;
        j-=n;
        j = (j+94)%94;
        input_[i] = j+32;
        ++i; 
    }
}




int main() {

    ifstream input_file("input_text.txt"); 
    while(!input_file.eof()) {
        getline(input_file,input);
    }

    int user_choice;

    cout<<"Hello, the below program works with the ceaser cipher. \n";
    cout<<"Please choose one of the options below \n";
    cout<<"\t 1. Press 1 in order to encrypt a message.\n";
    cout<<"\t 2. Press 2 in order to decrypt an encrypted message.\n";
    cin>>user_choice;

    try {

        if(user_choice != 1 && user_choice != 2) {
            throw 0; 
        }
    } 
    catch(int j) {
        cout<<"Choose a the number '1' or number '2' please.\n";
        cout<<"Program terminated";
    }

    int r; 
    int num; 

    switch(user_choice) {
        case 1: 
            srand(time(NULL));
            r = rand() % 94;
            cout<<"Encrypted text below: \n";
            encrypt(input,r);
            cout<<input<<"\n";
            cout<<r<<"\n"; 
            break;

        case 2:
            cout<<"Input key below\n";
            cin>>num;
            cout<<"\n";
            
            try {

                if(num<0 || num>94) {
                    throw 0;
                }

            }
            catch(int x) {
                cout<<"Key should be an integer between 0 and 127.";
                break; 
            }

            decrypt(input,num);
            cout<<"Decrypted text below: \n";
            cout<<input<<"\n";
            cout<<"\n";
            break;
        default:

            break; 
    }

    return 0; 

}

