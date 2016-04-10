#ifndef CALENDAR_H
#define CALENDAR_H

enum calendarTypes {
  gregorian = 0,
  indian = 1
};

class Calendar {
  calendarTypes crtCalendarType;

  int HH, DD, MM, YYYY;

public:

  Calendar();

  void setDefaultType(calendarTypes);

  void getCurrentDate(int& DD, int& MM, int& YYYY);
  void setCurrentDate(const int DD, const int MM, const int YYYY);

  void incrementDate();
  void decrementDate();

  void incrementHour();
  void decrementHour();

private:

  int gregorianMonthsLength[12];

  void toGregorian();
  void toIndian();

  bool leapYear();
  
};

#endif // CALENDAR_H
