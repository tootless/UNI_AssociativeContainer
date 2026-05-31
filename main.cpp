#include "mylib.h"
#include "functions.h"

int main() {
    std::map<std::string, std::map<int, int>> word_map;
    std::map<std::string, std::map<int, int>> url_map;

    std::string eng_text = "text1.txt";
    std::string lt_text = "text2.txt";
    std::string out = "results.txt";

    try
    {
        read_file(word_map, url_map, eng_text);
        //read_file(word_map, url_map, lt_text);
        write_file(word_map, url_map, out);

        std::cout << "perskaityta\n";
        std::cout << "Failas: " << out << " sudarytas.\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    return 0;
}