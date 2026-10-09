# Security notes

- Do not commit credentials, tokens, private keys, or production secrets.
- The update manager currently performs only basic local manifest presence checks.
- Signature verification, artifact hash verification, network transport, rollback protection, and atomic patch installation are not implemented.
- The OpenAPI contract is not a deployed service and provides no authentication.
- Review all contributed code and dependencies before production use.
