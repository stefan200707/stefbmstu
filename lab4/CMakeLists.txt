
cmake_minimum_required(VERSION 3.10)
project(my_app)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(my_app ${SOURCES} ${HEADERS})
target_include_directories(my_app PRIVATE include)

# Явно добавляем ВСЕ возможные пути include
target_include_directories(my_app PRIVATE 
    /opt/homebrew/include
    /opt/homebrew/opt/libpqxx/include
    /opt/homebrew/opt/libpq/include
    /usr/local/include
    /usr/include
)

# Явно линкуем библиотеки
target_link_libraries(my_app PRIVATE 
    /opt/homebrew/lib/libpqxx.dylib
    /opt/homebrew/lib/libpq.dylib
    /opt/homebrew/opt/libpqxx/lib/libpqxx.dylib
    /opt/homebrew/opt/libpq/lib/libpq.dylib
)

# Добавляем определения если нужно
target_compile_definitions(my_app PRIVATE 
    PQXX_HAVE_PQENCRYPTPASSWORDCONN=1
)