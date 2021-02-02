#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

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
    int i=0;
    char array[1024];
    strcpy(array, number.c_str());
 
    if(strlen(array)== 0){
        
        arquivo.close();
        cout << "number empty" << endl;
        return true;
    }else{
        while(array[i] != 0){
            if(array[i]<'0' || array[i]>'9' || strlen(array) >15 || strlen(array)<4 ){
                cout << "Enter with a number valid" << endl;
                return true;
            }
            i++;
        }  
        arquivo.open("listOfNumbers.txt"); 
    }

    if (arquivo.is_open()) {
        
        while (getline(arquivo, line))
        {
            if (number.compare(line) == 0) {
                arquivo.close();
                cout << "Number already exist" << endl;
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
    cout << "\nNumber of letters : " << vezes; 
    return vezes;

}

int amountNumbers(){
    ifstream arquivo;

    arquivo.open("listOfNumbers.txt");

    arquivo.seekg(0,ios::end); 
    long nrec = (arquivo.tellg( ))/sizeof(amountLetters());
    cout << "\n ";
    arquivo.close();
    return nrec;

}

string* getAllNumbers() {
    ifstream arquivo;
    string line;

    int qtdLines = amountNumbers();
    string* numbers = new string[qtdLines];
    
    arquivo.open("listOfNumbers.txt");
    int i=0;
  
    if (arquivo.is_open()) {
        while (getline(arquivo,line))
        {
            //cout << line << endl;
            numbers[i] = line;
            i++;

        }
        arquivo.close();
       
        return numbers;
        
       
    }
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
void deleteAllNumbers(){
    
    string line;
    ifstream arquivo;
    arquivo.open("listOfNumbers.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (getline(arquivo, line))
    {
        if (line == ""){
            temp << line << endl;
        }
    }
    cout << "All numbers have been deleted " << endl;
    arquivo.close();
    temp.close();
    remove("listOfNumbers.txt");
    rename("temp.txt", "listOfNumbers.txt");


}


void menu(){

    string number;
    string newNumber;
    string* list ;
    int x=0;
    int i;
    char strI [20];
    while(i!=9){
        cout << "\n CHOOSE AN OPTION \n" << "------------------------------------ " << endl;
        cout<< "Enter 1 to add a number to the list \nEnter 2 to update a number in the list \nEnter 3 to see all numbers in the list \nEnter 4 to see a number in the list \n" 
        << "Enter 5 to delete a number from the list \nEnter 6 to see the quantity in the list numbers \nEnter 7 to see the quantity in the letters of the file\nEnter 8 to delete all numbers of the file\nEnter 9 to close program "<< endl;
        gets(strI);
		i=atoi(strI);  
        
        switch (i) {
        case 1:
            system("clear");
            cout << "Add a number in the list: \n";
            cin >> number;
            addNumbers(number);
            cin.get();
            
            break;
        case 2:
            system("clear");
            cout << "update a number in the list: \n";
            cout << "Enter the number current: ";
            cin >> number;
            cout << "Enter the number new: ";
            cin >> newNumber;
            updateNumber(number,newNumber);
            cin.get();
            
            break;
        case 3:
            system("clear");
            cout << "Consult all number in the list: \n";
            cout << "\nAmount of numbers : " << amountNumbers() << endl; 
            list = getAllNumbers();
            x = amountNumbers();
            for (int c = 0; c < x; c++) {
                cout << list[c] << endl;
            }
            cin.get();
            break;

        case 4:
            system("clear");
            cout << "Consult a number in the list by number: \n";
            cin >> number;
            getOneNumber(number);
            cin.get();
            
            break;
        case 5:
             system("clear");
            cout << "Delete a number in the list: \n";
            cin >> number;
            deleteNumber(number);
            cin.get();
           
            break;
        case 6:
            system("clear");
            cout << "Consult amount in the list numbers: \n";
            cout << "\nAmount of numbers : " << amountNumbers() << endl;
            cin.get();
           
            break;
        case 7:
            system("clear");
            cout << "Consult amount in the list letters: \n";
            amountLetters();
            cin.get();
            
            break;
        case 8:
            system("clear");
            cout << "Delete all numbers in the list: \n";
            deleteAllNumbers();
            cin.get();
            
            break;
        default:
            if(i>9 ){
                cout << "No option chosen \n";
                break;
            }
        }
        if(i==9){
	    cout << "The program has ended \n";
    }
        
        
    }
    

}

int main(){
    menu();
    //deleteAllNumbers();
    //getOneNumber("207");
    //addNumbers("");
    //updateNumber("444","2000");
    //amountNumbers();
    //amountLetters();
    //deleteNumber("");
    //getAllNumbers();
    return 0;
}