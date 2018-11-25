#include "Date.h"

void Date::recalcTimebyDate() {
    mTime = (mYear - 1) * 365 + mDay - 1;
    for (int m = 1; m < mMonth; ++m) {
        mTime += daysInMonth[m];
    }
}

void Date::recalcDatebyTime() {
    int tmpTime = mTime;
    mYear = tmpTime / 365 + 1;
    tmpTime %= 365;
    int m;
    for (m = 1; m <= 12; ++m) {
        if (tmpTime < daysInMonth[m]) {
            break;
        }
        tmpTime -= daysInMonth[m];
    }
    mMonth = m;
    mDay = tmpTime + 1;
}

void Date::recalcIsAfter() {
    if (mTime < 0) {
        mTime = -mTime;
        mIsAfter = -1;
    } else {
        mIsAfter = 1;
    }
}

void Date::initMap() {
    daysInMonth[1] = 31;
    daysInMonth[2] = 28;
    daysInMonth[3] = 31;
    daysInMonth[4] = 30;
    daysInMonth[5] = 31;
    daysInMonth[6] = 30;
    daysInMonth[7] = 31;
    daysInMonth[8] = 31;
    daysInMonth[9] = 30;
    daysInMonth[10] = 31;
    daysInMonth[11] = 30;
    daysInMonth[12] = 31;
}

Date::Date(int d, int m, int y) {
    initMap();
    mDay = d;
    mMonth = m;
    mYear = y;
    if (mDay > 0 && mMonth > 0 && mYear > 0) {
        mIsAfter = 1;
    } else if (mDay < 0 && mMonth < 0 && mYear < 0) {
        mIsAfter = -1;
        mDay = -mDay;
        mMonth = -mMonth;
        mYear = -mYear;
    } else {
        std::cout << "incorrect input" << std::endl;
    }
    recalcTimebyDate();
}

Date::Date(int t) {
    mTime = t;
    mIsAfter = 1;
    if (mTime < 0) {
        mIsAfter = -1;
        mTime = -mTime;
    }
    initMap();
    recalcDatebyTime();
}

Date::~Date() = default;

Date::Date(const Date &other) {
    initMap();
    mTime = other.mTime;
    mIsAfter = other.mIsAfter;
    recalcDatebyTime();
}

Date &Date::operator=(const Date &other) {

    mTime = other.mTime;
    mIsAfter = other.mIsAfter;
    recalcDatebyTime();
    return *this;
}

std::istream &operator>>(std::istream &in, Date &date) {
    int d, m, y;
    std::cin >> d >> m >> y;
    date = Date(d, m, y);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
    std::cout << date.mDay << '.' << date.mMonth << '.' << date.mYear << "   " << date.mTime;
    if (date.mIsAfter == 1) {
        std::cout << "  after" << std::endl;
    } else {
        std::cout << "  before" << std::endl;

    }
    return out;
}

Date &Date::operator+=(const Date &other) {
    mTime = mIsAfter * mTime + other.mIsAfter * other.mTime;
    recalcIsAfter();
    recalcDatebyTime();
    return *this;
}

Date &Date::operator-=(const Date &other) {
    mTime = mIsAfter * mTime - other.mIsAfter * other.mTime;
    recalcIsAfter();
    recalcDatebyTime();
    return *this;
}

Date &Date::operator*=(const Date &other) {
    mTime = mIsAfter * mTime * other.mIsAfter * other.mTime;
    recalcIsAfter();
    recalcDatebyTime();
    return *this;
}

Date &Date::operator/=(const Date &other) {
    if (other.mTime != 0) {
        mTime = mIsAfter * mTime / other.mIsAfter * other.mTime;
        recalcIsAfter();
        recalcDatebyTime();
    }
    return *this;
}

Date &Date::operator%=(const Date &other) {
    if (other.mTime != 0) {
        mTime = mIsAfter * mTime % other.mIsAfter * other.mTime;
        recalcIsAfter();
        recalcDatebyTime();
    }
    return *this;
}

Date Date::operator+(const Date &other) {
    Date tmp(*this);
    tmp += other;
    return tmp;
}

Date Date::operator+() const {
    return *this;
}

Date Date::operator-() const {
    return Date(-this->mDay, -this->mMonth, -this->mYear);
}

Date Date::operator!() const {
    return -(*this);
}

Date Date::operator-(const Date &other) {
    Date tmp(*this);
    tmp -= other;
    return tmp;
}

Date Date::operator*(const Date &other) {
    Date tmp(*this);
    tmp *= other;
    return tmp;
}

Date Date::operator/(const Date &other) {
    Date tmp(*this);
    tmp /= other;
    return tmp;
}

Date Date::operator%(const Date &other) {
    Date tmp(*this);
    tmp %= other;
    return tmp;
}

Date &Date::operator|=(const Date &other) {
    mTime = mIsAfter * mTime | other.mIsAfter * other.mTime;
    recalcIsAfter();
    recalcDatebyTime();
    return *this;
}

Date &Date::operator^=(const Date &other) {
    mTime = mIsAfter * mTime ^ other.mIsAfter * other.mTime;
    recalcIsAfter();
    recalcDatebyTime();
    return *this;
}

Date &Date::operator&=(const Date &other) {
    mTime = mIsAfter * mTime & other.mIsAfter * other.mTime;
    recalcIsAfter();
    recalcDatebyTime();
    return *this;
}

Date &Date::operator~() {
    mIsAfter = -mIsAfter;
    return *this;
}

Date Date::operator|(const Date &other) {
    Date tmp(*this);
    tmp |= other;
    return tmp;
}

Date Date::operator^(const Date &other) {
    Date tmp(*this);
    tmp ^= other;
    return tmp;
}

Date Date::operator&(const Date &other) {
    Date tmp(*this);
    tmp &= other;
    return tmp;
}

Date &Date::operator++() {
    mTime++;
    recalcIsAfter();
    recalcDatebyTime();
    return *this;
}

const Date Date::operator++(int) {
    Date tmp(*this);
    ++(*this);
    return tmp;

}

Date &Date::operator--() {
    mTime--;
    recalcIsAfter();
    recalcDatebyTime();
    return *this;
}

const Date Date::operator--(int) {
    Date tmp(*this);
    --(*this);
    return tmp;
}

bool Date::operator==(const Date &rhs) const {
    return mTime == rhs.mTime && mIsAfter == rhs.mIsAfter;
}

bool Date::operator!=(const Date &rhs) const {
    return !(rhs == *this);
}

bool Date::operator<(const Date &rhs) const {
    return mIsAfter * mTime < rhs.mIsAfter * rhs.mTime;
}

bool Date::operator>(const Date &rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date &rhs) const {
    return !(rhs < *this);
}

bool Date::operator>=(const Date &rhs) const {
    return !(*this < rhs);
}

Date &Date::operator<<=(int years) {
    mTime = mIsAfter * mTime + years * 365;
    recalcIsAfter();
    recalcDatebyTime();
    return *this;
}

Date &Date::operator>>=(int years) {
    mTime = mIsAfter * mTime - years * 365;
    recalcIsAfter();
    recalcDatebyTime();
    return *this;
}

Date Date::operator<<(int years) {
    Date tmp(*this);
    tmp <<= years;
    return tmp;
}

Date Date::operator>>(int years) {
    Date tmp(*this);
    tmp >>= years;
    return tmp;
}

bool Date::operator&&(const Date &other) {
    return mIsAfter && other.mIsAfter;
}

bool Date::operator||(const Date &other) {
    return mIsAfter || other.mIsAfter;
}

int Date::operator[](size_t ind) const {
    if (ind == 0) {
        return mDay;
    } else if (ind == 1) {
        return mMonth;
    } else {
        return mYear;
    }
}

int Date::operator()(size_t ind) const {
    if (ind == 0) {
        return mDay;
    } else if (ind == 1) {
        return mMonth;
    } else {
        return mYear;
    }
}

Date::operator std::string() const {
    return std::to_string(mDay) + '.' + std::to_string(mMonth) + '.' + std::to_string(mYear);
}

const Date Date::operator,(Date &v2) {
    return *this;
}