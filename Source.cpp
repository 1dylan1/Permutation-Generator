#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

map<int, char> makeMap(string word) {
	map<int, char> map;
	int n = 1;
	for (int i = 0; i < word.length(); i++) {
		if (i != word.length()) {
			if (word[i] == word[i + 1]) {
				map.insert(pair<int, char>(n, word[i]));
				i++;
				n++;
			}
			else {
				map.insert(pair<int, char>(n, word[i]));
				n++;
			}
		}
	}
	return map;
}

string convertToNumbers(string word) {
	int size = word.size();
	string s = "";
	int n = 1;
	for (int i = 0; i < size; i++) {
		char c[2];
		if (i != size) {
			if (word[i] == word[i + 1]) {
				sprintf(c, "%d", n);
				s = s + c;
				s = s + c;
				n++;
				i++;
			}
			else {
				sprintf(c, "%d", n);
				s = s + c;
				n++;
			}
		}
	}
	return s;
}

string permute(string word) {

	int a_i = -1;
	//finding a_i (i)
	for (int i = 0; i < word.length() - 1; i++) {
		if (word[i + 1] > word[i] && word[i] > a_i) {
			a_i = i;
		}
	}

	//finding a_j (j)
	int a_j = -1;
	for (int v = a_i + 1; v < word.length(); v++) {
		if (word[v] > word[a_i] && word[v] > a_j) {
			a_j = v;
		}
	}

	swap(word[a_i], word[a_j]);
	a_i++;
	reverse(word.begin() + a_i, word.end()); //reverse a_[i+1] including a_[i+1] with rest of word

	return word;
}

void printPermutations(string word, int permutations) {

	cout << "permutations" << endl;

	map<int, char> map = makeMap(word); //key value pairs
	word = convertToNumbers(word);
	vector<string> permutationList;
	int size = word.length();
	permutations--;

	permutationList.push_back(word);
	for (int i = 0; i < permutations; i++) {
		word = permute(word);
		permutationList.push_back(word); //fill vector with our permutations
	}

	for (int i = 0; i < permutationList.size(); i++) {
		for (int z = 0; z < permutationList[i].length(); z++) {
			for (auto k = map.begin(); k != map.end(); k++) {
				int temp = permutationList[i][z] - 48;
				if (temp == k->first) {
					cout << k->second;
				}
			}
		}
		cout << endl;
	}

}

int main() {

	string word = "ABC";
	int permutations = 8;
	printPermutations(word, permutations);

	return 0;
}
