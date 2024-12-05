#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>


// 0 1 2
// 3 X 4
// 5 6 7
std::vector<std::pair<int, int>> directions = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};

bool is_valid_coord(int x, int y) {
    return x >= 0 && x < 140 && y >= 0 && y < 140;
}





int main() {

    std::ifstream file("../inputs/data04.txt");
    std::string line;

    char wordsearch[140][140];

    int idx = 0;
    int jdx = 0;

    while (std::getline(file, line)) {
        char cline[141]; 
        strcpy(cline, line.c_str());
        memcpy(wordsearch[idx], cline, 140);
        idx++;
    }
    
    // find all X's
    std::vector<std::pair<int, int>> coords_x;

    for (int i = 0; i < 140; i++) {
        for (int j = 0; j < 140; j++) {
            if (wordsearch[i][j] == 'X') {
                coords_x.push_back({i, j});
            }
        }       
    }

    int times_found = 0;

    for (std::pair<int, int> coord : coords_x) {


        for (std::pair<int, int> dir : directions) {
            int current_char = 1;   // already found an X
            while (current_char != 0) {

                if (is_valid_coord(dir.first * current_char + coord.first, dir.second * current_char + coord.second)) {

                    switch (current_char) {
                        case 1:
                            if (wordsearch[dir.first * current_char + coord.first][dir.second * current_char + coord.second] == 'M') {
                                current_char = 2;
                            } else {
                                current_char = 0;
                            }
                            break;
                        case 2:
                            if (wordsearch[dir.first * current_char + coord.first][dir.second * current_char + coord.second] == 'A') {
                                current_char = 3;
                            } else {
                                current_char = 0;
                            }
                            break;
                        case 3:
                            if (wordsearch[dir.first * current_char + coord.first][dir.second * current_char + coord.second] == 'S') {
                                current_char = 4;
                            } else {
                                current_char = 0;
                            }
                            break;

                    }

                    if (current_char == 4) {
                        times_found++;
                        current_char = 0;
                    }
                } else {
                    current_char = 0;
                }
            }
        }        

    }

    printf("Times found: %d\n", times_found);

    return 0;
}
