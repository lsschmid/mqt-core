//
// Created by Ludwig Schmid on 30.10.23.
//

#include "operations/AodOperation.hpp"

#include "cassert"

#include <utility>

namespace qc {
AodOperation::AodOperation(OpType s, std::vector<Qubit> qubits,
                           std::vector<uint32_t> dirs, std::vector<fp> start,
                           std::vector<fp> end) {
  auto dirsEnum = std::vector<Dimension>(dirs.size());
  for (size_t i = 0; i < dirs.size(); ++i) {
    dirsEnum[i] = static_cast<Dimension>(dirs[i]);
  }
  AodOperation(s, std::move(qubits), std::move(dirsEnum), std::move(start),
               std::move(end));
}

AodOperation::AodOperation(OpType s, std::vector<Qubit> qubits,
                           std::vector<Dimension> dirs, std::vector<fp> start,
                           std::vector<fp> end) {
  assert(dirs.size() == start.size() && start.size() == end.size());
  type = s;
  targets = std::move(qubits);
  name = toString(type);
  nqubits = targets.size();
  startQubit = targets[0];

  for (size_t i = 0; i < dirs.size(); ++i) {
    operations.emplace_back(dirs[i], start[i], end[i]);
  }
}

AodOperation::AodOperation(std::string type, std::vector<Qubit> targets,
                           std::vector<uint32_t> dirs, std::vector<fp> start,
                           std::vector<fp> end)
    : AodOperation(OP_NAME_TO_TYPE.at(type), std::move(targets),
                   std::move(dirs), std::move(start), std::move(end)) {}

AodOperation::AodOperation(
    OpType s, std::vector<Qubit> targets,
    std::vector<std::tuple<Dimension, fp, fp>>& operations) {
  type = s;
  this->targets = std::move(targets);
  name = toString(type);
  nqubits = this->targets.size();
  startQubit = this->targets[0];

  for (const auto& [dir, index, param] : operations) {
    operations.emplace_back(dir, index, param);
  }
}

AodOperation::AodOperation(OpType s, std::vector<Qubit> t,
                           std::vector<SingleOperation>& ops)
    : operations(std::move(ops)) {
  type = s;
  this->targets = t;
  name = toString(type);
  nqubits = this->targets.size();
  startQubit = this->targets[0];
}

void AodOperation::dumpOpenQASM(
    std::ostream& of, const RegisterNames& qreg,
    [[maybe_unused]] const RegisterNames& creg) const {
  of << std::setprecision(std::numeric_limits<fp>::digits10);
  of << name;
  // write AOD oferations
  of << " (";
  for (const auto& op : operations) {
    of << op.toQASMString();
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
    for (auto& op : operations) {
      op.start = op.end;
      op.end = -op.start;
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