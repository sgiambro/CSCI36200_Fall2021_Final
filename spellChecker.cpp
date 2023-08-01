#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "TimeInterval.h"


using namespace std;

class spellChecker{
	
	vector<string> words[702];
	int elements;
	
	public:
		spellChecker();
		void insertWord(string w);
		int hashFunction(string w);
		void search();
};


spellChecker::spellChecker(){
	elements = 702;
}

void spellChecker::insertWord(string w){
	
	//makes the word lowercase
	transform(w.begin(), w.end(), w.begin(), ::tolower);
	
	//gets where the word will be stored
	int index = hashFunction(w);
	
	//stores the key
	words[index-1].push_back(w);
	
}

int spellChecker::hashFunction(string w){
	
	//add a space for out of range errors then find the first and second letter
	w += " ";
    char first =  w.at(0);
    char second =  w.at(1);
    int num;

	//gets number corresponding to the second letter
    switch(second) {
      case 'a' : num = 1; break;
      case 'b' : num = 2; break;
      case 'c' : num = 3; break;
      case 'd' : num = 4; break;
      case 'e' : num = 5; break;
      case 'f' : num = 6; break;
      case 'g' : num = 7; break;
      case 'h' : num = 8; break;
      case 'i' : num = 9; break;
      case 'j' : num = 10; break;
      case 'k' : num = 11; break;
      case 'l' : num = 12; break;
      case 'm' : num = 13; break;
      case 'n' : num = 14; break;
      case 'o' : num = 15; break;
      case 'p' : num = 16; break;
      case 'q' : num = 17; break;
      case 'r' : num = 18; break;
      case 's' : num = 19; break;
      case 't' : num = 20; break;
      case 'u' : num = 21; break;
      case 'v' : num = 22; break;
      case 'w' : num = 23; break;
      case 'x' : num = 24; break;
      case 'y' : num = 25; break;
      case 'z' : num = 26; break;
      default  : num = 0;
    }
	
	//if there is no second letter use the first letter 
	//if there is a second letter then add the number to the range given by the first number
	if( num == 0 ){
		switch(first) {
		  case 'a' : return 1; break;
		  case 'b' : return 2; break;
		  case 'c' : return 3; break;
		  case 'd' : return 4; break;
		  case 'e' : return 5; break;
		  case 'f' : return 6; break;
		  case 'g' : return 7; break;
		  case 'h' : return 8; break;
		  case 'i' : return 9; break;
		  case 'j' : return 10; break;
		  case 'k' : return 11; break;
		  case 'l' : return 12; break;
		  case 'm' : return 13; break;
		  case 'n' : return 14; break;
		  case 'o' : return 15; break;
		  case 'p' : return 16; break;
		  case 'q' : return 17; break;
		  case 'r' : return 18; break;
		  case 's' : return 19; break;
		  case 't' : return 20; break;
		  case 'u' : return 21; break;
		  case 'v' : return 22; break;
		  case 'w' : return 23; break;
		  case 'x' : return 24; break;
		  case 'y' : return 25; break;
		  case 'z' : return 26; break;
		  default  : return 0;
		}
	}
	else {
		switch(first) {
		  case 'a' : return (num + 26); break;
		  case 'b' : return (num + 52); break;
		  case 'c' : return (num + 78); break;
		  case 'd' : return (num + 104); break;
		  case 'e' : return (num + 130); break;
		  case 'f' : return (num + 156); break;
		  case 'g' : return (num + 182); break;
		  case 'h' : return (num + 208); break;
		  case 'i' : return (num + 234); break;
		  case 'j' : return (num + 260); break;
		  case 'k' : return (num + 286); break;
		  case 'l' : return (num + 312); break;
		  case 'm' : return (num + 338); break;
		  case 'n' : return (num + 364); break;
		  case 'o' : return (num + 390); break;
		  case 'p' : return (num + 416); break;
		  case 'q' : return (num + 442); break;
		  case 'r' : return (num + 468); break;
		  case 's' : return (num + 494); break;
		  case 't' : return (num + 520); break;
		  case 'u' : return (num + 546); break;
		  case 'v' : return (num + 572); break;
		  case 'w' : return (num + 598); break;
		  case 'x' : return (num + 624); break;
		  case 'y' : return (num + 650); break;
		  case 'z' : return (num + 676); break;
		  default  : return 0;
		}
	}
}

void spellChecker::search(){
	
	//make a TimeInterval object to track the operation time
	TimeInterval time;
	
	//gets the users word
	cout << "Give a word you want to search:     ";
	string word;
	cin >> word;
	
	//makes the word lowercase
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	
	//get the words location in the hash table
	int index = (hashFunction(word)) - 1;
	
	//check to see if the word is there
	bool match;
	for (vector<string>::iterator x = words[index].begin() ; x != words[index].end() ; x++) {
			if(*x == word){
				match = true;
			}
		}
	
	//if its there print true and the related words with the time
	//if its not there give a suggestion
	//if its still not correct print false
	if (match == true || word == "i"){
		if(word == "i"){
			cout << "True" << endl;
		
			time.start();
			
			for (vector<string>::iterator x = words[8].begin() ; x != words[8].end() ; x++) {
				cout << *x << endl;
			}
			
			time.stop();
			cout << time.GetInterval() << " micro-sec" << endl;
		}
		else{
			cout << "True" << endl;
			
			time.start();
			
			for (vector<string>::iterator x = words[index].begin() ; x != words[index].end() ; x++) {
				cout << *x << endl;
			}
			
			time.stop();
			cout << time.GetInterval() << " micro-sec" << endl;
		}
	}
	else{
		
		//gets ascii value for user word
		int userTotal = 0;
		for(int x = 0 ; x<word.length() ; x++){
			userTotal += int(word.at(x));
		}
		
		
		//gets range of posible suggestions assuming the first letter is correct
		int start , end;
		char first =  word.at(0);
		
		switch(first) {
		  case 'a' : start = 27; end = 52; break;
		  case 'b' : start = 53; end = 78; break;
		  case 'c' : start = 79; end = 104; break;
		  case 'd' : start = 105; end = 130; break;
		  case 'e' : start = 131; end = 156; break;
		  case 'f' : start = 157; end = 182; break;
		  case 'g' : start = 183; end = 208; break;
		  case 'h' : start = 209; end = 234; break;
		  case 'i' : start = 235; end = 260; break;
		  case 'j' : start = 261; end = 286; break;
		  case 'k' : start = 287; end = 312; break;
		  case 'l' : start = 313; end = 338; break;
		  case 'm' : start = 339; end = 364; break;
		  case 'n' : start = 365; end = 390; break;
		  case 'o' : start = 391; end = 416; break;
		  case 'p' : start = 417; end = 442; break;
		  case 'q' : start = 443; end = 468; break;
		  case 'r' : start = 469; end = 494; break;
		  case 's' : start = 495; end = 520; break;
		  case 't' : start = 521; end = 546; break;
		  case 'u' : start = 547; end = 572; break;
		  case 'v' : start = 573; end = 598; break;
		  case 'w' : start = 599; end = 624; break;
		  case 'x' : start = 625; end = 650; break;
		  case 'y' : start = 651; end = 676; break;
		  case 'z' : start = 677; end = 702; break;
		  default  : start = 0; end = 0; break;
		}
		
		//commpar ascii values for all words in range to get best suggestion
		int dictionaryTotal = 0;
		int tempTot = 0;
		string suggestion;
		string temp;
		for(int i = (start-1) ; i < end ; i++){
			for (vector<string>::iterator x = words[i].begin() ; x != words[i].end() ; x++) {
				temp = *x;
				tempTot = 0;
				for(int j = 0 ; j < temp.length() ; j++){
					tempTot += int(temp.at(j));
					
					if(abs(userTotal - tempTot) < abs(userTotal - dictionaryTotal)){
						dictionaryTotal = tempTot;
						suggestion = temp;
					}
				}
			}
		}
		
		//get if its the right word
		string responce;
		cout << "Did you mean " << suggestion << "? (y/n)" << endl;
		cin >> responce;
		
		
		//get if its the right word print true and the related words with the time
		//if not print false
		if(responce == "y"){
			word = suggestion;
			cout << "True" << endl;
		
			time.start();
			
			for (vector<string>::iterator x = words[index].begin() ; x != words[index].end() ; x++) {
				cout << *x << endl;
			}
			
			time.stop();
			cout << time.GetInterval() << " micro-sec" << endl;
		}
		else{
			cout << "False" << endl;
		}
		
		
	}
	
	
}



int main(){
	
	spellChecker sp;
	

	//creates the dictionary
	string line;
	ifstream myFile("Dictionary.txt");

	while( getline(myFile , line) ) {
		sp.insertWord(line);
	}
	

	//search for the a user inputer word
	sp.search();
	
	
}