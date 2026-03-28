#include <fstream>
#include "packet_parser.h"

bool parsePacket(std::ifstream &file, int &id, int &value, int &checksum){
    return (bool)(file >> id >> value >> checksum);
}