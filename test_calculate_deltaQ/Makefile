

LIBS =  -lm -lstdc++ -lcurses

#include head file
INC = -I./
TARGET = ./cal

DIRS:=  ./


FILE_C := $(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))
FILE_CPP := $(foreach dir,$(DIRS),$(wildcard $(dir)/*.cpp))

OBJS := $(patsubst %.c,%.o, $(FILE_C)) $(patsubst %.cpp,%.opp, $(FILE_CPP))

POSTFLAG := -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable

all:$(TARGET)

%.o:%.c
	$(CC) -c  $(CFLAGS) $(INC) $< -o $@ $(POSTFLAG)
%.opp:%.cpp
	$(CC) -c $(CFLAGS) $(INC) $< -o $@ $(POSTFLAG)

	
	
$(TARGET):$(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) $(LDFLAGS) $(POSTFLAG)


clean:
	$(RM) $(TARGET)
	$(RM) $(OBJS)

