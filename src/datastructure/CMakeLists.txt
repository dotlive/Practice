project(DatasStructure)

set(datastructure_inc_path ${CMAKE_HOME_DIRECTORY}/datastructure/include)
set(datastructure_src_path ${CMAKE_HOME_DIRECTORY}/datastructure/src)

# tree
set(tree_include_dir ${datastructure_inc_path}/Tree/)
set(tree_headers
    ${tree_include_dir}/BinaryTree/BinaryTreeNode.h
    ${tree_include_dir}/BinaryTree/BinaryTree.h
)
source_group("Header Files\\Tree" FILES ${tree_headers})

set(tree_source_dir ${datastructure_src_path}/Tree)
set(tree_src
    ${tree_source_dir}/UTest.cpp
)
source_group("Source Files\\Tree" FILES ${tree_src})

include_directories(${tree_include_dir})
include_directories(${tree_include_dir}/BinaryTree)

add_executable(test_tree ${tree_headers} ${tree_src})