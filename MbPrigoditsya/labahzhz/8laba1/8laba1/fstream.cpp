#pragma warning(disable : 4996)
#pragma warning(disable : 4703)
#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>
#include <fstream>
#include <cctype>

#include "libs/simple_char.h"
#include "libs/input_validation.h"

#include "fstream_files.h"

int main() {
  system("chcp 65001");

  //clear_scr();
  //переменные для названия файлов
  char *input_file_name;
  char *output_file_name;
  //записываем через getfile
  input_file_name = get_file_name("Имя входного файла: ", "Невозможно прочитать файл. Возможно его не существует.");
  output_file_name = get_file_name("Имя выходного файла: ", "Невозможно записать или создать файл.", true);

  check_words(input_file_name, output_file_name, false);

  draw_line(20);

  cout << "В файл " << output_file_name << " был успешно записан результат." << endl;

  return 0;
}
