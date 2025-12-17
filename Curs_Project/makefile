# *********************************
# файл для сборки консольной программы
# курсового проекта
# с данными датчика температуры
# *********************************
# *******реализация под Linux*******

CC = gcc

temp_prog.o: main.o temp_api.o
	$(CC) -o temp_prog.o main.o temp_api.o
	
# *******реализация под Windows*******
#
#temp_prog.exe: main.o temp_api.o
#	$(CC) -o temp_prog.exe main.o temp_api.o


main.o: main.c temp_api.h
	$(CC) -O0 -g3 -Wall -c main.c

temp_api.o: temp_api.c temp_api.h
	$(CC) -O0 -g3 -Wall -c temp_api.c

# ************************************
# **********очистка проекта*********
# Linux
clean:
	rm -rf *.s *.o
	
# Windows
clean_win:
	del -rf *.s *.o *.exe
