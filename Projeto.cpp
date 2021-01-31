#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void getAllNumbers() {
    ifstream arquivo;
    string line;
    arquivo.open("listOfNumbers.txt");

    if (arquivo.is_open()) {
        while (getline(arquivo, line))
        {
            cout << line << endl;
        }
        arquivo.close();
    }
}

string getOneNumber(string number) {
    ifstream arquivo;
    string line;
    
    arquivo.open("listOfNumbers.txt");

    if (arquivo.is_open()) {
        while (getline(arquivo, line))
        {
            
            if (number.compare(line) == 0) {
          
                cout <<line << endl;
                arquivo.close();
                
                return line;
            }
        }
        arquivo.close();
        return "NOT_FOUD";
    }
}



bool verifyNumber(string number){
    ifstream arquivo;
    string line;


    char array[1024];
    strcpy(array, number.c_str());

    if(strlen(array)== 0){
        arquivo.close();
        cout << "number empty" << endl;
        return false;
    }else{
        arquivo.open("listOfNumbers.txt");
    }
    
    if (arquivo.is_open()) {
        
        while (getline(arquivo, line))
        {
            if (number.compare(line) == 0) {
                arquivo.close();
                
                return true;
            }
        }
        arquivo.close();
        return false;
    }
}


void addNumbers(string number){
    ofstream arquivo;
    
    if (!verifyNumber(number)) {
        arquivo.open("listOfNumbers.txt", ios::app);
        arquivo << number + "\n";
        arquivo.close();
        cout << "Number add successfully" << endl;
    } else {
        cout << "Number already exist" << endl;
    }

    
}

string updateNumber(string number, string newNumber) {
    fstream arquivo;
    string line;
    ofstream temp;

    if (!verifyNumber(newNumber)) {
        arquivo.open("listOfNumbers.txt");
        temp.open("temp.txt");
        while (getline(arquivo, line))
        {
       
            if (number.compare(line) == 0) {
                temp << newNumber << endl;
        
            }else if (line != number){
                temp << line << endl;
            }
        }
        cout << "Number update successfully" << endl;
        arquivo.close();
        temp.close();
        remove("listOfNumbers.txt");
        rename("temp.txt", "listOfNumbers.txt");
        return line;
    }else{
        cout << "Number invalid" << endl;
    }
}
int amountLetters() {
    
    FILE *arquivo;
    char c, letra = '\n';
    int vezes;

    arquivo= fopen("listOfNumbers.txt","r");

        //Lendo o arquivo 1 por 1
    while(fread (&c, sizeof(char), 1, arquivo)) {
        if(c == letra) {
             vezes++;
        }
    } 
    cout << "\nNumero de registros : " << vezes; 
    return vezes;

}

void amountNumbers(){
    ifstream arquivo;

    arquivo.open("listOfNumbers.txt");

    arquivo.seekg(0,ios::end); 
    long nrec = (arquivo.tellg( ))/sizeof(amountLetters());
    cout << "\nNumero de registros : " << nrec; 
    cout << "\n ";
    arquivo.close();
}

void deleteNumber(string number){
    
    string line;
    ifstream arquivo;
    arquivo.open("listOfNumbers.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (getline(arquivo, line))
    {
        if (line != number){
            temp << line << endl;
        }
    }
    cout << "The number: " << number << " was deleted successfully"  << endl;
    arquivo.close();
    temp.close();
    remove("listOfNumbers.txt");
    rename("temp.txt", "listOfNumbers.txt");


}

void menu(){
    string number;
    string newNumber;
    int i;
    char strI [20];
    while(i!=8){
        system("clear");
        cout << "\n ESCOLHA UMA OPÇÂO \n" << "------------------------------------ " << endl;
        cout<< "Enter 1 to add a number to the list \nEnter 2 to update a number in the list \nEnter 3 to see all numbers in the list \nEnter 4 to see a number in the list \n" 
        << "Enter 5 to delete a number from the list \nEnter 6 to see the quantity in the list numbers \nEnter 7 to see the quantity in the letters of the list\nEnter 8 to close program "<< endl;
        gets(strI);
		i=atoi(strI);    
        switch (i) {
        case 1:
            cout << "Add a number in the list: \n";
            cin >> number;
            addNumbers(number);
            break;
        case 2:
            cout << "update a number in the list: \n";
            cout << "Type the number current: ";
            cin >> number;
            cout << "Type the number new: ";
            cin >> newNumber;
            updateNumber(number,newNumber);
            break;
        case 3:
            cout << "Consult all number in the list: \n";
            getAllNumbers();
            break;
        case 4:
            cout << "Consult a number in the list by number: \n";
            cin >> number;
            getOneNumber(number);
            break;
        case 5:
            cout << "Delete a number in the list: \n";
            cin >> number;
            deleteNumber("222");
            break;
        case 6:
            cout << "Consult amount in the list numbers: \n";
            amountNumbers();
            break;
        case 7:
            cout << "Consult amount in the list letters: \n";
            amountLetters();
            break;
        case 8:
            cout << "Você decidiu sair \n";
            break;
        }
        if(i>8){
            cout << " nenhum Opção escolhida \n";
            system("clear");
        }
        if(i<=0)
		{
			 
			cout << "Nenhum Opção escolhida! \n";
            system("clear");
		}  
        
    }
}
int main(){
    menu();
    //getOneNumber("207");
    //addNumbers("444");
    //updateNumber("444","2000");
    //amountNumbers();
    //amountLetters();
    //deleteNumber("222");
    //getAllNumbers();
    return 0;
}