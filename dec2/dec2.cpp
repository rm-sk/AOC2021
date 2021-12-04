#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    //input validation
    if (argc<2){
        cerr << "Please provide an input file." << endl;
        return -1;
    }

    ifstream input(argv[1]);

    //input parsing
    vector<string> direction;
    vector<string> value;
    string temp_input;

    while (input)
    {
        input >> temp_input;
        direction.push_back(temp_input);
        input >> temp_input;
        value.push_back(temp_input);
    }

    vector<int> valueint;

    for (int i=0; i<value.size(); i++){
        valueint.push_back(stoi(value[i]));
    }

    //part 1 - depth, horizontal
    int hor = 0;
    int depth = 0;

    for (int i=0; i<direction.size(); i++){
        if (direction[i]=="forward"){
            hor+=valueint[i];
        }
        else if(direction[i]=="up"){
            depth-=valueint[i];
        }
        else if(direction[i]=="down"){
            depth+=valueint[i];
        }
    }

    int mult = depth*hor;

    cout << mult << endl;


    //part 2 - depth, horizontal, aim

    hor = 0;
    depth = 0;
    int aim = 0;

    for (int i=0; i<direction.size(); i++){
        if (direction[i]=="forward"){
            hor+=valueint[i];
            depth+=aim*valueint[i];
        }
        else if(direction[i]=="up"){
            aim-=valueint[i];
        }
        else if(direction[i]=="down"){
            aim+=valueint[i];
        }
    }

    mult = depth*hor;

    cout << mult << endl;



    return 0;
}
