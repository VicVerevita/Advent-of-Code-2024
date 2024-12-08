#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

/*
 * S . . S . . S
 * . A . A . A .
 * . . M M M . .
 * S A M X M A S
 * . . M M M . .
 * . A . A . A .
 * S . . S . . S
 */

void dfs(int r, int c, int letter_index, std::pair<int, int> dir, int &answer,
         const std::vector<std::string> &input, int start_r, int start_c);

bool is_valid(int r, int c, const std::vector<std::string> &input);

void dfs2(int r, int c, int letter_index, std::pair<int, int> dir, int &answer,
          const std::vector<std::string> &input, int start_r, int start_c);

std::vector<std::pair<int, int>> directions = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

std::string xmas = "XMAS";

std::vector<std::pair<int, int>> directions2 = {
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

std::string xmas2 = "MAS";

int main() {
  std::string text;
  std::ifstream file_read("input.in");
  std::vector<std::string> input;

  while (getline(file_read, text)) {
    input.emplace_back(text);
  }

  if (input.empty())
    std::cout << "Empty input" << std::endl;
  if (input[input.size() - 1].empty()) {
    input.pop_back();
  }
  file_read.close();
  int row_count = input.size();
  int col_count = input[0].size();
  int answer = 0;

  for (int r = 0; r < row_count; r++) {
    for (int c = 0; c < col_count; c++) {
      char curr = input[r][c];
      if (curr == 'X') {
        for (const auto &dir : directions) {
          dfs(r, c, 0, dir, answer, input, r, c);
        }
      }
    }
  }

  std::cout << answer << std::endl;

  std::string text2;
  std::ifstream file_read2("input2.in");
  std::vector<std::string> input2;

  while (getline(file_read2, text2)) {
    input2.emplace_back(text2);
  }

  if (input2.empty())
    std::cout << "Empty input" << std::endl;
  if (input2[input2.size() - 1].empty()) {
    input2.pop_back();
  }
  file_read2.close();
  row_count = input.size();
  col_count = input[0].size();
  answer = 0;

  for (int r = 0; r < row_count; r++) {
    for (int c = 0; c < col_count; c++) {
      char curr = input2[r][c];
      if (curr == 'M') {
        for (const auto &dir : directions2) {
          dfs2(r, c, 0, dir, answer, input2, r, c);
        }
      }
    }
  }

  std::cout << answer / 2 << std::endl;
}

void dfs(int r, int c, int letter_index, std::pair<int, int> dir, int &answer,
         const std::vector<std::string> &input, int start_r, int start_c) {

  char curr = input[r][c];
  char letter_to_find = xmas[letter_index];

  if (curr != letter_to_find) {
    return;
  }

  if (curr == 'S') {
    answer++;
    return;
  }

  int new_r = r + dir.first;
  int new_c = c + dir.second;

  if (new_r < 0 || new_c < 0)
    return;
  if (new_r >= input.size() || new_c >= input[0].size())
    return;

  dfs(new_r, new_c, letter_index + 1, dir, answer, input, start_r, start_c);
}

bool is_valid(int r, int c, const std::vector<std::string> &input) {
  if (r < 0 || c < 0)
    return false;
  if (r >= input.size() || c >= input[0].size())
    return false;
  return true;
}

void dfs2(int r, int c, int letter_index, std::pair<int, int> dir, int &answer,
          const std::vector<std::string> &input, int start_r, int start_c) {

  char curr = input[r][c];
  char letter_to_find = xmas2[letter_index];

  if (curr != letter_to_find) {
    return;
  }

  if (curr == 'S') {
    int r1 = r;
    int c1 = start_c;

    int r2 = start_r;
    int c2 = c;

    if (is_valid(r1, c1, input) && is_valid(r2, c2, input)) {
      char char_1 = input[r1][c1];
      char char_2 = input[r2][c2];

      bool has_s = char_1 == 'S' || char_2 == 'S';
      bool has_m = char_1 == 'M' || char_2 == 'M';

      if (has_m && has_s) {
        // cout << start_r << " " << start_c << " - " << r << " " << c << endl;
        answer++;
      }
    }

    return;
  }

  int new_r = r + dir.first;
  int new_c = c + dir.second;

  if (is_valid(new_r, new_c, input)) {
    dfs2(new_r, new_c, letter_index + 1, dir, answer, input, start_r, start_c);
  }
}
