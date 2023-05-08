// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: text editor
// Program Description: this program can make edits in a file
// Last Modification Date: 15/5/2022
// Authors Names: Omar Adel , Asem Emad , Mohamed Tarek
// Authors IDs: 20210266 , 20210191 , 20210343

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


fstream myfile;
fstream mySecondfile;
fstream tempfile;
static string fileName;
string input;
void list_of_functions();
bool choose();


int main(){
    cout <<"Wirte the file name"<<endl;
    getline(cin , fileName);
    // will open the file for writing in append mode (if the file dosn't exist , it will be created)
    myfile.open(fileName + ".txt", std::fstream::in);
    if (myfile.fail())
    {
        myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
        cout<<"This is a new file. I created it for you"<<endl;
    }
    else{
        cout<<"This File Already Exists"<<endl;
        myfile.close();
        myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    }

    while (true)
    {
        choose();
    }
}

//___________________________________________________________________________________________

void list_of_functions(){
    // displaying programme functions
    for (int i = 0; i < 69; i++)
    {
        cout<<"-";
    }
    cout<<endl;
    cout<<"Add new text to the end of the file"<<setw(21)<<"||"<<setw(10)<<"1"<<endl;
    cout<<"Display the content of the file"<<setw(25)<<"||"<<setw(10)<<"2"<<endl;
    cout<<"Empty the file"<<setw(42)<<"||"<<setw(10)<<"3"<<endl;
    cout<<"Encrypt the file content"<<setw(32)<<"||"<<setw(10)<<"4"<<endl;
    cout<<"Decrypt the file content"<<setw(32)<<"||"<<setw(10)<<"5"<<endl;
    cout<<"Merge another file"<<setw(38)<<"||"<<setw(10)<<"6"<<endl;
    cout<<"Count the number of words in the file"<<setw(19)<<"||"<<setw(10)<<"7"<<endl;
    cout<<"Count the number of characters in the file"<<setw(14)<<"||"<<setw(10)<<"8"<<endl;
    cout<<"Count the number of characters in the file"<<setw(14)<<"||"<<setw(10)<<"9"<<endl;
    cout<<"Search for a word in the file"<<setw(27)<<"||"<<setw(10)<<"10"<<endl;
    cout<<"Count the number of times a word exists in the file"<<setw(5)<<"||"<<setw(10)<<"11"<<endl;
    cout<<"Turn the file content to upper case"<<setw(21)<<"||"<<setw(10)<<"12"<<endl;
    cout<<"Turn the file content to lower case"<<setw(21)<<"||"<<setw(10)<<"13"<<endl;
    cout<<"Turn file content to 1st caps"<<setw(27)<<"||"<<setw(10)<<"14"<<endl;
    cout<<"Save"<<setw(52)<<"||"<<setw(10)<<"15"<<endl;
    cout<<"Exit"<<setw(52)<<"||"<<setw(10)<<"16"<<endl;
    for (int i = 0; i < 69; i++)
    {
        cout<<"-";
    }
    cout<<endl;
}

//___________________________________________________________________________________________


void new_text(){
    cout<<"wtite what do you want"<<endl;
    string user_input;
    cin.ignore();
    getline(cin , user_input);
    myfile<<user_input<<"\n"; // writing in the file in append mode

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----"<<endl;
}

//___________________________________________________________________________________________


void display_the_content(){
    myfile>>input; // it seems to be a pointer that refers to the first word in the file
    while (!myfile.eof())
    {
        cout<<input<<" ";
        myfile>>input; // pointer +1
    }

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----"<<endl;
}

//___________________________________________________________________________________________


void clear()
{
    myfile.close();
    myfile.open(fileName + ".txt", std::ofstream::out | std::ofstream::trunc); // clear all the items

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----"<<endl;
}

//___________________________________________________________________________________________


void ceaser_cipher_encryption(){
    string word;
    tempfile.open("temp.txt" , std::fstream::in | std::fstream::out | std::fstream::app);
    while(getline(myfile, word)){ //read data from file object and put it into string.
        for (int i = 0; i < word.length(); i++)
        {
            char encrypting;
            encrypting = word[i];/* getting the value of letters in asci*/
            if (int(encrypting) == 122)/* if the letter = z it must be replaced by c*/
            {
                tempfile<<"a";
            }
            else if (int(encrypting) == 90)/* if the letter = Z it must be replaced by C*/
            {
                tempfile<<"A";
            }
            else if (int(encrypting) == 32)
            {
                tempfile<<" ";
            }
            else
            {tempfile<<char(int(encrypting)+1);}/*adding the previous value to 1 and getting the letter of the new asci number*/
    }
    tempfile<<"\n";
    }
    myfile.close();
    myfile.open(fileName + ".txt", std::ofstream::out | std::ofstream::trunc);
    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    tempfile.close();
    tempfile.open("temp.txt",std::fstream::in | std::fstream::out |std::fstream::app);
    word="";
    while(getline(tempfile, word)){ //read data from file object and put it into string.
        myfile<<word<<endl;
        }
    tempfile.close();
    remove("temp.txt");

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----"<<endl;
}

//___________________________________________________________________________________________


void ceaser_cipher_decryption(){
    string word;
    tempfile.open("temp.txt" , std::fstream::in | std::fstream::out | std::fstream::app);
    while(getline(myfile, word)){ //read data from file object and put it into string.
        for (int i = 0; i < word.length(); i++)
        {
            char decrypting= word[i];
            if(int(decrypting) == 97){/*if the letter == a it must be replaced by x*/
                tempfile<<"z";
            }
            else if (int(decrypting) == 65)/*if the letter == A it must be replaced by X*/
            {
                tempfile<<"Z";
            }
            else if (int(decrypting) == 32)
            {
                tempfile<<" ";
            }
            else
            {tempfile<<char(int(decrypting)-1);}/*adding the previous value to -3 and getting the letter of the new asci number*/
        }
        tempfile<<"\n";
    }
    myfile.close();
    myfile.open(fileName + ".txt", std::ofstream::out | std::ofstream::trunc);
    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    tempfile.close();
    tempfile.open("temp.txt",std::fstream::in | std::fstream::out |std::fstream::app);
    word="";
    while(getline(tempfile, word)){ //read data from file object and put it into string.
        myfile<<word<<endl;
        }
    tempfile.close();
    remove("temp.txt");

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----"<<endl;
}

//___________________________________________________________________________________________


void upper_case(){
    string word;
    string upper;
    tempfile.open("temp.txt",std::fstream::in | std::fstream::out |std::fstream::app);
    while(getline(myfile, word)){ //read data from file object and put it into string.
        for (int i = 0; i < word.length(); i++)
        {
            upper+=toupper(word[i]);
        }
        tempfile<<upper<<endl;
        upper="";
        }
    myfile.close();
    myfile.open(fileName + ".txt", std::ofstream::out | std::ofstream::trunc);
    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    tempfile.close();
    tempfile.open("temp.txt",std::fstream::in | std::fstream::out |std::fstream::app);
    word="";
    while(getline(tempfile, word)){ //read data from file object and put it into string.
        myfile<<word<<endl;
        upper="";
        }
    myfile.close();
    tempfile.close();
    remove("temp.txt");

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----"<<endl;
}

//___________________________________________________________________________________________


void lower_case(){
    string word;
    string lower;
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    tempfile.open("temp.txt",std::fstream::in | std::fstream::out |std::fstream::app);
    while(getline(myfile, word)){ //read data from file object and put it into string.
        for (int i = 0; i < word.length(); i++)
        {
            lower+=tolower(word[i]);
        }
        tempfile<<lower<<endl;
        lower="";
        }
    myfile.close();
    myfile.open(fileName + ".txt", std::ofstream::out | std::ofstream::trunc);
    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    tempfile.close();
    tempfile.open("temp.txt",std::fstream::in | std::fstream::out |std::fstream::app);
    word="";
    while(getline(tempfile, word)){ //read data from file object and put it into string.
        myfile<<word<<endl;
        lower="";
        }
    myfile.close();
    tempfile.close();
    remove("temp.txt");

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----"<<endl;
}

//___________________________________________________________________________________________


void repeat(){
    string repeated_word;
    int times = 0; // creating a counter
    cout<<"write the word"<<endl;
    cin>>repeated_word;
    myfile>>input;
    while (!myfile.eof())// looping over each word in the file
    {
        if (repeated_word == input)
        {
            times+=1; // increment the counter
        }
        myfile>>input;// getting the next word
    }
    cout<<"this word repeted "<<times<<" times"<<endl;

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----"<<endl;
}

//___________________________________________________________________________________________


void first_upper_second_lower(){
    string word;
    string temp;// variable to take every word in a specific line.
    string cpy;
    while(getline(myfile, word)){ // getting every line in a variable.
        for (int i = 0; i < word.length(); i++)
        {
            if (int(char(word[i]))!=32) // if there is no space , put this letter in the varible.
            {
                temp+=word[i];
            }
            else{
                temp[0]=toupper(temp[0]);
                cpy+=temp;
                cpy+=" "; //cpy = temp + space
                temp="";
            }
        }
        temp+="\n";
    }
    temp[0]=toupper(temp[0]);//making the same with the last word
    cpy+=temp;
    myfile.close();
    myfile.open(fileName + ".txt", std::ofstream::out | std::ofstream::trunc);
    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    myfile<<cpy;
    myfile.close();

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----"<<endl;
}

//___________________________________________________________________________________________


void save(){
    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----"<<endl;
}

//___________________________________________________________________________________________


void merg_file(){
    string name_file2;
    string line;
    cout<<"Enter the Filename you want to merg it with the file"<<endl;
    cin>>name_file2;
    mySecondfile.open(name_file2 + ".txt", fstream::in | fstream::out | fstream::app);
        while(getline(mySecondfile,line)){

            myfile<<line<<endl; // taking every word in the second file to the first
        }
    mySecondfile.close();

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----\n"<<endl;

}

//___________________________________________________________________________________________


void number_of_words(){
    int words = 0; // creating a counter
    while(!myfile.eof()){
        words += 1;// incremnting the counter after each word.
        myfile>>input;// getting the next word
    }
    cout <<"The number of Words is = "<< words << endl;

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----\n"<<endl;

}

//___________________________________________________________________________________________


void number_of_characters(){
    int chars = 0;// creating a counter
    char c;
    string line;
    while(getline(myfile,line)){
        for (char& c : line)
        {
            if(c != ' '){
                chars += 1;// increamnting the counter after each character.
        }
        }
    }
    cout <<"The number of characters is = "<< chars << endl;

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----\n"<<endl;

}

//___________________________________________________________________________________________


void number_of_lines(){
    int lines = 0; // creating a counter
    string line;
    while(getline(myfile,line)){ // getting each line in a variable.
        lines += 1; ;// incremnting the counter after each line.

    }
    cout <<"The number of Lines is = "<< lines << endl;

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----\n"<<endl;

}

//___________________________________________________________________________________________


void search_word(){
    string word;
    bool check = false;

    cout<<"Enter the word to search it: "<<endl;
    cin>>word; // getting the word.

    myfile>>input;

    while(!myfile.eof()){ //looping over each word
        if(input == word){
            check = true;
        }
        myfile>>input; // getting the next word if the two words are not matching.
    }

    if(check){
        cout<<"its exist !!"<<endl;
    }else{
        cout<<"its dosn't exist"<<endl;
    }

    myfile.close();
    myfile.open(fileName + ".txt", std::fstream::in | std::fstream::out |std::fstream::app);
    cout<<"----succeeded----\n"<<endl;
}

//___________________________________________________________________________________________


bool choose(){
    int x;
    list_of_functions();
    cout<<"choose what do you want"<<endl;
    while (!(cin >> x))
    {
        cout << "enter a valid num" << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    if (x == 1)
    {
        new_text();
        return true;
    }
    else if (x == 2)
    {
        display_the_content();
        return true;
    }
    else if (x == 3)
    {
        clear();
        return true;
    }
    else if (x == 4)
    {
        ceaser_cipher_encryption();
        return true;
    }
    else if (x == 5)
    {
        ceaser_cipher_decryption();
        return true;
    }
    else if (x == 6)
    {
        merg_file();
        return true;
    }
    else if (x == 7)
    {
        number_of_words();
        return true;
    }
    else if (x == 8)
    {
        number_of_characters();
        return true;
    }
    else if (x == 9)
    {
        number_of_lines();
        return true;
    }
    else if (x == 10)
    {
        search_word();
        return true;
    }
    else if (x == 11)
    {
        repeat();
        return true;
    }
    else if (x == 12)
    {
        upper_case();
        return true;
    }
    else if (x == 13)
    {
        lower_case();
        return true;
    }
    else if (x == 14)
    {
        first_upper_second_lower();
        return true;
    }
    else if (x == 15)
    {
        save();
        return true;
    }
    else if (x == 16)
    {
        exit(0);
        return false;
    }
    else {
        cout<<"Please choose number between 1 and 15"<<endl;
        choose();
        return true;
    }
}
