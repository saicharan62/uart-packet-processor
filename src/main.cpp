#include <fstream>
#include <iostream>
using namespace std;

class CircularBuffer {
private:
    static const int SIZE = 5;
    int buffer[SIZE];
    int index = 0;
    int count = 0;
    int start = 0;    
public:
    CircularBuffer() {
        for(int i=0; i<SIZE; i++){
            buffer[i] = 0;
        }
    }
    void add(int value){
        buffer[index] = value;

        if(count == SIZE){
            start = (start + 1) % SIZE;
        }
        else {
            count++;
        }
        index = (index + 1) % SIZE;
    }
    void display(){
        for(int i=0; i < count; i++){
            int idx = (start + i) % SIZE;
            cout << buffer[idx] << " ";
        }
        cout << endl;
    }
};

int main(int argc, char* argv[]){
    if(argc < 3){
        cout << "Usage: ./processor <filename> <threshold>";
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

    int packet_id;
    int value;
    int checksum;
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