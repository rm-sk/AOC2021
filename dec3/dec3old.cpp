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
    vector<string> binary;
    string temp_input;

    while (input)
    {
        input >> temp_input;
        binary.push_back(temp_input);
    }

    vector<int> binaryint;

    for (int i=0; i<binary.size(); i++){
        cout << binary[i] << endl;;
        binaryint.push_back(stoi(binary[i]));
    }


    //part 1

    int total = binaryint.size();

    int count1;
    int count2;
    int count3;
    int count4;

    int mod;

    int onecount;

    //count 1s in each bit
    for (int i=0; i<total; i++){
        mod = binaryint[i]%1000;
        count1 += mod;
        binaryint[i] = binaryint[i]-mod;

        mod = binaryint[i]%100;
        count2 += mod;
        binaryint[i] = binaryint[i]-mod;

        mod = binaryint[i]%10;
        count3 += mod;
        binaryint[i] = binaryint[i]-mod;

        mod = binaryint[i]%1;
        count4 += mod;
        binaryint[i] = binaryint[i]-mod;
    }


    // declare gamma and epsilon
    int gamma = 0;;
    int epsilon = 0;;

    if (count1>total/2) gamma += 1000;
    else epsilon += 1000;

    if (count2>total/2) gamma += 100;
    else epsilon += 100;

    if (count3>total/2) gamma += 10;
    else epsilon += 10;

    if (count4>total/2) gamma += 1;
    else epsilon += 1;


    //convert gamma and epsilon to decimal
    int gammadec = 0;
    int epsilondec = 0;

    for (int i=0; i<4; i++){
        //gamma first
        mod = gamma%1000;
        gammadec += mod*1;
        gamma = gamma-mod;

        mod = gamma%100;
        gammadec += mod*2;
        gamma = gamma-mod;

        mod = gamma%10;
        gammadec += mod*4;
        gamma = gamma-mod;

        mod = gamma%1;
        gammadec += mod*8;
        gamma = gamma-mod;

        //repeat for epsilon
        mod = epsilon%1000;
        epsilondec += mod*1;
        epsilon = epsilon-mod;

        mod = epsilon%100;
        epsilondec += mod*2;
        epsilon = epsilon-mod;

        mod = epsilon%10;
        epsilondec += mod*4;
        epsilon = epsilon-mod;

        mod = epsilon%1;
        epsilondec += mod*8;
        epsilon = epsilon-mod;
    }

    int mult = gammadec*epsilondec;

    cout << mult << endl;




    return 0;
}
