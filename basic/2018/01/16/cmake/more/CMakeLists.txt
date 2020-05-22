# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.0.0)

# 项目信息
project(main)

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
#aux_source_directory(<dir> <variable>)

aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(main.out ${DIR_SRCS})