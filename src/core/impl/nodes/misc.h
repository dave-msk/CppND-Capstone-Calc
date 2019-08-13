#ifndef CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_MISC_H_
#define CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_MISC_H_

#include <memory>

#include "core/impl/nodes/node.h"
#include "core/impl/nodes/priority.h"
#include "core/lang/symbols.h"

namespace calc {
namespace impl {
namespace nodes {

class OpenBracket : public Node {
 public:
  OpenBracket();

 private:
  virtual bool IsValidParent(const Node&) const;
};

class CloseBracket : public Node {
 public:
  CloseBracket();

 private:
  virtual bool IsValidParent(const Node&) const;
  virtual Node* ExtendTree(Node*);
};

}  // namespace nodes
}  // namespace impl
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_IMPL_NODES_MISC_H_
