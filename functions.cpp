#include "functions.h"

void read_file(std::map<std::string, std::map<int,int>>& word_map, const std::string& filename) {
	std::string path = "Text/" + filename;
	if (!filename.ends_with('.txt')) path += '.txt';

	std::ifstream fin(path, std::ios::in);

	if (!fin.is_open()) throw std::runtime_error("File " + filename + " failed to open.");

	std::string line;
	int line_num = 0;

	while (std::getline(fin, line)) {
		std::istringstream iss(line);
		std::string word, result;
		line_num++;

		while (iss >> word) {
			//find invalid words
			//check characters from the back first, then front
			while (!word.empty() && invalid_char(word.back())) {
				word.pop_back();
			}
			while (!word.empty() && invalid_char(word.front())) {
				word.erase(word.begin());
			}
			if (!word.empty()) {
				std::transform(word.begin(), word.end(), word.begin(), ::tolower);
				word_map[word][line_num]++; //adds word if !exist, exist -> word_count++; line_num++;
			}
		}
	}
}

bool is_url(std::string str) {
	std::array<std::string, 10> formats1 = { "http://","https://","www." };
	std::array<std::string, 10> formats2 = { ".lt", ".com", ".ru", ".to" };
	for (const auto& s : formats1) {
		if(str.rfind(s,0)) return true; //find s in str from 0
	}
	for (const auto& s : formats2) {
		return str.find(s) != std::string::npos; //from end (find move left <- right)
	}
	return false;
}

bool invalid_char(char c)
{
	std::string inv_char = " \t\n.,!@#$%^&*()_+-=?/{}[]'\" ";

	return inv_char.find(c) != std::string::npos; //returns false if found
}

void write_file(std::map <std::string, std::map<int, int>>& word_map, const std::string& filename){
	std::string path = "Text/" + filename;
	if (!filename.ends_with('.txt')) path += '.txt';


}