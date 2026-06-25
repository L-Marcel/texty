#pragma once
#include "../reference.hpp"

struct StructReference : public Reference {
  string name;
  unordered_map<string, Reference*> properties;

  StructReference(Type node_type, string name);

  Reference* get_property(string name) override;
};
