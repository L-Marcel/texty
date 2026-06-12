#include "core.hpp"

namespace txy {
template <typename T>
struct array {
  ::std::shared_ptr<::std::vector<T>> ptr;

  array(int size) : ptr(::std::make_shared<::std::vector<T>>(size)) {}

  T& operator[](int index) { return (*ptr)[index]; }
};
};  // namespace txy
// namespace txy