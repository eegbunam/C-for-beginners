#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <stdlib.h>    
#include <time.h>       

using namespace std;


vector<string> readFile(const char *name){
    string line;
    ifstream outfile;
    outfile.open(name);
    vector<string> outputs;
    if (outfile.is_open()){

        while( std::getline(outfile, line) ){
            outputs.push_back(line);
        }

    }
    outfile.close();
    return outputs;
}
int main(){
    string question;
    vector<string> readFile(const char *name);
    vector<string> answers = readFile("magic.txt");

    srand (time(NULL));
    int lenOfArray = answers.size();
    int iSecret = rand() % lenOfArray;

    cout << "Please ask a  Question " << endl;
    cin >> question;
    cout << " The Magic Ball says: " << answers[iSecret] << endl;





}