#include "journey.h"

int const MIN_IN_HOUR = 60, HOURS_IN_DAY = 24;
int const MIN_IN_DAY = MIN_IN_HOUR * HOURS_IN_DAY;

int Journey::convertStrDateToInt(std::string& time) const {
    int ans = MIN_IN_HOUR * (10 * (time[0] - '0') + (time[1] - '0'));
    ans += (time[3] - '0') * 10 + (time[4] - '0');
    return ans;
}

std::string convertNumToStr(int& num) {
    return "" + (char)('0' + (num / 10)) + ('0' + (num % 10));
}

std::string convertIntDateToStr(int& time) {
    int minutes = time % MIN_IN_DAY;
    int hours = (time / MIN_IN_DAY) % HOURS_IN_DAY;
    return
}

std::string Journey::newTime(std::string& oldTime, int time) const {
    return "";
}