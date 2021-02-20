#include <iostream>
using namespace std;
 
int findDays(int year , int month)  // number of days in a given month for a given year
{
  bool leap;
  if (!(year%400)) {leap=true;}
  else if (!(year%4)&&(year%100)) {leap=true;}
  else {leap=false;}
  
  switch(month) {
    case 1: return 31;
    case 2: return 28+leap;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
  }
}