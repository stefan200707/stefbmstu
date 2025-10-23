#!/bin/bash

filename=$1

# Проверка и создание файла
if [ ! -f "$filename" ]; then
    for i in {1..10}; do
        echo "Случайная строка $RANDOM"
    done > "$filename"
fi

# Отправка строк через netcat
counter=0
while IFS= read -r line; do
    echo "$line" | nc -q 0 localhost 8080
    ((counter++))
done < "$filename"

echo "Отправлено строк: $counter"

while true; do
    date >> log.txt
    sleep 60
done &
