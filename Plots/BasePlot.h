/* Copyright (c) 2010 - All Rights Reserved
 *   Fred Stober <stober@cern.ch>
 *   Manuel Zeise <zeise@cern.ch>
 */

#ifndef KAPPA_BASEPLOT_H
#define KAPPA_BASEPLOT_H

#include <TDirectory.h>
//#include <iostream>

namespace KappaTools
{
	class BasePlot
	{
		protected:
			TDirectory * outFile;
		
		public:
			BasePlot();
			TDirectory * getDirectory(TDirectory * tmpFile, TString tmpDirectory);
	};
}
#endif
