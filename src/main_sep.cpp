#include <fstream>
#include <iostream>
#include "circular_buffer.h"

using namespace std;

int main(int argc, char* argv[]){
    if(argc < 3){
        cout << "Usage: ./processor <filename> <threshold>" << endl;
        return 1;
    }

    ifstream file(argv[1]);

    if(!file){
        cout << "Error: file does not exist" << endl;
        return 1;
    }

    int threshold;

    try {
        threshold = stoi(argv[2]);
    } catch(...) {
        cout << "Invalid threshold value" << endl;
        return 1;
    }

    ofstream logFile("output.txt");

    int packet_id, value, checksum;
    CircularBuffer cb;

    while(file >> packet_id >> value >> checksum){

        cb.add(value);

        if(checksum != (packet_id + value) % 2){
            logFile << "CORRUPTED PACKET ID: " << packet_id << endl;
        }

        if(value < 0){
            logFile << "INVALID VALUE: " << value << endl;
        }

        if(value > threshold){
            cout << "ALERT: " << value << endl;
            logFile << "ALERT: " << value << endl;
        }
    }

    cb.display();

    return 0;
}