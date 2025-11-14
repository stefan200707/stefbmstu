SELECT 
    t.id AS task_id,
    t.title,
    t.priority,
    t.due_date,
    t.status,
    u.name AS responsible_user
FROM tasks t
JOIN task_assignment ta ON t.id = ta.task_id
JOIN users u ON ta.user_id = u.id
WHERE t.due_date < CURRENT_DATE
  AND t.status <> 'done';

UPDATE tasks
SET status = 'done'
WHERE id = 5;

DELETE FROM tasks
WHERE id = 5
  AND NOT EXISTS (
        SELECT 1 
        FROM task_assignment ta
        WHERE ta.task_id = tasks.id
  );
SELECT * FROM tasks;


