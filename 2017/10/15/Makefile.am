#Makefile.am AUTOMAKE_OPTIONS=foreign //
#automake提供了3 种软件等级：foreign、gnu和gnits，让用户选择采用，默认等级为gnu。在本例使用foreign等级，它只检测必须的文件。
#//定义要产生的执行文件名。如果要产生多个执行文件，每个文件名用空格隔开
bin_PROGRAMS= hello
#//定义“hello”这个执行程序所需要的原始文件。
hello_SOURCES= include/pr.h src/hello.c
#//添加头文件目录（重要的）
hello_CPPFLAGS = -I include/
