#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

enum {
fifo, roundrobin, shortfifo
};


int main (int argc, char* argv[]){

string argument = "input=input.txt;size=22;scheduling=fifo;quantum=4";
//argument = argv[1];

string filename;
int index;

string sizetxt;
int size;

string quantumtxt;
int quantum;

string stype;

string textline;
string person;
int arrtime;
int duration;



filename = argument;
index = filename.find(';');
filename = filename.substr(0,index);
filename = filename.erase(0,6);
cout << filename << endl;

sizetxt = argument;
index = sizetxt.find(';');
sizetxt = sizetxt.erase(0,index + 1);
index = sizetxt.find(';');
sizetxt = sizetxt.substr(0,index);
sizetxt = sizetxt.erase(0,5);

size = stoi(sizetxt);
cout << size << endl;
//cout << sizetxt << endl;

quantumtxt = argument;
index = quantumtxt.find_last_of(';');
quantumtxt = quantumtxt.erase(0,index+1);
quantumtxt = quantumtxt.erase(0,8);

quantum = stoi(quantumtxt);

cout << quantum << endl;

stype = argument;
index = stype.find_last_of(';');
stype = stype.substr(0,index);
index = stype.find(';');
stype = stype.erase(0,index+1);
index = stype.find(';');
stype = stype.erase(0,index+1);
stype = stype.erase(0,11);

cout << stype << endl;

ifstream input (filename);

if (input.fail()){cout << "no input" << endl;}

getline(input,textline,'\n');

while (!input.eof()){
getline(input,textline,'\n');

istringstream linetext(textline);
//cout << textline << endl;

linetext >> person >> arrtime >> duration;

cout << person << '\t' << arrtime << '\t' << duration << endl;


}



system ("pause");

}