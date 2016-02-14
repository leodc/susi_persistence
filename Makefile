#	PREFIX
CC=g++


#	FLAGS
POSTGIS_LIBRARY=-lpqxx -lpq


#	FILES
OBJS_GEPGRAPHIC=src/geographic/Coords.cc src/geographic/BoundingBox.cc tests/geographic_main.cc
OBJS_POSTGIS=src/postgis/postgis.h src/postgis/PostgisFunctions.cc src/geographic/GeoPoint.cc src/geographic/GeoPolygon.cc src/geographic/Coords.cc tests/postgis_main.cc


#	OUTPUT
OUT_FILE=-o ./tests/out


geographic: $(OBJS_GEPGRAPHIC)
	$(CC) $(OBJS_GEPGRAPHIC) $(OUT_FILE)


postgis: $(OBJS_POSTGIS)
	$(CC) $(OBJS_POSTGIS) $(OUT_FILE) $(POSTGIS_LIBRARY)

