SELECT priority,
COUNT(*) AS task_count
FROM tasks
WHERE priority IN ('Высокий', 'Средний', 'Низкий')
GROUP BY priority
ORDER BY 
    CASE 
        WHEN priority = 'Высокий' THEN 1
        WHEN priority = 'Средний' THEN 2
        WHEN priority = 'Низкий' THEN 3
	END;