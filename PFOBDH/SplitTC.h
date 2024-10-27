#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

void SplitTC(int* time, std::string* dtime, char* sequence, std::string* targetstr, char* targetf, std::string* commandstr, char* commandf, std::string* argumentstr, char* argumentf, int* argumentt, char telecommand[64]);