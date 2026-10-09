# API error conventions

Responses use JSON objects with an error code, optionally accompanied by a message, validation issues, or current revision metadata.

- 400: malformed JSON, invalid parameters, or schema validation failure.
- 401: missing/invalid bearer token.
- 403: authenticated user lacks the required project role.
- 404: resource not found or not visible to the caller.
- 409: duplicate project resource or revision-head conflict.
- 422: validly shaped request that cannot be applied, such as an invalid revision parent or failed math operation.
- 429: login rate limit exceeded.
- 500: unexpected server failure; response does not include the stack trace.

Clients should use the stable error code for user-facing handling and include X-Request-Id when reporting unexpected failures.
