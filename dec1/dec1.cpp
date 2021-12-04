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
    vector<string> sonar;
    string temp_input;

    while (input)
    {
        input >> temp_input;
        sonar.push_back(temp_input);
    }

    vector<int> sonarint;

    for (int i=0; i<sonar.size(); i++){
        sonarint.push_back(stoi(sonar[i]));
    }

    //part 1 - check whether depth increases
    int increased = 0;

    for (int i=1; i<sonarint.size(); i++){
        if (sonarint[i-1]<sonarint[i]){
            increased++;
        }
    }

    //part 2 - check if window increases
    vector<int> sums;

    int max = sonarint.size()-(sonarint.size()%3);
    int tempsum;

    for (int i=2; i<max-1; i++){
        tempsum = sonarint[i]+sonarint[i-1]+sonarint[i-2];
        sums.push_back(tempsum);
        tempsum = 0;
    }

    int sumsincreased = 0;

    for (int i=1; i<sums.size(); i++){
        cout << sums[i] << endl;
        if (sums[i-1]<sums[i]){
            sumsincreased++;
            // cout << "i: " << i << endl;
        }
    }

    cout << max << endl;
    cout << sums.size() << endl;
    cout << sumsincreased << endl;


    return 0;
}
