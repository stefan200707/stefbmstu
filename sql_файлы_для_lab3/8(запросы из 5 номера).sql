SELECT t.* 
FROM tasks t
JOIN users u ON t.id = u.id
WHERE u.name = 'Иван Петров';