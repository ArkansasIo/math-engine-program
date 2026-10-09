CREATE INDEX IF NOT EXISTS audit_log_project_id_idx ON audit_log(project_id,id DESC);
CREATE INDEX IF NOT EXISTS audit_log_actor_created_idx ON audit_log(actor_id,created_at DESC);
CREATE INDEX IF NOT EXISTS project_members_user_project_idx ON project_members(user_id,project_id);
CREATE INDEX IF NOT EXISTS collaboration_events_project_created_idx ON collaboration_events(project_id,created_at DESC);
CREATE INDEX IF NOT EXISTS reviews_project_status_idx ON reviews(project_id,status,created_at DESC);
