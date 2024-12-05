#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <string>



int main() {

    std::ifstream file("../inputs/data03.txt");
    std::string line;
    std::string data;

    while(std::getline(file, line)) {
        data += line;
    }
    
    std::regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");

    std::vector<std::pair<int, int>> results;

    auto begin = std::sregex_iterator(data.begin(), data.end(), pattern);
    auto end = std::sregex_iterator();

    for (auto iter = begin; iter != end; ++iter) {
        std::smatch match = *iter;
            
        int x = std::stoi(match[1].str());
        int y = std::stoi(match[2].str());

        results.emplace_back(x, y);
    }

    int total = 0;

    for (std::pair<int, int> result : results) {
        total += result.first * result.second;
    }

    printf("Total: %d\n", total);

    return 0;
}
