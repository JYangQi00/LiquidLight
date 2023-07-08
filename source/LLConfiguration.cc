#include "LLConfiguration.hh"

LLConfiguration::LLConfiguration(std::string& sConfigFile, bool bDebug = false) {
	inih::INIReader r{ sConfigFile };

    //General settings
    m_uiSpatialDim = r.Get<unsigned int>("general", "SpatialDimension");

    //Scintillation settings
    m_dLXeSingletLifetime = r.Get<double>("scintillation", "LXeSingletLifetime");
    m_dLXeTripletLifetime = r.Get<double>("scintillation", "LXeTripletLifetime");
    m_dLXeSingletTripletRatioNR = r.Get<double>("scintillation", "LXeSingletTripletRatioNR");
    m_dLXeSingletTripletRatioER = r.Get<double>("scintillation", "LXeSingletTripletRatioER");

    //Optical settings
    m_uiNChannels = r.Get<unsigned int>("optical", "NChannels");
    m_sHitpatternType = r.Get<std::string>("optical", "HitpatternType");
    if (m_sHitpatternType == "constant") {
        m_dHitpatternConstValue = r.GetVector<double>("optical", "HitpatternConstValue");
        if (m_dHitpatternConstValue.size()!=m_uiNChannels) {
            std::cout << "ERROR: Hit pattern constant value does not match the number of channels" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else{
        std::cout << "ERROR: Other hitpattern types are not yet implemented" << std::endl;
        exit(EXIT_FAILURE);
    }

    m_sLCEType = r.Get<std::string>("optical", "LCEType");
    if (m_sLCEType == "constant"){
        m_dLCEConstValue = r.Get<double>("optical", "LCEConstValue");
    }
    else{
        std::cout << "ERROR: Other LCE types are not yet implemented" << std::endl;
        exit(EXIT_FAILURE);
    }

    m_dQE = r.Get<double>("optical", "QE");

}

LLConfiguration::~LLConfiguration() {}