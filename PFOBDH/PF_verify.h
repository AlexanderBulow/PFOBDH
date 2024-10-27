#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

void PF_verify(int* time, std::string* dtime, int clock, char sequence[64], std::string targetstr, std::string commandstr, std::string argumentstr, int argumentt, int* previousseqcount, int* currentcount, int* valid, char telecommand[64]);