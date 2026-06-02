CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = diabetes_analyzer

SRCS = main.c patient.c analyse.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all