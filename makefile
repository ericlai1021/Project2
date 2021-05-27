all: main.c BST.h BS.h Array.h Linked_list.h Hash.h
	gcc -g main.c

clean:
	rm a.out
