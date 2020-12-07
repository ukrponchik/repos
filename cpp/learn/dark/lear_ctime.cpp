#include <ctime>
#include <iostream>
#include <locale>

int main() {
  // CLOCKS_PER_SEC - Кількість тіків у секунду
  std::cout << CLOCKS_PER_SEC << std::endl;

  std::clock_t a; // Зберігає кількість тіків (long)
  std::size_t b;  // Зберігає розмір (unsinged long)
  std::time_t c;  // Зберігає час у мс (long)
  std::tm d; // Зберігає детальну інформацію про час (tm)

  timespec e; // Зберігає секунди і наносекунди (timespec) ISO C++17

  // clock - повертає кількість мілісекунд,
  // які пройшли з початку запуску програми
  std::cout << std::clock() << std::endl; // Кількість секунд / CLOCKS_PER_SEC

  // time - повертає час, в секундах, який пройшов з 00:00 1 січня 1970
  time_t time1Since1970;
  time_t time2Since1970;
  time1Since1970 = std::time(&time2Since1970);
  std::cout << time1Since1970 << std::endl;
  std::cout << time2Since1970 << std::endl;

  // difftime - повертає різницю типу double між двома часами
  std::cout << std::difftime(time2Since1970, time1Since1970) << std::endl;

  // timespec_get - записує в структуру timespec (по адресі), кількість секунд
  // і наносекунд, які пройшли з 00:00 1 січня 1970. Другий параметр - система
  // часу. (Зазвичай UTC)
  timespec_get(&e, TIME_UTC);
  std::cout << e.tv_sec << std::endl;
  std::cout << e.tv_nsec << std::endl;

  /** Функції перетворення часу **/
  // ctime - повертає в рядковому представленні час, який пройшов з 00:00 1
  // січня 1970. Приймає тип time_t *
  std::cout << std::ctime(&time1Since1970) << std::endl;

  // ctime_r - записує в масив-рядок рядкове представлення, як пройшло з
  // 00:00 1 січня 1970 (Безпечна)
  char fulldate[50];
  if (ctime_r(&time1Since1970, fulldate))
    std::cout << fulldate << std::endl;

  // localtime - перетворює час типу time_t в структуру tm
  d = *std::localtime(&time1Since1970);

  // asctime - повертає в рядковому представленні час, який пройшов з 00:00 1
  // січня 1970. Приймає тип tm*

  std::cout << std::asctime(&d) << std::endl;

  // strftime - перетворює в рядкове представлення типу char* час типу tm.
  // Представлення указується в параметрі
  if (std::strftime(fulldate, sizeof(fulldate), "%A %c", &d))
    std::cout << fulldate << '\n';

  // wcsftime - перетворює в рядкове представлення типу whar_t* час типу tm.
  // Представлення указується в параметрі
  wchar_t wfulldate[100];
  if (std::wcsftime(wfulldate, sizeof(wfulldate), L"%A %c", &d))
    std::wcout << wfulldate << '\n';

  // gmtime - перетворює час типу time_t в формат UTC
  d = *std::gmtime(&time1Since1970);
  std::cout << std::asctime(&d) << std::endl;

  // mktime - перетворює календарний час в час, який пройшов з 00:00 1 січня
  // 1970. Поля time->tm_wday, time->tm_yday ігноруються
  std::tm tm = *std::localtime(&time1Since1970);
  d = *std::localtime(&time1Since1970);
  std::cout << "Today is " << std::asctime(&d);
  std::cout << "and DST is " << (d.tm_isdst ? "in effect" : "not in effect")
            << "\n\n";
  d.tm_mon -= 12;
  std::mktime(&d);
  std::cout << "100 months ago was " << std::asctime(&d);
  std::cout << "and DST was " << (d.tm_isdst ? "in effect" : "not in effect")
            << "\n\n";
}
