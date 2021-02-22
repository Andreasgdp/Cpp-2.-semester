#include "Pi.h"
#include <math.h>

Pi::Pi() {

}

Pi::Pi(int order) {
    mOrder = order;
}

double Pi::calcPi() {
    for (int i = 0; i < mOrder; i++) {
        mPi += pow(-1, i) * (1 / (2 * i + 1));
    }

    return mPi *= 4;
}
