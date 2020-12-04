all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_students

test-ile: all
	./mydb baza.csv count_students

test-memory: all
	valgrind ./mydb baza.csv count_students
	
test-add_student: all
	./mydb baza.csv add_student Adam Małysz 007007 malysz7@lece.pl

test-add-subject: all
	./mydb baza.csv add_subject 000017 1DE2199 5.000000 1DE2106
