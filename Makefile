build:
	gcc main.c -L./target/release -lartcis_bat -ludev

main.o: main.c
	gcc -c $< -o $@

device.a: device.o
	ar rcs $@ $^

device.o: device.c
	gcc -c -o $@ $<
