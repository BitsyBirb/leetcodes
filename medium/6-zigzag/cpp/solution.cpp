#include <string>
#include <vector>
#include <iostream>

std::string convert(std::string s, int numRows) {
        // Just push back in each string vector
        // Note that no diagonals exist with rows=1 or rows=2
        // Probably a better way of handling it. maybe.
        if(numRows==1) return s;
        if(numRows==2){
            std::string guh = "";
            std::string hug = "";
            bool flip = false;
            for(int i = 0; i < s.length(); i++){
                if(flip) hug+=s[i];
                else guh+=s[i];
                flip=!flip;
            }
            return guh+hug;
        }

        // Here we actually have diagonals
        std::vector<std::string> rows;
        rows.resize(numRows);
        for(int i = 0; i < rows.size(); i++) rows[i]="";
        
        int row = 0;
        bool bounce = false;
        for(int i = 0; i < s.length(); i++){
            std::cout << "Storing '" << s[i] << "' into row #" << row << "\n";
            rows[row] += s[i]; //apend char that occurs on row
            if(!bounce){
                row++;
                if(row == numRows){
                    bounce = true;
                    row-=2;
                }
            }
            else{
                row--;
                if(row < 0){
                    row = 1;
                    bounce = false;
                }
            }
        }
        std::string final = "";
        for(int i = 0; i < rows.size(); i++){
            final+=rows[i];
        }
        return final;
    }

int main(int argc, char** argv){
    std::cout << "Input string: ";
    std::string input;
    std::cin >> input;
    std::cout << "Number of rows: ";
    int numba =0;
    std::cin >> numba; 
    std::string result = convert(input, numba);

    std::cout << "Final result is: " << result << std::endl; //flush

    return 0;
}