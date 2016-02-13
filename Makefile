POSTGRES_LIBRARY=-lpqxx -lpq
OBJS=geographic/Coords.cc geographic/BoundingBox.cc main.cc
CC=g++
OUT_FILE=-o out

out: $(OBJS)
	$(CC) $(OBJS) $(OUT_FILE) $(POSTGRES_LIBRARY)