#include "calendar.h"

Calendar::Calendar() : gregorianMonthsLength{31,28,31,30,31,30,31,31,30,31,30,31} {
  crtCalendarType = gregorian;
}

void Calendar::setDefaultType(calendarTypes calendarType) {
  crtCalendarType = calendarType;
}

void Calendar::getCurrentDate(int& DD, int& MM, int& YYYY) {
  if(crtCalendarType == indian)
    toIndian();

  DD = this->DD;
  MM = this->MM;
  YYYY = this->YYYY;

  toGregorian();
}

void Calendar::setCurrentDate(const int DD, const int MM, const int YYYY) {
  this->DD = DD;
  this->MM = MM;
  this->YYYY = YYYY;
}

void Calendar::incrementDate() {
  bool isLeapYear = leapYear();

  if(isLeapYear)
    ++gregorianMonthsLength[1];

  ++DD;
  if(DD > gregorianMonthsLength[MM-1]) {
    DD = 1;
    ++MM;
    if(MM > 12) {
      MM = 1;
      ++YYYY;
    }
  }

  if(isLeapYear)
    --gregorianMonthsLength[1];
}

void Calendar::decrementDate() {
  bool isLeapYear = leapYear();

  if(isLeapYear)
    ++gregorianMonthsLength[1];

  --DD;
  if(DD == 0) {
    --MM;
    if(MM == 0) {
      MM = 12;
      --YYYY;
    }
    DD = gregorianMonthsLength[MM-1];
  }

  if(isLeapYear)
    --gregorianMonthsLength[1];
}

void Calendar::incrementHour() {
  ++HH;
  if(HH == 24) {
    HH = 0;
    incrementDate();
  }
}

void Calendar::decrementHour() {
  --HH;
  if(HH == -1) {
    HH = 23;
    decrementDate();
  }
}

void Calendar::toGregorian() {
  if(crtCalendarType == indian) {
    YYYY += 77;
    for(int i=1;i<=110;++i)
      incrementDate();
  }
}

void Calendar::toIndian() {
  YYYY -= 77;
  for(int i=1;i<=110;++i)
    decrementDate();
}

bool Calendar::leapYear() {
  if(YYYY % 400 == 0)
    return true;
  if(YYYY % 4 == 0 && YYYY % 100 != 0)
    return true;
  return false;
}
