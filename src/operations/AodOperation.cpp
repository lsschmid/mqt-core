//
// Created by Ludwig Schmid on 30.10.23.
//

#include "operations/AodOperation.hpp"

#include "cassert"

#include <utility>

namespace qc {

AodOperation::AodOperation(OpType s, std::vector<Qubit> qubits,
                           std::vector<uint32_t> dirs,
                           std::vector<fp> start,
                           std::vector<fp> end) {
  assert(dirs.size() == start.size() && start.size() == end.size());
  type = s;
  targets = std::move(qubits);
  name = toString(type);
  nqubits = targets.size();
  startQubit = targets[0];

  for (size_t i = 0; i < dirs.size(); ++i) {
    if (dirs[i] == 0) {
      xOperations.push_back({start[i], end[i]});
    } else {
      yOperations.push_back({start[i], end[i]});
    }
  }
}

AodOperation::AodOperation(std::string type, std::vector<Qubit> targets,
                           std::vector<uint32_t> dirs,
                           std::vector<fp> start,
                           std::vector<fp> end)
    : AodOperation(OP_NAME_TO_TYPE.at(type), std::move(targets),
                   std::move(dirs), std::move(start), std::move(end)) {}


AodOperation::AodOperation(
    OpType s, std::vector<Qubit> targets,
    std::vector<std::tuple<uint32_t, fp, fp>> operations) {
  type = s;
  this->targets = std::move(targets);
  name = toString(type);
  nqubits = this->targets.size();
  startQubit = this->targets[0];

  for (const auto& [dir, index, param] : operations) {
    if (dir == 0) {
      xOperations.push_back({index, param});
    } else {
      yOperations.push_back({index, param});
    }
  }
}

void AodOperation::dumpOpenQASM(
    std::ostream& of, const RegisterNames& qreg,
    [[maybe_unused]] const RegisterNames& creg) const {
  of << std::setprecision(std::numeric_limits<fp>::digits10);
  of << name;
  // write AOD oferations
  of << " (";
  for (const auto& xOp : xOperations) {
    of << "0, " << xOp.start << ", " << xOp.end << "; ";
  }
  for (const auto& yOp : yOperations) {
    of << "1, " << yOp.start << ", " << yOp.end << ";";
  }
  // remove last semicolon
  of.seekp(-1, std::ios_base::end);
  of << ")";
  // write qubit start
  for (const auto& qubit : targets) {
    of << " " << qreg[qubit].second << ",";
  }
  of.seekp(-1, std::ios_base::end);
  of << ";\n";
}

void AodOperation::invert() {
  if (type == OpType::AodMove) {
    for (auto& xOp : xOperations) {
      xOp.end = -xOp.end;
    }
    for (auto& yOp : yOperations) {
      yOp.end = -yOp.end;
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