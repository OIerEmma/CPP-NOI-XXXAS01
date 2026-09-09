cmake_minimum_required(VERSION 3.28)
project(CPP-NOI-XXXAS01)

set(CMAKE_CXX_STANDARD 11)

add_executable(CPP-NOI-XXXAS01 src/main.cpp
        src/GEEK/GESP/L7/03哈希函数/L2六类题型/T3_LC0001_Two_Sum.cpp
        src/GEEK/GESP/L7/03哈希函数/L2六类题型/T4_LC0560_Subarray_Sum_Equals_K.cpp
        src/GEEK/GESP/L7/03哈希函数/L2六类题型/T5_LC0049_Group_Anagrams.cpp
        src/GEEK/GESP/L7/00历年真题/L7_202406_2.cpp
        src/GEEK/GESP/L7/00历年真题/L7_202503_2.cpp
        src/GEEK/GESP/L7/00历年真题/L7_202603_1_QPOW.cpp
        src/GEEK/GESP/L7/00历年真题/L7_202603_1_DP.cpp
        src/GEEK/GESP/L7/00历年真题/L7_202603_2.cpp)
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
                src/EMME/HASH/LC0001_Two_Sum.cpp
                src/EMME/HASH/LC0560_subarray-sum-equals-k.cpp
                src/EMME/HASH/LC0049_Group-Anagrams.cpp)
        message(\ \ \ \ --\ src/${name}\ will\ be\ compiled\ to\ bin/${name})
    endif ()
endforeach ()