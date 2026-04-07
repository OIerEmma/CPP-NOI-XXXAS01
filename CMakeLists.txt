cmake_minimum_required(VERSION 3.28)
project(CPP-NOI-XXXAS01)

set(CMAKE_CXX_STANDARD 11)

add_executable(CPP-NOI-XXXAS01 src/main.cpp
        src/GEEK/LBLD/CH06_BINARYTREE_RECURSIVE/L02_IMPL/思路篇/LC0116_Populating_Next_Right_Pointers_in_Each_Node.cpp
        src/GEEK/LBLD/CH06_BINARYTREE_RECURSIVE/L02_IMPL/思路篇/LC0114_Flatten_Binary_Tree_to_Linked_List.cpp
        src/GEEK/LBLD/CH06_BINARYTREE_RECURSIVE/L02_IMPL/构造篇/LC0654_Maximum_Binary_Tree.cpp
        src/GEEK/LBLD/CH06_BINARYTREE_RECURSIVE/L02_IMPL/构造篇/LC0105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp
        src/GEEK/LBLD/CH06_BINARYTREE_RECURSIVE/L02_IMPL/构造篇/LC0106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp
        src/GEEK/LBLD/CH06_BINARYTREE_RECURSIVE/L02_IMPL/构造篇/LC0889_Construct_Binary_Tree_from_Preorder_and_Postorder_Traversal.cpp
        src/GEEK/LBLD/CH06_BINARYTREE_RECURSIVE/L02_IMPL/构造篇/LC0652_Find_Duplicate_Subtrees.cpp)

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
        add_executable(${name} ${file})
        message(\ \ \ \ --\ src/${name}\ will\ be\ compiled\ to\ bin/${name})
    endif ()
endforeach ()