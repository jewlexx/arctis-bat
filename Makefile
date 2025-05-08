build: main.o device.a
	gcc -o main $^ -lhidapi-hidraw

main.o: main.c
	gcc -c $< -o $@

device.a: device.o
	ar rcs $@ $^

device.o: device.c
	gcc -c -o $@ $<
