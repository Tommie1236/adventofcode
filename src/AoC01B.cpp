#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <array>



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
    //int ListA[6] = {3, 4, 2, 1, 3 ,3};
    //int ListB[6] = {4, 3, 5, 3, 9, 3};
    
    int size = sizeof(ListA) / sizeof(ListA[0]);
    printf("Size: %d\n", size);
    int total = 0;

    std::map<int, int> countA;
    std::map<int, int> countB;

    for (int i = 0; i < size; i++) {
        countB[ListB[i]]++; 
    }

    for (int number : ListA) {

        total += (number * countB[number]);
    }

    printf("Total: %d\n", total);

    return 0;
}