#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

struct node {

	struct node *next[26];
	int end;

};

void put(struct node *root, string str) {
	
	struct node *curr = root;

	for(int i = 0;i<str.length();i++) {
		int charIndex = str[i] - 'a';
		if(curr->next[charIndex] == 0) {
			curr->next[charIndex] = (struct node*)malloc(sizeof(struct node));
		}
		curr = curr->next[charIndex];
	}

	curr->end = 1;

}

void printTree(struct node *root, vector<string> &output, string str = "") {

	struct node *curr = root;
	
		cout<<str<<endl;
	if(curr->end == 1) {
		output.push_back(str);
		return;
	}
	
	for(int i = 0;i<26;i++) {
		if(curr->next[i] != 0) {
			str += (char)(i + 'a');
			printTree(curr->next[i], output, str);
			str.resize(str.size() - 1);
		}
	}
}		


int main() {

	struct node *root = (struct node*)malloc(sizeof(struct node));

	vector<string> content, output;

	string str;

	ifstream file;

	file.open("content.csv");

	while(file) {

		getline(file, str);
		content.push_back(str);

	}


	for(int i = 0;i<content.size();i++) {
		put(root, content[i]);
	}

	printTree(root, output);
	cout<<output.size();

	for(int i = 0;i<output.size();i++) {

		cout<<output[i]<<endl;

	}



}
