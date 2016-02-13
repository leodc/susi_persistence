
OBJS=geographic/Coords.cc geographic/BoundingBox.cc main.cc
CC=g++
OUT_FILE=-o out

out: $(OBJS)
	$(CC) $(OBJS) $(OUT_FILE)