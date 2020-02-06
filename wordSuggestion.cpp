#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {

	ifstream file;

	file.open("content.csv");

	string str;

	vector<string> content;

	vector<vector<string>> contentArr;
	int splitIndex;

	while(file) {

		getline(file, str);

		for(int i = 0;i<str.size();i++) {
			if(str[i] == ',') {
				splitIndex = i;	
				break;
			}
		}

		if(str.size() == 0)
			break;

		content.push_back(str.substr(0, splitIndex));
		content.push_back(str.substr(splitIndex, str.size() - splitIndex));

		contentArr.push_back(content);
		content.clear();

	}

	for(int i = 0;i<contentArr.size();i++) {

		cout<<(contentArr[i])[0]<<" "<<(contentArr[i])[1];
		cout<<endl;

	}
	
	return 0;

}

