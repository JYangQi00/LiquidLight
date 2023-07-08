#ifndef LLCONFIGURATION_HH
#define LLCONFIGURATION_HH

#include <iostream>
#include <vector>
#include "Ini.hh"
#include "LLGenericMap.hh"
#include "LLConstantMap.hh"

class LLConfiguration {
public:
	LLConfiguration(std::string& sConfigFile, bool bDebug);
	~LLConfiguration();

	std::string sConfigFile;

	//General settings
	unsigned int m_uiSpatialDim;

	//Scintillation settings
	double m_dLXeSingletLifetime;
	double m_dLXeTripletLifetime;
	double m_dLXeSingletTripletRatioNR;
	double m_dLXeSingletTripletRatioER;

	//Optical settings
	std::string m_sHitpatternType;
	std::string m_sLCEType;
	std::vector<double> m_dHitpatternConstValue;
	double m_dLCEConstValue;
	unsigned int m_uiNChannels;
	double m_dQE;

private:
	const float dGainConvert = 6095.248943620215;
	

};

#endif