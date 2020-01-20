#include <iostream>
#include <String>
#include <algorithm>
using namespace std;

bool uniqCharNSquare(string);
bool uniqCharNLogN(string);
bool uniqCharN(string);

int main(){
	
	string word = "Intervention";
	string word2 = "Apple Pie";
	//uniqCharNSquare(word2);
	//uniqCharNLogN(word2);
	uniqCharN(word2);
}

// Checks every character againsts all others, returns false if found, true if not
// O(n^2)
bool uniqCharNSquare(string word){
	
	for(int i=0;i<word.length()-1;i++){
		for(int z=i+1; z <word.length();z++){
			if(word[i]==word[z]){
				cout << "The word " << word << " has repeating characters" << endl;
				return false;
			}
		}
	}
	cout << "The word " << word << " does NOT have repeating characters" << endl;
	return true;
	
}


// Sorts the word, then checks adjacent letter
// O(n log n)
bool uniqCharNLogN(string word){
	// STL sort function is based off of Quick Sort 
	string temp = word;
	sort(temp.begin(),temp.end());
	
	for(int i=0; i<temp.length()-1;i++){
		if(temp[i]==temp[i+1]){
			cout << "The word " << word << " has repeating characters" << endl;
			return false;
		}
	}
	cout << "The word " << word << " does NOT repeating characters" << endl;
	return true;
}


// Uses a boolean Array for characters
// O(n)
bool uniqCharN(string word){
	
	// 256 char in ASCII, so if the length is greater than characters must have repeated
	if(word.length()>256){
		return false;
	}
	
	bool character[256] = {false};
	
	for(int i=0;i<word.length();i++){
		
		// If the character in the boolean array, after casting the letter is found to be true, that means the letter has been found before and is repeating
		if(character[int(word[i])] == true){
			cout << "The word " << word << " has repeating characters" << endl;
			return false;
		}
		
		character[int(word[i])] = true;
	}
	cout << "The word " << word << " does NOT repeating characters" << endl;
	return true;
}







