#pragma once
#include "../reference.hpp"

struct VariableReference : public Reference {
  bool is_const;
  string name_suffix;

  VariableReference(Type node_type, bool is_const, string name_suffix);

  Reference* get_property(string name) override;
};