# Testing

## C++23 core
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

## API
```sh
cd server
npm install
npm run build
npm run typecheck
npm test
```

The CI workflow starts PostgreSQL, compiles the API, runs unit tests, and applies the SQL migrations with stop-on-error enabled.

## Web client
```sh
cd client
npm install
npm run typecheck
npm run build
```

## Test boundaries
The current tests cover C++ numerical primitives and the pure math evaluator/role hierarchy. Full HTTP integration tests, authenticated multi-user collaboration tests, worker failure/retry tests, and end-to-end browser tests remain future work.
