// i 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
// o 3 5 2 0 7 1 4 6 8
OPENQASM 2.0;
include "qelib1.inc";
qreg q[20];
creg c[7];
cx q[3],q[4];
cx q[4],q[3];
cx q[3],q[4];
cx q[6],q[5];
cx q[5],q[6];
cx q[6],q[5];
cx q[6],q[1];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
u2(0.0,3.141592653589793) q[0];
cx q[6],q[1];
u2(0.0,3.141592653589793) q[1];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
u2(0.7853981633974483,3.141592653589793) q[7];
u2(0.7853981633974483,3.141592653589793) q[8];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[3],q[8];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[1],q[6];
cx q[6],q[1];
cx q[1],q[6];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
u1(-0.7853981633974483) q[8];
cx q[7],q[8];
u1(0.7853981633974483) q[8];
cx q[3],q[8];
cx q[3],q[4];
cx q[4],q[3];
cx q[3],q[4];
u2(0.0,2.356194490192345) q[8];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[3],q[8];
cx q[7],q[6];
u1(-0.7853981633974483) q[6];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[8],q[3];
cx q[3],q[8];
cx q[3],q[4];
cx q[4],q[3];
cx q[3],q[4];
cx q[8],q[7];
u1(0.7853981633974483) q[7];
cx q[6],q[7];
u1(0.7853981633974483) q[6];
u1(-0.7853981633974483) q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[7],q[6];
u1(-0.7853981633974483) q[6];
u1(0.7853981633974483) q[7];
cx q[7],q[6];
u2(0.7853981633974483,3.141592653589793) q[6];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
u1(7.0685834705770345) q[8];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[3],q[8];
u1(-0.7853981633974483) q[8];
cx q[3],q[8];
cx q[8],q[3];
cx q[3],q[8];
u1(0.7853981633974483) q[3];
cx q[8],q[3];
u2(0.0,2.356194490192345) q[3];
cx q[2],q[3];
cx q[3],q[2];
cx q[2],q[3];
cx q[2],q[1];
u1(-0.7853981633974483) q[1];
cx q[6],q[1];
u1(0.7853981633974483) q[1];
cx q[2],q[1];
u1(-0.7853981633974483) q[1];
u1(0.7853981633974483) q[2];
cx q[6],q[1];
cx q[1],q[2];
cx q[2],q[1];
cx q[1],q[2];
u1(7.0685834705770345) q[2];
cx q[3],q[2];
u1(-0.7853981633974483) q[2];
cx q[3],q[4];
cx q[4],q[3];
cx q[3],q[4];
cx q[6],q[1];
u1(-0.7853981633974483) q[1];
u1(0.7853981633974483) q[6];
cx q[6],q[1];
u2(0.7853981633974483,3.141592653589793) q[1];
cx q[1],q[6];
cx q[6],q[1];
cx q[1],q[6];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
cx q[1],q[2];
cx q[2],q[1];
cx q[1],q[2];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[7],q[6];
u1(-0.7853981633974483) q[6];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[3],q[8];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[6],q[5];
cx q[5],q[6];
cx q[6],q[5];
u1(0.7853981633974483) q[8];
cx q[7],q[8];
cx q[3],q[8];
u1(-0.7853981633974483) q[8];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[6],q[7];
cx q[6],q[5];
cx q[5],q[6];
cx q[6],q[5];
u1(0.7853981633974483) q[7];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[3],q[8];
u2(0.0,2.356194490192345) q[8];
cx q[3],q[8];
cx q[8],q[3];
cx q[3],q[8];
cx q[3],q[2];
u1(-0.7853981633974483) q[2];
cx q[2],q[3];
cx q[3],q[2];
cx q[2],q[3];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[8],q[3];
u1(0.7853981633974483) q[3];
cx q[2],q[3];
u2(0.0,2.356194490192345) q[3];
cx q[3],q[8];
cx q[8],q[3];
cx q[3],q[8];
cx q[8],q[7];
u1(-0.7853981633974483) q[7];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[1],q[6];
u1(0.7853981633974483) q[6];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[8],q[7];
u1(-0.7853981633974483) q[7];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[1],q[6];
cx q[1],q[2];
cx q[2],q[1];
cx q[1],q[2];
u1(7.0685834705770345) q[6];
cx q[6],q[5];
cx q[5],q[6];
cx q[6],q[5];
u1(0.7853981633974483) q[8];
cx q[3],q[8];
cx q[8],q[3];
cx q[3],q[8];
cx q[2],q[3];
u1(0.7853981633974483) q[2];
u1(-0.7853981633974483) q[3];
cx q[2],q[3];
cx q[1],q[2];
cx q[2],q[1];
cx q[1],q[2];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
u2(0.7853981633974483,3.141592653589793) q[3];
cx q[2],q[3];
u1(-0.7853981633974483) q[3];
cx q[8],q[3];
u1(0.7853981633974483) q[3];
cx q[2],q[3];
u2(0.7853981633974483,3.141592653589793) q[2];
u2(0.0,2.356194490192345) q[3];
cx q[2],q[3];
cx q[3],q[2];
cx q[2],q[3];
u2(0.7853981633974483,3.141592653589793) q[2];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[6],q[5];
cx q[5],q[6];
cx q[6],q[5];
cx q[8],q[3];
u1(-0.7853981633974483) q[3];
cx q[3],q[8];
cx q[8],q[3];
cx q[3],q[8];
cx q[7],q[8];
u1(0.7853981633974483) q[8];
cx q[3],q[8];
u3(3.141592653589793,0.0,3.141592653589793) q[3];
cx q[3],q[8];
u1(-0.7853981633974483) q[8];
cx q[7],q[8];
u1(0.7853981633974483) q[8];
cx q[3],q[8];
u2(0.0,2.356194490192345) q[8];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[3],q[8];
cx q[7],q[6];
u1(-0.7853981633974483) q[6];
cx q[5],q[6];
u1(0.7853981633974483) q[6];
cx q[7],q[6];
u1(-0.7853981633974483) q[6];
cx q[5],q[6];
cx q[6],q[5];
cx q[5],q[6];
cx q[6],q[5];
u2(0.0,3.9269908169872414) q[5];
u1(0.7853981633974483) q[7];
cx q[6],q[7];
u1(0.7853981633974483) q[6];
u1(-0.7853981633974483) q[7];
cx q[6],q[7];
u2(0.7853981633974483,3.141592653589793) q[7];
cx q[8],q[3];
cx q[3],q[8];
cx q[8],q[7];
cx q[3],q[8];
u1(-0.7853981633974483) q[7];
cx q[8],q[3];
cx q[3],q[8];
cx q[8],q[7];
cx q[3],q[8];
u1(0.7853981633974483) q[7];
cx q[8],q[3];
cx q[3],q[8];
cx q[3],q[4];
cx q[4],q[3];
cx q[3],q[4];
cx q[7],q[8];
cx q[8],q[7];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[6],q[1];
u1(0.7853981633974483) q[1];
cx q[1],q[2];
cx q[2],q[1];
cx q[1],q[2];
cx q[3],q[2];
u1(-0.7853981633974483) q[2];
cx q[1],q[2];
cx q[2],q[1];
cx q[1],q[2];
u1(0.7853981633974483) q[3];
cx q[2],q[3];
cx q[3],q[2];
cx q[2],q[3];
cx q[6],q[1];
cx q[1],q[6];
cx q[6],q[1];
cx q[1],q[6];
cx q[1],q[2];
u1(0.7853981633974483) q[1];
u1(-0.7853981633974483) q[2];
cx q[1],q[2];
u1(7.0685834705770345) q[6];
cx q[1],q[6];
cx q[6],q[1];
cx q[1],q[6];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
cx q[7],q[8];
u1(-0.7853981633974483) q[8];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[6],q[7];
u1(0.7853981633974483) q[7];
cx q[8],q[7];
u2(0.0,2.356194490192345) q[7];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[8],q[3];
u1(-0.7853981633974483) q[3];
cx q[2],q[3];
cx q[3],q[2];
cx q[2],q[3];
cx q[1],q[2];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
u1(0.7853981633974483) q[2];
cx q[3],q[8];
cx q[8],q[3];
cx q[3],q[8];
cx q[3],q[2];
u2(0.0,2.356194490192345) q[2];
cx q[2],q[1];
u1(-0.7853981633974483) q[1];
cx q[1],q[2];
cx q[2],q[1];
cx q[1],q[2];
cx q[3],q[8];
cx q[8],q[3];
cx q[3],q[8];
cx q[3],q[2];
u1(0.7853981633974483) q[2];
cx q[1],q[2];
u1(0.7853981633974483) q[1];
u1(-0.7853981633974483) q[2];
cx q[3],q[2];
cx q[2],q[3];
cx q[3],q[2];
cx q[2],q[3];
cx q[2],q[1];
u1(-0.7853981633974483) q[1];
u1(0.7853981633974483) q[2];
cx q[2],q[1];
u2(0.7853981633974483,3.141592653589793) q[1];
cx q[1],q[6];
u2(0.0,3.9269908169872414) q[3];
cx q[6],q[1];
cx q[1],q[6];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[7],q[6];
u1(-0.7853981633974483) q[6];
cx q[1],q[6];
cx q[0],q[1];
cx q[1],q[0];
cx q[0],q[1];
u1(0.7853981633974483) q[6];
cx q[7],q[6];
u2(0.0,2.356194490192345) q[6];
u2(0.7853981633974483,3.141592653589793) q[7];
cx q[8],q[7];
u1(-0.7853981633974483) q[7];
cx q[6],q[7];
cx q[7],q[6];
cx q[6],q[7];
cx q[1],q[6];
u1(0.7853981633974483) q[6];
cx q[8],q[7];
cx q[7],q[8];
cx q[8],q[7];
cx q[7],q[6];
u2(0.0,2.356194490192345) q[6];
