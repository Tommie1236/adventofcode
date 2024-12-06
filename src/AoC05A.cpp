#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<std::pair<int, int>> rules;
std::vector<std::vector<int>> updates;
std::vector<std::vector<int>> correct_updates;
    
int total = 0;


int main() {

    std::ifstream file("../inputs/data05.txt");
    std::string line;
    
    int idx = 0;

    while (std::getline(file, line)) {
        if (idx < 1176) {
            rules.emplace_back(
                std::stoi(line.substr(0, 2).c_str()),
                std::stoi(line.substr(3, 4).c_str())
            );
        } else if (idx > 1177) {
            std::stringstream ss(line);
            std::vector<int> result;

            while (ss.good()) {
                std::string substr;
                getline(ss, substr, ',');
                result.push_back(std::stoi(substr));
            }
            updates.emplace_back(result);
        }
        idx++;
    }
    printf("Rules: %d\n", rules.size());
    printf("Updates: %d\n", updates.size());

    for (std::vector<int> update : updates) {
        std::vector<int> checked_elements;

        for (int element: update) {
            bool correct = true;

            for (std::pair<int, int> rule : rules) {

                if (element == rule.first) {

                    if (std::find(checked_elements.begin(), checked_elements.end(), rule.second) != checked_elements.end()) {

                        correct = false;
                        break;
                    }
                }
            }
            if (correct) {
                checked_elements.push_back(element);
            }
        }
        if (checked_elements.size() == update.size()) {
            correct_updates.push_back(checked_elements);
        }
    }
        




    for (std::vector<int> update : correct_updates) {
        int size = update.size();
        total += update[size/2];
    }
    printf("Total: %d\n", total);



}
