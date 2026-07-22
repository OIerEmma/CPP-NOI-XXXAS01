cmake_minimum_required(VERSION 3.28)
project(CPP-NOI-XXXAS01)

set(CMAKE_CXX_STANDARD 11)

add_executable(CPP-NOI-XXXAS01 src/main.cpp)
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
                src/EMME/DP/升维/XRS_Monkey_Taking_Sweets.cpp
                src/EMME/DP/升维/Monkey_Taking_Sweets_Two_Var_Optimization.cpp
                src/EMME/DP/升维/LC0121_best-time-to-buy-and-sell-stock.cpp
                src/EMME/DP/升维/LC0309_best-time-to-buy-and-sell-stock-with-cooldown.cpp
                src/EMME/DP/升维/LC0122_best-time-to-buy-and-sell-stock-ii.cpp
                src/EMME/DP/升维/LC0714_best-time-to-buy-and-sell-stock-with-transaction-fee.cpp)
        message(\ \ \ \ --\ src/${name}\ will\ be\ compiled\ to\ bin/${name})
    endif ()
endforeach ()