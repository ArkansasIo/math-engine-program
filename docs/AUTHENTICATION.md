# Authentication and authorization

The API supports account registration and login using bcrypt password hashes. Successful login returns a short-lived JWT access token. Clients send it as an Authorization: Bearer token on protected HTTP requests. Tokens are currently held in memory by the web client.

Project roles are owner, editor, reviewer, and viewer. Owners manage membership and release metadata; editors can modify revisions and create reviews; reviewers can decide reviews; viewers can read project data. The API checks project membership on project-scoped routes.

Before public production use, add email verification, account recovery, token revocation/refresh strategy, abuse monitoring, a one-time WebSocket ticket instead of query-string tokens, secret rotation, and a documented incident-response process.
