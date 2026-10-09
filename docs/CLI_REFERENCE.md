# CLI reference

Build the project, then run the executable produced as axiomforge_cli.

## Session commands
- `help` — print command syntax.
- `about` — display application and developer identity.
- `build-info` — display product and build identifiers.
- `quit` or `exit` — leave the terminal.

## Arithmetic and number theory
- `math add A B`
- `math subtract A B`
- `math multiply A B`
- `math classify N` — zero/positive/negative and odd/even classification.
- `math prime N`
- `math gcd A B`
- `math lcm A B`
- `math factorial N` — integer result is bounded by unsigned 64-bit overflow checks.
- `math choose N R` — binomial coefficient.
- `math permute N R` — ordered selections.
- `math mean X1 X2 ...`
- `math median X1 X2 ...`

## Polynomial calculus
Polynomial coefficients are entered in ascending powers: C0, C1, C2 means C0 + C1*x + C2*x^2.

- `math derivative C0 C1 ...`
- `math integral C0 C1 ...` — antiderivative with zero integration constant.

## Logic
Boolean values may be `true`, `false`, `1`, or `0`.

- `logic not A`
- `logic and A B`
- `logic or A B`
- `logic xor A B`
- `logic implies A B`
- `logic equivalent A B`

## Knowledge graph
- `graph children NODE_ID`
- `graph path FROM_ID TO_ID`

## Numerical library API
Matrix, statistics, probability, geometry, vector, unit-conversion, complex-number, and numerical-analysis APIs are available as C++ headers under include/axiomforge/math. Not every library function has a CLI command yet.
