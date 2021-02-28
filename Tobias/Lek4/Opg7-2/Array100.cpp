#include "Array100.h"
#include <ctime>
#include <random>
#include <iostream>



Array100::Array100()
{

}

void Array100::Fill(int min, int max) {
    std::default_random_engine engine{static_cast<unsigned int>(time(0))};
        std::uniform_int_distribution<int> random{min, max};
        for (size_t i = 0; i < mArray.size(); i++) {
            mArray[i] = random(engine);
        }
}

void Array100::Print() {
    for(size_t i = 0; i < mArray.size(); i++) {
        std::cout << i << ": " << mArray[i] << std::endl;
    }
}
