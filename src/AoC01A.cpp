#include <iostream>
#include <fstream>
#include <algorithm>



int main() {

    std::ifstream file("../inputs/data01.txt");
    std::string line;


    int ListA[1000] = {0};
    int ListB[1000] = {0};
    int idx = 0;
    
    while (std::getline(file, line)) {

        //printf("%s\n", line.c_str());

        std::string partA = line.substr(0, 5);
        std::string partB = line.substr(8, 13);

        ListA[idx] = std::stoi(partA);
        ListB[idx] = std::stoi(partB);
        
        idx++;
    }
    
    int size = sizeof(ListA) / sizeof(ListA[0]);
    int total = 0;
    
    std::sort(ListA, ListA + size);
    std::sort(ListB, ListB + size);

    for (int i = 0; i < 1000; i++) {
        total += std::abs(ListA[i] - ListB[i]);
    }

    printf("Total: %d\n", total);
    return 0;
}