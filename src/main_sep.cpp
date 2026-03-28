#include <fstream>
#include <iostream>
#include "circular_buffer.h"
#include "packet_parser.h"
#include "fault_detector.h"

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

    while(parsePacket(file, packet_id, value, checksum)){

        cb.add(value);

        if(isCorrupted(packet_id, value, checksum)){
            logFile << "CORRUPTED PACKET ID: " << packet_id << endl;
        }

        if(isInvalid(value)){
            logFile << "INVALID VALUE: " << value << endl;
        }

        if(isAlert(value, threshold)){
            cout << "ALERT: " << value << endl;
            logFile << "ALERT: " << value << endl;
        }
    }
    cb.display();

    return 0;
}