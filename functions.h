#pragma once
#include "mylib.h"

void read_file(std::map<std::string, std::map<int, int>>& word_map, std::map<std::string, std::map<int, int>>& url_map, const std::string& filename);

void write_file(std::map < std::string, std::map<int, int>>& word_map, std::map<std::string, std::map<int, int>>& url_map, const std::string& filename);

bool is_url(std::string str);

bool invalid_char(char c);