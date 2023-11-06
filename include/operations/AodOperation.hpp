//
// Created by Ludwig Schmid on 30.10.23.
//

#pragma once

#include "operations/Operation.hpp"

namespace qc {
class AodOperation : public Operation {
  struct SingleOperation {
    fp start;
    fp end;
  };
  std::vector<SingleOperation> xOperations;
  std::vector<SingleOperation> yOperations;

public:
  AodOperation() = default;
  AodOperation(OpType type, std::vector<Qubit> targets,
               std::vector<uint32_t> dirs, std::vector<fp> starts,
               std::vector<fp> ends);
  AodOperation(std::string type, std::vector<Qubit> targets,
               std::vector<uint32_t> dirs, std::vector<fp> starts,
               std::vector<fp> ends);
  AodOperation(OpType type, std::vector<Qubit> targets,
               std::vector<std::tuple<uint32_t, fp, fp>> operations);

  [[nodiscard]] std::unique_ptr<Operation> clone() const override {
    return std::make_unique<AodOperation>(*this);
  }

  void addControl([[maybe_unused]] Control c) override {}
  void clearControls() override {}
  void removeControl([[maybe_unused]] Control c) override {}
  Controls::iterator removeControl(Controls::iterator it) override {
    return it;
  }

  [[nodiscard]] fp inline getMaxParameterX() const {
    return std::abs(std::max_element(
                        xOperations.begin(), xOperations.end(),
                        [](const SingleOperation& a, const SingleOperation& b) {
                          return std::abs(a.end) < std::abs(b.end);
                        })
                        ->end);
  }

  [[nodiscard]] fp inline getMaxParameterY() const {
    return std::abs(std::max_element(
                        yOperations.begin(), yOperations.end(),
                        [](const SingleOperation& a, const SingleOperation& b) {
                          return std::abs(a.end) < std::abs(b.end);
                        })
                        ->end);
  }

  [[nodiscard]] std::vector<fp> inline getParamterXs() const {
    std::vector<fp> params;
    params.reserve(xOperations.size());
    for (const auto& op : xOperations) {
      params.push_back(op.end);
    }
    return params;
  }

  [[nodiscard]] std::vector<fp> inline getParamterYs() const {
    std::vector<fp> params;
    params.reserve(yOperations.size());
    for (const auto& op : yOperations) {
      params.push_back(op.end);
    }
    return params;
  }


  void dumpOpenQASM(std::ostream& of, const RegisterNames& qreg,
                    const RegisterNames& creg) const override;

  void invert() override;
};
} // namespace qc