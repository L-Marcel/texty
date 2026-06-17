#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
namespace fs = filesystem;

unordered_set<string> visited_files;
unordered_set<string> using_namespaces;
string content;

void process_file(const fs::path& filepath) {
  fs::path canonical = fs::weakly_canonical(filepath);
  if (visited_files.count(canonical.string())) return;
  visited_files.insert(canonical.string());

  ifstream file(filepath);
  string line;

  while (getline(file, line)) {
    string trimmed = line;
    trimmed.erase(0, trimmed.find_first_not_of(" \t"));

    if (trimmed.empty() || trimmed.find("//") == 0) continue;
    if (trimmed.find("#pragma once") == 0) continue;

    if (trimmed.find("#include \"") == 0) {
      size_t start = trimmed.find('"') + 1;
      size_t end = trimmed.find('"', start);
      string relative_path = trimmed.substr(start, end - start);

      fs::path next_file = filepath.parent_path() / relative_path;
      if (fs::exists(next_file)) {
        process_file(next_file);
      };

      continue;
    };

    if (trimmed.find("using namespace ") == 0) {
      if (using_namespaces.count(trimmed)) continue;
      using_namespaces.insert(trimmed);
      continue;
    };

    content += line + "\n";
  };
};

int main() {
  for (const auto& entry : fs::recursive_directory_iterator("src/standard")) {
    if (entry.path().extension() == ".h" || entry.path().extension() == ".c") {
      process_file(entry.path());
    };
  };

  ofstream out("src/embedded_standard.hpp");
  out << "#pragma once" << std::endl << std::endl;
  out << "const char* TEXTY_STANDARD_LIBRARY = R\"__texty_std__(" << std::endl;
  ;

  for (const auto& ns : using_namespaces) {
    out << ns << std::endl;
  };

  out << content << ")__texty_std__\";" << std::endl;

  return 0;
};