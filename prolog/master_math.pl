% AxiomForge declarative mathematics facts and rules.
integer_class(N, negative) :- integer(N), N < 0.
integer_class(0, zero).
integer_class(N, positive) :- integer(N), N > 0.
even(N) :- integer(N), 0 is N mod 2.
odd(N) :- integer(N), 1 is abs(N) mod 2.
prime(N) :- integer(N), N > 1, \+ factor_between(N, 2).
factor_between(N, D) :- D*D =< N, 0 is N mod D.
factor_between(N, D) :- D*D < N, D2 is D+1, factor_between(N,D2).
branch(calculus, mathematics).
branch(algebra, mathematics).
branch(number_theory, mathematics).
contains(calculus, limits).
contains(calculus, derivatives).
contains(calculus, integrals).
contains(number_theory, prime_numbers).
depends_on(calculus, algebra).
depends_on(differential_equations, calculus).
