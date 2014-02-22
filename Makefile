all: send receive

send: LightwaveRF.o send.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

receive: LightwaveRF.o receive.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi
clean:
	$(RM) *.o send receive
