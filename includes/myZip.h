#pragma once
#include <vector>
#include "struct.h"
#include <algorithm>
#include <string> 
#include <map> 


bool equalsBytes(const std::vector<bool>& Bite1, const std::vector<bool>& Bite2);

std::vector<bool> sliceBits(const std::vector<bool>& bits, int start);

std::vector<std::pair<std::vector<bool>, int>> counterDuplicateBytes(const std::vector<bool>& bits);

void sortedCounterDuplicateBytes(std::vector<std::pair<std::vector<bool>, int>>& duplicates);

Node* createTree(const std::vector<std::pair<std::vector<bool>, int>>& duplicates);

void treeCode(std::map<std::vector<bool>, std::string>& dict, const Node* root, std::string code = "");

void myZip(std::vector<bool> bits);
