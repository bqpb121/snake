TARGET:=snake #可执行文件名
SOURCES:=$(wildcard ./src/*.cpp) #把当前目录下所有的.c文件，以空格隔开赋值给了SOURCES
OBJS:=$(patsubst  %.cpp, %.o, $(SOURCES))
CC:=arm-linux-g++ #指定编译器，如果需要在开发板上运行，把该处改成arn-linux-gcc
INCS:=-I ./inc	#指定头文件的搜索路径
LIBS:=-L ./lib	#指定库文件的搜索路径
LIBNAME:= -pthread -lfont -lm	-std=c++11	#指定依赖的库的名字

$(TARGET):$(OBJS) 
	$(CC) $^ -o $@ $(INCS) $(LIBS) $(LIBNAME)
	mv $(TARGET) ./bin
	sudo cp ./bin/$(TARGET) /home/china/tftpboot/
	
%.o:%.cpp
	$(CC) -c $< -o $@ $(INCS) $(LIBS) $(LIBNAME)

clean:
	rm ./src/*.o -f
	#rm ./bin/$(TARGET) -f 
