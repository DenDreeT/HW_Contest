all: area

# Компиляция программы
area: main.o root.o integral.o func.o
	gcc -o area.exe main.o root.o integral.o func.o

# Компиляция отдельных модулей
main.o: main.c
	gcc -c -o main.o main.c
root.o: root.c
	cc -c -o root.o root.c
integral.o: integral.c
	gcc -c -o integral.o integral.c
func.o: func.c
	gcc -c -o func.o func.c

# Очистка проекта
clean:
	rm *.o area.exe
