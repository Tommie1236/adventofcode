#include <iostream>
#include <fstream>
#include <sstream>


int main() {

    std::ifstream file("../inputs/data02.txt");
    std::string line;

    int reports[1000][8] = {0};
    int idx = 0;

    int save = 0;
    int unsave = 0;

    while (std::getline(file, line)) {

        std::stringstream ss(line);

        std::string part;

        int jdx = 0;

        while (std::getline(ss, part, ' ')) {
            reports[idx][jdx] = std::stoi(part);
            jdx++;
        }
            
        
        idx++;
    }

    /*int reports[6][5] = {
        {7, 6, 4, 2, 1},
        {1, 2, 7, 8, 9},
        {9, 7, 6, 2, 1},
        {1, 3, 2, 4, 5},
        {8, 6, 4, 4, 1},
        {1, 3, 6, 7, 9}};*/

    for (int i = 0; i < 1000; i++) {
        bool direction = reports[i][1] - reports[i][0] > 0;
        
        bool is_save = 1;
        for (int j = 0; j < 7; j++) {
            if (reports[i][j + 1] == 0) {
                break;
            }

            // unsave if the direction changes
            if (direction != (reports[i][j + 1] - reports[i][j] > 0)) {
                is_save = 0;
                break;
            }
            // unsave if both items are the same
            if (reports[i][j + 1] == reports[i][j]) {
                is_save = 0;
                break;
            }
            // unsave if the difference is smaller than 1 or greater than 3
            if (abs(reports[i][j + 1] - reports[i][j]) > 3) {
                is_save = 0;
                break;
            }

        }
        if (is_save) {
            save++;
        } else {
            unsave++;
        }

    }



    printf("Save: %d\n", save);
    printf("Unsave: %d\n", unsave);
    printf("Total: %d\n", save + unsave);

    return 0;
}