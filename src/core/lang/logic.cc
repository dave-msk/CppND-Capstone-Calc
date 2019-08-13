#include "core/lang/logic.h"

#include <cmath>

#include "core/lang/symbols.h"

namespace {
namespace binaryfn {

float Add(float l, float r) {
  return l + r;
}

float Minus(float l, float r) {
  return l - r;
}

float Multiply(float l, float r) {
  return l * r;
}

float Divide(float l, float r) {
  return l / r;
}

float Power(float l, float r) {
  return std::pow(l, r);
}

}  // namespace binaryfn

namespace unaryfn {

float Identity(float v) {
  return v;
}

float Negate(float v) {
  return -v;
}

float Sin(float v) {
  return std::sin(v);
}

float Cos(float v) {
  return std::cos(v);
}

float Tan(float v) {
  return std::tan(v);
}

float Sinh(float v) {
  return std::sinh(v);
}

float Cosh(float v) {
  return std::cosh(v);
}

float Tanh(float v) {
  return std::tanh(v);
}

}  // namespace unaryfn
}  // namespace

namespace calc {
namespace lang {

BinaryFn GetBinaryFn(BinaryOpType type) {
  switch (type) {
    case BinaryOpType::ADD: return &::binaryfn::Add;
    case BinaryOpType::MINUS: return &::binaryfn::Minus;
    case BinaryOpType::MULTIPLY: return &::binaryfn::Multiply;
    case BinaryOpType::DIVIDE: return &::binaryfn::Divide;
    case BinaryOpType::POWER: return &::binaryfn::Power;
  }
}

UnaryFn GetUnaryFn(UnaryOpType type) {
  switch (type) {
    case (UnaryOpType::IDENTITY): return &::unaryfn::Identity;
    case (UnaryOpType::NEGATE): return &::unaryfn::Negate;
    case (UnaryOpType::SIN): return &::unaryfn::Sin;
    case (UnaryOpType::COS): return &::unaryfn::Cos;
    case (UnaryOpType::TAN): return &::unaryfn::Tan;
    case (UnaryOpType::SINH): return &::unaryfn::Sinh;
    case (UnaryOpType::COSH): return &::unaryfn::Cosh;
    case (UnaryOpType::TANH): return &::unaryfn::Tanh;
  }
}

Literal GetConstant(Constant type) {
  switch (type) {
    case Constant::E: return Literal(M_E);
    case Constant::PI: return Literal(M_PI);
  }
}

}  // namespace lang
}  // namespace calc
