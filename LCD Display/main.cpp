#include <iostream>
#include <string>
#include <vector>

//Methods
std::vector<std::string> prompt_input();
void create_map_from_data_and_display(std::vector<std::string> theData);
void write_some_data_to_map(std::vector<std::vector<char>>& dest_map, std::string& some_data);
void write_char_to_map(std::vector<std::vector<char>>& dest_map, char&, int startPoint);
void draw_number_segment(std::vector<std::vector<char>>& dest_map, int segment_type, int row);
void remove_size_part(std::string& some_data);
void display();
bool is_input_line_valid(std::string& input_line);
bool is_number(char c);

//Attributes
int start_point = 0;
int sizeOfDigit = 6;
int width;
int height;
std::vector<std::string> all_data;
std::vector<std::vector<char>> map;

int main() {
    all_data = prompt_input();
    create_map_from_data_and_display(all_data);
    system("pause");
    return 0;
}

void create_map_from_data_and_display(std::vector<std::string>& data) {

    for (std::string& some_data : data) {

        sizeOfDigit = atoi(&std::string(some_data, 0, 1)[0]);

        remove_size_part(some_data);

        height = (2 * sizeOfDigit) + 3;
        width = (((sizeOfDigit + 2) + 1) * some_data.length()) - 1 + 5;

        map = std::vector<std::vector<char>>(height, std::vector<char>(width));

        write_some_data_to_map(map, some_data);

        display();
    }
}

//This writes an entire string to the map, character by character, it also passes the index of the character as an argument to write_to_char so that
//the write_to_char method should calculate start_point so that different characters are written on different locations on the map
void write_some_data_to_map(std::vector<std::vector<char>>& dest_map, std::string& some_data) {
    for (unsigned int i = 0; i < some_data.length(); i++) {
        write_char_to_map(dest_map, some_data[i], i);
    }

}

//This uses the draw_number_segment method to draw segments in a particular order so as to draw a full number
void write_char_to_map(std::vector<std::vector<char>>& dest_map, char& c, int index) {
    start_point = (index * (sizeOfDigit + 3));
    switch (c) {
    case '0':
        draw_number_segment(dest_map, 1, 0);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 5, i + 1);
        }
        draw_number_segment(dest_map, 2, sizeOfDigit + 1);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 5, sizeOfDigit + 1 + i + 1);
        }
        draw_number_segment(dest_map, 1, (sizeOfDigit * 2) + 2);
        draw_number_segment(dest_map, 6, 0);
        break;
    case '1':
        draw_number_segment(dest_map, 2, 0);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 4, i + 1);
        }
        draw_number_segment(dest_map, 2, sizeOfDigit + 1);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 4, sizeOfDigit + 1 + i + 1);
        }
        draw_number_segment(dest_map, 2, (sizeOfDigit * 2) + 2);
        draw_number_segment(dest_map, 6, 0);
        break;
    case '2':
        draw_number_segment(dest_map, 1, 0);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 4, i + 1);
        }
        draw_number_segment(dest_map, 1, sizeOfDigit + 1);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 3, sizeOfDigit + 2 + i);
        }
        draw_number_segment(dest_map, 1, (sizeOfDigit * 2) + 2);
        draw_number_segment(dest_map, 6, 0);
        break;
    case '3':
        draw_number_segment(dest_map, 1, 0);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 4, i + 1);
        }
        draw_number_segment(dest_map, 1, sizeOfDigit + 1);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 4, sizeOfDigit + 2 + i);
        }
        draw_number_segment(dest_map, 1, (sizeOfDigit * 2) + 2);
        break;
    case '4':
        draw_number_segment(dest_map, 2, 0);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 5, i + 1);
        }
        draw_number_segment(dest_map, 1, sizeOfDigit + 1);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 4, sizeOfDigit + 2 + i);
        }
        break;
    case '5':
        draw_number_segment(dest_map, 1, 0);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 3, i + 1);
        }
        draw_number_segment(dest_map, 1, sizeOfDigit + 1);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 4, sizeOfDigit + 2 + i);
        }
        draw_number_segment(dest_map, 1, (sizeOfDigit * 2) + 2);
        break;
    case '6':
        draw_number_segment(dest_map, 1, 0);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 3, i + 1);
        }
        draw_number_segment(dest_map, 1, sizeOfDigit + 1);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 5, sizeOfDigit + 2 + i);
        }
        draw_number_segment(dest_map, 1, (sizeOfDigit * 2) + 2);
        break;
    case '7':
        draw_number_segment(dest_map, 1, 0);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 4, i + 1);
        }
        draw_number_segment(dest_map, 2, sizeOfDigit + 1);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 4, sizeOfDigit + 2 + i);
        }
        draw_number_segment(dest_map, 2, (sizeOfDigit * 2) + 2);
        break;
    case '8':
        draw_number_segment(dest_map, 1, 0);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 5, i + 1);
        }
        draw_number_segment(dest_map, 1, sizeOfDigit + 1);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 5, sizeOfDigit + 2 + i);
        }
        draw_number_segment(dest_map, 1, (sizeOfDigit * 2) + 2);
        break;
    case '9':
        draw_number_segment(dest_map, 1, 0);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 5, i + 1);
        }
        draw_number_segment(dest_map, 1, sizeOfDigit + 1);
        for (int i = 0; i < sizeOfDigit; i++) {
            draw_number_segment(dest_map, 4, sizeOfDigit + 2 + i);
        }
        draw_number_segment(dest_map, 1, (sizeOfDigit * 2) + 2);
        break;

    default:
        break;
    }
}

//A number has different parts (eg a '1' has two vertical parts and a '5' has two vertical parts and three horizontal parts)
// This method draws a single part of a number to a position on the map designated by the row and the start_point
//Draws a part of a number (eg the upper part of a number)
//segemnt_type determines the pattern of the part of the number, the supported segments are:
//1 - ' --- '
//2 - '     '
//3 - '|    '
//4 - '    |'
//5 - '|   |'
//6 - space
void draw_number_segment(std::vector<std::vector<char>>& dest_map, int segment_type, int row) {
    switch (segment_type) {
    case 1:
        dest_map[row][start_point + 0] = ' ';
        for (int i = 0; i < sizeOfDigit; i++) {
            dest_map[row][start_point + i + 1] = '-';
        }
        dest_map[row][start_point + sizeOfDigit + 1] = ' ';
        break;
    case 2:
        dest_map[row][start_point + 0] = ' ';
        for (int i = 0; i < sizeOfDigit; i++) {
            dest_map[row][start_point + i + 1] = ' ';
        }
        dest_map[row][start_point + sizeOfDigit + 1] = ' ';
        break;
    case 3:
        dest_map[row][start_point + 0] = '|';
        for (int i = 0; i < sizeOfDigit; i++) {
            dest_map[row][start_point + i + 1] = ' ';
        }
        dest_map[row][start_point + sizeOfDigit + 1] = ' ';
        break;
    case 4:
        dest_map[row][start_point + 0] = ' ';
        for (int i = 0; i < sizeOfDigit; i++) {
            dest_map[row][start_point + i + 1] = ' ';
        }
        dest_map[row][start_point + sizeOfDigit + 1] = '|';
        break;
    case 5:
        dest_map[row][start_point + 0] = '|';
        for (int i = 0; i < sizeOfDigit; i++) {
            dest_map[row][start_point + i + 1] = ' ';
        }
        dest_map[row][start_point + sizeOfDigit + 1] = '|';
        break;
    case 6:
        break;
        for (int i = 0; i < height; i++) {
            dest_map[i][start_point + 5] = ' ';
        }
        break;
    default:
        break;
    }
}

//Prompt the user for input until the user enters '0 0', then return the input
std::vector<std::string> prompt_input() {
    std::string input_line;
    std::vector<std::string> input;
    while (true) {
        //I use getline insted of 'cin << temp' because the when you type, say, 3 564432, the 'cin << temp' reads this as two seperate lines of input '3' and '564432'
        //this makes the implementation of 'create_map_from_data_and_dispaly' harder, so getline should be used so that the entire '3 564432' is read as a simgle line of input
        std::getline(std::cin, input_line);
        if (!is_input_line_valid(input_line)) {
            std::cout << "\tUsage: [size of number(s)] [number(s)]\n\tenter '0 0' to stop entering and see results\n";
            break;
            EXIT_FAILURE;
        }
        if (input_line == "0 0") break;
        input.push_back(input_line);
    }
    return input;
}

//Check input_line to make sure it's in the right format and doesn't contain any letters
bool is_input_line_valid(std::string& input_line) {
    bool has_size = false;
    bool has_space = false;
    bool has_number = false;
    bool has_invalid_char;
    for (int i = 0; i < input_line.length(); i++) {
        if (input_line[i] == ' ') has_space = true;
        if (has_space) {
            if (is_number(input_line[i - 1]) && is_number(input_line[i + 1])) {
                has_number = true;
                has_size = true;
            }
        }
    }
    if (has_number && has_size && has_space) {
        return true;
    }
    return false;
}

//Checks if c is a character that can be converted to a number
bool is_number(char c) {
    char numbers[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
    for (char& number : numbers) {
        if (c == number) return true;
    }
    return false;
}
//Removes the part of the string that specifies what the size of the numbers
void remove_size_part(std::string& some_data) {
    for (int i = 0; i < some_data.length(); i++) {
        if (some_data[i] == ' ') {
            some_data = std::string(some_data, i + 1, some_data.length() - i);
        }
    }
}

//Print all contents currently in the map to the console
void display() {
    for (int i = 0; i < map.size(); i++) {
        for (int e = 0; e < map[i].size(); e++) {
            std::cout << map[i][e];
        }
        std::cout << "\n";
    }
}
