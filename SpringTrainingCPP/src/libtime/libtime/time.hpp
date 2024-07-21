#pragma once

#include <iomanip>
#include <iostream>

namespace csctime {
class TimeSpan {
 private:
  long int seconds;

 public:
  explicit TimeSpan(long int s = 0) : seconds(s){};

  long int getSeconds() const {
    return seconds;
  }

  constexpr bool operator==(const TimeSpan& other) const noexcept {
    return seconds == other.seconds;
  }

  constexpr bool operator!=(const TimeSpan& other) const noexcept {
    return !(seconds == other.seconds);
  }

  constexpr bool operator<(const TimeSpan& other) const noexcept {
    return seconds < other.seconds;
  }

  constexpr bool operator>(const TimeSpan& other) const noexcept {
    return other.seconds < seconds;
  }

  constexpr bool operator<=(const TimeSpan& other) const noexcept {
    return !(seconds < other.seconds);
  }

  constexpr bool operator>=(const TimeSpan& other) const noexcept {
    return !(other.seconds < seconds);
  }

  TimeSpan operator+(const TimeSpan& other) const {
    const long int result = seconds + other.seconds;
    return TimeSpan(result);
  }

  TimeSpan operator-(const TimeSpan& other) const {
    const long int result = seconds - other.seconds;
    return TimeSpan(result);
  }

  friend std::ostream& operator<<(std::ostream& os, const TimeSpan& t) {
    long int secs = t.getSeconds();
    const long int days = secs / 86400;
    secs %= 86400;
    const long int hours = secs / 3600;
    secs %= 3600;
    const long int minutes = secs / 60;
    secs %= 60;
    os << std::setfill('0') << std::setw(2) << days << "d" << std::setw(2)
       << std::setfill('0') << std::setw(2) << hours << "h" << std::setw(2)
       << std::setfill('0') << std::setw(2) << minutes << "m" << std::setw(2)
       << std::setfill('0') << std::setw(2) << secs << "s" << std::setw(2);
    return os;
  }
};

class Time {
 private:
  long int seconds;

 public:
  explicit Time(long int s = 0) : seconds(s){};

  long int getSeconds() const {
    return seconds;
  }

  constexpr bool operator==(const Time& other) const noexcept {
    return seconds == other.seconds;
  }

  constexpr bool operator!=(const Time& other) const noexcept {
    return !(seconds == other.seconds);
  }

  constexpr bool operator<(const Time& other) const noexcept {
    return seconds < other.seconds;
  }

  constexpr bool operator>(const Time& other) const noexcept {
    return other.seconds < seconds;
  }

  constexpr bool operator<=(const Time& other) const noexcept {
    return !(seconds < other.seconds);
  }

  constexpr bool operator>=(const Time& other) const noexcept {
    return !(other.seconds < seconds);
  }

  Time operator+(const TimeSpan& other) const {
    const long int result = seconds + other.getSeconds();
    return Time(result);
  }

  TimeSpan operator-(const Time& other) const {
    const long int result = seconds - other.getSeconds();
    return TimeSpan(result);
  }

  Time operator-(const TimeSpan& other) const {
    const long int result = seconds - other.getSeconds();
    return Time(result);
  }

  friend std::ostream& operator<<(std::ostream& os, const Time& t) {
    long int secs = t.getSeconds();
    const long int days = secs / 86400;
    secs %= 86400;
    const long int hours = secs / 3600;
    secs %= 3600;
    const long int minutes = secs / 60;
    secs %= 60;
    os << std::setfill('0') << std::setw(2) << days << "d" << std::setw(2)
       << std::setfill('0') << std::setw(2) << hours << "h" << std::setw(2)
       << std::setfill('0') << std::setw(2) << minutes << "m" << std::setw(2)
       << std::setfill('0') << std::setw(2) << secs << "s" << std::setw(2);
    return os;
  }
};

namespace literals {
inline Time operator""_d(unsigned long long d) {
  return Time(static_cast<long int>(d * 86400));
}

inline Time operator""_h(unsigned long long h) {
  return Time(static_cast<long int>(h * 3600));
}

inline Time operator""_m(unsigned long long m) {
  return Time(static_cast<long int>(m * 60));
}

inline Time operator""_s(unsigned long long s) {
  return Time(static_cast<long int>(s));
}
}  // namespace literals
}  // namespace csctime