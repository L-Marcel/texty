#include "function.hpp"

const set<string> varchar_functions = {"format", "join"};

bool check_if_is_varchar_function(const string& name) {
  return varchar_functions.find(name) != varchar_functions.end();
};

string get_varchar_function_types_as_string(const string& name) {
  if (name == "format") {
    return "(string, ...args)";
  } else if (name == "join") {
    return "(string, string, ...string)";
  } else {
    return "(...args)";
  }
};

vector<Type> get_required_varchar_function_types(const string& name) {
  if (name == "format") {
    return {Type(TypeKind::STRING)};
  } else if (name == "join") {
    return {Type(TypeKind::STRING), Type(TypeKind::STRING)};
  } else {
    return {};
  }
};

Type get_others_varchar_function_types(const string& name) {
  if (name == "join") {
    return Type(TypeKind::STRING);
  } else {
    return Type(TypeKind::UNKNOWN);
  }
};