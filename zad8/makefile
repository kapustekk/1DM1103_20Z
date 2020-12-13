all:
	cc baza.c main.c -o mydb -Wall --pedantic

test: all
	./mydb baza.csv list_base

test-students: all
	./mydb baza.csv list_students

test-od-konca: all
	./mydb baza.csv list_students_from_end
	
test-ile: all
	./mydb baza.csv count_students

test-memory: all
	valgrind ./mydb baza.csv count_students

test-sortuj-stud-malejaco: all
	./mydb baza.csv sort_students
	
test-sortuj-stud-rosnaco: all
	./mydb baza.csv sort_students reverse

test-sortuj-przed-po-nazwie: all
	./mydb baza.csv sort_subjects_by_name

test-sortuj-przed-po-kodzie: all
	./mydb baza.csv sort_subjects_by_code

test-sortuj-przed-po-kodzie-rosnaco: all
	./mydb baza.csv sort_subjects_by_code reverse
test-sortuj-przed-po-nazwie-rosnaco: all
	./mydb baza.csv sort_subjects_by_name reverse

test-filtruj-przedmiot: all
	./mydb baza.csv filter_subject 1DE2103

test-filtruj-studenta: all
	./mydb baza.csv filter_student 000007

test-add_student: all
	./mydb baza.csv add_student Adam Małysz 007007 malysz7@lece.pl

test-add_subject: all
	./mydb baza.csv add_subject 1DE2199 Matematyka 5067Z