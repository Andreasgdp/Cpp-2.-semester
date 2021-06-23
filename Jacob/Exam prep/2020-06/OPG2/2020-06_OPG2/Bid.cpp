#include "Bid.h"

bool Bid::operator<(const Bid &rhs) {
    return (mPriority < rhs.mPriority);
}
