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
			//find invalid characters from the back first
			while (!word.empty() && invalid_char(word.back())) {
				word.pop_back();
			}
			//find invalid characters from the front
			if (!word.empty() && invalid_char(word.front())) {
				word.erase(word.begin());
			}
			if (!word.empty()) {
				std::transform(word.begin(), word.end(), word.begin(), ::tolower);
				word_map[word][line_num]++;
			}
		}
	}
}
bool invalid_char(char c)
{
	std::string inv_char = " \t\n.,!@#$%^&*()_+-=?/{}[]'\" ";

	return inv_char.find(c) != std::string::npos; //returns false if found
}