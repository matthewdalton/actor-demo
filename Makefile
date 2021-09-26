CXX=g++
CXXFLAGS=-std=c++11

SRCS=actor-demo.cpp Actor.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: actor-demo

actor-demo: $(OBJS)
	$(CXX) -o actor-demo $(OBJS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ >> ./.depend

clean:
	$(RM) $(OBJS) actor-demo

distclean: clean
	$(RM) *~ .depend
include .depend
