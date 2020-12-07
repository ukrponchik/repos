#include <clocale>
#include <cstdio>
#include <ctime>
#include <cwchar>

int main() {
  // the C locale will be UTF-8 enabled English;
  // decimal dot will be German
  // date and time formatting will be Japanese
  std::setlocale(LC_ALL, "en_US.UTF-8");
  std::setlocale(LC_NUMERIC, "de_DE.UTF-8");
  std::setlocale(LC_TIME, "uk_UA.UTF-8");

  wchar_t str[100];
  std::time_t t = std::time(NULL);
  std::wcsftime(str, 100, L"%A %c", std::localtime(&t));
  std::wprintf(L"Number: %.2f\nDate: %Ls\n", 3.14, str);
}
