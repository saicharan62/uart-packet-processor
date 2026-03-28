#ifndef PACKET_PARSER_H
#define PACKET_PARSER_H

#include <fstream>

bool parsePacket(std::ifstream &file, int &id, int &value, int &checksum);

#endif