#ifndef CPPND_CAPSTONE_CALC_CORE_NODES_OTHERS_BRACKET_H_
#define CPPND_CAPSTONE_CALC_CORE_NODES_OTHERS_BRACKET_H_

#include <memory>

#include "core/nodes/node.h"
#include "core/nodes/priority.h"

namespace calc {
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
  virtual std::shared_ptr<Node> ExtendTree(Node& parent);
};

}  // namespace nodes
}  // namespace calc

#endif  // CPPND_CAPSTONE_CALC_CORE_NODES_OTHERS_BRACKET_H_
