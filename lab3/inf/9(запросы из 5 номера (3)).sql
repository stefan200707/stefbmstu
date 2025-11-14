SELECT * FROM tasks
WHERE priority = 'Высокий'
  AND due_date BETWEEN '2024-06-01' AND '2024-06-01'::date + INTERVAL '7 days';