/* Copyright (c) 2010 - All Rights Reserved
 *   Fred Stober <stober@cern.ch>
 *   Manuel Zeise <zeise@cern.ch>
 */

#include "VertexPlots.h"

namespace KappaTools
{
	StandardVertexPlots::StandardVertexPlots(TDirectory * tmpFile, TString tmpDirectory)
	{
		getDirectory(tmpFile, tmpDirectory);

		pos_xy				= new TH1D("pos_xy","d_{xy}^{\\mathrm{pos.}}", 50, 0., 0.25);
		pos_xy->Sumw2();
		pos_z				= new TH1D("pos_z","z_{\\mathrm{pos.}}", 50, -20., 20.);
		pos_z->Sumw2();
		pos_rho				= new TH1D("pos_rho","#rho_{\\mathrm{pos.}}", 50, 0., 2.5);
		pos_rho->Sumw2();

		nTracks				= new TH1D("nTracks","\\mathrm{tracks}", 50, 0., 50.);
		nTracks->Sumw2();

		chi2				= new TH1D("chi2","#chi^{2}", 50, 0., 50.);
		chi2->Sumw2();
		ndof				= new TH1D("ndof","\\mathrm{ndof}", 25, 0., 25.);
		ndof->Sumw2();
		chi2norm			= new TH1D("chi2norm","#chi^{2} / \\mathrm{ndof}", 10, 0., 10.);
		chi2norm->Sumw2();
		chi2prob			= new TH1D("chi2prob","\\mathrm{prob}(#chi^{2})", 50, 0., 1.);
		chi2prob->Sumw2();
	}

	void StandardVertexPlots::process(KVertex * pv, double weight)
	{
		if (!pv)
			return;

		pos_xy->Fill(pv->position.Perp2());
		pos_z->Fill(pv->position.z());
		pos_rho->Fill(pv->position.rho());

		nTracks->Fill(pv->nTracks,weight);

		chi2->Fill(pv->chi2, weight);
		ndof->Fill(pv->nDOF, weight);
		chi2norm->Fill(pv->chi2/pv->nDOF, weight);
		chi2prob->Fill(TMath::Prob(pv->chi2, static_cast<int>(pv->nDOF)), weight);
	}

	void StandardVertexPlots::final()
	{
	}
}

