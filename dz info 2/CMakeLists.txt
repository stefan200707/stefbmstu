cmake_minimum_required(VERSION 3.16)
project(bmstu_dz_info2)

set(CMAKE_CXX_STANDARD 17)

# Homebrew paths for ARM (M1, M2, M3, M4)
set(BREW_PREFIX "/opt/homebrew")

include_directories(
        ${BREW_PREFIX}/include
        ${BREW_PREFIX}/opt/libpq/include
        ${BREW_PREFIX}/opt/libpqxx/include
)

link_directories(
        ${BREW_PREFIX}/lib
        ${BREW_PREFIX}/opt/libpq/lib
        ${BREW_PREFIX}/opt/libpqxx/lib
)

# Основной исполняемый файл
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
        pq
        pqxx
)

# Список CSV файлов для копирования
set(CSV_FILES
        ${CMAKE_SOURCE_DIR}/products.csv
        ${CMAKE_SOURCE_DIR}/customers.csv
        ${CMAKE_SOURCE_DIR}/sales.csv
)

# Целевая директория для копирования
set(CSV_TARGET_DIR ${CMAKE_CURRENT_BINARY_DIR})

# Функция для копирования файла с проверкой существования
function(copy_csv_file source_file)
    if(EXISTS ${source_file})
        message(STATUS "Найден CSV файл: ${source_file}")
        add_custom_command(
                TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${source_file}
                ${CSV_TARGET_DIR}/
                COMMENT "Копируем ${source_file} в ${CSV_TARGET_DIR}"
        )
    else()
        message(WARNING "CSV файл не найден: ${source_file}")
    endif()
endfunction()

# Копируем все CSV файлы
foreach(csv_file ${CSV_FILES})
    copy_csv_file(${csv_file})
endforeach()

# Дополнительная цель для ручного копирования CSV файлов
add_custom_target(copy_csv ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CSV_TARGET_DIR}
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CSV_FILES}
        ${CSV_TARGET_DIR}/
        COMMENT "Копируем CSV файлы в директорию сборки"
)

# Показываем информацию о путях
message(STATUS "Директория исходников: ${CMAKE_SOURCE_DIR}")
message(STATUS "Директория сборки: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CSV файлы будут скопированы в: ${CSV_TARGET_DIR}")