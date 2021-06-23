#ifndef TOWERHANOI_H
#define TOWERHANOI_H
#include <vector>
#include <string>

class TowerHanoi
{
public:
    TowerHanoi(unsigned int height = 3);
    void move();

private:
    void move(unsigned int disks, unsigned int source, unsigned int aux, unsigned int dest);
    void printTower();
    std::string generateDisk(unsigned int width);

    unsigned int mHeight;
    std::vector<unsigned int> mPegs[3];
};

#endif // TOWERHANOI_H
