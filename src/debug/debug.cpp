#include "debug.hpp"

void Debug::print_node(ostream& os, const Node* node, string label) {
  os << "  \"" << node << "\" [label=\"" << label << "\"];" << std::endl;
};

void Debug::print_relation(ostream& os, const Node* from, Node* to) {
  os << "  \"" << from << "\" -> \"" << to << "\";" << std::endl;
  to->print(os);
};