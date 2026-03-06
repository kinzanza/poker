#основной CMAKE файл
#запуск проекта
cmake_minimum_required(VERSION 3.20)
project(poker)


add_subdirectory(ui)
add_subdirectory(logic)
add_subdirectory(net)
add_subdirectory(controller)
add_subdirectory(app)


