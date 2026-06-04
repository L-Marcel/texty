#pragma once
#include "../../structures/struct.hpp"
#include "array_allocation.hpp"

struct StructAllocationNode : public ExpressionNode {
  vector<pair<string, ExpressionNode*>> attributes;

  StructAllocationNode(int line, string name,
                       vector<pair<string, ExpressionNode*>> attributes);

  void compile_dot(ostream& os) const override;
  void compile_code(ostream& os) const override;
  Type get_type() const override;
};