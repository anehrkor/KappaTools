#------------------------------------------------------------------------------
BASEDIR ?= $(shell cd ..; pwd)
PROGRAM  = triggerPrescale.sbin writeLSList.sbin duplicateEventChecker.sbin xsec.sbin
#------------------------------------------------------------------------------

include $(BASEDIR)/Makefile.root

%.sbin: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(BASEDIR)/lib/libKRootTools.a $(BASEDIR)/../Kappa/DataFormats/test/libKappa.o $(BASEDIR)/../Kappa/DataFormats/test/Hash.o $(BASEDIR)/lib/libKToolbox.a
