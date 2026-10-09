# Mathematics modules

The current C++23 core now includes a growing set of independent numerical modules:

- Arithmetic: signed integer addition, subtraction, multiplication, integer classification.
- Number theory: primality, GCD, LCM, prime factorization.
- Polynomials: coefficient-vector representation, evaluation, addition/subtraction/multiplication, symbolic derivative and antiderivative.
- Linear algebra: dense matrices, checked indexing, transpose, addition, multiplication, determinant by pivoted elimination.
- Statistics: mean, median, population/sample variance and standard deviation.
- Combinatorics: factorial, permutations, combinations with unsigned 64-bit overflow checks.
- Propositional logic: NOT, AND, OR, XOR, implication, equivalence, truth-table generation.
- Finite sets: union, intersection, difference, subset checks for ordered sets.
- 3D vector math: dot product, cross product, norm, normalization.
- Geometry: 2D distance, circle/triangle area, sphere volume.
- Numerical methods: central-difference derivative, Simpson integration, bisection root finding.
- Probability: binomial PMF, normal PDF/CDF, uniform PDF.
- Units: common length, time, mass, and temperature conversions.
- Complex numbers: standard-library complex arithmetic helpers.
- Knowledge graph: mathematics branches and typed concept nodes.

Floating-point modules use double and therefore inherit IEEE-754 rounding/precision limits. The polynomial module is a symbolic polynomial representation, not a general-purpose expression parser or complete computer algebra system. Matrix operations do not yet include a full solver/eigenvalue/decomposition suite. Additional calculus, probability distributions, numerical analysis, geometry, units, abstract algebra, and arbitrary-precision arithmetic remain planned.
