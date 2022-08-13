all:
	echo $(PATH)
	gcc pong.c -L. -lm -lraylib -lpthread -ldl -lrt -o "pong.c.out"
	exec "./pong.c.out"
