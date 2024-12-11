cmake_minimum_required(VERSION 3.28)  
project(CMake_for_LB7)

set(CPP Task.cpp)

set(H Task_1.h check_ho_rip_for_task_5.h check_write_for_task_5.h check_write_string.h create_notation.h delenie_2.h delenie_ostatok_task_3.h for_3_task_4.h for_61_or_131_task_4.h meniu.h my_sum.h ostatok.h priamoi_kod_task_2.h rewerse_task_3.h size_for_task_2.h sum_differense.h summa_task_2.h write_base.h write_for_start.h write_for_task_4.h write_no_limit.h)

add_executable(${PROJECT_NAME}_address ${CPP} ${H})

set(ASAN "-fsanitize=address")
set(TSAN "-fsanitize=thread")

target_compile_options(${PROJECT_NAME}_address PRIVATE ${ASAN})
target_link_libraries(${PROJECT_NAME}_address PRIVATE ${ASAN})

add_executable(${PROJECT_NAME}_tsan ${CPP} ${H})
target_compile_options(${PROJECT_NAME}_tsan PRIVATE ${TSAN})
target_link_libraries(${PROJECT_NAME}_tsan PRIVATE ${TSAN})  

add_executable(${PROJECT_NAME} ${CPP} ${H})


