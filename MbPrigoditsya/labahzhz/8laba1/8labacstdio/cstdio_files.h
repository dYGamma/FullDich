
#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cctype>


char *get_file_name(const char *promt = "", const char *error_promt = "", const char* type = "") {

  FILE *input_file;

  int len;
  char *input_file_name;

  bool ok = false;
  while (!ok) {
    cout << promt;
    input_file_name = get_string(&len);
    if (len > 0) {
      ok = true;

      input_file = fopen(input_file_name, type); 

      if (input_file == NULL) {
        cout << error_promt << endl;
        ok = false;
    
      }

    }
  }
  // тип операции передаётся в функцию
  fclose(input_file); // переместил fclose

  return input_file_name;
}

void check_words(char *input_file_name, char *output_file_name, bool data = false) {

  FILE *input_file;
  FILE *output_file;

  input_file = fopen(input_file_name, "r");
  output_file = fopen(output_file_name, "w");

  char c;
  bool space = true;
  bool state = false;
  int symb;

  if (data) {
    draw_line(20);
    cout << "Отладочная информация." << endl;
    draw_line(20);
  }

  while (!feof(input_file)) {
    fscanf(input_file, "%c", &c);
    if (c == '\"' || c == '\'') {
      state = !state;
      if (!state) {
        if (data) cout << endl;
        fprintf(output_file, "\n");
      }
    } else if (state) {
      if (data) cout << c;
      fprintf(output_file, "%c", c); //поток, тип символа, сам символ
    }

  }

  fclose(input_file);
  fclose(output_file);

}
