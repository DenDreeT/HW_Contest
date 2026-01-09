# *********************************
# файл для сборки консольной программы
# курсового проекта
# с данными датчика температуры
# *********************************

all: temp_stats

temp_stats: main.o temp_functions.o
	gcc -o temp_stats.exe main.o temp_functions.o

main.o: main.c temp_functions.h
	gcc -c main.c

temp_functions.o: temp_functions.c temp_functions.h
	gcc -c temp_functions.c

clean:
	rm -rf *.s *.o *.exe

# Windows
clean_win:
	del -rf *.s *.o *.exe
