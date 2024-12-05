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
    
    std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");

    std::vector<std::pair<int, int>> results;

    auto begin = std::sregex_iterator(data.begin(), data.end(), pattern);
    auto end = std::sregex_iterator();

    for (auto iter = begin; iter != end; ++iter) {
        std::smatch match = *iter;
        printf("%s\n", match.str().c_str());
            
        if (match[1].matched && match[2].matched) {
            int x = std::stoi(match[1].str());
            int y = std::stoi(match[2].str());

            results.emplace_back(x, y);
        } else if (match.str() == "do()") {
            printf("do()");
            results.emplace_back(1000, 1000);
        } else if (match.str() == "don't()") {
            printf("don't()");
            results.emplace_back(2000, 2000);
        }

    }

    int total = 0;
    bool enabled = true;

    for (std::pair<int, int> result : results) {
        
        if (result.first == 1000) {
            enabled = true;
            continue;
        } else if (result.first == 2000) {
            enabled = false;
            continue;
        }

        if (enabled) {
            total += result.first * result.second;
        }
    }

    printf("Total: %d\n", total);

    return 0;
}
