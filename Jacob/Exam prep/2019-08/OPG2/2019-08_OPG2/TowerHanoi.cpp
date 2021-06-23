#include "TowerHanoi.h"
#include <iostream>
#include <iomanip>

TowerHanoi::TowerHanoi(unsigned int height) {
    mHeight = height;
    mPegs[0] = std::vector<unsigned int>(mHeight);
    for (unsigned int i = 0; i < mHeight; ++i) {
        mPegs[0][i] = mHeight - i;
    }
}
void TowerHanoi::move() {
    if (mHeight == mPegs[0].size()) {
        move(mHeight, 0, 1, 2);
    } else {
        std::cout << "Error: Tower already moved" << std::endl;
    }
}

void TowerHanoi::move(unsigned int disks, unsigned int source, unsigned int aux, unsigned int dest) {
    if (disks == 1) {
        // TODO: move disk from source to dest
        mPegs[dest].push_back(mPegs[source].back());
        mPegs[source].pop_back();
        printTower();
    } else {
        move(disks - 1, source, dest, aux); // Step 1
        // TODO: move disk from source to dest
        mPegs[dest].push_back(mPegs[source].back());
        mPegs[source].pop_back();
        printTower();
        move(disks - 1, aux, source, dest); // Step 3
    }
}

void TowerHanoi::printTower() {
    for (unsigned int i = mHeight; i > 0; --i) {
        for (unsigned int j = 0; j < 3; ++j) {
            if (mPegs[j].size() >= i) {
                std::cout << std::right << std::setw(mHeight+2) << generateDisk(mPegs[j][i-1]);
                std::cout << std::left << std::setw(mHeight+2) << generateDisk(mPegs[j][i-1]);
            } else {
                std::cout << std::left << std::setw(2*(mHeight+2)) << " ";
            }

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::string TowerHanoi::generateDisk(unsigned int width) {
    std::string res;
    for(unsigned int i = 0; i < width; ++i)
        res.append("*");

    return res;
}
