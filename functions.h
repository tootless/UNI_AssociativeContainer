#pragma once
#include "mylib.h"

void read_file(std::map<std::string, std::map<int,int>>& word_map, const std::string& filename);

bool invalid_char(char c);