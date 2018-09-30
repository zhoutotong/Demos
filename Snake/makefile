SRCS = chaintable.c main.c
OBJS = $(SRCS:.c=.o)
TARGET = snake.exe

CXXFLAGS = -std=c99
CC = GCC

$(TARGET):$(OBJS)
	$(CC) -o $@ $^ 

%.o:%.c
	$(CC) -o $@ -c $< $(CXXFLAGS)
	
clean:
	del $(OBJS) $(TARGET)
