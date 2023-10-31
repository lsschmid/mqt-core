//
// Created by Ludwig Schmid on 30.10.23.
//

#include "operations/AodOperation.hpp"

#include "cassert"

#include <utility>

namespace qc {

AodOperation::AodOperation(OpType s, std::vector<Qubit> qubits,
                           std::vector<uint32_t> dirs,
                           std::vector<uint32_t> indices,
                           std::vector<fp> params) {
  assert(dirs.size() == indices.size() && indices.size() == params.size());
  type = s;
  targets = std::move(qubits);
  name = toString(type);
  nqubits = targets.size();
  startQubit = targets[0];

  for (size_t i = 0; i < dirs.size(); ++i) {
    if (dirs[i] == 0) {
      xOperations.push_back({indices[i], params[i]});
    } else {
      yOperations.push_back({indices[i], params[i]});
    }
  }
}

AodOperation::AodOperation(std::string type, std::vector<Qubit> targets,
                           std::vector<uint32_t> dirs,
                           std::vector<uint32_t> indices,
                           std::vector<fp> params)
    : AodOperation(OP_NAME_TO_TYPE.at(type), std::move(targets),
                   std::move(dirs), std::move(indices), std::move(params)) {}

void AodOperation::dumpOpenQASM(
    std::ostream& of, const RegisterNames& qreg,
    [[maybe_unused]] const RegisterNames& creg) const {
  of << std::setprecision(std::numeric_limits<fp>::digits10);
  of << name;
  // write AOD oferations
  of << " (";
  for (const auto& xOp : xOperations) {
    of << "0, " << xOp.aodIndex << ", " << xOp.parameter << "; ";
  }
  for (const auto& yOp : yOperations) {
    of << "1, " << yOp.aodIndex << ", " << yOp.parameter << ";";
  }
  // remove last semicolon
  of.seekp(-1, std::ios_base::end);
  of << ")";
  // write qubit indices
  for (const auto& qubit : targets) {
    of << " " << qreg[qubit].second << ",";
  }
  of.seekp(-1, std::ios_base::end);
  of << ";\n";
}

void AodOperation::invert() {
  if (type == OpType::AodMove) {
    for (auto& xOp : xOperations) {
      xOp.parameter = -xOp.parameter;
    }
    for (auto& yOp : yOperations) {
      yOp.parameter = -yOp.parameter;
    }
  }
  if (type == OpType::AodActivate) {
    type = OpType::AodDeactivate;
  }
  if (type == OpType::AodDeactivate) {
    type = OpType::AodActivate;
  }
}

} // namespace qc