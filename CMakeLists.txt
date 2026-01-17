cmake_minimum_required(VERSION 3.28)
project(CPP-NOI-XXXAS01)

set(CMAKE_CXX_STANDARD 11)

add_executable(CPP-NOI-XXXAS01 src/main.cpp
        src/AMY/L4_202306_2.cpp)

# 递归遍历所有的 cpp 文件
file(GLOB_RECURSE files "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# 将所有的 cpp 文件单独生成可执行文件
foreach (file ${files})
    # 简化的检查：使用 grep 查找 "int main" 字符串
    execute_process(
            COMMAND grep -q "int main" ${file}
            RESULT_VARIABLE founded
    )
    if (${founded} EQUAL 0)
        # 如果找到了 main 函数，则创建可执行文件
        get_filename_component(name ${file} NAME)
        add_executable(${name} ${file}
                src/EMME/GESP_exam_question/L4_question/202306/L4_202306_question02.cpp)
        message(\ \ \ \ --\ src/${name}\ will\ be\ compiled\ to\ bin/${name})
    endif ()
endforeach ()