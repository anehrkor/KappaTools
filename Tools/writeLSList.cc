#include "TChain.h"
#include "Kappa/DataFormats/interface/KMetadata.h"
#include "../Toolbox/CmdLineSetup.h"
#include <iomanip>

void run(std::string filename)
{
	TChain * lumis_tree = new TChain("Lumis");

	lumis_tree->SetCacheSize(200000000);
	lumis_tree->Add(filename.c_str());

	TBranch * b_lumimetadata;
	KDataLumiMetadata * m_lumimetadata = new KDataLumiMetadata();
	lumis_tree->SetBranchAddress("KLumiMetadata", &m_lumimetadata, &b_lumimetadata);
	lumis_tree->AddBranchToCache(b_lumimetadata);

	Long64_t nentries = lumis_tree->GetEntries();

	for (unsigned int i = 0;i < nentries;i++)
	{
		lumis_tree->GetEntry(i);
		std::cout
			<< std::setw(7) << m_lumimetadata->nRun << "\t"
			<< std::setw(7) << m_lumimetadata->nLumi << "\t"
			<< filename << std::endl;
	}

	delete m_lumimetadata;
	delete lumis_tree;
}

int main(int argc, char* argv[])
{
	std::vector<std::string> filenames = CmdLineBase::ParseArgs(argc, argv, OPT_Help | OPT_Version);

	for (std::vector<std::string>::iterator it = filenames.begin(); it != filenames.end();it++)
		run(*it);

	return 0;
}
