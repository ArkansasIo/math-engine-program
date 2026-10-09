# Mathematics engine architecture

The C++23 library is divided into small modules under include/axiomforge/math and src/math. The current set covers integer arithmetic, number theory, polynomial algebra/calculus, dense matrices, descriptive statistics, combinatorics, propositional logic, finite sets, vectors, elementary geometry, numerical methods, probability distributions, unit conversions, complex numbers, equation roots, interpolation, and one-dimensional minimization.

The CLI routes supported textual commands through QueryEngine. Library functions not exposed as CLI commands remain available to C++ callers.

Numerical contracts:
- Integer arithmetic uses signed 64-bit values; overflow of ordinary arithmetic is not checked in every operation.
- Combinatorics explicitly checks unsigned 64-bit result overflow.
- Floating-point APIs use double and require callers to account for rounding, domain restrictions, and non-finite results.
- Polynomial coefficients are stored in ascending powers; differentiation and antiderivatives operate exactly on the polynomial form but coefficients themselves are floating-point.
- This is not yet a full symbolic algebra system: there is no general expression parser, rewrite engine, theorem prover, arbitrary-precision backend, or complete calculus system.
