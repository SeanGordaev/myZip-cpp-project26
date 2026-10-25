#include "myZip.h"
#include <bitset>

using namespace std;

bool equalsBytes(const vector<bool>& Bite1, const vector<bool>& Bite2) {
    for (int i = 0; i < 8; i++) {
        if (Bite1[i] != Bite2[i])
            return false;
    }
    return true;
}

vector<bool> sliceBits(const vector<bool>& bits, int start) {
    auto S = bits.begin() + start;
    auto E = bits.begin() + start + 8;
    vector<bool> subBite(E - S);
    copy(S, E, subBite.begin());

    return subBite;
}

vector<pair<vector<bool>, int>> counterDuplicateBytes(const vector<bool>& bits) {

    vector<pair<vector<bool>, int>> Duplicate;

    for (int i = 0; i < bits.size(); i += 8) {
        int count = 0;

        vector<bool> subBite1 = sliceBits(bits, i);

        for (int j = 0; j < bits.size(); j += 8) {
            vector<bool> subBite2 = sliceBits(bits, j);

            if (equalsBytes(subBite1, subBite2)) {
                if (i != j) {
                    i += 8;
                }
                count++;
            }
        }

        pair<vector<bool>, int> P;
        P.first = subBite1;
        P.second = count;
        Duplicate.push_back(P);
    }

    return Duplicate;

}

void sortedCounderDuplicateBytes(vector<pair<vector<bool>, int>>& duplicates) {
    sort(duplicates.begin(), duplicates.end(), [](const pair<vector<bool>, int>& a, const pair<vector<bool>, int>& b) {
        return a.second < b.second;
    });
}

void createTree(const vector<pair<vector<bool>, int>>& duplicates) {

}

void myZip(vector<bool> bits) {

}
