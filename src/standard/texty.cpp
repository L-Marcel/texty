#include <cmath>
#include "core.hpp"

namespace txy {

using unbounded_value = ::std::monostate;
using bound_value =
    ::std::variant<unbounded_value, ::std::uint8_t, ::std::int32_t,
                   ::std::int64_t, float, double>;

template <typename T>
struct range {
  static_assert(::std::is_same_v<T, ::std::uint8_t> ||
                    ::std::is_same_v<T, ::std::int32_t> ||
                    ::std::is_same_v<T, ::std::int64_t> ||
                    ::std::is_same_v<T, float> || ::std::is_same_v<T, double>,
                "range precisa ter limites numericos");

  bound_value left;
  bound_value right;
  bool left_inclusive;
  bool right_inclusive;

  range(T left, T right, bool left_inclusive, bool right_inclusive)
      : left(left),
        right(right),
        left_inclusive(left_inclusive),
        right_inclusive(right_inclusive) {};
  range(unbounded_value left, T right, bool left_inclusive,
        bool right_inclusive)
      : left(left),
        right(right),
        left_inclusive(left_inclusive),
        right_inclusive(right_inclusive) {};
  range(T left, unbounded_value right, bool left_inclusive,
        bool right_inclusive)
      : left(left),
        right(right),
        left_inclusive(left_inclusive),
        right_inclusive(right_inclusive) {};
  range(unbounded_value left, unbounded_value right, bool left_inclusive,
        bool right_inclusive)
      : left(left),
        right(right),
        left_inclusive(left_inclusive),
        right_inclusive(right_inclusive) {};
};

template <typename T>
struct array {
  ::std::shared_ptr<::std::vector<T>> ptr;

  array() : ptr(::std::make_shared<::std::vector<T>>()) {};
  array(::std::int32_t size)
      : ptr(::std::make_shared<::std::vector<T>>(
            static_cast<::std::size_t>(size))) {};
  array(::std::initializer_list<T> init)
      : ptr(::std::make_shared<::std::vector<T>>(init)) {};
  array(::std::int32_t size, ::std::initializer_list<T> init)
      : ptr(::std::make_shared<::std::vector<T>>(init)) {
    ptr->resize(static_cast<::std::size_t>(size));
  };

  T& operator[](::std::int32_t index) {
    return (*ptr)[static_cast<::std::size_t>(index)];
  };

  bool contains(const T& value) const {
    return ::std::find(ptr->begin(), ptr->end(), value) != ptr->end();
  };

  array<T> operator<<(const array<T>& other) const {
    array<T> result;
    result.ptr->reserve(this->ptr->size() + other.ptr->size());
    result.ptr->insert(result.ptr->end(), this->ptr->begin(), this->ptr->end());
    result.ptr->insert(result.ptr->end(), other.ptr->begin(), other.ptr->end());
    return result;
  };
};

template <typename T>
struct option {
  ::std::optional<T> inner;

  option() : inner(::std::nullopt) {}
  option(T value) : inner(::std::move(value)) {};

  bool is_some() const { return this->inner.has_value(); };
  bool is_none() const { return !this->inner.has_value(); };

  T unwrap() const {
    if (!this->inner.has_value()) {
      throw ::std::runtime_error("tentativa de acessar valor none");
    }
    return this->inner.value();
  };
};
};
