#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void findPer(vector<vector<char>> vec, vector<string> &output, int n=0, string str = "") {

	if (n == vec.size()-1) {
		output.push_back(str);
		return;
	}

	for(int i=0;i<vec[n].size();i++) {
		findPer(vec, output, n+1, str + vec[n][i]);
    	}


}

int main(int argc, char** argv) {

	ifstream file;

	file.open(argv[1]);

	string str;

	vector<char> content;

	vector<vector<char>> contentVec;

	vector<string> output;

	while(file) {

		getline(file, str);

		for(int i = 0;i<str.size();i++) {
			if(str[i] != ',' && str[i] != ' ')
				content.push_back(str[i]);
		}

		contentVec.push_back(content);
		content.clear();

	}

	findPer(contentVec, output);

	for(int i = 0;i<output.size();i++) {
		cout<<output[i]<<" ";
		if(i < output.size() - 1) {
	            cout << ", ";
	        }
	}
	
	return 0;

}

