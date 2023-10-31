//
// Created by Ludwig Schmid on 30.10.23.
//

#pragma once

#include "operations/Operation.hpp"

namespace qc {
class AodOperation : public Operation {
  struct SingleOperation {
    uint32_t aodIndex;
    fp parameter;
  };
  std::vector<SingleOperation> xOperations;
  std::vector<SingleOperation> yOperations;

public:
  AodOperation() = default;
  AodOperation(OpType type, std::vector<Qubit> targets,
               std::vector<uint32_t> dirs, std::vector<uint32_t> indices,
               std::vector<fp> params);
  AodOperation(std::string type, std::vector<Qubit> targets,
               std::vector<uint32_t> dirs, std::vector<uint32_t> indices,
               std::vector<fp> params);

  [[nodiscard]] std::unique_ptr<Operation> clone() const override {
    return std::make_unique<AodOperation>(*this);
  }

  void addControl([[maybe_unused]] Control c) override {}
  void clearControls() override {}
  void removeControl([[maybe_unused]] Control c) override {}
  Controls::iterator removeControl(Controls::iterator it) override {
    return it;
  }

  [[nodiscard]] fp inline getMaxParameterX(){
   return std::abs(std::max_element(xOperations.begin(), xOperations.end(),
                            [](const SingleOperation& a, const SingleOperation& b) {
                              return std::abs(a.parameter) < std::abs(b.parameter);
                            })->parameter);
  }

  [[nodiscard]] fp inline getMaxParameterY(){
    return std::abs(std::max_element(yOperations.begin(), yOperations.end(),
                                     [](const SingleOperation& a, const SingleOperation& b) {
                                       return std::abs(a.parameter) < std::abs(b.parameter);
                                     })->parameter);
  }

  void dumpOpenQASM(std::ostream& of, const RegisterNames& qreg,
                    const RegisterNames& creg) const override;

  void invert() override;
};
} // namespace qc