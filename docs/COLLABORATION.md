# Collaboration protocol

Revision commits lock the target branch row, compare the caller's expected head with the current head, create a revision, advance the branch head, and persist a collaboration event in one database transaction. A stale expected head returns HTTP 409 with the current head ID; clients should fetch history and resolve the conflict rather than blindly retry.

WebSocket clients connect to /api/v1/ws and send a subscribe message containing the project ID. The server verifies project viewer access and replays up to 100 persisted events after the supplied event ID. Events arriving during replay are buffered and de-duplicated by event ID.

Live fanout is currently in-process. For horizontally scaled deployments, add a shared broker or PostgreSQL LISTEN/NOTIFY, plus reconnect cursors and bounded backpressure.
